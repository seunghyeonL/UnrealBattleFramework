// Fill out your copyright notice in the Description page of Project Settings.


#include "SoundInstanceSubsystem.h"

#include "Engine/DataTable.h"
#include "Data/CharacterSoundDataRow.h"
#include "Data/Boss1SoundDataRow.h"
#include "Sound/SoundBase.h"

void USoundInstanceSubsystem::LoadAllSoundTables()
{
	UDataTable* CharacterSoundDataTable = LoadObject<UDataTable>(nullptr, TEXT("/Game/DataTable/DT_CharacterSound"));
	check(CharacterSoundDataTable);
	UDataTable* Boss1SoundDataTable = LoadObject<UDataTable>(nullptr, TEXT("/Game/DataTable/DT_Boss1Sound"));
	check(Boss1SoundDataTable);

	ProcessSoundTable<FCharacterSoundDataRow>(CharacterSoundDataTable);
	ProcessSoundTable<FBoss1SoundDataRow>(Boss1SoundDataTable);
}

void USoundInstanceSubsystem::GetAllSoundNames(TArray<FName>& OutNames) const
{
	CachedSounds.GetKeys(OutNames);
}

void USoundInstanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	
	CategoryVolumes.Add("Master", 1.f);
	CategoryVolumes.Add("SFX", 1.f);
	CategoryVolumes.Add("BGM", 1.f);
	CategoryVolumes.Add("UI", 1.f);
}
