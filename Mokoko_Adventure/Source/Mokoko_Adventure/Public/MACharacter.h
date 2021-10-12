// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MACharacter.generated.h"

UCLASS()
class MOKOKO_ADVENTURE_API AMACharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMACharacter();

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class USpringArmComponent* springArm;

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class UCameraComponent* camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float moveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float rotationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
	FVector directionToRotate = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
	FVector directionReady = FVector::ZeroVector;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Landed(const FHitResult& hit) override;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/*UFUNCTION()
	void Jump();*/

private:
	void UpDown(float newAxisValue);
	void LeftRight(float newAxisValue);
	void LookUp(float newAxisValue);
	void Turn(float newAxisValue);

};
