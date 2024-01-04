#pragma once

#include "AlsParkourState.generated.h"

USTRUCT(BlueprintType)
struct ALS_API FAlsParkourState
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS", Meta = (ClampMin = 0, ClampMax = 1))
	float GroundedAmount{ 1.0f };
};
