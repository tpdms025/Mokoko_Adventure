// Fill out your copyright notice in the Description page of Project Settings.


#include "MAPlayerController.h"
#include "MAIntroWidget.h"
#include "MAPlayTipWidget.h"

AMAPlayerController::AMAPlayerController()
{
	static ConstructorHelpers::FClassFinder<UMAIntroWidget> UI_INTRO_C(TEXT("/Game/MokokoResource/Blueprints/UI_Intro.UI_Intro_C"));
	if (UI_INTRO_C.Succeeded())
	{
		IntroWidgetClass = UI_INTRO_C.Class;
	}	
	
	static ConstructorHelpers::FClassFinder<UMAPlayTipWidget> UI_PLAYTIP_C(TEXT("/Game/MokokoResource/Blueprints/UI_PlayTip.UI_PlayTip_C"));
	if (UI_PLAYTIP_C.Succeeded())
	{
		PlayTipWidgetClass = UI_PLAYTIP_C.Class;
	}
}

void AMAPlayerController::BeginPlay()
{
	Super::BeginPlay();

	IntroWidget = CreateWidget<UMAIntroWidget>(this, IntroWidgetClass);
	IntroWidget->AddToViewport();
	IntroWidget->BindPlayerController(this);

	PlayTipWidget = CreateWidget<UMAPlayTipWidget>(this, PlayTipWidgetClass);
	PlayTipWidget->AddToViewport();
}

void AMAPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction(TEXT("SpaceBar"), EInputEvent::IE_Pressed, this, &AMAPlayerController::OnSpaceEvent);

#pragma region test
	InputComponent->BindAction(TEXT("Test_ChangeMode"), EInputEvent::IE_Pressed, this, &AMAPlayerController::OnTestEvent);
#pragma endregion

}

void AMAPlayerController::OnSpaceEvent()
{
	OnSpaceBarPressedEvent.Broadcast();
}

void AMAPlayerController::OnTestEvent()
{
	OnTestPressedEvent.Broadcast();
}
