// Fill out your copyright notice in the Description page of Project Settings.


#include "MATitleGameModeBase.h"
#include "MATitlePlayerController.h"
#include "MATitlePawn.h"

AMATitleGameModeBase::AMATitleGameModeBase()
{
	DefaultPawnClass = AMATitlePawn::StaticClass();
	PlayerControllerClass = AMATitlePlayerController::StaticClass();
}