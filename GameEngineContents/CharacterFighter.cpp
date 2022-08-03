#include "PreCompile.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineComponent.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include <GameEngineCore/GameEngineFolderTexture.h>
#include <GameEngineCore/GameEngineStateManager.h>
#include "CharacterFighter.h"
#include "GamePlayKeyManager.h"
#include "PlayerInterface.h"
#include "GameEnginePlusTextureRenderer.h"
#include "PlayerInterface.h"

#define FighterAnimationInter 0.08f

std::map<std::string, FrameAnimation_DESC*> CharacterFighter::CharacterAnimation_DESCs;


CharacterFighter::CharacterFighter() 
	: EndJump(false)
	, StartJump(false)
	, JumpGoingDown(false)
	, Att_BaseAtt_Delay(0.f)
	, DelayPunch(false)
	, KeyManager(nullptr)
	, JumpKick_DelayTime(0.f)
	, BaseJumpKick(0.f)
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
		Avata_Shoes_a->SetDefaultCharacterAvata("ft_shoes0000a");
		Avata_Shoes_b->SetDefaultCharacterAvata("ft_shoes0000b");
		Avata_Skin->SetDefaultCharacterAvata("ft_body0011");
	}

	SetKeyManager();

}

void CharacterFighter::OnEvent()
{
	EndJump = false;
	StartJump = false;
	JumpGoingDown = false;
	Att_BaseAtt_Delay = 0.f;
	DelayPunch = false;
	KeyManager = nullptr;
	JumpKick_DelayTime = 0.f;
	BaseJumpKick = 0.f;
}

void CharacterFighter::SetKeyManager()
{
	if (KeyManager == nullptr)
	{
		KeyManager = PlayerUserInterface->GetUI_KeyManager();
	}
}

void CharacterFighter::Update(float _DeltaTime)
{

}

void CharacterFighter::SetAnimationForFrameAnimationDESC()
{
	CharacterAnimation_DESCs["Att_Dash"] = new FrameAnimation_DESC("", 0, 2, 0.1f, false);
	CharacterAnimation_DESCs["Att_Dash_Delay"] = new FrameAnimation_DESC("", 3, 4, 0.1f, false);
	CharacterAnimation_DESCs["Att_BasePunch1"] = new FrameAnimation_DESC("", 5, 6, 0.1f, false);
	CharacterAnimation_DESCs["Att_OneinchPunch"] = new FrameAnimation_DESC("", 7, 9, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Att_Upper"] = new FrameAnimation_DESC("", 10, 16, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Att_BasePunch2"] = new FrameAnimation_DESC("", 17, 19, 0.07f, false);
	CharacterAnimation_DESCs["Att_BasePunch2_Delay"] = new FrameAnimation_DESC("", 20, 20, 0.08f, false);
	CharacterAnimation_DESCs["Att_BasePunch3"] = new FrameAnimation_DESC("", 21, 25, 0.07f, false);
	CharacterAnimation_DESCs["Att_BasePunch3_Delay"] = new FrameAnimation_DESC("", 26, 28, 0.1f, false);
	CharacterAnimation_DESCs["Att_BaseKick"] = new FrameAnimation_DESC("", 29, 35, 0.08f, false);
	CharacterAnimation_DESCs["Move_QuickStand"] = new FrameAnimation_DESC("", 36, 38, FighterAnimationInter, false);
	CharacterAnimation_DESCs["Move_Dash"] = new FrameAnimation_DESC("", 39, 46, 0.07f, true);  // 대쉬
	CharacterAnimation_DESCs["Move_JumpReady"] = new FrameAnimation_DESC("", 47, 47, 0.08f, false);
	CharacterAnimation_DESCs["Move_JumpUp"] = new FrameAnimation_DESC("", 48, 49, 0.09f, true);
	CharacterAnimation_DESCs["Move_JumpDown"] = new FrameAnimation_DESC("", 50, 51, 0.09f, true);
	CharacterAnimation_DESCs["Move_Landing"] = new FrameAnimation_DESC("", 52, 53, 0.03f, false);
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
	StatManager->GetFSMManager().CreateStateMember("Att_BasePunch1", this, &CharacterFighter::FSM_Att_BasePunch1_Update, &CharacterFighter::FSM_Att_BasePunch1_Start, &CharacterFighter::FSM_Att_BasePunch1_End);
	StatManager->GetFSMManager().CreateStateMember("Att_BasePunch2", this, &CharacterFighter::FSM_Att_BasePunch2_Update, &CharacterFighter::FSM_Att_BasePunch2_Start, &CharacterFighter::FSM_Att_BasePunch2_End);
	StatManager->GetFSMManager().CreateStateMember("Att_BasePunch3", this, &CharacterFighter::FSM_Att_BasePunch3_Update, &CharacterFighter::FSM_Att_BasePunch3_Start, &CharacterFighter::FSM_Att_BasePunch3_End);
	StatManager->GetFSMManager().CreateStateMember("Att_BaseKick", this, &CharacterFighter::FSM_Att_BaseKick_Update, &CharacterFighter::FSM_Att_BaseKick_Start, &CharacterFighter::FSM_Att_BaseKick_End);
	StatManager->GetFSMManager().CreateStateMember("Att_Dash", this, &CharacterFighter::FSM_Att_Dash_Update, &CharacterFighter::FSM_Att_Dash_Start, &CharacterFighter::FSM_Att_Dash_End);

	
	StatManager->GetFSMManager().ChangeState("Move_Stand");
}


void CharacterFighter::FSM_Move_Walk_Start(const StateInfo& _Info)
{
	ChangeAvataAnimation("Move_Walk");
	StatManager->SetWalk();
}

void CharacterFighter::FSM_Move_Walk_Update(float _DeltaTime, const StateInfo& _Info)
{
	bool IsMove = false;
	float MoveSpeed = 1.5f;

	if (KeyManager->GetDoubleMoveKeyInput() != EngineInput::None)
	{
		StatManager->GetFSMManager().ChangeState("Move_Dash");
		return;
	}

	float4 Dir = KeyManager->Input_Move_Press();
	if (Dir.CompareInt2D(float4::ZERO))
	{
		StatManager->GetFSMManager().ChangeState("Move_Stand");
		return;
	}
	else
	{
		if (Dir.x > 0.f)
		{
			SetRightDir();
		}
		else if (Dir.x < 0.f)
		{
			SetLeftDir();
		}
		GetTransform().SetLocalMove(Dir * MoveSpeed * DefaultMove * _DeltaTime);
	}

	if (KeyManager->Input_JumpKey_Down())
	{
		StatManager->GetFSMManager().ChangeState("Move_Jump");
		return;
	}

	if (KeyManager->Input_BaseAttKey_DownAndPress())
	{
		StatManager->GetFSMManager().ChangeState("Att_BasePunch1");
		return;
	}
}

void CharacterFighter::FSM_Move_Walk_End(const StateInfo& _Info)
{
}


void CharacterFighter::FSM_Move_Dash_Start(const StateInfo& _Info)
{
	ChangeAvataAnimation("Move_Dash");
	StatManager->SetDash();
}

void CharacterFighter::FSM_Move_Dash_Update(float _DeltaTime, const StateInfo& _Info)
{
	//StatManager->GetFSMManager().ChangeState("Att_Dash");

	bool IsMove = false;
	float MoveSpeed = 1.5f ;//StatManager->GetMoveSpeed();

	if (KeyManager->Input_BaseAttKey_DownAndPress())
	{
		StatManager->GetFSMManager().ChangeState("Att_Dash");
		return;
	}

	float4 Dir = KeyManager->Input_Move_Press();
	if (Dir.CompareInt2D(float4::ZERO))
	{
		StatManager->GetFSMManager().ChangeState("Move_Stand");
		return;
	}
	else
	{
		if (Dir.x > 0.f)
		{
			SetRightDir();
			//if (KeyManager->GetPushInput_LeftRight() == EngineInput::LEFT)
			//{
			//	StatManager->GetFSMManager().ChangeState("Move_Walk");
			//	return;
			//}
			// 방향 바뀌면 걷는 액션 보류
		}
		else if (Dir.x < 0.f)
		{
			SetLeftDir();
			//if (KeyManager->GetPushInput_LeftRight() == EngineInput::RIGHT)
			//{
			//	StatManager->GetFSMManager().ChangeState("Move_Walk");

			//	return;
			//}
			// 방향 바뀌면 걷는 액션 보류
		}
		GetTransform().SetLocalMove(Dir * MoveSpeed * DefaultMove * _DeltaTime);
	}

	if (KeyManager->Input_JumpKey_Down())
	{
		StatManager->GetFSMManager().ChangeState("Move_Jump");
		return;
	}
}

void CharacterFighter::FSM_Move_Dash_End(const StateInfo& _Info)
{
}


void CharacterFighter::FSM_Move_Stand_Start(const StateInfo& _Info)
{
	if (StatManager->GetEngage() < 0.f)
	{
		ChangeAvataAnimation("Move_Stand");
	}
	else
	{
		ChangeAvataAnimation("Move_Stand_Battle");
	}
	StatManager->SetStand();
}

void CharacterFighter::FSM_Move_Stand_Update(float _DeltaTime, const StateInfo& _Info)
{

	if (StatManager->GetEngage() < 0.f)
	{
		ChangeAvataAnimation("Move_Stand");
	}

	if (KeyManager->Input_AllArrow_DownAndPress())
	{
		StatManager->GetFSMManager().ChangeState("Move_Walk");
		return;
	}

	if (KeyManager->Input_JumpKey_Down())
	{
		StatManager->GetFSMManager().ChangeState("Move_Jump");
		return;
	}

	if (KeyManager->Input_BaseAttKey_DownAndPress())
	{
		StatManager->GetFSMManager().ChangeState("Att_BasePunch1");
		return;
	}
}


void CharacterFighter::FSM_Move_Stand_End(const StateInfo& _Info)
{

}


void CharacterFighter::FSM_Move_Jump_Start(const StateInfo& _Info)
{

	JumpKick_DelayTime = 0.15f;
	BaseJumpKick = false;
	EndJump = false;
	StartJump = true;
	JumpGoingDown = false;
	ChangeAvataAnimation("Move_JumpReady");
	StatManager->SetJump(GetTransform().GetLocalPosition());
}

void CharacterFighter::FSM_Move_Jump_Update(float _DeltaTime, const StateInfo& _Info)
{
	
	if (EndJump == true && StartJump == false)
	{
		if (Avata_Skin->IsEndFrame())
		{
			StatManager->GetFSMManager().ChangeState("Move_Stand");
		}
		return;
	}

	if (StartJump == true)
	{
		if (Avata_Skin->IsEndFrame())
		{
			ChangeAvataAnimation("Move_JumpUp");
			StartJump = false;
		}
		return;
	}

	if (JumpKick_DelayTime > 0.f)
	{
		JumpKick_DelayTime -= _DeltaTime;
	}
	else if (KeyManager->Input_BaseAttKey_DownAndPress() &&
			 BaseJumpKick == false)
	{
		ChangeAvataAnimation("Att_JumpKick");
		BaseJumpKick = true;
	}

	float4 LandingPos = StatManager->LandingPostion;
	GetTransform().SetLocalMove(float4({ 0, 1 }) * StatManager->JumpHigh * _DeltaTime);

	float MoveSpeed = 1.5f;

	float4 Dir = KeyManager->Input_Move_Press();
	{
		if (Dir.y != 0.f)
		{
			StatManager->LandingPostion.y += Dir.y * DefaultMove * MoveSpeed * 0.5f * _DeltaTime;
			Dir.y *= DefaultMove * MoveSpeed * 0.5f * _DeltaTime * 0.02f;
		}
		if (Dir.x != 0.f)
		{
			if (Dir.x > 0.f)
			{
				SetRightDir();
			}
			else if (Dir.x < 0.f)
			{
				SetLeftDir();
			}
			StatManager->LandingPostion.x += Dir.x * DefaultMove * MoveSpeed * _DeltaTime;
			Dir.x *= DefaultMove * MoveSpeed * _DeltaTime;
		}
		GetTransform().SetLocalMove(Dir);
	}


	if (LandingPos.y >= GetTransform().GetLocalPosition().y)
	{
		ChangeAvataAnimation("Move_Landing");
		GetTransform().SetLocalPosition(LandingPos);
		EndJump = true;
		return;
	}

	if (StatManager->JumpHigh <= 0.f && 
		JumpGoingDown == false &&
		BaseJumpKick == false)
	{
		ChangeAvataAnimation("Move_JumpDown");
		JumpGoingDown = true;
	}

}


void CharacterFighter::FSM_Move_Jump_End(const StateInfo& _Info)
{
	StatManager->SetEngage();
	StatManager->SetJumpEnd();
}


void CharacterFighter::FSM_Att_BasePunch1_Start(const StateInfo& _Info)
{
	StatManager->SetDoBaseAtt();
	Att_BaseAtt_Delay = 0.f;
	ChangeAvataAnimation("Att_BasePunch1");
}

void CharacterFighter::FSM_Att_BasePunch1_Update(float _DeltaTime, const StateInfo& _Info)
{
	if (Avata_Skin->IsEndFrame())
	{
		Att_BaseAtt_Delay += _DeltaTime;
		if (Att_BaseAtt_Delay > 0.2f)
		{
			StatManager->GetFSMManager().ChangeState("Move_Stand");
			return;
		}

		if (KeyManager->Input_BaseAttKey_DownAndPress())
		{
			StatManager->GetFSMManager().ChangeState("Att_BasePunch2");
			return;
		}

	}
}
void CharacterFighter::FSM_Att_BasePunch1_End(const StateInfo& _Info)
{
	StatManager->SetEngage();
	StatManager->SetDoBaseAttEnd();
}



void CharacterFighter::FSM_Att_BasePunch2_Start(const StateInfo& _Info)
{
	StatManager->SetDoBaseAtt();
	DelayPunch = false;
	ChangeAvataAnimation("Att_BasePunch2");

}
void CharacterFighter::FSM_Att_BasePunch2_Update(float _DeltaTime, const StateInfo& _Info)
{
	if (Avata_Skin->IsEndFrame() && DelayPunch == false)
	{
		ChangeAvataAnimation("Att_BasePunch2_Delay");
		DelayPunch = true;
	}
	if (DelayPunch == true)
	{
		if (Avata_Skin->IsEndFrame())
		{
			StatManager->GetFSMManager().ChangeState("Move_Stand");
			return;
		}

		if (KeyManager->Input_BaseAttKey_DownAndPress())
		{
			StatManager->GetFSMManager().ChangeState("Att_BasePunch3");
			return;
		}
	}
}
void CharacterFighter::FSM_Att_BasePunch2_End(const StateInfo& _Info)
{
	StatManager->SetEngage();
	StatManager->SetDoBaseAttEnd();
}

void CharacterFighter::FSM_Att_BasePunch3_Start(const StateInfo& _Info)
{
	StatManager->SetDoBaseAtt();
	DelayPunch = false;
	ChangeAvataAnimation("Att_BasePunch3");

}

void CharacterFighter::FSM_Att_BasePunch3_Update(float _DeltaTime, const StateInfo& _Info)
{
	if (Avata_Skin->IsEndFrame() && DelayPunch == false)
	{
		ChangeAvataAnimation("Att_BasePunch3_Delay");
		DelayPunch = true;
	}
	if (DelayPunch == true)
	{
		if (Avata_Skin->IsEndFrame())
		{
			StatManager->GetFSMManager().ChangeState("Move_Stand");
			return;
		}

		if (KeyManager->Input_BaseAttKey_DownAndPress())
		{
			StatManager->GetFSMManager().ChangeState("Att_BaseKick");
			return;
		}
	}

}

void CharacterFighter::FSM_Att_BasePunch3_End(const StateInfo& _Info)
{
	StatManager->SetEngage();
	StatManager->SetDoBaseAttEnd();
}


void CharacterFighter::FSM_Att_BaseKick_Start(const StateInfo& _Info)
{
	StatManager->SetDoBaseAtt();
	ChangeAvataAnimation("Att_Basekick");
}

void CharacterFighter::FSM_Att_BaseKick_Update(float _DeltaTime, const StateInfo& _Info)
{
	if (Avata_Skin->IsEndFrame())
	{
		StatManager->GetFSMManager().ChangeState("Move_Stand");
		return;
	}
}

void CharacterFighter::FSM_Att_BaseKick_End(const StateInfo& _Info)
{
	StatManager->SetEngage();
	StatManager->SetDoBaseAttEnd();
}


void CharacterFighter::FSM_Att_Dash_Start(const StateInfo& _Info)
{
	DelayPunch = false;
	StatManager->SetDash();
	StatManager->SetDoBaseAtt();
	ChangeAvataAnimation("Att_Dash");
}

void CharacterFighter::FSM_Att_Dash_Update(float _DeltaTime, const StateInfo& _Info)
{
	if (Avata_Skin->IsEndFrame() && DelayPunch == false)
	{
		ChangeAvataAnimation("Att_Dash_Delay");
		DelayPunch = true;
	}
	if (DelayPunch == true)
	{
		if (Avata_Skin->IsEndFrame())
		{
			StatManager->GetFSMManager().ChangeState("Move_Stand");
			return;
		}

		//if (GameEngineInput::GetInst()->IsDown("BaseAtt") ||
		//	GameEngineInput::GetInst()->IsPress("BaseAtt"))
		//{
		//	StatManager->GetFSMManager().ChangeState("Att_BaseKick");
		//	return;
		//}
	}
}

void CharacterFighter::FSM_Att_Dash_End(const StateInfo& _Info)
{
	StatManager->SetDashEnd();
	StatManager->SetDoBaseAttEnd();
}
