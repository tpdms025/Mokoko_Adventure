// Fill out your copyright notice in the Description page of Project Settings.


#include "MAIntroWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UMAIntroWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ProgressBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("ProgressBar")));

	TimeCount = Cast<UTextBlock>(GetWidgetFromName(TEXT("TB_TimeCount")));

	startIntro = true;
}

void UMAIntroWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (startIntro)
	{


		TimeCount->SetText(FText::FromString(FString::FromInt(time).Append("s")));
		time -= InDeltaTime;
	}
}

void UMAIntroWidget::OnSpaceBarEvent()
{
	ProgressBar->SetPercent(ProgressBar->Percent + (1 / spaceCount));
}

void UMAIntroWidget::OnStartIntro()
{
	startIntro = true;
}
