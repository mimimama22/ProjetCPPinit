// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>("DoorMesh");
	SetRootComponent(DoorMesh);

}

void ADoor::CloseDoor_Implementation()
{	
	UE_LOG(LogTemp, Warning, TEXT("OpenClose"));
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADoor::OpenDoor_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("OpenDoor"));
	
}


// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

