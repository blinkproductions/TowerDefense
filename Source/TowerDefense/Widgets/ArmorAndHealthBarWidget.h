// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ArmorAndHealthBarWidget.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API UArmorAndHealthBarWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	// VARIABLES:
	UPROPERTY(BlueprintReadWrite, Category = "Properties")
	float ArmorAmount;
	
	UPROPERTY(BlueprintReadWrite, Category = "Properties")
	float HealthAmount;
};
