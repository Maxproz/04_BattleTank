// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be the last include

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
    void BeginPlay() override;
    
    void Tick(float DeltaTime) override;
    
    ATank* GetControlledTank() const;
    
    // Start the tank moving the barrel so that a shot would
    // - hit where the crosshair intersects in the world
    void AimTowardsCrosshair();
    
    // Return an OUT parameter, true if hit landscape
    bool GetSightRayHitLocation(FVector& HitLocation) const;
    
    UPROPERTY(EditDefaultsOnly)
    float CrosshairXLocation = 0.5f;
    
    UPROPERTY(EditDefaultsOnly)
    float CrosshairYLocation = 0.3333f;
    
    UPROPERTY(EditDefaultsOnly)
    float LineTraceRange = 1000000;

    bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
    bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
    
};
