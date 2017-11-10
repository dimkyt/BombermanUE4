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

  // Returns true if a bomb can be spawned and increments the active bomb counter;
  UFUNCTION(BlueprintCallable, Category = "Bombs")
  bool SpawnBomb();

protected:
  // Max number of bombs that can be spawned at the same time 
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bombs")
  int32 MaxBombs;
	
  // Number of currently spawned bombs
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bombs")
  int32 ActiveBombs;
};  
