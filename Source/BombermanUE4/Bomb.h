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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

  // Returns the endpoint of the blast in the up direction
  UFUNCTION(BlueprintPure)
  FVector UpBlastEndpoint(FVector Start);

  // Returns the endpoint of the blast in the down direction
  UFUNCTION(BlueprintPure)
  FVector DownBlastEndpoint(FVector Start);

  // Returns the endpoint of the blast in the right direction
  UFUNCTION(BlueprintPure)
  FVector RightBlastEndpoint(FVector Start);

  // Returns the endpoint of the blast in the left direction
  UFUNCTION(BlueprintPure)
  FVector LeftBlastEndpoint(FVector Start);

protected:
  // Time to bomb explosion
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float BombDelay = 3.0f;

  // Radius of explosion
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float BlastRadius = 200.0f;
	
};
