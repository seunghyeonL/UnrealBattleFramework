﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"
#include "DevCheatManager.generated.h"

UCLASS()
class BATTLEFRAMEWORK_API UDevCheatManager : public UCheatManager
{
	GENERATED_BODY()

public:
	UFUNCTION(exec)
	virtual void God() override;
};
