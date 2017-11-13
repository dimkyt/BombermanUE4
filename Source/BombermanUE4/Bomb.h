// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bomb.generated.h"

class APlayerBase;

UCLASS()
class BOMBERMANUE4_API ABomb : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABomb();

  // Initialize additional properties
  UFUNCTION(BlueprintCallable)
  void initialize(APlayerBase* Spawner, float BlastMultiplier, bool Remote);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
  // Time to bomb explosion
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float BombDelay;

  // Returns the endpoint of the blast.
  // The direction must one of the cardinal axis (i.e. (-1, 0,0)).
  UFUNCTION(BlueprintPure)
  FVector BlastEndpoint(FVector Start, FVector direction);

  // Radius of explosion
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float BlastRadius;

  float BlastRadiusDefault;

  // True if it must be remotely detonated
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  bool IsRemote;

  // Player that spawned the bomb
  UPROPERTY(BlueprintReadOnly)
  APlayerBase* SpawnedBy;
	
};
