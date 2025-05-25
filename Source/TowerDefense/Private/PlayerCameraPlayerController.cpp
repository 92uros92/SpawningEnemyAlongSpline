// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCameraPlayerController.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"

#include "Components/SceneComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"



APlayerCameraPlayerController::APlayerCameraPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = SceneComponent;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 2500.0f;
	SpringArm->bDoCollisionTest = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

}

void APlayerCameraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(TowerDefenseContext, 0);
		}
	}

	// Set start location for the camera
	TargetLocation = GetActorLocation();
	TargetZoom = 3000.f;

	// Set initial rotation for the camera
	const FRotator Rotation = SpringArm->GetRelativeRotation();
	TargetRotation = FRotator(Rotation.Pitch + -50, Rotation.Yaw, 0.f);
}

void APlayerCameraPlayerController::Forward(const FInputActionValue& Value)
{
	const float ForwardValue = Value.Get<float>();

	if (ForwardValue == 0.f)
	{
		return;
	}

	TargetLocation = SpringArm->GetForwardVector() * ForwardValue * MoveSpeed + TargetLocation;
}

void APlayerCameraPlayerController::Right(const FInputActionValue& Value)
{
	const float RightValue = Value.Get<float>();

	if (RightValue == 0.f)
	{
		return;
	}

	TargetLocation = SpringArm->GetRightVector() * RightValue * MoveSpeed + TargetLocation;
}

void APlayerCameraPlayerController::Zoom(const FInputActionValue& Value)
{
	const float ZoomValue = Value.Get<float>();

	if (ZoomValue == 0.f)
	{
		return;
	}

	const float Zoom = ZoomValue * 100.f;
	TargetZoom = FMath::Clamp(Zoom + TargetZoom, MinZoom, MaxZoom);
}

void APlayerCameraPlayerController::RotateRight()
{
	TargetRotation = UKismetMathLibrary::ComposeRotators(TargetRotation, FRotator(0.f, -45.0f, 0.f));
}

void APlayerCameraPlayerController::RotateLeft()
{
	TargetRotation = UKismetMathLibrary::ComposeRotators(TargetRotation, FRotator(0.f, 45.0f, 0.f));
}

void APlayerCameraPlayerController::EnableRotate()
{
	CanRotate = true;
}

void APlayerCameraPlayerController::DisableRotate()
{
	CanRotate = false;
}

void APlayerCameraPlayerController::RotateHorizontal(const FInputActionValue& Value)
{
	const float RotateHorizontalValue = Value.Get<float>();

	if (RotateHorizontalValue == 0.f)
	{
		return;
	}

	if (CanRotate)
	{
		TargetRotation = UKismetMathLibrary::ComposeRotators(TargetRotation, FRotator(0.f, RotateHorizontalValue, 0.f));
	}
}

void APlayerCameraPlayerController::RotateVertical(const FInputActionValue& Value)
{
	const float RotateVerticalValue = Value.Get<float>();

	if (RotateVerticalValue == 0.f)
	{
		return;
	}

	if (CanRotate)
	{
		TargetRotation = UKismetMathLibrary::ComposeRotators(TargetRotation, FRotator(RotateVerticalValue, 0.f, 0.f));
	}
}

void APlayerCameraPlayerController::CameraBounds()
{
	float NewPitch = TargetRotation.Pitch;

	if (TargetRotation.Pitch < RotatePitchMax * -1)
	{
		NewPitch = (RotatePitchMax * -1);
	}
	else if (TargetRotation.Pitch > RotatePitchMin * -1)
	{
		NewPitch = (RotatePitchMin * -1);
	}

	// Set the new pitch
	TargetRotation = FRotator(NewPitch, TargetRotation.Yaw, 0.f);

	// Clamp desired location to within bound
	TargetLocation = FVector(TargetLocation.X, TargetLocation.Y, 0.f);
}

void APlayerCameraPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CameraBounds();

	// Move the pawn in the desired direction
	const FVector InterpolatedLocation = UKismetMathLibrary::VInterpTo(GetActorLocation(), TargetLocation, DeltaTime, MoveSpeed);
	SetActorLocation(InterpolatedLocation);

	// Zoom the camera in the desired direction
	const float InterpolatedZoom = UKismetMathLibrary::FInterpTo(SpringArm->TargetArmLength, TargetZoom, DeltaTime, ZoomSpeed);
	SpringArm->TargetArmLength = InterpolatedZoom;

	// Rotate the camera in the desired direction
	const FRotator InterpolatedRotation = UKismetMathLibrary::RInterpTo(SpringArm->GetRelativeRotation(), TargetRotation, DeltaTime, RotateSpeed);
	SpringArm->SetRelativeRotation(InterpolatedRotation);
}

void APlayerCameraPlayerController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(ForwardAction, ETriggerEvent::Triggered, this, &APlayerCameraPlayerController::Forward);
		EnhancedInputComponent->BindAction(RightAction, ETriggerEvent::Triggered, this, &APlayerCameraPlayerController::Right);
		EnhancedInputComponent->BindAction(ZoomAction, ETriggerEvent::Triggered, this, &APlayerCameraPlayerController::Zoom);
		EnhancedInputComponent->BindAction(RotateHorizontalAction, ETriggerEvent::Triggered, this, &APlayerCameraPlayerController::RotateHorizontal);
		EnhancedInputComponent->BindAction(RotateVerticalAction, ETriggerEvent::Triggered, this, &APlayerCameraPlayerController::RotateVertical);
		
		EnhancedInputComponent->BindAction(RotateRightAction, ETriggerEvent::Started, this, &APlayerCameraPlayerController::RotateRight);
		EnhancedInputComponent->BindAction(RotateLeftAction, ETriggerEvent::Started, this, &APlayerCameraPlayerController::RotateLeft);
		EnhancedInputComponent->BindAction(RotateAction, ETriggerEvent::Started, this, &APlayerCameraPlayerController::EnableRotate);
		EnhancedInputComponent->BindAction(RotateAction, ETriggerEvent::Completed, this, &APlayerCameraPlayerController::DisableRotate);

	}


}

