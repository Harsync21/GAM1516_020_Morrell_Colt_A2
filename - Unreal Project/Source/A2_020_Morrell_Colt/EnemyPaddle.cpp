// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyPaddle.h"
#include "Ball.h"

#include "Components/StaticMeshComponent.h"

#include "UObject/ConstructorHelpers.h"

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AEnemyPaddle::AEnemyPaddle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    //Create Player Object
    EPaddle = CreateDefaultSubobject<UBoxComponent>(TEXT("RootComponent"));
    EPaddle->SetWorldScale3D(FVector(1.0f));
    SetRootComponent(EPaddle);
    RootComponent = EPaddle;
    EPaddle->SetBoxExtent(FVector(10.f, 10.f, 150.f));
    EPaddle->SetRelativeLocation(FVector(0.0f, 0.0f, 0.f));
    EPaddle->SetCollisionProfileName(TEXT("BlockAll"));
    EPaddle->GetBodyInstance()->bLockXTranslation = true;
    EPaddle->GetBodyInstance()->bLockYTranslation = true;
    EPaddle->GetBodyInstance()->bLockZTranslation = false;
    EPaddle->GetBodyInstance()->bLockYRotation = true;
    EPaddle->GetBodyInstance()->bLockXRotation = true;

    //Create and position a mesh component so we can see where our sphere is
    UStaticMeshComponent* EPaddleVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
    EPaddleVisual->SetupAttachment(RootComponent);
    static ConstructorHelpers::FObjectFinder<UStaticMesh> EPaddleVisualAsset(TEXT("/Game/StarterContent/Props/SM_PillarFrame300.SM_PillarFrame300"));

    if (EPaddleVisualAsset.Succeeded())
    {
        EPaddleVisual->SetStaticMesh(EPaddleVisualAsset.Object);
        EPaddleVisual->SetRelativeLocation(FVector(-10.0f, 0.0f, -150.f));
        EPaddleVisual->SetWorldScale3D(FVector(1.0f));
    }
}

void AEnemyPaddle::MovePaddle(float Amount)
{
	//FVector direction = FVector(0.0f, 0.0f, 75.0f);
	//Velocity = Amount * 75.0f;
}

// Called when the game starts or when spawned
void AEnemyPaddle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyPaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if (Target != nullptr)
    {
		//FVector targetLocation = GetActorLocation();

		//targetLocation.Z += 10.0f;

       //DECLARE a variable called targetLocation of type FVector and assign it to the return value of FMath::VInterpConstantTo(..) passing in --> GetActorLocation(), Target->GetActorLocation(), DeltaTime, 600.0f
       float targetLocation = FMath::FInterpConstantTo(GetActorLocation().Z, Target->GetActorLocation().Z, DeltaTime, 600.0f);

	   ////GetActorLocation().Z
       //CALL  SetActorLocation(..) passing in targetLocation
       SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, targetLocation));
    }
}

void AEnemyPaddle::SetBall(ABall* Ball)
{
	this->Ball = Ball;
}

