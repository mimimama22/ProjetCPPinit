// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_GrabObject.h"


// Sets default values
ABP_GrabObject::ABP_GrabObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);
	
	//set the actor physics
	Mesh->SetSimulatePhysics(true);
	
}

// Called when the game starts or when spawned
void ABP_GrabObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABP_GrabObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

