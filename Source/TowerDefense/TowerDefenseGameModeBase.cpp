// Copyright Epic Games, Inc. All Rights Reserved.


#include "TowerDefenseGameModeBase.h"
#include "Kismet/GameplayStatics.h"

ATowerDefenseGameModeBase::ATowerDefenseGameModeBase()
{
	TimeForPregame = 2.f;
	bFreeGoldSystem = false;
	CurrentGold = 0;
	FreeGoldToGive = 1;
	TimeDelayForFreeGold = 1.f;
	
	DealingRange = Tier1DealingRange;

	TiersUnlocked = {true, false, false};
}

void ATowerDefenseGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	//GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Yellow, FString::Printf(TEXT("(ATowerDefenseGameModeBase)Current Gold: %d"), CurrentGold ));
}

void ATowerDefenseGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
	StartPregame();
	
}

void ATowerDefenseGameModeBase::SpawnEnemy(ATD_Enemy* EnemyType, int32 AmountToSpawn, int SpawnPoint)
{
}

void ATowerDefenseGameModeBase::GiveFreeGold()
{
	GiveGold(FreeGoldToGive);
}

void ATowerDefenseGameModeBase::GiveGold(int32 GoldToGive)
{
	CurrentGold += GoldToGive;
}

void ATowerDefenseGameModeBase::GameOver(bool bResult)
{
}

void ATowerDefenseGameModeBase::DetermineTiersUnlocked()
{
	if (CurrentWave > 5 && CurrentWave <= 10)
	{
		TiersUnlocked[1] = true;
		DealingRange = 16.f;
	} else if (CurrentWave > 10)
	{
		for (auto i : TiersUnlocked)
		{
			i = true;
		}
		DealingRange = 25.f;
	}
}

void ATowerDefenseGameModeBase::GiveStartingGold(int32 StartingGold)
{
	GiveGold(StartingGold);
}

void ATowerDefenseGameModeBase::WaveEnded()
{
	// If CurrentWave is not equal the last wave then increment CurrentWave
}

void ATowerDefenseGameModeBase::StartPregame()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Pregame started...");
	
	GetWorld()->GetTimerManager().SetTimer(PregameTimerHandle, this, &ATowerDefenseGameModeBase::StartLevel, TimeForPregame, false);
}

void ATowerDefenseGameModeBase::StartLevel()
{
	// Free gold system:
	if (bFreeGoldSystem)
	{
		GetWorld()->GetTimerManager().SetTimer(DelayForFreeGoldTimerHandle, this, &ATowerDefenseGameModeBase::GiveFreeGold, TimeDelayForFreeGold, true);	
	}
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "LEVEL START!!");
}

void ATowerDefenseGameModeBase::PauseGame()
{
}

float ATowerDefenseGameModeBase::GetFreeGoldTimePercentage()
{
	return GetWorldTimerManager().GetTimerElapsed(DelayForFreeGoldTimerHandle) / TimeDelayForFreeGold;
}
