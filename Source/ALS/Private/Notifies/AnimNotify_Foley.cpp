#include "Notifies/AlsAnimNotify_Foley.h"

#include "AlsCharacter.h"
#include "Components/AudioComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/World.h"
#include "Sound/SoundBase.h"
#include "Kismet/GameplayStatics.h"
#include "Utility/AlsConstants.h"
#include "Utility/AlsEnumUtility.h"
#include "Utility/AlsMacros.h"
#include "Utility/AlsMath.h"
#include "Utility/AlsUtility.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(AlsAnimNotify_Foley)

FString UAlsAnimNotify_Foley::GetNotifyName_Implementation() const
{
	TStringBuilder<64> NotifyNameBuilder;

	NotifyNameBuilder << TEXTVIEW("Foley: ") << AlsEnumUtility::GetNameStringByValue(SoundType);

	return FString{ NotifyNameBuilder };
}

void UAlsAnimNotify_Foley::Notify(USkeletalMeshComponent* Mesh, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(Mesh, Animation, EventReference);

	if (!IsValid(Mesh))
	{
		return;
	}
	auto* Character{ Cast<AAlsCharacter>(Mesh->GetOwner()) };
	if (!IsValid(Character))
	{
		auto MeshUserData{ Mesh->GetSkeletalMeshAsset()->GetAssetUserDataOfClass(UAlsEditorFoleySettings::StaticClass()) };
		if (!IsValid(MeshUserData))
		{
			UE_LOG(LogAls, Warning, TEXT("Foley settings not found in mesh %s."), *(Mesh->GetName()));
			return;
		}
		auto EditorFoleySettings{ Cast< UAlsEditorFoleySettings >(MeshUserData) };
		if (!IsValid(EditorFoleySettings->Sound.Get()))
		{
			if (!IsValid(EditorFoleySettings->Sound.LoadSynchronous()))
			{
				UE_LOG(LogAls, Warning, TEXT("Default foley sound is not configured."));
				return;
			}
		}
		auto* Audio = UGameplayStatics::SpawnSound2D(Mesh->GetWorld(), EditorFoleySettings->Sound.Get(), SoundVolumeMultiplier);
		if (IsValid(Audio))
		{
			Audio->SetIntParameter(FName{ TEXTVIEW("FoleyType") }, static_cast<int32>(SoundType));
		}
		else
		{
			UE_LOG(LogAls, Error, TEXT("Could not spawn foley sound in editor."));
		}
		return;
	}
	Character->Foley(SoundType, SoundVolumeMultiplier);
}

