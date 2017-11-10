// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerBase.h"


// Sets default values
APlayerBase::APlayerBase()
  : AvailableBombs(1),
    MaxBombs(1),
    HasDetonator(false),
    SpeedMultiplier(1.0f),
    BlastMultiplier(1.0f)
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
  if (AvailableBombs > 0)
  {
    --AvailableBombs;
    return true;
  }

  return false;
}

void APlayerBase::BombDestroyed()
{
  if (!HasDetonator && AvailableBombs<MaxBombs)
  {
    ++AvailableBombs;
  }
  else
  {
    AvailableBombs = 1;
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
  if (!HasDetonator)
  {
    AvailableBombs += Increment;
  }
  MaxBombs += Increment;
}

void APlayerBase::DetonatorPicked()
{
  HasDetonator = true;
  AvailableBombs = 1;
}

void APlayerBase::DetonatorExpired()
{
  HasDetonator = false;
  AvailableBombs = MaxBombs;
}

