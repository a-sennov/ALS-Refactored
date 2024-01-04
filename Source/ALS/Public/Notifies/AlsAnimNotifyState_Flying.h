#pragma once

#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "AlsCharacterMovementComponent.h"
#include "AlsAnimNotifyState_Flying.generated.h"

UCLASS(DisplayName = "Als Flying Animation Notify State")
class ALS_API UAlsAnimNotifyState_Flying : public UAnimNotifyState
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings", Meta = (ForceUnits = "s"))
	TEnumAsByte<EMovementMode> FinalMode{ EMovementMode::MOVE_Walking };
public:
	UAlsAnimNotifyState_Flying();

	virtual FString GetNotifyName_Implementation() const override;

	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference) override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
};

