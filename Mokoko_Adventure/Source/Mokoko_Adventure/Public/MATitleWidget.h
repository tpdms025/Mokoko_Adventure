// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Mokoko_Adventure/Mokoko_Adventure.h"
#include "Blueprint/UserWidget.h"
#include "MATitleWidget.generated.h"

/**
 * 
 */
UCLASS()
class MOKOKO_ADVENTURE_API UMATitleWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void OnGameStartClicked();

	UFUNCTION()
	void OnExitClicked();

protected:
	UPROPERTY()
	class UButton* GameStartButton;

	UPROPERTY()
	class UButton* ExitButton;

#pragma region Testing
public:
	void SetPlayerController(class AMATitlePlayerController* MAPC);
private:
	UPROPERTY()
	class AMATitlePlayerController* TitlePlayerController;
#pragma endregion

};
