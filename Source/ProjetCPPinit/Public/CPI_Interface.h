// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/Interface.h"
#include "CoreMinimal.h"
#include "CPI_Interface.generated.h"
/**
 * 
 */

UINTERFACE(MinimalAPI, Blueprintable)
class UCPI_Interact : UInterface
{
	GENERATED_BODY()
};

class ICPI_Interact
{
	GENERATED_BODY()
	// Add interface functions to this class. This is the class that will be inherited to implement this interface.

public:
	
	virtual bool MyInterfaceFunction();
  
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category=Interface)
	bool MyImplementableFunction();
  
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category=Interface)
	FString MyNativeFunction();

	FString GetInterfaceName();
	
};




