// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify_PlaySound.h"
#include "AnimNotify_PlaySoundByName.generated.h"

UCLASS()
class BATTLEFRAMEWORK_API UAnimNotify_PlaySoundByName : public UAnimNotify_PlaySound
{
	GENERATED_BODY()

//Functions
public:
#if WITH_EDITOR
	UFUNCTION()
	static TArray<FName> GetAvailableSoundNames();
#endif

protected:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

	
//Variables
public:
	UPROPERTY(EditAnywhere, meta = (GetOptions = "GetAvailableSoundNames"))
	FName SoundName;

	UPROPERTY(EditAnywhere)
	float Volume = 1.f;

	UPROPERTY(EditAnywhere)
	float Pitch = 1.f;
};
