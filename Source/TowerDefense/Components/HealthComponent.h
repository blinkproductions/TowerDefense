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
	void SetHealth(float NewHealthAmount) { CurrentHealth = NewHealthAmount; }

	UFUNCTION(BlueprintCallable)
	void SetArmor(float NewArmorAmount) { CurrentArmor = NewArmorAmount; }

	UFUNCTION(BlueprintPure)
	float GetCurrentHealthPercentage() const { return CurrentHealth / 100.f; }

	UFUNCTION(BlueprintPure)
	float GetCurrentArmorPercentage() const { return CurrentArmor / 100.f; }
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadWrite)
	bool bIsDead;
	
private:
	// VARIABLES:
	float CurrentHealth;
	float CurrentArmor;

	UPROPERTY(EditDefaultsOnly, Category = "Health Properties")
	float MaxHealth = 100.f;

	UPROPERTY(EditDefaultsOnly, Category = "Health Properties")
	float MaxArmor = 50.f;
};
