// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOWERDEFENSE_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
		
	// Sets default values for this component's properties
	UHealthComponent();

	// FUNCTIONS:
	UFUNCTION(BlueprintCallable)
	void TakeDamage(float AmountOfDamage);

	UFUNCTION(BlueprintCallable)
	void Heal(float HealAmount);

	UFUNCTION(BlueprintCallable)
	void SetCurrentHealth(float NewCurrentHealthAmount) { CurrentHealth = NewCurrentHealthAmount; }

	UFUNCTION(BlueprintCallable)
	void SetCurrentArmor(float NewCurrentArmorAmount) { CurrentArmor = NewCurrentArmorAmount; }

	UFUNCTION(BlueprintCallable)
	void SetMaxArmor(float NewMaxArmor) { MaxArmor = NewMaxArmor; }

	UFUNCTION(BlueprintCallable)
	void SetMaxHealth(float NewMaxHealth) { MaxHealth = NewMaxHealth; }

	UFUNCTION(BlueprintPure)
	float GetCurrentHealthPercentage() const { return CurrentHealth / MaxHealth; }

	UFUNCTION(BlueprintPure)
	float GetCurrentArmorPercentage() const { return CurrentArmor / MaxArmor; }
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// VARIABLES:
	UPROPERTY(BlueprintReadWrite)
	bool bIsDead;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Health Properties")
	float CurrentHealth;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Health Properties")
	float MaxHealth;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Health Properties")
	float CurrentArmor;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Health Properties")
	float MaxArmor;
};
