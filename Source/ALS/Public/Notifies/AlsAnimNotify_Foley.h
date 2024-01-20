#pragma once

#include "Animation/AnimNotifies/AnimNotify.h"
#include "Engine/DataAsset.h"
#include "Engine/AssetUserData.h"
#include "Engine/EngineTypes.h"
#include "AlsAnimNotify_Foley.generated.h"

UENUM(BlueprintType)
enum class EAlsFoleyTypes : uint8
{
	Short,
	Long,
	Run,
	StrikeBare,
	StrikeClothed,
};

UCLASS(Blueprintable, BlueprintType)
class ALS_API UAlsEditorFoleySettings : public UAssetUserData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS")
	TSoftObjectPtr<USoundBase> Sound;
};

UCLASS(DisplayName = "Als Foley Effects Animation Notify", AutoExpandCategories = ("Settings|Sound"))
class ALS_API UAlsAnimNotify_Foley : public UAnimNotify
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings|Sound")
	EAlsFoleyTypes SoundType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings|Sound", Meta = (ClampMin = 0, ForceUnits = "x"))
	float SoundVolumeMultiplier{ 1.0f };

public:
	virtual FString GetNotifyName_Implementation() const override;

	virtual void Notify(USkeletalMeshComponent* Mesh, UAnimSequenceBase* Animation,	const FAnimNotifyEventReference& EventReference) override;
};
