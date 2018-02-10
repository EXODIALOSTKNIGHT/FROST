// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Engine/TriggerVolume.h"
#include "Death2.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FROST_API UDeath2 : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDeath2();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	void Dead();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	AActor * Player;
	FVector CheckPoint = FVector(-16180.f, 0.0f, 436.73288f);

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PitFall;

	UPROPERTY(EditAnywhere)
	float test = 0;
	
};
