// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class SCROLLER2D_API AMovingPlatform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMovingPlatform();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = SpriteImg)
		class UPaperSpriteComponent* PlatformSprite;


private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PlatformParameters, meta = (AllowPrivateAccess = "true"))
		bool AllowToMove = true;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = PlatformParameters, meta = (AllowPrivateAccess = "true"))
		FVector InitialLocation;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = PlatformParameters, meta = (AllowPrivateAccess = "true"))
		bool MovingToward = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlatformParameters, meta = (AllowPrivateAccess = "true"))
		float Speed = .5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlatformParameters, meta = (AllowPrivateAccess = "true"))
		FVector DirectionNegative = FVector(500.0f, 0.0f, 0.0f);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlatformParameters, meta = (AllowPrivateAccess = "true"))
		FVector DirectionPositive = FVector(500.0f, 0.0f, 0.0f);

};
