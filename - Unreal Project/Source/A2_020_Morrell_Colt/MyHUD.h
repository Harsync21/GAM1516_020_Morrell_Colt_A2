// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PongGameState.h"
#include "MyHUD.generated.h"

class UUserWidget;
/**
 * 
 */
UCLASS()
class A2_020_MORRELL_COLT_API AMyHUD : public AHUD
{
	GENERATED_BODY()

public:
    AMyHUD();
	class APongGameState* GameState;

    UPROPERTY(EditAnywhere, Category = "PlayerGuiClass")
        TSubclassOf<class UUserWidget> PlayerGuiClass;

    UPROPERTY(EditAnywhere, Category = "PlayerGui")
        class UUserWidget* PlayerGui;

protected:
    void BeginPlay() override;

private: 
	int32 PlayerPoints;
	int32 EnemyPoints;
	
};
