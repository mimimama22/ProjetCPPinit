// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPI_Interface.h"
#include "BP_GrabObject.generated.h"



UCLASS()
class PROJETCPPINIT_API ABP_GrabObject : public AActor , public ICPI_Interact
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Mesh, meta = (AllowPrivateAccess = "true"));
	UStaticMeshComponent* Mesh;
	
	
public:	
	// Sets default values for this actor's properties
	ABP_GrabObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
