// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjetCPPinitGameMode.h"
#include "ProjetCPPinitCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProjetCPPinitGameMode::AProjetCPPinitGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
