﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerControlEffectBase.h"
#include "StiffnessEffect.generated.h"

/**
 * 
 */
UCLASS()
class BATTLEFRAMEWORK_API UStiffnessEffect : public UPlayerControlEffectBase
{
	GENERATED_BODY()

public:
	UStiffnessEffect();
	
	virtual void Activate() override;
	virtual void Activate(float Duration) override;
	virtual void Deactivate() override;
	
	virtual void Move(const FInputActionValue& Value) override;
	virtual void Look(const FInputActionValue& Value) override;
	virtual void Dash() override;
	virtual void Sprint() override;
	virtual void Parry() override;
	virtual void BaseAttack() override;
	virtual void WeaponSkill() override;
	virtual void MagicSkill() override;
};
