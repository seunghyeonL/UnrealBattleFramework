// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Sound/SoundBase.h"
#include "CharacterSoundDataRow.generated.h"

USTRUCT(BlueprintType)
struct FCharacterSoundDataRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName SoundName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName SoundCategory;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<USoundBase> SoundAsset;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float BaseVolume = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float BasePitch = 1.0f;
};
