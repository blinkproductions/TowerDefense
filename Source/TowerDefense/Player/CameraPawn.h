// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CameraPawn.generated.h"

UCLASS()
class TOWERDEFENSE_API ACameraPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACameraPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Components
	UPROPERTY(EditDefaultsOnly)
	class USceneComponent* RootScene;
	
	UPROPERTY(EditDefaultsOnly)
	class USpringArmComponent* SpringArm;

	UPROPERTY(EditDefaultsOnly)
	class UCameraComponent* Camera;
	
	// Variables
	UPROPERTY(EditDefaultsOnly, Category = "Camera Parameters")
	float Margin;

	UPROPERTY(EditDefaultsOnly, Category = "Camera Parameters")
	float CameraPanSpeed;

	UPROPERTY(EditDefaultsOnly, Category = "Camera Parameters")
	float ZoomRate;
	
	float CurrentArmLength;
	
	int32 ScreenSizeX;
	int32 ScreenSizeY;
	
	class APlayerController* PC;

	// Functions
	UFUNCTION(BlueprintCallable)
	FVector GetCameraPanDirection();
	
	void PanMoveCamera(FVector PanDirection);

	void ZoomCamera(float Val);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};


