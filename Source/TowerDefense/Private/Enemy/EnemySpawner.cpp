// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemySpawner.h"
#include "Enemy/Enemy.h"
#include "Enemy/EnemyAIController.h"
#include "Enemy/SplineController.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"






AEnemySpawner::AEnemySpawner()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
	
	//**	Find spline in world and then cast FoundSplines to SplineActorRef		**//
	TArray<AActor*> FoundSplines;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASplineController::StaticClass(), FoundSplines);

	if (FoundSplines.Num() > 0)
	{
		SplineActorRef = Cast<ASplineController>(FoundSplines[0]);
	}
}

void AEnemySpawner::SpawnEnemy()
{
	//**	Spawn the Enemy		**//
	AEnemy* theEnemy = GetWorld()->SpawnActor<AEnemy>(Enemy, RootComponent->GetComponentLocation(), RootComponent->GetComponentRotation());
	if (!theEnemy)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to spawn enemy!"));
		return;
	}

	//**	Get theEnemy controller		**//
	theEnemy->SpawnDefaultController();
	AController* myEnemyController = theEnemy->GetController();
	AEnemyAIController* AIController;

	if (myEnemyController)
	{
		//myEnemyController->Possess(theEnemy);

		AIController = Cast<AEnemyAIController>(myEnemyController);

		if (!AIController)
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to cast to AEnemyAIController"));
			return;
		}

		if (AIController)
		{
			//**	Call SetSpline function from AEnemyAIController		**//
			AIController->SetSpline(SplineActorRef);
		}
	}
}

void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

