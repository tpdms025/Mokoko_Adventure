// Fill out your copyright notice in the Description page of Project Settings.


#include "MATitleWidget.h"
#include "Components/Button.h"
#include "MATitlePlayerController.h"

void UMATitleWidget::NativeConstruct()
{
	Super::NativeConstruct();

	GameStartButton = Cast<UButton>(GetWidgetFromName(TEXT("btnGameStart")));
	if (nullptr != GameStartButton)
	{
		GameStartButton->OnClicked.AddDynamic(this, &UMATitleWidget::OnGameStartClicked);
	}

	ExitButton = Cast<UButton>(GetWidgetFromName(TEXT("btnExit")));
	if (nullptr != ExitButton)
	{
		ExitButton->OnClicked.AddDynamic(this, &UMATitleWidget::OnExitClicked);
	}
}

void UMATitleWidget::OnGameStartClicked()
{
#pragma region Testing
	TitlePlayerController->OnChangeMode();
	MALOG(Warning, TEXT("curGameMode = %d"), TitlePlayerController->curGameMode);
#pragma endregion
}

void UMATitleWidget::OnExitClicked()
{
}

#pragma region Testing
void UMATitleWidget::SetPlayerController(AMATitlePlayerController* MAPC)
{
	TitlePlayerController = MAPC;
}
#pragma endregion