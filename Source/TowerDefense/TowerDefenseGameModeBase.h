// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TowerDefenseGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API ATowerDefenseGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	// CONSTRUCTORS:
	ATowerDefenseGameModeBase();
	
	// FUNCTIONS:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	void SpawnEnemy(class ATD_Enemy* EnemyType, int32 AmountToSpawn, int SpawnPoint);
	void GiveFreeGold();
	UFUNCTION(BlueprintCallable)
	void GiveGold(int32 GoldToGive);
	void RoundOver(bool bResult);
	void StartPregame();
	void StartLevel();
	void PauseGame();
	UFUNCTION(BlueprintPure)
	float GetFreeGoldTimePercentage();
	UFUNCTION(BlueprintPure)
	FORCEINLINE float GetCurentGold() { return CurrentGold; }

	UPROPERTY(BlueprintReadOnly, Category = "Time Handles")
	FTimerHandle EnemySpawnTimerHandle;
	UPROPERTY(BlueprintReadOnly, Category = "Time Handles")
	FTimerHandle StopwatchTimerHandle;
	UPROPERTY(BlueprintReadOnly, Category = "Time Handles")
	FTimerHandle PregameTimerHandle;
	UPROPERTY(BlueprintReadOnly, Category = "Time Handles")
	FTimerHandle DelayForFreeGoldTimerHandle;

protected:
	// VARIABLES:
	int32 MaxNumberOfWaves;
	int32 CurrentWave;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Time Properties")
	float TimeForPregame;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Time Properties")
	float TimeForSetup;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Time Properties")
	float TimeForLevel;
	
	bool bWinner;

	UPROPERTY(EditDefaultsOnly, Category = "Base Properties")
	float MaxHealthOfBase;
	float CurrentHealthOfBase;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Gold Properties")
	bool bFreeGoldSystem;
	UPROPERTY(EditDefaultsOnly, Category = "Gold Properties")
	int32 FreeGoldToGive;
	UPROPERTY(EditDefaultsOnly, Category = "Gold Properties")
	float TimeDelayForFreeGold;
	
	int32 CurrentGold;
	

	// DeckToGiveForLevel

	// EnemiesToSpawn
	// SpawnPointsInWorld
	UPROPERTY(EditDefaultsOnly, Category = "Enemy Wave Properties")
	float SpawnTimerDelay;
	
};
