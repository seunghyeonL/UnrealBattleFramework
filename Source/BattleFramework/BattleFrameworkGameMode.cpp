// Copyright Epic Games, Inc. All Rights Reserved.

#include "BattleFrameworkGameMode.h"
#include "BattleFrameworkCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABattleFrameworkGameMode::ABattleFrameworkGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
