// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"
#include "PaperSpriteComponent.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values
AMovingPlatform::AMovingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	if (RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("TankBase"));

	}
	PlatformSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PlatformSprite"));
	PlatformSprite->AttachTo(RootComponent);


}
// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	InitialLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (AllowToMove)
	{
		FVector MoveLocation;
		if (MovingToward)
		{
			MoveLocation = UKismetMathLibrary::VInterpTo_Constant(GetActorLocation(), DirectionPositive + InitialLocation, DeltaTime, 100);
			if (GetActorLocation().Equals(DirectionPositive + InitialLocation, .01)) MovingToward = false;
		}
		else
		{
			MoveLocation = UKismetMathLibrary::VInterpTo(GetActorLocation(), InitialLocation, DeltaTime, Speed);
			if (GetActorLocation().Equals(InitialLocation, 5)) MovingToward = true;
		}
		SetActorLocation(MoveLocation);
	}
}
