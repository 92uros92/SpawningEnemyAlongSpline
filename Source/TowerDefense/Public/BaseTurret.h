// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BaseTurret.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class TOWERDEFENSE_API ABaseTurret : public APawn
{
	GENERATED_BODY()

public:
	ABaseTurret();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = Input) 
	UInputMappingContext* TowerDefenseContext;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* Right;

private:

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(EditDefaultsOnly)
	USkeletalMeshComponent* TurretMesh;

};
