// Fill out your copyright notice in the Description page of Project Settings.


#include "Mokoko_Adventure/Mokoko_Adventure.h"
#include "MAAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"
#include "MACharacter.h"

UMAAnimInstance::UMAAnimInstance()
{
	isInAir = false;
}


void UMAAnimInstance::NativeUpdateAnimation(float deltaSecond)
{
	Super::NativeUpdateAnimation(deltaSecond);
	auto pawn = TryGetPawnOwner();		//폰이 유효하는지 검사
	if (::IsValid(pawn))
	{
		//auto character = Cast<ACharacter>(pawn);
		AMACharacter* character = Cast<AMACharacter>(pawn);
		if (character)
		{
			isInAir = character->GetMovementComponent()->IsFalling();
			directionReady = character->directionReady;

			//angle = CalculateDirection(FVector::RightVector, directionReady.Rotation());
			angle = CalculateDirection(FRotationMatrix(character->GetControlRotation()).GetUnitAxis(EAxis::X), directionReady.Rotation());
			//CalculateDirection
		}
	}
}
