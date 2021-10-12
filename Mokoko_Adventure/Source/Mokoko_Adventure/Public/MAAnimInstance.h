// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Mokoko_Adventure/Mokoko_Adventure.h"
#include "Animation/AnimInstance.h"
#include "MAAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class MOKOKO_ADVENTURE_API UMAAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UMAAnimInstance();
	virtual void NativeUpdateAnimation(float deltaSecond) override;
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pawn", meta = (AllowPrivateAccess = "true"))
	bool isInAir; 

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pawn", meta = (AllowPrivateAccess = "true"))
	FVector directionReady = FVector::ZeroVector;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pawn", meta = (AllowPrivateAccess = "true"))
	float angle;
};
