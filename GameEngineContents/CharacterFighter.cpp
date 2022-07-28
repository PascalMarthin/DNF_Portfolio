#include "PreCompile.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineComponent.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include <GameEngineCore/GameEngineFolderTexture.h>
#include <GameEngineCore/GameEngineStateManager.h>
#include "CharacterFighter.h"
#include "GamePlayKeyManager.h"
#include "PlayerInterface.h"

#define FighterAnimationInter 0.15f

std::map<std::string, FrameAnimation_DESC*> CharacterFighter::CharacterAnimation_DESCs;


CharacterFighter::CharacterFighter() 
{
}

CharacterFighter::~CharacterFighter() 
{
}


void CharacterFighter::Start()
{
	GamePlayCharacter::Start();
	for (GameEnginePlusTextureRenderer* Avata : AllAvatas)
	{
		for (auto& DESC : CharacterAnimation_DESCs)
		{
			Avata->CreateFrameAnimationFolderPlus(DESC.first, (*DESC.second));
		}
		Avata->ChangeFrameAnimationPlus("Move_Stand");
	}
	{
		Avata_Coat->SetDefaultCharacterAvata("ft_coat0000a");
		Avata_Hair_b->SetDefaultCharacterAvata("ft_hair0000a");
		Avata_Hair_a->SetDefaultCharacterAvata("ft_hair0000b");
		Avata_Pants->SetDefaultCharacterAvata("ft_pants0000d");
		Avata_Shoes->SetDefaultCharacterAvata("ft_shoes0000a");
		Avata_Skin->SetDefaultCharacterAvata("ft_body0011");
	}


}

void CharacterFighter::Update(float _DeltaTime)
{

}

void CharacterFighter::SetAnimationForFrameAnimationDESC()
{
	CharacterAnimation_DESCs["Att_Dash"] = new FrameAnimation_DESC("", 0, 4, FighterAnimationInter);
	CharacterAnimation_DESCs["Att_BasePunch1"] = new FrameAnimation_DESC("", 5, 6, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Att_OneinchPunch"] = new FrameAnimation_DESC("", 7, 9, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Att_Upper"] = new FrameAnimation_DESC("", 10, 16, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Att_BasePunch2"] = new FrameAnimation_DESC("", 17, 20, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Att_BasePunch3"] = new FrameAnimation_DESC("", 21, 28, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Att_BaseKick1"] = new FrameAnimation_DESC("", 29, 35, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Move_QuickStand"] = new FrameAnimation_DESC("", 36, 38, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Move_Dash"] = new FrameAnimation_DESC("", 39, 46, FighterAnimationInter, true);  // ´ë½¬
	CharacterAnimation_DESCs["Move_Jump"] = new FrameAnimation_DESC("", 47, 53, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Att_JumpKick"] = new FrameAnimation_DESC("", 54, 57, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Att_Spire"] = new FrameAnimation_DESC("", 58, 65, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Att_LowKick1"] = new FrameAnimation_DESC("", 66, 70, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Att_LowKick2"] = new FrameAnimation_DESC("", 71, 75, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Hit_Stand1"] = new FrameAnimation_DESC("", 76, 77, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Hit_Stand2"] = new FrameAnimation_DESC("", 78, 78, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Hit_Falling"] = new FrameAnimation_DESC("", 79, 79, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Hit_FallUntilFloor"] = new FrameAnimation_DESC("", 80, 80, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Hit_Down"] = new FrameAnimation_DESC("", 81, 85, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Hit_Stand3"] = new FrameAnimation_DESC("", 84, 87, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Att_Mount"] = new FrameAnimation_DESC("", 86, 93, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Att_Casting"] = new FrameAnimation_DESC("", 92, 95, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Att_Suplex1"] = new FrameAnimation_DESC("", 96, 100, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Att_Suplex2"] = new FrameAnimation_DESC("", 101, 107, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Att_Grap"] = new FrameAnimation_DESC("", 108, 108, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Att_JumpKick2"] = new FrameAnimation_DESC("", 109, 112, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Move_Stand"] = new FrameAnimation_DESC("", 113, 116, FighterAnimationInter, true);
	CharacterAnimation_DESCs["Att_Changing"] = new FrameAnimation_DESC("", 117, 121, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Att_Throwing"] = new FrameAnimation_DESC("", 122, 127, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Att_Nen"] = new FrameAnimation_DESC("", 128, 131, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Move_Stand_Battle"] = new FrameAnimation_DESC("", 132, 135, FighterAnimationInter, true);
	CharacterAnimation_DESCs["Move_Walk"] = new FrameAnimation_DESC("", 136, 143, FighterAnimationInter);
	CharacterAnimation_DESCs["Att_TakeDown"] = new FrameAnimation_DESC("", 144, 146, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Att_MiddleKick"] = new FrameAnimation_DESC("", 147, 150, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Att_RisingUpper"] = new FrameAnimation_DESC("", 151, 153, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Att_Punch_Off"] = new FrameAnimation_DESC("", 154, 156, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Att_Dash_Punch1"] = new FrameAnimation_DESC("", 157, 159, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Att_Dash_Punch2"] = new FrameAnimation_DESC("", 160, 160, FighterAnimationInter, false);
}

void CharacterFighter::DestroyFrameAnimationDESC()
{
	for (auto& Iter : CharacterFighter::CharacterAnimation_DESCs)
	{
		if (Iter.second != nullptr)
		{
			delete Iter.second;
			Iter.second = nullptr;
		}
	}
	CharacterAnimation_DESCs.clear();
}

void CharacterFighter::Set_Default_FSMManager()
{
	StatManager->GetFSMManager().CreateStateMember("Move_Walk", this, &CharacterFighter::FSM_Move_Walk_Update, &CharacterFighter::FSM_Move_Walk_Start, &CharacterFighter::FSM_Move_Walk_End);
	StatManager->GetFSMManager().CreateStateMember("Move_Dash", this, &CharacterFighter::FSM_Move_Dash_Update, &CharacterFighter::FSM_Move_Dash_Start, &CharacterFighter::FSM_Move_Dash_End);
	StatManager->GetFSMManager().CreateStateMember("Move_Stand", this, &CharacterFighter::FSM_Move_Stand_Update, &CharacterFighter::FSM_Move_Stand_Start, &CharacterFighter::FSM_Move_Stand_End);
	StatManager->GetFSMManager().CreateStateMember("Move_Jump", this, &CharacterFighter::FSM_Move_Jump_Update, &CharacterFighter::FSM_Move_Jump_Start, &CharacterFighter::FSM_Move_Jump_End);

	StatManager->GetFSMManager().ChangeState("Move_Stand");
}


void CharacterFighter::FSM_Move_Walk_Start(const StateInfo& _Info)
{
	ChangeAvataAnimation("Move_Walk");
}

void CharacterFighter::FSM_Move_Walk_Update(float _DeltaTime, const StateInfo& _Info)
{
	bool IsMove = false;
	float MoveSpeed = 2.0f;

	if (PlayerUserInterface->GetUI_KeyManager()->GetDoubleMoveKeyInput() != EngineInput::None)
	{
		StatManager->GetFSMManager().ChangeState("Move_Dash");
	}

	if (GameEngineInput::GetInst()->IsPress("UP_Arrow") == true)
	{
		IsMove = true;
		GetTransform().SetLocalMove(float4({ 0, DefaultMove }) * MoveSpeed * _DeltaTime);
	}

	if (GameEngineInput::GetInst()->IsPress("Down_Arrow") == true)
	{
		IsMove = true;
		GetTransform().SetLocalMove(float4({ 0, -DefaultMove }) * MoveSpeed * _DeltaTime);
	}

	if (GameEngineInput::GetInst()->IsPress("Left_Arrow") == true)
	{
		IsMove = true;
		GetTransform().SetLocalMove(float4({ -DefaultMove, 0 }) * MoveSpeed * _DeltaTime);
		GetTransform().PixLocalNegativeX();
	}
	if (GameEngineInput::GetInst()->IsPress("Right_Arrow") == true)
	{
		IsMove = true;
		GetTransform().SetLocalMove(float4({ DefaultMove, 0 }) * MoveSpeed * _DeltaTime);
		GetTransform().PixLocalPositiveX();
	}


	if (IsMove == false)
	{
		StatManager->GetFSMManager().ChangeState("Move_Stand");
	}
}

void CharacterFighter::FSM_Move_Walk_End(const StateInfo& _Info)
{

}


void CharacterFighter::FSM_Move_Dash_Start(const StateInfo& _Info)
{
	ChangeAvataAnimation("Move_Dash");
}

void CharacterFighter::FSM_Move_Dash_Update(float _DeltaTime, const StateInfo& _Info)
{
	bool IsMove = false;
	float MoveSpeed = 3.0f;


	if (GameEngineInput::GetInst()->IsPress("UP_Arrow") == true)
	{
		IsMove = true;
		GetTransform().SetLocalMove(float4({ 0, DefaultMove }) * MoveSpeed * _DeltaTime);
	}

	if (GameEngineInput::GetInst()->IsPress("Down_Arrow") == true)
	{
		IsMove = true;
		GetTransform().SetLocalMove(float4({ 0, -DefaultMove }) * MoveSpeed * _DeltaTime);
	}

	if (GameEngineInput::GetInst()->IsPress("Left_Arrow") == true)
	{

		IsMove = true;
		GetTransform().SetLocalMove(float4({ -DefaultMove, 0 }) * MoveSpeed * _DeltaTime);
		GetTransform().PixLocalNegativeX();
	}

	if (GameEngineInput::GetInst()->IsPress("Right_Arrow") == true)
	{
		IsMove = true;
		GetTransform().SetLocalMove(float4({ DefaultMove, 0 }) * MoveSpeed * _DeltaTime);
		GetTransform().PixLocalPositiveX();
	}

	if (IsMove == false)
	{
		StatManager->GetFSMManager().ChangeState("Move_Stand");
	}
}

void CharacterFighter::FSM_Move_Dash_End(const StateInfo& _Info)
{

}


void CharacterFighter::FSM_Move_Stand_Start(const StateInfo& _Info)
{
	ChangeAvataAnimation("Move_Stand");
}

void CharacterFighter::FSM_Move_Stand_Update(float _DeltaTime, const StateInfo& _Info)
{
	if (GameEngineInput::GetInst()->IsDown("UP_Arrow") == true ||
		GameEngineInput::GetInst()->IsDown("Down_Arrow") == true ||
		GameEngineInput::GetInst()->IsDown("Left_Arrow") == true ||
		GameEngineInput::GetInst()->IsDown("Right_Arrow") == true)
	{
		StatManager->GetFSMManager().ChangeState("Move_Walk");
	}

	if (GameEngineInput::GetInst()->IsDown("Jump"))
	{
		StatManager->GetFSMManager().ChangeState("Move_Jump");
	}
}


void CharacterFighter::FSM_Move_Stand_End(const StateInfo& _Info)
{

}


void CharacterFighter::FSM_Move_Jump_Start(const StateInfo& _Info)
{
	ChangeAvataAnimation("Move_Jump");
	StatManager->SetJump();
}

void CharacterFighter::FSM_Move_Jump_Update(float _DeltaTime, const StateInfo& _Info)
{
	GetTransform().SetLocalMove(float4({ DefaultMove, 0 }) * StatManager->CurrentJumpIndex * _DeltaTime);
	
	//if (StatManager->Get)
	//{

	//}
}


void CharacterFighter::FSM_Move_Jump_End(const StateInfo& _Info)
{

}


