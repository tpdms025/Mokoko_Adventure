// Fill out your copyright notice in the Description page of Project Settings.


#include "MAIntroWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Animation/WidgetAnimation.h"
#include "MAPlayerController.h"

void UMAIntroWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ProgressBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("PB_SpaceBar")));

	TimeCount = Cast<UTextBlock>(GetWidgetFromName(TEXT("TB_TimeCount")));

	startIntro = false;
	isEventEnded = false;
	curSpaceCount = 0;
}

void UMAIntroWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (startIntro)
	{
		if (curSpaceCount >= spaceTotalCount)
		{
			ProgressBar->SetIsMarquee(true);
			startIntro = false;
			isEventEnded = true;
			PlayAnimation(FadeOut);
		}
		else
		{
			ProgressBar->SetPercent(curSpaceCount / spaceTotalCount);
			if (curSpaceCount >= 0.0f)
			{
				curSpaceCount -= decreasingPower * InDeltaTime;
			}
		}

		if (time > 0.0f)
		{
			TimeCount->SetText(FText::FromString(FString::FromInt(time).Append("s")));
			time -= InDeltaTime;
		}
	}

}

void UMAIntroWidget::BindPlayerController(AMAPlayerController* PC)
{
	playerController = PC;
	PC->OnSpaceBarPressedEvent.AddUObject(this, &UMAIntroWidget::OnSpaceBarEvent);
	PC->OnTestPressedEvent.AddUObject(this, &UMAIntroWidget::OnStartIntro);
}

void UMAIntroWidget::OnSpaceBarEvent()
{
	curSpaceCount += spacePower;
}

void UMAIntroWidget::OnStartIntro()
{
	startIntro = true;
}