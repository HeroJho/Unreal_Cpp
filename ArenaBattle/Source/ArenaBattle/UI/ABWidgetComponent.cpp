// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ABWidgetComponent.h"
#include "ABUserWidget.h"

void UABWidgetComponent::InitWidget()
{
	Super::InitWidget(); // ��ϵ� ������ ����

	// ������ ���� ������ �����´�.
	UABUserWidget* ABUserWidget = Cast<UABUserWidget>(GetWidget());
	if (ABUserWidget)
	{   // Ȯ���� ���� Ŭ������ Owner�� �Ѱ��ش�.
		ABUserWidget->SetOwningActor(GetOwner());
	}
}
