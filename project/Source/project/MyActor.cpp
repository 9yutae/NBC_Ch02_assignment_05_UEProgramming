// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Initialize the Actor's Location
	start = FVector2D(0, 0);
	// Get Current Location
	currentLocation = start;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	// print Log(Initial Location)
	UE_LOG(LogTemp, Log, TEXT("Actor location Initialize : %s"), *start.ToString());
	// Move 10 times
	move();
	// print Log(After Movements)
	UE_LOG(LogTemp, Log, TEXT("Last Actor location : %s"), *currentLocation.ToString());
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AMyActor::move() {
	// Maximum Movement Count
	int32 MaxMoveCount = 10;

	// Move Actor 10 times
	for (int32 i = 0;i < MaxMoveCount; i++) {
		currentLocation = FVector2D(currentLocation.X + step(), currentLocation.Y + step());  // Move Randomly using step() function
		UE_LOG(LogTemp, Warning, TEXT("%s. Current Location : %s"), *FString::FromInt(i+1),*currentLocation.ToString());  // print Log after every movements
	}
}

int32 AMyActor::step() {
	return FMath::RandRange(0, 1);  // Return 0 or 1 randomly
}
