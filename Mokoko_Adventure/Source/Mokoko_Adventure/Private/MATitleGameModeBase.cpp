// Fill out your copyright notice in the Description page of Project Settings.


#include "MATitleGameModeBase.h"
#include "MATitlePlayerController.h"

AMATitleGameModeBase::AMATitleGameModeBase()
{
	PlayerControllerClass = AMATitlePlayerController::StaticClass();
}