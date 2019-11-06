// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPaddle.h"
#include "Ball.h"
#include "BallSpawner.h"

#include "Classes/Camera/CameraComponent.h"
#include "Classes/GameFramework/SpringArmComponent.h"
#include "Classes/Components/InputComponent.h"

#include "Components/StaticMeshComponent.h"

#include "UObject/ConstructorHelpers.h"

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

#include "Classes/GameFramework/FloatingPawnMovement.h"

// Sets default values
APlayerPaddle::APlayerPaddle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Allows Paddle to Stay in the air
	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>("PawnMovement");

    //Create Player Object
    UBoxComponent* Paddle = CreateDefaultSubobject<UBoxComponent>(TEXT("RootComponent"));
    Paddle->SetWorldScale3D(FVector(1.0f));
    Paddle->SetBoxExtent(FVector(10.f,10.f,150.f));
    SetRootComponent(Paddle);
    Paddle->SetCollisionProfileName(TEXT("BlockAll"));

    //Create and position a mesh component so we can see where our sphere is
    UStaticMeshComponent* PaddleVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
    PaddleVisual->SetupAttachment(RootComponent);
    static ConstructorHelpers::FObjectFinder<UStaticMesh> PaddleVisualAsset(TEXT("/Game/StarterContent/Props/SM_PillarFrame300.SM_PillarFrame300"));

    if (PaddleVisualAsset.Succeeded())
    {
        PaddleVisual->SetStaticMesh(PaddleVisualAsset.Object);
        PaddleVisual->SetRelativeLocation(FVector(-10.0f, 0.0f, -150.f));
        PaddleVisual->SetWorldScale3D(FVector(1.0f));
    }


    CameraArm = CreateDefaultSubobject<USpringArmComponent>("CameraSpringArm");
    //CameraArm->SetupAttachment(RootComponent);
    CameraArm->TargetArmLength = 500.f;

    //Camera Component
	Camera = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    Camera->SetProjectionMode(ECameraProjectionMode::Orthographic);
    Camera->SetOrthoWidth(5000.f);
    Camera->SetupAttachment(CameraArm);

	//Automatically Possesses Player
	AutoPossessPlayer = EAutoReceiveInput::Player0;

}

// Called when the game starts or when spawned
void APlayerPaddle::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerPaddle::Move(float amount)
{
	Movement = amount * 5;
}

void APlayerPaddle::ParticleToggle()
{
    
}

void APlayerPaddle::Serve()
{

}

// Called every frame
void APlayerPaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Movement != 0)
	{
		FVector NewLocation = GetActorLocation() + (GetActorUpVector() * Movement);
		SetActorLocation(NewLocation);
	}

}

// Called to bind functionality to input
void APlayerPaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

