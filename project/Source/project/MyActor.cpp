﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initialize the Actor's Location and properties
	SetActorLocation(FVector(0, 0, 0));
	coordinateArray.Add(FVector2D(0, 0));
	eventCount = 0;
	totalDistance = 0.0f;


	// 클래스의 생성자(Constructor)에서 컴포넌트 생성
	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	
	// 에셋 지정
	// 에셋의 키 값을 FObjectFinder 변수로 전달해 해당 에셋의 포인터를 가져옴
	// 게임 도중 에셋의 경로가 변경될 일 없으므로 static으로 선언
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		SM_BODY(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Props/SM_Statue.SM_Statue'"));

	// SetStaticMesh 함수에 SM_BODY 포인터 전달
	if (SM_BODY.Succeeded())
	{
		Body->SetStaticMesh(SM_BODY.Object);
	}

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()	
{
	Super::BeginPlay();

	// print Log(Initial Location)
	UE_LOG(LogTemp, Log, TEXT("Actor location Initialize : %s"), *coordinateArray[0].ToString());
	
	// SetTimer를 이용하여 0.5초 간격으로 move 실행
	GetWorldTimerManager().SetTimer(MyTimerHandle, this, &AMyActor::move, 0.50f, true);

	// print Log(After Movements)
	UE_LOG(LogTemp, Log, TEXT("Last Actor location : %s"), *coordinateArray.Top().ToString());
	UE_LOG(LogTemp, Display, TEXT("Total Move Distance : %s"), *FString::SanitizeFloat(distance(coordinateArray[0], coordinateArray.Top())));
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AMyActor::move() {
	// MovementCount 변수를 사용하여 총 10회 이동하도록 설정
	if (--MovementCount <= 0) {
		GetWorldTimerManager().ClearTimer(MyTimerHandle);
	}

	// 이동할 좌표 설정
	FVector2D currentLocation = coordinateArray.Top();
	FVector2D nextLocation = FVector2D(currentLocation.X + step(), currentLocation.Y + step());  // Move Randomly using step() function

	// 이동
	SetActorLocation(FVector(nextLocation, 0));
	coordinateArray.Add(nextLocation);

	// 로그 출력
	UE_LOG(LogTemp, Warning, TEXT("%s. Current Location : %s"), *FString::FromInt(10-MovementCount), *nextLocation.ToString());  // print Log after every movements
	UE_LOG(LogTemp, Display, TEXT("Recent Move Distance : %s"), *FString::SanitizeFloat(distance(currentLocation, nextLocation)));

	createEvent();
}

int32 AMyActor::step() {
	return FMath::RandRange(0, 1) * 100;  // Return 0 or 1 randomly
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

/*
void AMyActor::move() {
	// Maximum Movement Count
	int32 MaxMoveCount = 10;

	// Move Actor 10 times
	for (int32 i = 1;i <= MaxMoveCount; i++) {
		FVector2D currentLocation = coordinateArray[i - 1];
		FVector2D nextLocation = FVector2D(currentLocation.X + step(), currentLocation.Y + step());  // Move Randomly using step() function

		SetActorLocation(FVector(nextLocation, 0));
		coordinateArray.Add(nextLocation);

		UE_LOG(LogTemp, Warning, TEXT("%s. Current Location : %s"), *FString::FromInt(i),*nextLocation.ToString());  // print Log after every movements
		UE_LOG(LogTemp, Display, TEXT("Recent Move Distance : %s"), *FString::SanitizeFloat(distance(currentLocation, nextLocation)));

		createEvent();
	}
}
*/