#include "Notifies/AlsAnimNotifyState_Flying.h"
#include "AlsCharacter.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(AlsAnimNotifyState_Flying)

UAlsAnimNotifyState_Flying::UAlsAnimNotifyState_Flying()
{
#if WITH_EDITORONLY_DATA
	bShouldFireInEditor = false;
#endif
	bIsNativeBranchingPoint = true;
}

FString UAlsAnimNotifyState_Flying::GetNotifyName_Implementation() const
{
	return FString{ TEXTVIEW("Als Fly") };
}

void UAlsAnimNotifyState_Flying::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	auto* Character{ Cast<AAlsCharacter>(MeshComp->GetOwner()) };
	if (IsValid(Character))
	{
		Character->GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Flying);
	}
}

void UAlsAnimNotifyState_Flying::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	auto* Character{ Cast<AAlsCharacter>(MeshComp->GetOwner()) };
	if (IsValid(Character))
	{
		Character->GetCharacterMovement()->SetMovementMode(FinalMode);
	}
}
