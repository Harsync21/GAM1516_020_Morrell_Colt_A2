// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "PongGameState.generated.h"

/**
 * 
 */
UCLASS()
class A2_020_MORRELL_COLT_API APongGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	APongGameState();

	int32 PlayerPoints;
    int32 EnemyPoints;
};
