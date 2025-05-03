// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify_PlaySoundByName.h"
#include "DevFramework/GameInstance/SoundInstanceSubsystem.h"
#include "Data/CachedSoundData.h"
#include "Kismet/GameplayStatics.h"

#include "DebugHelper.h"

#if WITH_EDITOR
TArray<FName> UAnimNotify_PlaySoundByName::GetAvailableSoundNames()
{
	TArray<FName> Result;

	if (const UWorld* World = GEditor ? GEditor->GetEditorWorldContext().World() : nullptr)
	{
		checkf(World, TEXT("UAnimNotify_PlaySoundByName::GetAVailableSoundNames : World is nullptr"));
		if (const UGameInstance* GameInstance = World->GetGameInstance())
		{
			checkf(GameInstance, TEXT("UAnimNotify_PlaySoundByName::GetAVailableSoundNames : GameInstance is nullptr"));
			if (const USoundInstanceSubsystem* SoundSubsystem = GameInstance->GetSubsystem<USoundInstanceSubsystem>())
			{
				checkf(SoundSubsystem,
				       TEXT("UAnimNotify_PlaySoundByName::GetAVailableSoundNames : SoundInstanceSubsystem is nullptr"));
				SoundSubsystem->GetAllSoundNames(Result);
			}
		}
	}

	return Result;
}
#endif

void UAnimNotify_PlaySoundByName::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if (!IsValid(MeshComp) || !IsValid(MeshComp->GetWorld())) return;

	USoundInstanceSubsystem* Subsystem = MeshComp->GetWorld()->GetGameInstance()->GetSubsystem<USoundInstanceSubsystem>();
	if (!IsValid(Subsystem)) return;

	const FCachedSoundData* SoundData = Subsystem->GetSoundByName(SoundName);
	if (SoundData)
	{
		USoundBase* SoundBase = Cast<USoundBase>(SoundData->SoundAssetPath.TryLoad());
		checkf(Sound, TEXT("UAnimNotify_PlaySoundByName::Notify : Sound is Not Valid"));

		float FinalVolume = SoundData->BaseVolume * Subsystem->GetVolumeMultiplier();
		float FinalPitch = SoundData->BasePitch * Subsystem->GetPitchMultiplier();

		UGameplayStatics::SpawnSoundAttached(
		SoundBase,
		MeshComp,
		NAME_None,
		FVector::ZeroVector,
		EAttachLocation::KeepRelativeOffset,
		false,
		FinalVolume,
		FinalPitch);
	}
}
