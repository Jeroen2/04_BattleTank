// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* tank = GetPlayerTank();
	if (!tank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No controlled tank for this controller"));
	}
	else
	{
		FString name = tank->GetName();
		UE_LOG(LogTemp, Warning, TEXT("We are now controlling tank: %s"), *name);
	}

}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerController = GetWorld()->GetFirstPlayerController();
	if (PlayerController)
	{
		ATank* tank = Cast<ATank>(PlayerController->GetPawn());

		if (tank)
			return tank;
	}

	return nullptr;
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
