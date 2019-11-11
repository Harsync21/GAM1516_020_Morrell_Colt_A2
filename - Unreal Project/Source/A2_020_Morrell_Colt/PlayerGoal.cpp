// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerGoal.h"

#include "Components/StaticMeshComponent.h"

#include "UObject/ConstructorHelpers.h"

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APlayerGoal::APlayerGoal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    //Create Player Object
    UBoxComponent* PlayerGoal = CreateDefaultSubobject<UBoxComponent>(TEXT("RootComponent"));
    PlayerGoal->SetWorldScale3D(FVector(1.0f));
    PlayerGoal->SetBoxExtent(FVector(10.f, 10.f, 150.f));
    RootComponent = PlayerGoal;
    PlayerGoal->SetCollisionProfileName(TEXT("OnOverlay"));

    //Create and position a mesh component so we can see where our sphere is
    UStaticMeshComponent* PlayerGoalVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
    PlayerGoalVisual->SetupAttachment(RootComponent);
    static ConstructorHelpers::FObjectFinder<UStaticMesh> PlayerGoalVisualVisualAsset(TEXT("/Game/StarterContent/Props/SM_PillarFrame.SM_PillarFrame"));

    if (PlayerGoalVisualVisualAsset.Succeeded())
    {
        PlayerGoalVisual->SetStaticMesh(PlayerGoalVisualVisualAsset.Object);
        PlayerGoalVisual->SetRelativeLocation(FVector(-10.0f, 0.0f, -150.f));
        PlayerGoalVisual->SetWorldScale3D(FVector(1.0f));
    }

}

// Called when the game starts or when spawned
void APlayerGoal::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerGoal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

