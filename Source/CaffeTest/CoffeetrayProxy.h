// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoffeetrayProxy.generated.h"

/**
 * 
 */
UCLASS()
class CAFFETEST_API UCoffeetrayProxy : public UObject
{
	GENERATED_UCLASS_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "DeepLearning")
	static void Init(const FString& Flags);
		
	UFUNCTION(BlueprintCallable, Category = "DeepLearning")
	bool SendString(const FString& Command, const FString& String);

	UFUNCTION(BlueprintCallable, Category = "DeepLearning")
	bool Send(const FString& Command);

	UFUNCTION(BlueprintCallable, Category = "DeepLearning")
	bool SendInteger(const FString& Command, int32 Value);

	UFUNCTION(BlueprintCallable, Category = "DeepLearning")
	bool SendArray2(const FString& Command);

	UFUNCTION(BlueprintCallable, Category = "DeepLearning")
	bool ReadArray(const FString& Command);

	UFUNCTION(BlueprintCallable, Category = "DeepLearning")
	bool WriteArray(const FString& Command);

	virtual void BeginDestroy() override;
	
	void* tray{ nullptr };
};
