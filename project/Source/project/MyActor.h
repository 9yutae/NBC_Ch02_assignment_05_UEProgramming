// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class PROJECT_API AMyActor : public AActor
{
	GENERATED_BODY()
	
private:	
	// Initialize the Actor's Location
	// FVector2D start;

	// The Actor's Current Location
	TArray<FVector2D> coordinateArray;

	// The number of Event Occurrences
	int32 eventCount;

	// Total Distance
	float totalDistance;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Sets default values for this actor's properties
	AMyActor();

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// Move 10 times using step()
	virtual void move();

	// Get 0 or 1 Randomly
	virtual int32 step();

	// Calculate Distance of two Positions
	float distance(FVector2D first, FVector2D second);
	
	// Create Random Event
	void createEvent();
};
