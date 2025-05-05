// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CachedSoundData.generated.h"

USTRUCT(BlueprintType)
struct BATTLEFRAMEWORK_API FCachedSoundData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	FName SoundName;
	UPROPERTY(BlueprintReadOnly)
	FName SoundCategory;
	UPROPERTY(BlueprintReadOnly)
	FSoftObjectPath SoundAssetPath;
	UPROPERTY(BlueprintReadOnly)
	float BaseVolume = 1.f;
	UPROPERTY(BlueprintReadOnly)
	float BasePitch = 1.f;
};