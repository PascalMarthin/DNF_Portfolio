#include "PreCompile.h"
#include <GameEngineBase/GameEngineInput.h>
#include "GamePlayCharacter.h"
#include "GamePlayKeyManager.h"


GamePlayKeyManager::GamePlayKeyManager() 
	: Player(nullptr)
	, PlayerStatManager(nullptr)
{
}

GamePlayKeyManager::~GamePlayKeyManager() 
{
}


void GamePlayKeyManager::Start()
{
	Player = GetParent<GamePlayCharacter>();
	PlayerStatManager = Player->GetStatManager();
}
void GamePlayKeyManager::CheckKeyByMove(float _DeltaTime, float _MoveSpeed)
{

}
