// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MAPlayTipWidget.generated.h"

/**
 * 
 */
UCLASS()
class MOKOKO_ADVENTURE_API UMAPlayTipWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;
	
protected:
	class UCanvasPanel* CanvasPanel;

	void OnVisible(bool bVisible);
};
