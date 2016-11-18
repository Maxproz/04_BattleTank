// Copyright Maxpro 2016

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Put new includes above

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
    float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) override;
    
    // Return current health as a percentage of starting health, between 0 and 1
    UFUNCTION(BlueprintPure, Category = "Health")
    float GetHealthPercent() const;
    
    FTankDelegate OnDeath;
    
private:
	// Sets default values for this pawn's properties
	ATank();

    void BeginPlay() override;
    
    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    int32 StartingHealth = 100;
    
    UPROPERTY(VisibleAnywhere, Category = "Health")
    int32 CurrentHealth; // Initalized in BeginPlay()
};
