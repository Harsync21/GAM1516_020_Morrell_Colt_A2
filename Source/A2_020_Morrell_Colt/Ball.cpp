// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "Wall.h"

#include "PlayerGoal.h"
#include "EnemyGoal.h"

#include "PongGameMode.h"

#include "UObject/ConstructorHelpers.h"

#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"

#include "Components/PrimitiveComponent.h"

#include "Classes/GameFramework/ProjectileMovementComponent.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Root component is a sphere that reacts to physics
	USphereComponent* Ball = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	RootComponent = Ball;
	Ball->InitSphereRadius(40.0f);
	Ball->SetCollisionProfileName(TEXT("BlockAll"));

	//Create and position a mesh component so we can see where our sphere is
	UStaticMeshComponent* SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	SphereVisual->SetupAttachment(Ball);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));

	if (SphereVisualAsset.Succeeded())
	{
		SphereVisual->SetStaticMesh(SphereVisualAsset.Object);
		SphereVisual->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f));
		SphereVisual->SetWorldScale3D(FVector(0.8f));
	}

	BallMovement = CreateDefaultSubobject<UProjectileMovementComponent>("BallMovement");
    BallMovement->ProjectileGravityScale = 0.f;
	BallMovement->InitialSpeed = 2000.f;
	BallMovement->MaxSpeed = 2000.f;
    BallMovement->Friction = 0;
	BallMovement->bShouldBounce = true;
    BallMovement->Bounciness = 1.0f;

    OurParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("MovementParticles"));
    OurParticleSystem->SetupAttachment(SphereVisual);
    OurParticleSystem->bAutoActivate = false;
    OurParticleSystem->SetRelativeLocation(FVector(0.0f, 0.0f, 20.0f));

    static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleAsset(TEXT("/Game/StarterContent/Particles/P_Fire.P_Fire"));
    if (ParticleAsset.Succeeded())
    {
        OurParticleSystem->SetTemplate(ParticleAsset.Object);
        OurParticleSystem->ToggleActive();
    }

	OnActorHit.AddDynamic(this, &ABall::OnBallHit);
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABall::ParticleToggle()
{
    if (OurParticleSystem && OurParticleSystem->Template)
    {
        OurParticleSystem->ToggleActive();
    }
}

void ABall::OnBallHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{

    if (APlayerGoal * PlayerGoal = Cast<APlayerGoal>(OtherActor))
	{
		if (APongGameMode * GM = Cast<APongGameMode>(GetWorld()->GetAuthGameMode()))
		{
			GM->OnTargetHit("Player");
            Destroy();
            Iteration++;
		}
	}

	if (AEnemyGoal * EnemyGoal = Cast<AEnemyGoal>(OtherActor))
	{
		if (APongGameMode * GM = Cast<APongGameMode>(GetWorld()->GetAuthGameMode()))
		{
			GM->OnTargetHit("Enemy");
            Destroy();
            Iteration++;
		}
	}
}

UPrimitiveComponent* ABall::GetPhysicsComponent()
{
    return Cast<UPrimitiveComponent>(RootComponent);
}

