// Fill out your copyright notice in the Description page of Project Settings.


#include "BallSpawner.h"
#include "Components/ArrowComponent.h"
#include "ConstructorHelpers.h"

#include "Ball.h"
#include <TimerManager.h>
#include "PlayerPaddle.h"

// Sets default values
ABallSpawner::ABallSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    //ARROW COMPONENT//
    SpawnPointComponent = CreateDefaultSubobject<UArrowComponent>(TEXT("SpawnPoint"));
    SpawnPointComponent->SetupAttachment(RootComponent);
    SpawnPointComponent->ArrowSize = 5.f;
    SpawnPointComponent->SetRelativeRotation(FRotator(0.f, 0.f, 0.f));
    SpawnPointComponent->SetRelativeLocation(FVector(0.f, 0.f, 0.f));

}

// Called when the game starts or when spawned
void ABallSpawner::BeginPlay()
{
	Super::BeginPlay();
    //FTimerManager& Timer = GetWorldTimerManager();
    //Timer.SetTimer(SpawnTimer, this, &ABallSpawner::SpawnActor, SpawnDelay, true);
	
}

// Called every frame
void ABallSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABallSpawner::SpawnActor()
{
    if (BallActorTemplate != nullptr)
    {
        UWorld* World = GetWorld();

        if (World)
        {
            FActorSpawnParameters SpawnParams;

            SpawnParams.Owner = this;
            SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

            FTransform SpawnTransform = SpawnPointComponent->GetComponentTransform();
            ABall* Ball = World->SpawnActor<ABall>(BallActorTemplate, SpawnTransform, SpawnParams);

            if (Ball)
            {
                FVector direction = FRotationMatrix(SpawnTransform.Rotator()).GetScaledAxis(EAxis::X);
                UPrimitiveComponent* physicsComponent = Ball->GetPhysicsComponent();
                // physicsComponent->AddForce(direction * 1000000, NAME_None, true);
            }
        }
    }
}

