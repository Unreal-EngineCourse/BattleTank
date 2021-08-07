// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Error, TEXT(" AIController can't find player Tank  "));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIcontroller found player tank  %s"), *PlayerTank->GetName());
	}

}

ATank* ATankAIController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank()const {
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) {
		return nullptr;
	}
	// hola let's code
	return Cast<ATank>(PlayerPawn);
}