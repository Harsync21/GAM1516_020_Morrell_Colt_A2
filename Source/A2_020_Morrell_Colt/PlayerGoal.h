// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerGoal.generated.h"

UCLASS()
class A2_020_MORRELL_COLT_API APlayerGoal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayerGoal();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, Category = "Components")
        UStaticMeshComponent* PlayerGoal;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
