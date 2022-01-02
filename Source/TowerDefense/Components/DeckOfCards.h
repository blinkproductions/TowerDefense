// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../Structures/ST_UnitProperties.h"
#include "DeckOfCards.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOWERDEFENSE_API UDeckOfCards : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDeckOfCards();

	// FUNCTIONS:
	void PopulateDefaultDeck();
	void DebugCardDeck();
	void BurnACard();
	void DealACard();

	// VARIABLES:
	class ATowerDefenseGameModeBase* GM;
	TArray<FUnitProperties> DeckOfCards;
	TArray<FName> OutRowNames;

	// This is the amount of cards a deck can hold
	int32 MaxAmountOfCardsHeld;
	
	FUnitProperties CardToBeBurned;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
