// Fill out your copyright notice in the Description page of Project Settings.


#include "MATitlePawn.h"

// Sets default values
AMATitlePawn::AMATitlePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

}

// Called when the game starts or when spawned
void AMATitlePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMATitlePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMATitlePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

