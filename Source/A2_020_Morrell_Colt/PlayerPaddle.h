// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPaddle.generated.h"

UCLASS()
class A2_020_MORRELL_COLT_API APlayerPaddle : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPaddle();

	void Move(float amount);
    void Serve();
    void ParticleToggle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Serving")
		TSubclassOf<class ABall> BallClass;

	class UFloatingPawnMovement* FloatingPawnMovement;

	UPROPERTY(EditAnywhere, Category = "Components")
		UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, Category = "Components")
		class UCameraComponent* Camera;

    UPROPERTY(EditAnywhere, Category = "Components")
        class USpringArmComponent* CameraArm;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	float Movement;
};
