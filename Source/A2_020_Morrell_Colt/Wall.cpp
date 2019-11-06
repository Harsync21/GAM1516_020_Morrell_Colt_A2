// Fill out your copyright notice in the Description page of Project Settings.


#include "Wall.h"

#include "UObject/ConstructorHelpers.h"

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AWall::AWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    UBoxComponent* Wall = CreateDefaultSubobject<UBoxComponent>(TEXT("RootComponent"));
    RootComponent = Wall;
    Wall->SetBoxExtent(FVector(10.f, 10.f, 150.f));
    Wall->SetRelativeRotation(FRotator(90.f, 0.f, 0.f));
    Wall->SetRelativeScale3D(FVector(1, 1, 8));
    Wall->SetCollisionProfileName(TEXT("BlockAll"));

    //Create and position a mesh component so we can see where our sphere is
    UStaticMeshComponent* WallVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
    WallVisual->SetupAttachment(RootComponent);
    static ConstructorHelpers::FObjectFinder<UStaticMesh> WallVisualAsset(TEXT("/Game/StarterContent/Props/SM_PillarFrame.SM_PillarFrame"));

    if (WallVisualAsset.Succeeded())
    {
        WallVisual->SetStaticMesh(WallVisualAsset.Object);
        WallVisual->SetRelativeLocation(FVector(-10.0f, 0.0f, -150.f));
        //WallVisual->SetRelativeRotation(FRotator(90.f, 0.f, 0.f));
        //WallVisual->SetRelativeScale3D(FVector(1, 1, 11));
        //WallVisual->SetWorldScale3D(FVector(1.0f));
    }
}

// Called when the game starts or when spawned
void AWall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

