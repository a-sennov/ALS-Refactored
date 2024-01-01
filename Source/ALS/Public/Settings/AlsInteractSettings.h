#pragma once

#include "Engine/DataAsset.h"
#include "Engine/EngineTypes.h"
#include "AlsInteractSettings.generated.h"

UENUM(BlueprintType)
enum class EAlsPrepositionType : uint8
{
	Exact,
	Facing,
};

UCLASS(Blueprintable, BlueprintType)
class ALS_API UAlsInteractSettings : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	TObjectPtr<UAnimMontage> Montage;

	// If checked, mantling will automatically calculate the start time based on how much vertical
	// distance the character needs to move to reach the object they are about to mantle.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	EAlsPrepositionType Type;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	float Distance{ 0 };

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	float Shift{ 0 };
};


