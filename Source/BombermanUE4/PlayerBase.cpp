// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerBase.h"


// Sets default values
APlayerBase::APlayerBase()
  : AvailableBombs(1),
    AvailableRemoteBombs(1),
    HasDetonator(false),
    BlastMultiplier(1.0f),
    Speed(5000.0f),
    SpeedMultiplier(1.0f),
    RemoteDetonatorDuration(10.0f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool APlayerBase::SpawnBomb()
{
  if (!HasDetonator && AvailableBombs > 0)
  {
    --AvailableBombs;
    return true;
  }
  else if (HasDetonator && AvailableRemoteBombs > 0)
  {
    --AvailableRemoteBombs;
    return true;
  }

  return false;
}

void APlayerBase::BombDestroyed(bool IsRemoteBomb)
{
  if (!IsRemoteBomb)
  {
    ++AvailableBombs;
  }
  else
  {
    ++AvailableRemoteBombs;
  }
}

void APlayerBase::IncreaseBlastRadius(float Increment)
{
  BlastMultiplier += Increment;
}

void APlayerBase::IncreaseSpeed(float Increment)
{
  SpeedMultiplier += Increment;
}

void APlayerBase::IncreaseMaxBombs(int Increment)
{
  AvailableBombs += Increment;
}

void APlayerBase::DetonatorPicked()
{
  HasDetonator = true;
  RemoteDetonatorDuration = 10.0f;
}

void APlayerBase::DetonatorExpired()
{
  HasDetonator = false;
}

FVector APlayerBase::CalculateInputForce(float InputX, float InputY)
{
  return FVector(Speed*InputX, Speed*InputY, 0.0f)*SpeedMultiplier;
}

