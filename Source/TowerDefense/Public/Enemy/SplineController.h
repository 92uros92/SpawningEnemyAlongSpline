// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SplineController.generated.h"



class USplineComponent;


UCLASS()
class TOWERDEFENSE_API ASplineController : public AActor
{
	GENERATED_BODY()
	
public:	

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Spline")
	USplineComponent* SplineComponent;

	//**  FUNCTIONS  **//

	ASplineController();
	
	virtual void Tick(float DeltaTime) override;

	FVector GetLocationAtDistance(float Distance) const;

protected:

	virtual void BeginPlay() override;

};
