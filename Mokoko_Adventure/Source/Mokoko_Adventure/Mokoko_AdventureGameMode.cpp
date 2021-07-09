// Copyright Epic Games, Inc. All Rights Reserved.

#include "Mokoko_AdventureGameMode.h"
#include "Mokoko_AdventureCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMokoko_AdventureGameMode::AMokoko_AdventureGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
