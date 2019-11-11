// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

class APlayerPaddle;
/**
 * 
 */
UCLASS()
class A2_020_MORRELL_COLT_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMyPlayerController();

protected:
	APlayerPaddle* myPawn;

protected:
	void SetupInputComponent() override;
	void Move(float amount);
    void Serve();
};
