// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/Interface.h"
#include "CoreMinimal.h"
#include "CPI_Interface.generated.h"
/**
 * 
 */
class AProjetCPPinitCharacter;
UINTERFACE(MinimalAPI, Blueprintable)
class UCPI_Interact : public UInterface
{
	GENERATED_BODY()
	
};

class ICPI_Interact
{
	GENERATED_BODY()
	// Add interface functions to this class. This is the class that will be inherited to implement this interface.

public:
  
	//UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category=Interface)
	UFUNCTION(BlueprintCallable,BlueprintNativeEvent)
	bool Interraction(AProjetCPPinitCharacter *Character);
	
};




