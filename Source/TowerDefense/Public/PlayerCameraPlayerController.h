// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "PlayerCameraPlayerController.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
class UAbilitySystemComponent;
class UAttributeSet;

UCLASS()
class TOWERDEFENSE_API APlayerCameraPlayerController : public APawn
{
	GENERATED_BODY()

public:

	APlayerCameraPlayerController();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	virtual void BeginPlay() override;

	// Input Function

	UFUNCTION()
	void Forward(const FInputActionValue& Value);

	UFUNCTION()
	void Right(const FInputActionValue& Value);

	UFUNCTION()
	void Zoom(const FInputActionValue& Value);

	UFUNCTION()
	void RotateRight();

	UFUNCTION()
	void RotateLeft();

	UFUNCTION()
	void EnableRotate();

	UFUNCTION()
	void DisableRotate();

	UFUNCTION()
	void RotateHorizontal(const FInputActionValue& Value);

	UFUNCTION()
	void RotateVertical(const FInputActionValue& Value);

	// END Input Function

	// Settings for Camera

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Camera Settings")
	float MoveSpeed = 20.0f;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Camera Settings")
	float RotateSpeed = 2.0f;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Camera Settings")
	float RotatePitchMin = 10.0f;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Camera Settings")
	float RotatePitchMax = 80.0f;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Camera Settings")
	float ZoomSpeed = 2.0f;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Camera Settings")
	float MinZoom = 500.0f;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Camera Settings")
	float MaxZoom = 4000.0f;

	// END Settings for Camera

	// Enhanced Input Values

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputMappingContext* TowerDefenseContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* ForwardAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* RightAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* ZoomAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* RotateHorizontalAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* RotateVerticalAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* RotateRightAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* RotateLeftAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* RotateAction;
	// END Enhanced Input Values
	
	// Values for UserWidget 

	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<APlayerController> TowerDefensePlayerController;

	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<APlayerState> TowerDefensePlayerState;

	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<UAttributeSet> AttributeSet;
	// END Values for UserWidget 

private:	

	UFUNCTION()
	void CameraBounds();

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	USceneComponent* SceneComponent;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;

	UPROPERTY()
	FVector TargetLocation;

	UPROPERTY()
	FRotator TargetRotation;

	UPROPERTY()
	float TargetZoom;

	UPROPERTY()
	bool CanRotate;

};
