// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_GrabObject.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "ProjetCPPinit/ProjetCPPinitCharacter.h"


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
	
	AProjetCPPinitCharacter* Player = Cast<AProjetCPPinitCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	
	Player->OnGrabObjectDelegate.AddDynamic(this, &ABP_GrabObject::TestCallDelegate);
}


// Called every frame
void ABP_GrabObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(GetVelocity().Length() > 100.0f)
	{
		OnTestVelocityDelegate.Broadcast();
	}
		

}

void ABP_GrabObject::test_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("Interraction"));
}

bool ABP_GrabObject::Interraction_Implementation(AProjetCPPinitCharacter * Character)
{
	UE_LOG(LogTemp, Warning, TEXT("Interraction"));

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Interraction"));
	Character->GetPhysicsHandle()->GrabComponentAtLocation(Mesh, NAME_None, GetActorLocation());

	OnTestVelocityDelegate.AddUniqueDynamic(Character, &AProjetCPPinitCharacter::TestCallDelegate);
	
	return true;
}

void ABP_GrabObject::TestCallDelegate(bool bIsGrabbing)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("TestCallDelegate %s"), bIsGrabbing);
}

