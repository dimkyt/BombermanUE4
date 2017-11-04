// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerBase.h"


// Sets default values
APlayerBase::APlayerBase()
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
  if (ActiveBombs < MaxBombs)
  {
    ++ActiveBombs;
    return true;
  }

  return false;
}

