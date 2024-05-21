// Fill out your copyright notice in the Description page of Project Settings.


#include "Trigger.h"
#include "Door.h"
#include "Components/BoxComponent.h"
#include "ProjetCPPinit/ProjetCPPinitCharacter.h"


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
	mesh->OnComponentEndOverlap.AddDynamic(this, &ATrigger::OnOverlapEnd);
	
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

void ATrigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Overlap Begin"));
	
    if(AProjetCPPinitCharacter* Player = Cast<AProjetCPPinitCharacter>(OtherActor))
    {
		Player->DoorRef = DoorRef;
    }
}

void ATrigger::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Overlap End"));
	if(DoorRef)
	{
		DoorRef->CloseDoor();
	}
}
