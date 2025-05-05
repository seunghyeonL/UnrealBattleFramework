// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Data/CachedSoundData.h"

#include "Util/DebugHelper.h"

#include "SoundInstanceSubsystem.generated.h"

UCLASS()
class BATTLEFRAMEWORK_API USoundInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

#pragma region Functions
	
public:
	void LoadAllSoundTables();
	void GetAllSoundNames(TArray<FName>& OutNames) const;

	FORCEINLINE const FCachedSoundData* GetSoundByName(FName SoundAssetName) const
	{
		const FCachedSoundData* FoundPtr = CachedSounds.Find(SoundAssetName);
		check(FoundPtr);
		return FoundPtr;
	}
	FORCEINLINE float GetVolumeMultiplier() const { return VolumeMultiplier; }
	FORCEINLINE float GetPitchMultiplier() const { return PitchMultiplier; }
	
protected:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

private:
	template<typename T>
	void ProcessSoundTable(UDataTable* SoundTable)
	{
		if (!SoundTable) return;

		for (auto& Row : SoundTable->GetRowMap())
		{
			T* SoundData = reinterpret_cast<T*>(Row.Value);
			if (SoundData != nullptr)
			{
				FCachedSoundData CachedData;
				CachedData.SoundName = SoundData->SoundName;
				CachedData.SoundCategory = SoundData->SoundCategory;
				CachedData.SoundAssetPath = SoundData->SoundAsset.ToSoftObjectPath();
				CachedData.BaseVolume = SoundData->BaseVolume;
				CachedData.BasePitch = SoundData->BasePitch;

				if (!CachedSounds.Contains(SoundData->SoundName))
				{
					CachedSounds.Add(SoundData->SoundName, CachedData);
				}
				else
				{
					Debug::Print(TEXT("USoundInstanceSubsystem::ProcessSoundTable : Same DataTable Name"));
				}
			}
		}
	}
	
#pragma endregion


	
#pragma region Variables
	
public:
	TMap<FName, float> CategoryVolumes;
	
private:
	UPROPERTY()
	TMap<FName, FCachedSoundData> CachedSounds;

	float VolumeMultiplier = 1.f;
	float PitchMultiplier = 1.f;

#pragma endregion
};
