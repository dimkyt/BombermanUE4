// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerBase.generated.h"

UCLASS()
class BOMBERMANUE4_API APlayerBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayerBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

  // Returns true if a bomb can be spawned and decreases available bombs
  UFUNCTION(BlueprintCallable, Category = "Bombs")
  bool SpawnBomb();

  // Increases available bombs
  UFUNCTION(BlueprintCallable, Category = "Bombs")
  void BombDestroyed();

  // Increases blast radius multiplier
  UFUNCTION(BlueprintCallable, Category = "Bombs")
  void IncreaseBlastRadius(float Increment);

  // Increases the speed multiplier
  UFUNCTION(BlueprintCallable, Category = "Player")
  void IncreaseSpeed(float Increment);

  // Increases the number of bombs that can be active at the same time
  UFUNCTION(BlueprintCallable, Category = "Player")
  void IncreaseMaxBombs(int Increment);

protected:

  // Number of currently available bombs
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bombs")
  int32 AvailableBombs;

  // Bomb blast radius multiplier
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bombs")
  float BlastMultiplier;

  // Speed mulltiplier
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
  float SpeedMultiplier;
};  
