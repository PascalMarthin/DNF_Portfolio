#include "PreCompile.h"
#include <GameEngineBase/GameEngineInput.h>
#include "GamePlayCharacter.h"
#include "GamePlayKeyManager.h"


GamePlayKeyManager::GamePlayKeyManager() 
	: Player(nullptr)
{
}

GamePlayKeyManager::~GamePlayKeyManager() 
{
}


void GamePlayKeyManager::Start()
{
	Player = GetParent<GamePlayCharacter>();
}
void GamePlayKeyManager::CheckKeyByMove(float _DeltaTime, float _MoveSpeed)
{

}
