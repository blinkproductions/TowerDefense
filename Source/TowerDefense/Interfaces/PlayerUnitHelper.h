// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PlayerUnitHelper.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UPlayerUnitHelper : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TOWERDEFENSE_API IPlayerUnitHelper
{
	GENERATED_BODY()

public:
	// Overrides should handle the primary attacks of the unit
	//virtual void FirePrimaryAttack();
};
