// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BallSpawner.generated.h"

UCLASS()
class A2_020_MORRELL_COLT_API ABallSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABallSpawner();

    UPROPERTY(EditDefaultsOnly,
        BlueprintReadOnly,
        Category = "Config",
        meta = (AllowPrivateAccess = "true"))
        TSubclassOf<class ABall> BallActorTemplate;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    //Arrow Component//
    UPROPERTY(VisibleAnywhere,
        BlueprintReadOnly,
        Category = "Components",
        meta = (AllowPrivateAccess = "true"))
        class UArrowComponent* SpawnPointComponent;

    //Spawn Timer//
    UPROPERTY(BlueprintReadOnly,
        Category = "Config",
        meta = (AllowPrivateAccess = "true"))
        FTimerHandle SpawnTimer;

    /** timer interval to spawn new
       falling actor after previous
       actor was destroyed  */
    UPROPERTY(EditDefaultsOnly,
        BlueprintReadOnly,
        Category = "Config",
        meta = (AllowPrivateAccess = "true"))
        float SpawnDelay = 3.5f;

    UPROPERTY(EditDefaultsOnly,
        BlueprintReadOnly,
        Category = "Config",
        meta = (AllowPrivateAccess = "true"))
        int32 SpawnCount = 0;

    void SpawnActor();

};
