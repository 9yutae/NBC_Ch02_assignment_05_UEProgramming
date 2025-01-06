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
	UE_LOG(LogTemp, Display, TEXT("Total Move Distance : %s"), *FString::SanitizeFloat(distance(start, currentLocation)));
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
		FVector2D nextLocation = FVector2D(currentLocation.X + step(), currentLocation.Y + step());  // Move Randomly using step() function
		UE_LOG(LogTemp, Warning, TEXT("%s. Current Location : %s"), *FString::FromInt(i+1),*nextLocation.ToString());  // print Log after every movements
		UE_LOG(LogTemp, Display, TEXT("Recent Move Distance : %s"), *FString::SanitizeFloat(distance(currentLocation, nextLocation)));
		createEvent();
		currentLocation = nextLocation;
	}
}

int32 AMyActor::step() {
	return FMath::RandRange(0, 1);  // Return 0 or 1 randomly
}

// Calculate the distance of two Locations
float AMyActor::distance(FVector2D first, FVector2D second) {
	float dx = second.X - first.X;
	float dy = second.Y - first.Y;
	return FMath::Sqrt(dx * dx + dy * dy);
}

// Create Random Event
void AMyActor::createEvent() {
	int32 randomValue = FMath::RandRange(1, 100);
	const int32 probability = 50;
	if (randomValue > 50) {
		UE_LOG(LogTemp, Log, TEXT("Event Triggered!"));
		eventCount++;
	}
	else {
		UE_LOG(LogTemp, Log, TEXT("Event Not Triggered!"));
	}
}
