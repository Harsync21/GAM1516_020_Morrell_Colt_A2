// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PongGameMode.generated.h"

/**
 * 
 */
UCLASS()
class A2_020_MORRELL_COLT_API APongGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APongGameMode();

	void OnTargetHit(FString Goal);

	UPROPERTY(EditAnywhere, Category = "Game Rules")
	int32 PointsToWin;

	
};
