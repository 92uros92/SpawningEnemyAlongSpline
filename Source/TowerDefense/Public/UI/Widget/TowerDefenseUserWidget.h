// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TowerDefenseUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API UTowerDefenseUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

protected:
	/*
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
	*/
};
