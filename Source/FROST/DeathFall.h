// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Engine/TriggerVolume.h"
#include "DeathFall.generated.h"

UCLASS()
class FROST_API ADeathFall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADeathFall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Dead();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	AActor* Player;
	FVector CheckPoint = FVector(-16180.f, 0.0f, 436.73288f);

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PitFall;
	
};
