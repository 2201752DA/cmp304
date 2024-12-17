// Copyright Epic Games, Inc. All Rights Reserved.

#include "cmp302_realprojectGameMode.h"
#include "cmp302_realprojectCharacter.h"
#include "UObject/ConstructorHelpers.h"

Acmp302_realprojectGameMode::Acmp302_realprojectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
