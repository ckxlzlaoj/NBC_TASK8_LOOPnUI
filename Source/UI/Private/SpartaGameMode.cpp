// Fill out your copyright notice in the Description page of Project Settings.


#include "SpartaGameMode.h"
#include "SpartaMyCharacter.h"
#include "SpartaPlayerController.h"
#include "SpartaGameStateBase.h"

ASpartaGameMode::ASpartaGameMode()
{
    DefaultPawnClass = ASpartaMyCharacter::StaticClass();
    PlayerControllerClass = ASpartaPlayerController::StaticClass();
    // 우리가 만든 GameState로 설정
    GameStateClass = ASpartaGameStateBase::StaticClass();
}