#include "Engine/DataTable.h"
#include "ST_UnitProperties.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FUnitProperties : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Unit Property")
	FText Name;
	
	// Tower, Champion
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Icons")
	UTexture2D* UnitType;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Icons")
	UTexture2D* Thumbnail;
	
	// Single target, AOE, Straight line, AOE Cleave, Single Target Collateral
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Icons")
	UTexture2D* AttackType;
	
	//DPS, Utility
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Icons")
	UTexture2D* UnitClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Unit Property", meta = (Clampmin = 1.f))
	int32 Tier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Unit Property", meta = (Clampmin = 1.f))
	int32 Cost;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Unit Property", meta = (Clampmin = 1.f))
	float MaxHealth;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Unit Property", meta = (Clampmin = 0.f))
	float Damage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Unit Property", meta = (Clampmin = 0.f))
	float FireRate;

	// Air, Ground, Both
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Unit Property")
	FText TargetPreference;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Unit Property")
	FText UpgradeRequirements;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Unit Property")
	FText UnitDescription;
};

