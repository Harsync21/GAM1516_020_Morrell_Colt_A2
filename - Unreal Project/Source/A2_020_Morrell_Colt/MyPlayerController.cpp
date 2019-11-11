// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "PlayerPaddle.h"
#include "Ball.h"
#include "BallSpawner.h"

AMyPlayerController::AMyPlayerController()
{

}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (InputComponent != nullptr)
	{
		InputComponent->BindAxis("Move", this, &AMyPlayerController::Move);
        InputComponent->BindAction("Serve", IE_Pressed, this, &AMyPlayerController::Serve);
	}
}

void AMyPlayerController::Move(float amount)
{
	APlayerPaddle* pawn = Cast<APlayerPaddle>(GetPawn());
	if (pawn != nullptr)
	{
		pawn->Move(amount);
	}
}

void AMyPlayerController::Serve()
{
    APlayerPaddle* pawn = Cast<APlayerPaddle>(GetPawn());
    if (pawn != nullptr)
    {
        pawn->Serve();
    }
}


