// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ball.h"
#include "PlayerPaddle.h"
#include "GameFramework/Actor.h"
#include "EnemyPaddle.generated.h"

UCLASS()
class A2_020_MORRELL_COLT_API AEnemyPaddle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyPaddle();

	void MovePaddle(float Amount);

	bool bImGoingUp = true;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, Category = "Components")
        UStaticMeshComponent* EPaddleMesh;

    UPROPERTY(EditAnywhere, Category = "Components")
        class UBoxComponent* EPaddle;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetBall(class ABall* Ball);

    UPROPERTY(EditInstanceOnly,
        Category = "AI",
        meta = (EditCondition = "Target"))
        AActor* Target;

private:
	class ABall* Ball;
	float Velocity;
};
