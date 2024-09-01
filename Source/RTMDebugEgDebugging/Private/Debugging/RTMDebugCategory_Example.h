// Copyright (c) Richard Meredith AB. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameplayDebuggerCategory.h"

class FRTMDebugCategory_Example : public FGameplayDebuggerCategory
{
public:
	static TSharedRef<FGameplayDebuggerCategory> MakeInstance();

	virtual void CollectData(APlayerController* ownerPC, AActor* debugActor) override;
};

