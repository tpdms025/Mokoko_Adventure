// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Mokoko_Adventure/Mokoko_Adventure.h"
#include "Blueprint/UserWidget.h"
#include "MAIntroWidget.generated.h"

/**
 * 
 */
UCLASS()
class MOKOKO_ADVENTURE_API UMAIntroWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

protected:
	UPROPERTY()
	class UProgressBar* ProgressBar;

	UPROPERTY()
	class UTextBlock* TimeCount;

public:
	void BindPlayerController(class AMAPlayerController* PC);

protected:
	void OnSpaceBarEvent();

	void OnStartIntro();

private:
	TWeakObjectPtr<class AMAPlayerController> playerController;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = "true"), Category = UI)
	float time;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = "true"), Category = UI)
	float spacePower;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = "true"), Category = UI)
	int spaceTotalCount;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = "true"), Category = UI)
	float decreasingPower;

	float curSpaceCount;

	bool startIntro;
	bool isEventEnded;

private:
	UPROPERTY(Meta = (BindWidgetAnim), Meta = (AllowPrivateAccess = "true"), Transient)
	class UWidgetAnimation* FadeOut;
};