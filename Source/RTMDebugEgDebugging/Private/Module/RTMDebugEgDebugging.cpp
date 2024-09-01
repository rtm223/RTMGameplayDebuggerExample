// Copyright (c) Richard Meredith AB. All Rights Reserved

#include "RTMDebugEgDebugging.h"
#include "GameplayDebugger.h"
#include "Debugging/RTMDebugCategory_Example.h"

#define LOCTEXT_NAMESPACE "RTMDebugEgDebugging"
DEFINE_LOG_CATEGORY(RTMDebugEgDebugging);

IMPLEMENT_MODULE(FRTMDebugEgDebuggingModule, TemplateModule)

void FRTMDebugEgDebuggingModule::StartupModule()
{
	IModuleInterface::StartupModule();

	IGameplayDebugger& gameplayDebuggerModule = IGameplayDebugger::Get();
	gameplayDebuggerModule.RegisterCategory("Example", IGameplayDebugger::FOnGetCategory::CreateStatic(&FRTMDebugCategory_Example::MakeInstance), EGameplayDebuggerCategoryState::Disabled, 9);
}

#undef LOCTEXT_NAMESPACE
