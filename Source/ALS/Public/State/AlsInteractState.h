#pragma once

#include "Engine/DataAsset.h"
#include "Engine/EngineTypes.h"
#include "AlsInteractState.generated.h"

USTRUCT(BlueprintType)
struct ALS_API FAlsInteractState
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ALS")
	TObjectPtr<UAnimMontage> Montage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ALS")
	TObjectPtr<AActor> Actor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS")
	bool bMontageStarted{ false };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS")
	float PlayRate{ 1.0f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS", Meta = (ClampMin = -180, ClampMax = 180, ForceUnits = "deg"))
	float TargetYawAngle{ 0.0f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS")
	FVector PrepositionSpeed{ 0, 0, 0 };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS")
	float PrepositionTimeLeft{ 0 };
};
