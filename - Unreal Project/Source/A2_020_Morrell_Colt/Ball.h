// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"

UCLASS()
class A2_020_MORRELL_COLT_API ABall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABall();
    
    class ABallSpawner* BallSpawner;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Components")
		UStaticMeshComponent* BallMesh;

	UPROPERTY(EditAnywhere, Category = "Components")
		class UProjectileMovementComponent* BallMovement;

    UParticleSystemComponent* OurParticleSystem;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnBallHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

    class UPrimitiveComponent* GetPhysicsComponent();
};
