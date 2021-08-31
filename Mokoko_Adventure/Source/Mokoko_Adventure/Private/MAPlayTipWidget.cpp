// Fill out your copyright notice in the Description page of Project Settings.


#include "MAPlayTipWidget.h"
#include "Components/CanvasPanel.h"

void UMAPlayTipWidget::NativeConstruct()
{
	Super::NativeConstruct();

	CanvasPanel = Cast<UCanvasPanel>(GetWidgetFromName(TEXT("Canvas")));
	OnVisible(false);
}

void UMAPlayTipWidget::OnVisible(bool bVisible)
{
	CanvasPanel->SetRenderOpacity((bVisible ? 1.0f : 0.0f));
}