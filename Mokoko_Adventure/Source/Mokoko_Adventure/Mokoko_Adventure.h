// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(Mokoko_Adventure, Log, All);
#define MALOG_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))
#define MALOG_S(Verbosity) UE_LOG(Mokoko_Adventure, Verbosity, TEXT("%s"), *MALOG_CALLINFO)
#define MALOG(Verbosity, Format, ...) UE_LOG(Mokoko_Adventure, Verbosity, TEXT("%s %s"), *MALOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))