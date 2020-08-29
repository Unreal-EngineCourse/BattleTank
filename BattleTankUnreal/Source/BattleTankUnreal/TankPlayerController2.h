// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController2.generated.h" //must be the last include 

/**
 * 
 */
UCLASS()
class BATTLETANKUNREAL_API ATankPlayerController2 : public APlayerController
{
	GENERATED_BODY()
public:
	ATank* GetControlledTank() const ;
	virtual void BeginPlay() override;
};
