// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController2.h"


//tick 
	//super

void ATankPlayerController2::BeginPlay() {
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Error, TEXT("Player Controller Not Posessinng A Tank  "));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Player controller Possessing : %s"), *ControlledTank->GetName());
	}

}

void ATankPlayerController2::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}


ATank* ATankPlayerController2::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}

void ATankPlayerController2::AimTowardsCrosshair() {
	if (!GetControlledTank()) {
		return;
	}
	FVector HitLocation; // out parameter
	if (GetSightRayHitLocation(HitLocation)) // has a side effect , it is going to ray trace 
	{
		UE_LOG(LogTemp, Warning, TEXT("Look direction:%s"), *HitLocation.ToString());
		// TODO tell controlled Tank to aim at this point
	}
}
//Get World location of linetrace through crosshair , true if hits the landscape
bool ATankPlayerController2::GetSightRayHitLocation(FVector& HitLocation) const {
	//Find the crosshair position in pixel coordinates 
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

	// DE-project the screenposition of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}


	return true;
}

bool ATankPlayerController2::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation)const {
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility))
	{
		HitLocation=HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}
bool ATankPlayerController2::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection)const {
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection);

}