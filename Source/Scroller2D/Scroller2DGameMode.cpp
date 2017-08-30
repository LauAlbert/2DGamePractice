// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Scroller2DGameMode.h"
#include "Scroller2DCharacter.h"

AScroller2DGameMode::AScroller2DGameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = AScroller2DCharacter::StaticClass();	
}
