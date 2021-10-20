// Fill out your copyright notice in the Description page of Project Settings.


#include "MATitleGameModeBase.h"
#include "MATitlePlayerController.h"
#include "MATitlePawn.h"

AMATitleGameModeBase::AMATitleGameModeBase()
{
	PlayerControllerClass = AMATitlePlayerController::StaticClass();
	DefaultPawnClass = AMATitlePawn::StaticClass();
}