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
}

void ATowerDefenseGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Yellow, FString::Printf(TEXT("(ATowerDefenseGameModeBase)Current Gold: %d"), CurrentGold ));
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

void ATowerDefenseGameModeBase::RoundOver(bool bResult)
{
}

void ATowerDefenseGameModeBase::StartPregame()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Pregame started...");
	
	GetWorld()->GetTimerManager().SetTimer(PregameTimerHandle, this, &ATowerDefenseGameModeBase::StartLevel, TimeForPregame, false);
}

void ATowerDefenseGameModeBase::StartLevel()
{
	// Free gold system:
	if (bFreeGoldSystem)
	{
		GetWorld()->GetTimerManager().SetTimer(DelayForFreeGoldTimerHandle, this, &ATowerDefenseGameModeBase::GiveFreeGold, TimeDelayForFreeGold, true);	
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "LEVEL START!!");
}

void ATowerDefenseGameModeBase::PauseGame()
{
}

float ATowerDefenseGameModeBase::GetFreeGoldTimePercentage()
{
	return GetWorldTimerManager().GetTimerElapsed(DelayForFreeGoldTimerHandle) / TimeDelayForFreeGold;
}
