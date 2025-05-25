// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Waypoint.generated.h"


UCLASS()
class TOWERDEFENSE_API AWaypoint : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:

	int32 GetWaypointOrder();

private:

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	int32 WaypointOrder;
};
