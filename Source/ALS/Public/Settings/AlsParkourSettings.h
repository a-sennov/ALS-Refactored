#pragma once

#include "Engine/DataAsset.h"
#include "Engine/EngineTypes.h"
#include "Engine/NetSerialization.h"
#include "AlsParkourSettings.generated.h"


UCLASS(Blueprintable, BlueprintType)
class ALS_API UAlsParkourSettings : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	TObjectPtr<UAnimMontage> Montage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	FVector JumpOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	float IncomingAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	FVector VaultOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	FVector LandOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	float OutgoingAngle;
};

USTRUCT(BlueprintType)
struct ALS_API FAlsGeneralParkourSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS", Meta = (ClampMin = 0, ClampMax = 180, ForceUnits = "deg"))
	float TraceAngleThreshold{ 110.0f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS", Meta = (ClampMin = 0, ClampMax = 180, ForceUnits = "deg"))
	float MaxReachAngle{ 50.0f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS", Meta = (ForceUnits = "cm"))
	float SearchTraceLength{ 400.0f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS", Meta = (ForceUnits = "cm"))
	float SearchTraceInterval{ 10.0f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS", Meta = (ForceUnits = "cm"))
	float SearchTraceHeight{ 40.0f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS")
	int SearchTraceCount{ 25 };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS", Meta = (ForceUnits = "cm"))
	float DepthTraceLength{ 400.0f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS", Meta = (ForceUnits = "cm"))
	float VaultTraceInterval{ 10.0f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS", Meta = (ForceUnits = "cm"))
	float MinVaultBackHeight{ 75.0f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS")
	int VaultTraceCount{ 15 };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS", Meta = (ForceUnits = "cm"))
	float TicTakTraceLength{ 600.0f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS")
	int TicTacTraceCount{ 35 };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS", Meta = (ClampMin = 0, ClampMax = 90, ForceUnits = "deg"))
	float TicTakMaxApproachAngle{ 60.0f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS")
	TEnumAsByte<ECollisionChannel> TraceChannel{ ECC_Visibility };
};