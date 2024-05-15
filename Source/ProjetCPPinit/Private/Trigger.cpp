// Fill out your copyright notice in the Description page of Project Settings.


#include "Trigger.h"

#include "Components/BoxComponent.h"


// Sets default values
ATrigger::ATrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	mesh->SetBoxExtent(FVector(50.0f, 50.0f, 50.0f));
	SetRootComponent(mesh);
	//create overlap event
	mesh->OnComponentBeginOverlap.AddDynamic(this, &ATrigger::OnOverlapBegin);
	
}

// Called when the game starts or when spawned
void ATrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

