// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"



class AEnemy;
class ASplineController;


UCLASS()
class TOWERDEFENSE_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:

	ASplineController* SplineActorRef;

	//**  FUNCTIONS  **//

	AEnemySpawner();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, Category = "AI Navigation")
	TSubclassOf<AEnemy> Enemy;

	void SpawnEnemy();

protected:

	virtual void BeginPlay() override;


};
