// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimComponent.generated.h"

// Forward Declaration
class UTankBarrel;

// Holds barrel's properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimComponent();

    void SetBarrelReference(UTankBarrel* BarrelToSet);

    // TODO: add SetTurretReference
    
    void AimAt(FVector HitLocation, float LaunchSpeed);
	
private:
    UTankBarrel* Barrel = nullptr;
    
    void MoveBarrelTowards(FVector AimDirection);
    
};