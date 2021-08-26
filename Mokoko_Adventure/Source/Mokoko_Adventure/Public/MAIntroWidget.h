// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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
	void OnSpaceBarEvent();

	void OnStartIntro();

private:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = "true"), Category = UI)
	float time;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = "true"), Category = UI)
	float spaceCount;

	bool startIntro;
};
