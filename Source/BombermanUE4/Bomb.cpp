// Fill out your copyright notice in the Description page of Project Settings.

#include "Bomb.h"

#include "EngineUtils.h"


// Sets default values
ABomb::ABomb()
  : BombDelay(3.0f),
    BlastRadius(140.0f),
    BlastRadiusDefault(BlastRadius),
    IsRemote(false)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ABomb::initialize(float BlastMultiplier, bool Remote)
{
  BlastRadius = BlastMultiplier*BlastRadiusDefault;
  IsRemote = Remote;
}

// Called when the game starts or when spawned
void ABomb::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABomb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector ABomb::BlastEndpoint(FVector Start, FVector direction)
{
  return Start + direction*BlastRadius;
}

