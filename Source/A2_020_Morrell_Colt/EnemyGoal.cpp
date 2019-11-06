// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyGoal.h"

#include "Components/StaticMeshComponent.h"

#include "UObject/ConstructorHelpers.h"

#include "Components/BoxComponent.h"

// Sets default values
AEnemyGoal::AEnemyGoal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    //Create Player Object
    UBoxComponent* EnemyGoal = CreateDefaultSubobject<UBoxComponent>(TEXT("RootComponent"));
    EnemyGoal->SetWorldScale3D(FVector(1.0f));
    EnemyGoal->SetBoxExtent(FVector(10.f, 10.f, 150.f));
    RootComponent = EnemyGoal;
    EnemyGoal->SetCollisionProfileName(TEXT("OnOverlay"));

    //Create and position a mesh component so we can see where our sphere is
    UStaticMeshComponent* EnemyGoalVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
    EnemyGoalVisual->SetupAttachment(RootComponent);
    static ConstructorHelpers::FObjectFinder<UStaticMesh> EnemyGoalVisualVisualAsset(TEXT("/Game/StarterContent/Props/SM_PillarFrame.SM_PillarFrame"));

    if (EnemyGoalVisualVisualAsset.Succeeded())
    {
        EnemyGoalVisual->SetStaticMesh(EnemyGoalVisualVisualAsset.Object);
        EnemyGoalVisual->SetRelativeLocation(FVector(-10.0f, 0.0f, -150.f));
        EnemyGoalVisual->SetWorldScale3D(FVector(1.0f));
    }
}

// Called when the game starts or when spawned
void AEnemyGoal::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyGoal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

