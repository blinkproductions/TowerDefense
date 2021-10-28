// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerUnit.generated.h"

UCLASS()
class TOWERDEFENSE_API APlayerUnit : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerUnit();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// FUNCTIONS:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// COMPONENTS:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* UnitMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	class USceneComponent* MuzzleLocation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	class UArrowComponent* Arrow;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	class USphereComponent* TargetArea;
	
	// VARIABLES:

	// Used as a template to create the unit when spawned in
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category = "Unit Properties")
	//class UPlayerUnitProperties* UnitTemplate;
};
