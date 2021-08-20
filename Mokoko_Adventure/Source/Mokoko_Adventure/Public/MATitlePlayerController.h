// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Mokoko_Adventure/Mokoko_Adventure.h"
#include "GameFramework/PlayerController.h"
#include "MATitlePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MOKOKO_ADVENTURE_API AMATitlePlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AMATitlePlayerController();

	void ChangeInputMode(bool bGameMode = true);


protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
	TSubclassOf<class UMATitleWidget> TitleWidgetClass;

private:
	UPROPERTY()
	class UMATitleWidget* TitleWidget;

	FInputModeGameOnly GameInputMode;
	FInputModeUIOnly UIInputMode;

#pragma region Testing

protected:
	virtual void SetupInputComponent() override;
private:
public:
	bool curGameMode;
	void OnChangeMode();

#pragma endregion
};
