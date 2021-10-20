// Fill out your copyright notice in the Description page of Project Settings.


#include "MATitlePlayerController.h"
#include "MATitleWidget.h"

AMATitlePlayerController::AMATitlePlayerController()
{
	static ConstructorHelpers::FClassFinder<UMATitleWidget> UI_TITLE_C(TEXT("/Game/MokokoResource/Blueprints/UI_Title.UI_Title_C"));
	if (UI_TITLE_C.Succeeded())
	{
		TitleWidgetClass = UI_TITLE_C.Class;
	}

}

void AMATitlePlayerController::ChangeInputMode(bool bGameMode)
{
#pragma region Testing
	curGameMode = bGameMode;
#pragma endregion

	if (bGameMode)
	{
		SetInputMode(GameInputMode);
		bShowMouseCursor = false;
	}
	else
	{
		SetInputMode(UIInputMode);
		bShowMouseCursor = true;
	}
}

void AMATitlePlayerController::BeginPlay()
{
	Super::BeginPlay();

	ChangeInputMode(false);

	TitleWidget = CreateWidget<UMATitleWidget>(this, TitleWidgetClass);
	TitleWidget->AddToViewport();
	TitleWidget->SetPlayerController(this);


}

#pragma region Testing
void AMATitlePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction(TEXT("TEST_ChangeMode"), EInputEvent::IE_Pressed, this, &AMATitlePlayerController::OnChangeMode);

}

void AMATitlePlayerController::OnChangeMode()
{
	ChangeInputMode(!curGameMode);
	MALOG(Warning, TEXT("curGameMode = %d"), curGameMode);
}
#pragma endregion