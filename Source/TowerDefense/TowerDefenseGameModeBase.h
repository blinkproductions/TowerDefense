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
	void GameOver(bool bResult);
	void DetermineTiersUnlocked();

	// Called each time a wave ends. 
	void WaveEnded();
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
	UPROPERTY(BlueprintReadOnly, Category = "Time Handles")
	FTimerHandle DelayForBurningCardTimerHandle;

protected:
	// VARIABLES:
	// WAVE PROPERTIES:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Wave Properties")
	int32 MaxNumberOfWaves;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Wave Properties") // change to BlueprintReadOnly on shipped code
	int32 CurrentWave;

	//NOTE:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Wave Properties")
	TArray<bool>TiersUnlocked;

	// Dealing ranges depends on the CSV file. Modify these values when necessary.
	const float Tier1DealingRange = 7.f;
	const float Tier2DealingRange = 16.f;
	const float Tier3DealingRange = 25.f;
	
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
	UPROPERTY(EditDefaultsOnly, Category = "Gold Properties", meta = (EditCondition = bFreeGoldSystem))
	int32 FreeGoldToGive;
	UPROPERTY(EditDefaultsOnly, Category = "Gold Properties", meta = (EditCondition = bFreeGoldSystem))
	float TimeDelayForFreeGold;
	
	int32 CurrentGold;

	// Default value is 7 where 7 is the last  Tier 1 unit in the CSV file
	float DealingRange;
	
	// DeckToGiveForLevel

	// EnemiesToSpawn
	// SpawnPointsInWorld
	UPROPERTY(EditDefaultsOnly, Category = "Enemy Wave Properties")
	float SpawnTimerDelay;
	
};
