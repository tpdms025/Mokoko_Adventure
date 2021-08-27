// Fill out your copyright notice in the Description page of Project Settings.


#include "MAPlayerController.h"
#include "MAIntroWidget.h"

AMAPlayerController::AMAPlayerController()
{
	static ConstructorHelpers::FClassFinder<UMAIntroWidget> UI_INTRO_C(TEXT("/Game/MokokoResource/Blueprints/UI_Intro.UI_Intro_C"));
	if (UI_INTRO_C.Succeeded())
	{
		IntroWidgetClass = UI_INTRO_C.Class;
	}
}

void AMAPlayerController::BeginPlay()
{
	Super::BeginPlay();

	IntroWidget = CreateWidget<UMAIntroWidget>(this, IntroWidgetClass);
	IntroWidget->AddToViewport();
	IntroWidget->BindPlayerController(this);
}

void AMAPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction(TEXT("SpaceBar"), EInputEvent::IE_Pressed, this, &AMAPlayerController::OnSpaceEvent);
}

void AMAPlayerController::OnSpaceEvent()
{
	OnSpaceBarPressedEvent.Broadcast();
}