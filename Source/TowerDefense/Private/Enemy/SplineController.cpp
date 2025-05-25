// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/SplineController.h"
#include "Components/SplineComponent.h"



ASplineController::ASplineController()
{
	PrimaryActorTick.bCanEverTick = true;

	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("Spline"));
	RootComponent = SplineComponent;
	
}

void ASplineController::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASplineController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//**	Called in AEnemyAIController	**//
FVector ASplineController::GetLocationAtDistance(float Distance) const
{
	return SplineComponent->GetLocationAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
}

