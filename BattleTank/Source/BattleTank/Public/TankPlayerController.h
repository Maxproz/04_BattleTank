// Copyright Maxpro 2016

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be the last include

class UTankAimComponent;

/**
 * Responsible for helping the player aim.
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
    UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
    void FoundAimingComponent(UTankAimComponent* AimCompRef);
    
private:
    void BeginPlay() override;
    
    void Tick(float DeltaTime) override;
    
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
    
    void SetPawn(APawn* InPawn) override;
    
    UFUNCTION()
    void OnPossessedTankDeath();
};
