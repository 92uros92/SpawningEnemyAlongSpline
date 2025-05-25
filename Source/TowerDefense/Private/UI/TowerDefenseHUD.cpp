// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/TowerDefenseHUD.h"
#include "UI/Widget/TowerDefenseUserWidget.h"
#include "Blueprint/UserWidget.h"

void ATowerDefenseHUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* Widget = CreateWidget<UTowerDefenseUserWidget>(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();

}
