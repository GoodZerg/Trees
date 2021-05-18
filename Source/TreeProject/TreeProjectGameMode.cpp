// Copyright Epic Games, Inc. All Rights Reserved.

#include "TreeProjectGameMode.h"
#include "TreeProjectCharacter.h"

ATreeProjectGameMode::ATreeProjectGameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = ATreeProjectCharacter::StaticClass();	
}
