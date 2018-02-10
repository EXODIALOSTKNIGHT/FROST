// Fill out your copyright notice in the Description page of Project Settings.

#include "DeathFall.h"
#include "Engine/World.h"
#include "Engine/TriggerVolume.h"
#include "GameFramework/Actor.h"


// Sets default values
ADeathFall::ADeathFall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADeathFall::BeginPlay()
{
	Super::BeginPlay();
	Player = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void ADeathFall::Dead()
{
	Player->SetActorLocation(FVector(CheckPoint));
}

// Called every frame
void ADeathFall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Player && Player->IsOverlappingActor(PitFall))
	{
		Dead();
	}
}

