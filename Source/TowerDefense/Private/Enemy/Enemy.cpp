// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Enemy.h"
#include "AIController.h"
#include "Waypoint.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Enemy/EnemyAIController.h"

AEnemy::AEnemy()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();

}

void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
