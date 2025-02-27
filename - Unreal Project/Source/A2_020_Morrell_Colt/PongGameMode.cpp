// Fill out your copyright notice in the Description page of Project Settings.


#include "PongGameMode.h"
#include "PongGameState.h"
#include "UObject/ConstructorHelpers.h"

APongGameMode::APongGameMode()
{

}

void APongGameMode::OnTargetHit(FString Goal)
{
    //Goal = IsGoal;

    if (Goal == "Player")
    {
        if (APongGameState * GS = Cast<APongGameState>(GameState))
        {
            GS->PlayerPoints++;

            if (GS->PlayerPoints >= PointsToWin)
            {
                UE_LOG(LogTemp, Warning,TEXT("Player"));
				GEngine->AddOnScreenDebugMessage(-1, 100000.0f, FColor::White, "     Enemy:" + FString::FromInt(GS->PlayerPoints));
					//+ GS->PlayerPoints);
            }
        }
    }
    if (Goal == "Enemy")
    {
        if (APongGameState * GS = Cast<APongGameState>(GameState))
        {
            GS->EnemyPoints++;

            if (GS->EnemyPoints >= PointsToWin)
            {
                UE_LOG(LogTemp, Warning, TEXT("Enemy"));
                GEngine->AddOnScreenDebugMessage(-1, 10000.0f, FColor::White, "      Player:" + FString::FromInt(GS->EnemyPoints));
            }
        }
    }
}
