// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyAIController.h"
#include "Enemy/SplineController.h"
#include "Enemy/Enemy.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Components/SplineComponent.h"




AEnemyAIController::AEnemyAIController()
{
	PrimaryActorTick.bCanEverTick = true;

	Speed = 600.0f;
}

void AEnemyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

}

void AEnemyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (SplineContRef)
	{
		DistanceAlongSpline += Speed * DeltaTime;

		//**	Move Enemy to location with certain speed		**//
		FVector TargetLocation = SplineContRef->GetLocationAtDistance(DistanceAlongSpline);
		MoveToLocation(TargetLocation, 5.0f, false);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("SplineContRef is null in Tick!"));
	}
}

void AEnemyAIController::SetSpline(ASplineController* SplineActor)
{
	SplineContRef = SplineActor;
	UE_LOG(LogTemp, Warning, TEXT("Spline set in AI Controller: %s"), *GetNameSafe(SplineActor));
}
