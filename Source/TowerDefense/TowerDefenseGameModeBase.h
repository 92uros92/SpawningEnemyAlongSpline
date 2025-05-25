// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TowerDefenseGameModeBase.generated.h"





UCLASS()
class TOWERDEFENSE_API ATowerDefenseGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
protected:

	virtual void BeginPlay() override;

private:

	//**	The array of spawned enemy	**//
	TArray<AActor*> EnemySpawners;

	//**  FUNCTIONS  **//

	UFUNCTION(BlueprintCallable)
	void SpawnEnemy();


};
