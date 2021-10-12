// Fill out your copyright notice in the Description page of Project Settings.

#include "Mokoko_Adventure/Mokoko_Adventure.h"
#include "MACharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AMACharacter::AMACharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//variable Initialize
	moveSpeed = 600.0f;
	rotationSpeed = 10.0f;
	
	//set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(30.0f, 60.0f);
	GetCapsuleComponent()->SetRelativeRotation(FRotator::ZeroRotator);


	// Configure character movement
	GetCharacterMovement()->JumpZVelocity = 800.f;
	//GetCharacterMovement()->bOrientRotationToMovement = true;
	//GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);
	GetCharacterMovement()->MaxWalkSpeed = moveSpeed;
	GetCharacterMovement()->AirControl = 1.0f;


	//Create a springArm 
	springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	springArm->SetupAttachment(GetCapsuleComponent());
	springArm->TargetArmLength = 600.0f;
	springArm->SetRelativeRotation(FRotator(-30.0f, 0.0f, 0.0f));
	springArm->bDoCollisionTest = true;
	springArm->bInheritPitch = true;
	springArm->bInheritRoll = true;
	springArm->bInheritYaw = true;
	springArm->bUsePawnControlRotation = true;
	bUseControllerRotationYaw = false;

	//Create a follow camera
	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	camera->SetupAttachment(springArm);


	//Load skeletal mesh
	GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f));
	GetMesh()->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_MOKOKO(TEXT("SkeletalMesh'/Game/MokokoResource/Mokoko/Meshes/mokoko.mokoko'"));
	if (SK_MOKOKO.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SK_MOKOKO.Object);
	}

	//Load animation instance.
	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	static ConstructorHelpers::FClassFinder<UAnimInstance> MOKOKO_ANIM(TEXT("AnimBlueprint'/Game/MokokoResource/Mokoko/Animation/MokokoAnimBP.MokokoAnimBP_C'"));
	if (MOKOKO_ANIM.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(MOKOKO_ANIM.Class);
	}
	
}

// Called when the game starts or when spawned
void AMACharacter::BeginPlay()
{
	Super::BeginPlay();

}

void AMACharacter::Landed(const FHitResult& hit)
{
}

// Called every frame
void AMACharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (directionToRotate.SizeSquared() > 0.0f)
	{
		FRotator initialRotation = GetActorRotation();
		if (initialRotation != directionToRotate.Rotation())
		{
			FRotator controlRot = FRotator(0.0f,GetControlRotation().Yaw,0.0f);
			FRotator newRotation = FMath::RInterpTo(initialRotation, controlRot-directionToRotate.Rotation(), DeltaTime, rotationSpeed);
			SetActorRotation(newRotation);
		}
	}
}

// Called to bind functionality to input
void AMACharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AMACharacter::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AMACharacter::LeftRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AMACharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AMACharacter::Turn);
	
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed,this, &AMACharacter::Jump);
}

void AMACharacter::UpDown(float newAxisValue)
{
	if (GetMovementComponent()->IsFalling())
	{
		AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::X), newAxisValue);
		directionToRotate.Y = newAxisValue;
	}
	else
	{
		directionReady.Y = newAxisValue;
	}
}

void AMACharacter::LeftRight(float newAxisValue)
{
	if (GetMovementComponent()->IsFalling())
	{
		//AddMovementInput(GetActorRightVector(), newAxisValue);
		AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::Y), newAxisValue);
		directionToRotate.X = newAxisValue;
	}
	else
	{
		directionReady.X = newAxisValue;
		//directionToRotate = FRotationMatrix(GetControlRotation() + FRotator(0.0f, 180.0f*newAxisValue, 0.0f)).GetUnitAxis(EAxis::Y);
	}
} 

void AMACharacter::LookUp(float newAxisValue)
{
	AddControllerPitchInput(newAxisValue);
}

void AMACharacter::Turn(float newAxisValue)
{
	AddControllerYawInput(newAxisValue);
}

//void AMACharacter::Jump()
//{
//
//}

