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
	//Get World location if linetrace through crosshair
	//if it hits the landscame
		//Tell controlled tank to aim at this point
}