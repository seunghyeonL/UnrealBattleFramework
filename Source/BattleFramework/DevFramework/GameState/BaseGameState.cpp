// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGameState.h"
#include "DevFramework/GameInstance/SoundInstanceSubsystem.h"

ABaseGameState::ABaseGameState()
{
}

void ABaseGameState::BeginPlay()
{
	Super::BeginPlay();

	SoundSubsystem = GetGameInstance()->GetSubsystem<USoundInstanceSubsystem>();
	SoundSubsystem->LoadAllSoundTables();
}
