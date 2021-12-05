// Fill out your copyright notice in the Description page of Project Settings.


#include "MATitlePlayerController.h"
#include "MATitleWidget.h"
#include "UObject/Object.h"
#include "LevelSequence.h"
#include "LevelSequencePlayer.h"
#include "LevelSequenceActor.h"

AMATitlePlayerController::AMATitlePlayerController()
{
	static ConstructorHelpers::FClassFinder<UMATitleWidget> UI_TITLE_C(TEXT("/Game/MokokoResource/Blueprints/UI_Title.UI_Title_C"));
	if (UI_TITLE_C.Succeeded())
	{
		TitleWidgetClass = UI_TITLE_C.Class;
	}

	static ConstructorHelpers::FObjectFinder<ULevelSequence> LS_GAMESTART(TEXT("/Game/MokokoResource/Arctic/Cinematics/TitleShort_1.TitleShort_1"));
	if (LS_GAMESTART.Succeeded())
	{
		SequenceAsset = LS_GAMESTART.Object;
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
	PlayLevelSequence();
	MALOG(Warning, TEXT("curGameMode = %d"), curGameMode);
}
#pragma endregion

#pragma region LevelSequence

void AMATitlePlayerController::PlayLevelSequence()
{
	FMovieSceneSequencePlaybackSettings PlaybackSettings;
	ULevelSequencePlayer * LevelSequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(
		GetWorld(),
		SequenceAsset,
		PlaybackSettings,
		SequenceActor
	);
	// 시네머신 시퀀스가 끝나면 실행해야할 함수를 이벤트 할당 하였다.
	//LevelSequencePlayer->OnFinished.AddDynamic(this, &AStartMapCameraPawn::CharacterSelectCamera);

	LevelSequencePlayer->Play();
}

#pragma endregion