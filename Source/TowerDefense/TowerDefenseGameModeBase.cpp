// Copyright Epic Games, Inc. All Rights Reserved.


#include "TowerDefenseGameModeBase.h"
#include "Enemy/EnemySpawner.h"
#include "Enemy/EnemyAIController.h"
#include "Enemy/SplineController.h"
#include "Enemy/Enemy.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"




void ATowerDefenseGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	//**	Find all enemy		**//
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemySpawner::StaticClass(), EnemySpawners);
}

void ATowerDefenseGameModeBase::SpawnEnemy()
{
	
	//**	Call SpawnEnemy function from AEnemySpawner		**//
	Cast<AEnemySpawner>(EnemySpawners[FMath::FRandRange(0.f, EnemySpawners.Num())])->SpawnEnemy();

	UE_LOG(LogTemp, Warning, TEXT("Spawning Enemy"));
}
