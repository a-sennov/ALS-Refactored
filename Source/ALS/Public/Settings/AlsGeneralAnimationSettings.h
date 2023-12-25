#pragma once

#include "AlsGeneralAnimationSettings.generated.h"

USTRUCT(BlueprintType)
struct ALS_API FAlsGeneralAnimationSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS")
	uint8 bUseHandIkBones : 1 {true};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS")
	uint8 bUseFootIkBones : 1 {true};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS", Meta = (ClampMin = 0, ForceUnits = "cm/s"))
	float MovingSmoothSpeedThreshold{150.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS", Meta = (ClampMin = 0))
	float LeanInterpolationSpeed{4.0f};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ALS|Bones")
	FName PelvisBone{ TEXT("pelvis") };

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ALS|Bones")
	FName HeadBone{ TEXT("head") };

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ALS|Bones")
	FName Spine03Bone{ TEXT("spine_03") };

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ALS|Bones")
	FName FootLeftBone{ TEXT("foot_l") };

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ALS|Bones")
	FName FootRightBone{ TEXT("foot_r") };
};
