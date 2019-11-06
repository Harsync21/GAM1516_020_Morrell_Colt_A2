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
    UBoxComponent* EPaddle = CreateDefaultSubobject<UBoxComponent>(TEXT("RootComponent"));
    EPaddle->SetWorldScale3D(FVector(1.0f));
    EPaddle->SetBoxExtent(FVector(10.f, 10.f, 150.f));
    EPaddle->SetRelativeLocation(FVector(0.0f, 0.0f, 0.f));
    EPaddle->SetCollisionProfileName(TEXT("BlockAll"));

    //Create and position a mesh component so we can see where our sphere is
    UStaticMeshComponent* EPaddleVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
    EPaddleVisual->SetupAttachment(EPaddle);
    static ConstructorHelpers::FObjectFinder<UStaticMesh> EPaddleVisualAsset(TEXT("/Game/StarterContent/Props/SM_PillarFrame300.SM_PillarFrame300"));

    if (EPaddleVisualAsset.Succeeded())
    {
        EPaddleVisual->SetStaticMesh(EPaddleVisualAsset.Object);
        EPaddleVisual->SetRelativeLocation(FVector(-10.0f, 0.0f, -150.f));
        EPaddleVisual->SetWorldScale3D(FVector(1.0f));
    }
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

    if (Ball != nullptr)
    {
        //DECLARE a variable called targetLocation of type FVector and assign it to the return value of FMath::VInterpConstantTo(..) passing in --> GetActorLocation(), Target->GetActorLocation(), DeltaTime, 600.0f
        FVector targetLocation = FMath::VInterpConstantTo(GetActorLocation(), Ball->GetActorLocation(), DeltaTime, 600.0f);
        //CALL  SetActorLocation(..) passing in targetLocation
        SetActorLocation(targetLocation);
    }
}

