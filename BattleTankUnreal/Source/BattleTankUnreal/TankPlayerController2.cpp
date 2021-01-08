// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController2.h"


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

ATank* ATankPlayerController2::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}
