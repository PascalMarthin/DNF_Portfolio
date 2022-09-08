#include "PreCompile.h"
#include <GameEngineBase/GameEngineInput.h>
#include "PlayerInterface.h"
#include "GamePlayCharacter.h"
#include "GamePlayKeyManager.h"
#include "CharacterSkillManager.h"


GamePlayKeyManager::GamePlayKeyManager() 
	: InputDeltaTime(0)
	, CurrentMoveInput(EngineInput::None)
	, CurrentDoubleMoveInput(EngineInput::None)
	, CrrentPushInput_UPDown(EngineInput::None)
	, CrrentPushInput_LeftRight(EngineInput::None)

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
	//	ItemInventory_Consumable* Inventory = (*PlayerUserInterface)->GetUI_ItemBag()->GetItemInventory();
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

bool GamePlayKeyManager::Input_AllArrow_DownAndPress() const
{
	return  GameEngineInput::GetInst()->IsDown("UP_Arrow") ||
			GameEngineInput::GetInst()->IsDown("Down_Arrow") ||
			GameEngineInput::GetInst()->IsDown("Left_Arrow") ||
			GameEngineInput::GetInst()->IsDown("Right_Arrow") ||
			GameEngineInput::GetInst()->IsPress("UP_Arrow") ||
			GameEngineInput::GetInst()->IsPress("Down_Arrow") ||
			GameEngineInput::GetInst()->IsPress("Left_Arrow") ||
			GameEngineInput::GetInst()->IsPress("Right_Arrow");
}

bool GamePlayKeyManager::Input_JumpKey_Down() const
{
	return GameEngineInput::GetInst()->IsDown("Jump");
}

bool GamePlayKeyManager::Input_BaseAttKey_DownAndPress() const
{
	return GameEngineInput::GetInst()->IsDown("BaseAtt") ||
		GameEngineInput::GetInst()->IsPress("BaseAtt");
}

float4 GamePlayKeyManager::Input_Move_Press()
{
	bool MoveUPDown = false;
	bool MoveLeftRight = false;
	float4 Dir = float4::ZERO;
	if (GameEngineInput::GetInst()->IsPress("UP_Arrow") == true)
	{
		MoveUPDown = true;
		if (CurrentMoveInput != EngineInput::LEFT &&
			CurrentMoveInput != EngineInput::RIGHT)
		{
			if (CurrentMoveInput == EngineInput::DOWN)
			{
				CrrentPushInput_UPDown = CurrentMoveInput;
			}
			else if (CurrentMoveInput == EngineInput::UP)
			{
				CrrentPushInput_UPDown = CurrentMoveInput;
			}
		}


		if ((CrrentPushInput_UPDown == EngineInput::DOWN && 
			GameEngineInput::GetInst()->IsPress("Down_Arrow") == false) ||
			CrrentPushInput_LeftRight == EngineInput::None)
		{
			CrrentPushInput_UPDown = EngineInput::UP;
		}
	}
	if (GameEngineInput::GetInst()->IsPress("Down_Arrow") == true)
	{
		MoveUPDown = true;
		if (CurrentMoveInput != EngineInput::LEFT &&
			CurrentMoveInput != EngineInput::RIGHT)
		{
			if (CurrentMoveInput == EngineInput::UP)
			{
				CrrentPushInput_UPDown = CurrentMoveInput;
			}
			else if (CurrentMoveInput == EngineInput::DOWN)
			{
				CrrentPushInput_UPDown = CurrentMoveInput;
			}
		}

		if ((CrrentPushInput_UPDown == EngineInput::UP &&
			GameEngineInput::GetInst()->IsPress("UP_Arrow") == false) ||
			CrrentPushInput_LeftRight == EngineInput::None)
		{
			CrrentPushInput_UPDown = EngineInput::DOWN;
		}
	}

	if (GameEngineInput::GetInst()->IsPress("Left_Arrow") == true)
	{
		MoveLeftRight = true;
		if (CurrentMoveInput != EngineInput::UP &&
			CurrentMoveInput != EngineInput::DOWN)
		{
			if (CurrentMoveInput == EngineInput::RIGHT)
			{
				CrrentPushInput_LeftRight = CurrentMoveInput;
			}
			else if(CurrentMoveInput == EngineInput::LEFT)
			{
				CrrentPushInput_LeftRight = CurrentMoveInput;
			}
		}

		if ((CrrentPushInput_LeftRight == EngineInput::RIGHT &&
			GameEngineInput::GetInst()->IsPress("Right_Arrow") == false) ||
			CrrentPushInput_LeftRight == EngineInput::None)
		{
			CrrentPushInput_LeftRight = EngineInput::LEFT;
		}
	}

	if (GameEngineInput::GetInst()->IsPress("Right_Arrow") == true)
	{
		MoveLeftRight = true;
		if (CurrentMoveInput != EngineInput::UP &&
			CurrentMoveInput != EngineInput::DOWN)
		{
			if (CurrentMoveInput == EngineInput::LEFT)
			{
				CrrentPushInput_LeftRight = CurrentMoveInput;
			}
			else if (CurrentMoveInput == EngineInput::RIGHT)
			{
				CrrentPushInput_LeftRight = CurrentMoveInput;
			}
		}

		if ((CrrentPushInput_LeftRight == EngineInput::LEFT &&
			GameEngineInput::GetInst()->IsPress("Left_Arrow") == false) ||
			CrrentPushInput_LeftRight == EngineInput::None)
		{
			CrrentPushInput_LeftRight = EngineInput::RIGHT;
		}
	}

	if (!MoveUPDown)
	{
		CrrentPushInput_UPDown = EngineInput::None;
	}

	if (!MoveLeftRight)
	{
		CrrentPushInput_LeftRight = EngineInput::None;
	}


	if (CrrentPushInput_UPDown == EngineInput::UP)
	{
		Dir.y = 1;
		//Dir.z = 1;
	}
	else if (CrrentPushInput_UPDown == EngineInput::DOWN)
	{
		Dir.y = -1;
		//Dir.z = -1;
	}

	if (CrrentPushInput_LeftRight == EngineInput::LEFT)
	{
		Dir.x = -1;
	}
	else if (CrrentPushInput_LeftRight == EngineInput::RIGHT)
	{
		Dir.x = 1;
	}

	return Dir;
}

GamePlaySkill* GamePlayKeyManager::Input_SkillKeyCheck(CharacterSkillManager* _SkillManager) const
{
	GamePlaySkill* Skill = nullptr;
	if (GameEngineInput::GetInst()->IsDown("Key_A") && (Skill = _SkillManager->PossibleSkillReturn('A')))
	{
		return Skill;
	}
	if (GameEngineInput::GetInst()->IsDown("Key_S") && (Skill = _SkillManager->PossibleSkillReturn('S')))
	{
		return Skill;
	}
	if (GameEngineInput::GetInst()->IsDown("Key_D") && (Skill = _SkillManager->PossibleSkillReturn('D')))
	{
		return Skill;
	}
	if (GameEngineInput::GetInst()->IsDown("Key_F") && (Skill = _SkillManager->PossibleSkillReturn('F')))
	{
		return Skill;
	}
	if (GameEngineInput::GetInst()->IsDown("Key_G") && (Skill = _SkillManager->PossibleSkillReturn('G')))
	{
		return Skill;
	}
	if (GameEngineInput::GetInst()->IsDown("Key_H") && (Skill = _SkillManager->PossibleSkillReturn('H')))
	{
		return Skill;
	}
	if (GameEngineInput::GetInst()->IsDown("Key_Q") && (Skill = _SkillManager->PossibleSkillReturn('Q')))
	{
		return Skill;
	}
	if (GameEngineInput::GetInst()->IsDown("Key_W") && (Skill = _SkillManager->PossibleSkillReturn('W')))
	{
		return Skill;
	}
	if (GameEngineInput::GetInst()->IsDown("Key_E") && (Skill = _SkillManager->PossibleSkillReturn('E')))
	{
		return Skill;
	}
	if (GameEngineInput::GetInst()->IsDown("Key_R") && (Skill = _SkillManager->PossibleSkillReturn('R')))
	{
		return Skill;
	}
	return Skill;
}

void GamePlayKeyManager::OnEvent()
{
	InputDeltaTime = 0.f;
	CurrentMoveInput = EngineInput::None;
	CurrentDoubleMoveInput = EngineInput::None;
	CrrentPushInput_UPDown = EngineInput::None;
	CrrentPushInput_LeftRight = EngineInput::None;
}