// Fill out your copyright notice in the Description page of Project Settings.


#include "MATitlePawn.h"

// Sets default values
AMATitlePawn::AMATitlePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CAPSULE"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	RootComponent = Capsule;
	SpringArm->SetupAttachment(Capsule);
	Camera->SetupAttachment(SpringArm);

	Capsule->SetCapsuleRadius(30.0f);
	Capsule->SetRelativeLocationAndRotation(FVector(7000.0f, -1500.0f, 2500.0f), FRotator(0.0f, 180.0f, 0.0f));
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->SetRelativeRotation(FRotator(10.0f, 0.0f, 0.0f));
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

