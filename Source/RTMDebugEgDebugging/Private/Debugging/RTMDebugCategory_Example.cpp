// Copyright (c) Richard Meredith AB. All Rights Reserved

#include "RTMDebugCategory_Example.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/GameStateBase.h"
#include "GameFramework/PlayerState.h"
#include "Kismet/GameplayStatics.h"

TSharedRef<FGameplayDebuggerCategory> FRTMDebugCategory_Example::MakeInstance()
{
	return MakeShareable(new FRTMDebugCategory_Example());
}

void FRTMDebugCategory_Example::CollectData(APlayerController* ownerPC, AActor* debugActor)
{
	if(ownerPC)
	{
		const auto* playerState = ownerPC->GetPlayerState<APlayerState>();
		const auto* playerPawn = ownerPC->GetPawn();
		const auto* gameMode = UGameplayStatics::GetGameMode(ownerPC);
		const auto* gameState = UGameplayStatics::GetGameState(ownerPC);

		AddTextLine(FString::Printf(TEXT("PlayerController : {Cyan}%s"), *ownerPC->GetClass()->GetName()));
		AddTextLine(FString::Printf(TEXT("PlayerPawn : {Cyan}%s"), playerPawn ? *playerPawn->GetClass()->GetName() : TEXT("{red}[UNKNOWN]")));
		AddTextLine(FString::Printf(TEXT("PlayerState : {Cyan}%s"), playerState ? *playerState->GetClass()->GetName() : TEXT("[red}[UNKNOWN]")));
		AddTextLine(FString::Printf(TEXT("GameMode : {Cyan}%s"), gameMode ? *gameMode->GetClass()->GetName() : TEXT("{red}[UNKNOWN]")));
		AddTextLine(FString::Printf(TEXT("GameMode : {Cyan}%s"), gameState ? *gameState->GetClass()->GetName() : TEXT("{red}[UNKNOWN]")));
	}
}
