// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MAPlayerController.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnSpaceBarPressedEventDelegate);
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

private:
	UPROPERTY()
	class UMAIntroWidget* IntroWidget;
	
	void OnSpaceEvent();

public:
	FOnSpaceBarPressedEventDelegate OnSpaceBarPressedEvent;
};
