// Fill out your copyright notice in the Description page of Project Settings.

#include "Death2.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Engine/TriggerVolume.h"


// Sets default values for this component's properties
UDeath2::UDeath2()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UDeath2::Dead()
{
	Player->SetActorLocation(FVector(CheckPoint));
}


// Called when the game starts
void UDeath2::BeginPlay()
{
	Super::BeginPlay();

	Player = GetWorld()->GetFirstPlayerController()->GetPawn();
	
}


// Called every frame
void UDeath2::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (Player && Player->IsOverlappingActor(PitFall))
	{
		Dead();
	}
}

