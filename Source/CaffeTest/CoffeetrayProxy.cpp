// Fill out your copyright notice in the Description page of Project Settings.

#include "CaffeTest.h"
#include "CoffeetrayProxy.h"
#include "JavascriptContext.h"

PRAGMA_DISABLE_OPTIMIZATION

DECLARE_LOG_CATEGORY_EXTERN(LogCaffe, Verbose, All);
DEFINE_LOG_CATEGORY(LogCaffe);

void UCoffeetrayProxy::Init(const FString& Flags)
{
	auto log_callback = [](const char* msg) {
		UE_LOG(LogCaffe, Log, TEXT("%s"), ANSI_TO_TCHAR(msg));
	};
	coffeetray_init(TCHAR_TO_ANSI(*Flags), log_callback);
}

UCoffeetrayProxy::UCoffeetrayProxy(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	if (!HasAnyFlags(RF_ClassDefaultObject)) 
	{
		tray = coffeetray_create();
	}	
}

bool UCoffeetrayProxy::SendString(const FString& Command, const FString& String)
{
	auto str = StringCast<ANSICHAR>(*String);
	return tray && coffeetray_send(tray, TCHAR_TO_ANSI(*Command), str.Length(), (void*)str.Get());
}

bool UCoffeetrayProxy::Send(const FString& Command)
{
	return tray && coffeetray_send(tray, TCHAR_TO_ANSI(*Command), 0, nullptr);
}

bool UCoffeetrayProxy::SendInteger(const FString& Command, int32 Value)
{
	int V = Value;
	return tray && coffeetray_send(tray, TCHAR_TO_ANSI(*Command), sizeof(V), &V);
}

bool UCoffeetrayProxy::SendArray2(const FString& Command)
{
	int n = FArrayBufferAccessor::GetSize() / sizeof(float) / 2;
	float* data = reinterpret_cast<float*>(FArrayBufferAccessor::GetData());	
	struct Pack {
		float* data;
		float* label;
		int n;
	} pack = { data,data+n,n };
	return tray && coffeetray_send(tray, TCHAR_TO_ANSI(*Command), sizeof(pack), &pack);
}

void UCoffeetrayProxy::BeginDestroy()
{
	Super::BeginDestroy();

	if (tray) {
		coffeetray_destroy(tray);
		tray = nullptr;
	}	
}


