// Fill out your copyright notice in the Description page of Project Settings.

#include "Bomb.h"

#include "EngineUtils.h"


// Sets default values
ABomb::ABomb()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

FVector ABomb::UpBlastEndpoint(FVector Start)
{
  return FVector(Start.X + BlastRadius, Start.Y, Start.Z);
}

FVector ABomb::DownBlastEndpoint(FVector Start)
{
  return FVector(Start.X - BlastRadius, Start.Y, Start.Z);
}

FVector ABomb::RightBlastEndpoint(FVector Start)
{
  return FVector(Start.X, Start.Y + BlastRadius, Start.Z);
}

FVector ABomb::LeftBlastEndpoint(FVector Start)
{
  return FVector(Start.X, Start.Y - BlastRadius, Start.Z);
}

