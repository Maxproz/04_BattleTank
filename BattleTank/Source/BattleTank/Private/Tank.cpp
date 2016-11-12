// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimComponent.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
    
    // No need to protect pointers as added at constructor
    TankAimComponent =
        CreateDefaultSubobject<UTankAimComponent>(FName("Aim Component"));
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
    TankAimComponent->SetBarrelReference(BarrelToSet);
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ATank::AimAt(FVector HitLocation)
{
    TankAimComponent->AimAt(HitLocation, LaunchSpeed);
}

