// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TD_Enemy.generated.h"

UCLASS()
class TOWERDEFENSE_API ATD_Enemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATD_Enemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// FUNCTIONS:
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateHealth();

	// COMPONENTS:
	UPROPERTY(EditDefaultsOnly)
	class USpringArmComponent* SpringArm;
	
	UPROPERTY(EditDefaultsOnly)
	class UCameraComponent* Camera;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
	class UWidgetComponent* ArmorAndHealthWidget;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Components")
	class UHealthComponent* HealthComponent;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Rewards Prooperty")
	int32 GoldReward;

};
