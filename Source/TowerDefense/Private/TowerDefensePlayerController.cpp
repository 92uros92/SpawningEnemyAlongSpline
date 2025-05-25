// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerDefensePlayerController.h"

ATowerDefensePlayerController::ATowerDefensePlayerController()
{
	bReplicates = true;
}

void ATowerDefensePlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Show mouse cursor on screen

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	
	FInputModeGameAndUI InputmodeData;
	InputmodeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputmodeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputmodeData);

	// END Show mouse cursor on screen
}
