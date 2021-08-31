// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MAPlayerController.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnSpaceBarPressedEventDelegate);

#pragma region test
DECLARE_MULTICAST_DELEGATE(FOnTestEventDelegate);
#pragma endregion
/**
 * 
 */
UCLASS()
class MOKOKO_ADVENTURE_API AMAPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMAPlayerController();

protected:
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
	TSubclassOf<class UMAIntroWidget> IntroWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
	TSubclassOf<class UMAPlayTipWidget> PlayTipWidgetClass;


private:
	UPROPERTY()
	class UMAIntroWidget* IntroWidget;

	UPROPERTY()
	class UMAPlayTipWidget* PlayTipWidget;
	
	void OnSpaceEvent();
public:
	FOnSpaceBarPressedEventDelegate OnSpaceBarPressedEvent;

#pragma region test
private:
	void OnTestEvent();
public:
	FOnTestEventDelegate OnTestPressedEvent;
#pragma endregion
};
