// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bomb.generated.h"

UCLASS()
class BOMBERMANUE4_API ABomb : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABomb();

  // Initialize additional properties
  UFUNCTION(BlueprintCallable)
  void initialize(float BlastMultiplier, bool Remote);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

  // Returns the endpoint of the blast.
  // The direction must one of the cardinal axis (i.e. (-1, 0,0)).
  UFUNCTION(BlueprintPure)
  FVector BlastEndpoint(FVector Start, FVector direction);

protected:
  // Time to bomb explosion
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float BombDelay;

  // Radius of explosion
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float BlastRadius;

  float BlastRadiusDefault;

  // True if it must be remotely detonated
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  bool IsRemote;
	
};
