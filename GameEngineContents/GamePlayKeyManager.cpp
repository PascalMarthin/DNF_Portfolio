#include "PreCompile.h"
#include <GameEngineBase/GameEngineInput.h>
#include "PlayerInterface.h"
#include "ItemInventory.h"
#include "InterfaceItemBag.h"
#include "GamePlayCharacter.h"
#include "GamePlayKeyManager.h"


GamePlayKeyManager::GamePlayKeyManager() 
	: Player(nullptr)
	, PlayerStatManager(nullptr)
	, PlayerUserInterface(nullptr)
{
}

GamePlayKeyManager::~GamePlayKeyManager() 
{
}


void GamePlayKeyManager::Start()
{
	Player = GetParent<GamePlayCharacter>();

	PlayerStatManager = Player->GetStatManagerDoublePtr();
	PlayerUserInterface = Player->GetInterfaceDoublePtr();
}
void GamePlayKeyManager::CheckKeyByMove(float _DeltaTime, float _MoveSpeed)
{

}

void GamePlayKeyManager::CheckKeyByInterface(float _DeltaTime, float _MoveSpeed)
{
	if (GameEngineInput::GetInst()->IsDown("Inventory") == true)
	{
		ItemInventory* Inventory = (*PlayerUserInterface)->GetUI_ItemBag()->GetItemInventory();
		if (Inventory->IsUpdate())
		{
			Inventory->Off();
		}
		else
		{
			Inventory->On();
		}
	}

}