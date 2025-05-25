// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseTurret.h"

#include "Components/SceneComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"


ABaseTurret::ABaseTurret()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(Root);

	TurretMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("TureetMesh"));
	TurretMesh->SetupAttachment(Root);

}

void ABaseTurret::BeginPlay()
{
	Super::BeginPlay();

	
}

void ABaseTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseTurret::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


}

