// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "BaseGameState.generated.h"

class USoundInstanceSubsystem;

UCLASS()
class BATTLEFRAMEWORK_API ABaseGameState : public AGameState
{
	GENERATED_BODY()
	
//Functions
protected:
	ABaseGameState();
	virtual void BeginPlay() override;

//Variables
private:
	UPROPERTY()
	USoundInstanceSubsystem* SoundSubsystem;
};
