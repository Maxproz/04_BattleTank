// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimComponent.generated.h"

// Enum for aiming state
UENUM()
enum class EFiringState : uint8
{
    Reloading,
    Aiming,
    Locked
};

// Forward Declaration
class UTankBarrel;
class UTankTurret;

// Holds barrel's properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimComponent();

    void SetBarrelReference(UTankBarrel* BarrelToSet);
    void SetTurretReference(UTankTurret* TurretToSet);
    
    void AimAt(FVector HitLocation, float LaunchSpeed);
    
protected:
    UPROPERTY(BlueprintReadOnly, Category = "State")
    EFiringState FiringState = EFiringState::Reloading;
    
private:
    UTankBarrel* Barrel = nullptr;
    UTankTurret* Turret = nullptr;
    
    void MoveBarrelTowards(FVector AimDirection);
};
