// Fill out your copyright notice in the Description page of Project Settings.


#include "MAGameModeBase.h"
#include "MACharacter.h"
#include "MAPlayerController.h"

AMAGameModeBase::AMAGameModeBase()
{
	DefaultPawnClass = AMACharacter::StaticClass();
	PlayerControllerClass = AMAPlayerController::StaticClass();
}
