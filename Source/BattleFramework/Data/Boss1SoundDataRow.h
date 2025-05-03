// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Sound/SoundBase.h"
#include "Boss1SoundDataRow.generated.h"

USTRUCT(BlueprintType)
struct FBoss1SoundDataRow : public FTableRowBase
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
