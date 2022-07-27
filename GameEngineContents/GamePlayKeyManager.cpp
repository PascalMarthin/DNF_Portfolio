#include "PreCompile.h"
#include <GameEngineBase/GameEngineInput.h>
#include "PlayerInterface.h"
#include "ItemInventory.h"
#include "InterfaceItemBag.h"
#include "GamePlayCharacter.h"
#include "GamePlayKeyManager.h"


GamePlayKeyManager::GamePlayKeyManager() 
	: InputDeltaTime(0)
	, CurrentMoveInput(EngineInput::None)
	, CurrentDoubleMoveInput(EngineInput::None)
{
}

GamePlayKeyManager::~GamePlayKeyManager() 
{
}


void GamePlayKeyManager::Start()
{

}
void GamePlayKeyManager::CheckKeyByWalk(float _DeltaTime, float _MoveSpeed)
{

}

void GamePlayKeyManager::CheckKeyByInterface(float _DeltaTime, float _MoveSpeed)
{
	//if (GameEngineInput::GetInst()->IsDown("Inventory") == true)
	//{
	//	ItemInventory* Inventory = (*PlayerUserInterface)->GetUI_ItemBag()->GetItemInventory();
	//	if (Inventory->IsUpdate())
	//	{
	//		Inventory->Off();
	//	}
	//	else
	//	{
	//		Inventory->On();
	//	}
	//}

}

void GamePlayKeyManager::Update(float _DeltaTime)
{
	InputDeltaTime -= _DeltaTime;
	if (InputDeltaTime <= 0)
	{
		CurrentMoveInput = EngineInput::None;
		CurrentDoubleMoveInput = CurrentMoveInput;
	}

	if (GameEngineInput::GetInst()->IsDown("UP_Arrow"))
	{
		if (CurrentMoveInput == EngineInput::UP)
		{
			CurrentDoubleMoveInput = CurrentMoveInput;
		}
		CurrentMoveInput = EngineInput::UP;
		InputDeltaTime = 0.2f;
	}
	if (GameEngineInput::GetInst()->IsDown("Down_Arrow"))
	{
		if (CurrentMoveInput == EngineInput::DOWN)
		{
			CurrentDoubleMoveInput = CurrentMoveInput;
		}
		CurrentMoveInput = EngineInput::DOWN;
		InputDeltaTime = 0.2f;
	}
	if (GameEngineInput::GetInst()->IsDown("Left_Arrow"))
	{
		if (CurrentMoveInput == EngineInput::LEFT)
		{
			CurrentDoubleMoveInput = CurrentMoveInput;
		}
		CurrentMoveInput = EngineInput::LEFT;
		InputDeltaTime = 0.2f;
	}
	if (GameEngineInput::GetInst()->IsDown("Right_Arrow"))
	{
		if (CurrentMoveInput == EngineInput::RIGHT)
		{
			CurrentDoubleMoveInput = CurrentMoveInput;
		}
		CurrentMoveInput = EngineInput::RIGHT;
		InputDeltaTime = 0.2f;
	}
}

//void GamePlayKeyManager::OnEvent()
//{
//	InputDeltaTime = 0.f;
//	CurrentInput = std::queue<EngineInput>();
//}