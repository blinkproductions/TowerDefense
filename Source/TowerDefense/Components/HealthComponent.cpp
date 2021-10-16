// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	CurrentArmor = MaxArmor;
	CurrentHealth = MaxHealth;
	bIsDead = false;
}

void UHealthComponent::TakeDamage(float AmountOfDamage)
{
	if (CurrentArmor > 0)
	{
		CurrentArmor -= AmountOfDamage;
	} else if (CurrentHealth > 0)
	{
		CurrentHealth -= AmountOfDamage;	
	} 
}

void UHealthComponent::Heal(float HealAmount)
{
	CurrentHealth += HealAmount;
}

// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (CurrentHealth <= 0)
	{
		bIsDead = true;
	}
}

