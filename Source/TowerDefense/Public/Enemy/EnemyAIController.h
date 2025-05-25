// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"




class AEnemySpawner;
class AEnemy;
class ASplineController;
class USplineComponent;


UCLASS()
class TOWERDEFENSE_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
	
public:

	AEnemyAIController();

	virtual void OnPossess(APawn* InPawn) override;

	virtual void Tick(float DeltaTime) override;

	void SetSpline(ASplineController* SplineActor);

private:

	ASplineController* SplineContRef;

	float DistanceAlongSpline = 0.f;

	// Units per second
	float Speed; 

};
