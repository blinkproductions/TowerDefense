// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EnemyUnitProperties.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API UEnemyUnitProperties : public UObject
{
	GENERATED_BODY()

public:
	FText EnemyDisplayName;
	FText EnemyDescription;
	//ESpeedModifier SpeedModifier;
	float BaseSpeed;
	bool bCanMove;
	FVector TargetLocation;
};