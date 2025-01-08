// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h" // 클래스 템플릿의 기본 헤더 CoreMinimal.h로 변경
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS() // 클래스 선언 매크로
class PROJECT_API AMyActor : public AActor
{
	GENERATED_BODY()	// 클래스 선언 매크로
	
private:	
	// Initialize the Actor's Location
	// FVector2D start;

	// The Actor's Current Location
	UPROPERTY(VisibleAnywhere, Category=MyValue)
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

	// 포인터 변수로 MyActor 선언
	UPROPERTY(VisibleAnywhere)  // 언리얼 실행 환경이 객체를 자동으로 관리하도록 매크로 선언, VisibleAnywher = 속성값 확인 가능
	UStaticMeshComponent* Body;

	UPROPERTY(EditAnywhere, Category=ID)
	int32 ID;

};
