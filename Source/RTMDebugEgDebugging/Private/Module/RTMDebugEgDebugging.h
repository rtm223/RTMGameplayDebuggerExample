// Copyright (c) Richard Meredith AB. All Rights Reserved

#pragma once

DECLARE_LOG_CATEGORY_EXTERN(RTMDebugEgDebugging, All, All)
DECLARE_STATS_GROUP(TEXT("RTMDebugEgDebugging"), STATGROUP_RTMDebugEgDebugging, STATCAT_Advanced)

class FRTMDebugEgDebuggingModule : public IModuleInterface
{
	virtual void StartupModule() override;
};