// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "CaffeTestGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CAFFETEST_API ACaffeTestGameMode : public AGameMode
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category="Misc")
	void TestCaffe();
	
	
};
