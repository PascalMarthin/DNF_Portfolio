#include "PreCompile.h"
#include "GamePlayCharacter.h"
#include "GamePlayKeyManager.h"
#include "PlayerInterface.h"
#include "AvataManager.h"

void GamePlayCharacter::Create_Fighter_F_Default_FSManager()
{
	Manager_StatManager->GetFSMManager().CreateStateMember("Move_Walk", std::bind(&GamePlayCharacter::FSM_Move_Walk_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&GamePlayCharacter::FSM_Move_Walk_Start, this, std::placeholders::_1)
		, std::bind(&GamePlayCharacter::FSM_Move_Walk_End, this, std::placeholders::_1));
	Manager_StatManager->GetFSMManager().CreateStateMember("Move_Dash", std::bind(&GamePlayCharacter::FSM_Move_Dash_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&GamePlayCharacter::FSM_Move_Dash_Start, this, std::placeholders::_1)
		, std::bind(&GamePlayCharacter::FSM_Move_Dash_End, this, std::placeholders::_1));

	Manager_StatManager->GetFSMManager().CreateStateMember
	("Move_Stand", std::bind(&GamePlayCharacter::FSM_Move_Stand_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&GamePlayCharacter::FSM_Move_Stand_Start, this, std::placeholders::_1)
		, std::bind(&GamePlayCharacter::FSM_Move_Stand_End, this, std::placeholders::_1));
	Manager_StatManager->GetFSMManager().CreateStateMember
	("Move_Jump", std::bind(&GamePlayCharacter::FSM_Move_Jump_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&GamePlayCharacter::FSM_Move_Jump_Start, this, std::placeholders::_1)
		, std::bind(&GamePlayCharacter::FSM_Move_Jump_End, this, std::placeholders::_1));
	Manager_StatManager->GetFSMManager().CreateStateMember
	("Att_BasePunch1", std::bind(&GamePlayCharacter::FSM_Att_BasePunch1_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&GamePlayCharacter::FSM_Att_BasePunch1_Start, this, std::placeholders::_1)
		, std::bind(&GamePlayCharacter::FSM_Att_BasePunch1_End, this, std::placeholders::_1));
	Manager_StatManager->GetFSMManager().CreateStateMember
	("Att_BasePunch2", std::bind(&GamePlayCharacter::FSM_Att_BasePunch2_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&GamePlayCharacter::FSM_Att_BasePunch2_Start, this, std::placeholders::_1)
		, std::bind(&GamePlayCharacter::FSM_Att_BasePunch2_End, this, std::placeholders::_1));
	Manager_StatManager->GetFSMManager().CreateStateMember
	("Att_BasePunch3", std::bind(&GamePlayCharacter::FSM_Att_BasePunch3_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&GamePlayCharacter::FSM_Att_BasePunch3_Start, this, std::placeholders::_1)
		, std::bind(&GamePlayCharacter::FSM_Att_BasePunch3_End, this, std::placeholders::_1));
	Manager_StatManager->GetFSMManager().CreateStateMember
	("Att_BaseKick", std::bind(&GamePlayCharacter::FSM_Att_BaseKick_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&GamePlayCharacter::FSM_Att_BaseKick_Start, this, std::placeholders::_1)
		, std::bind(&GamePlayCharacter::FSM_Att_BaseKick_End, this, std::placeholders::_1));
	Manager_StatManager->GetFSMManager().CreateStateMember
	("Att_Dash", std::bind(&GamePlayCharacter::FSM_Att_Dash_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&GamePlayCharacter::FSM_Att_Dash_Start, this, std::placeholders::_1)
		, std::bind(&GamePlayCharacter::FSM_Att_Dash_End, this, std::placeholders::_1));


	Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
}


void GamePlayCharacter::FSM_Move_Walk_Start(const StateInfo& _Info)
{
	Manager_AvataManager->ChangeAvataAnimation("Move_Walk");
	Manager_StatManager->SetWalk();
}

void GamePlayCharacter::FSM_Move_Walk_Update(float _DeltaTime, const StateInfo& _Info)
{
	bool IsMove = false;
	float MoveSpeed = Manager_StatManager->GetMoveSpeed();

	if (PlayerUserInterface->GetUI_KeyManager()->GetDoubleMoveKeyInput() != EngineInput::None)
	{
		Manager_StatManager->GetFSMManager().ChangeState("Move_Dash");
		return;
	}

	float4 Dir = PlayerUserInterface->GetUI_KeyManager()->Input_Move_Press();
	if (Dir.CompareInt2D(float4::ZERO))
	{
		Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
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

	if (PlayerUserInterface->GetUI_KeyManager()->Input_JumpKey_Down())
	{
		Manager_StatManager->GetFSMManager().ChangeState("Move_Jump");
		return;
	}

	if (PlayerUserInterface->GetUI_KeyManager()->Input_BaseAttKey_DownAndPress())
	{
		Manager_StatManager->GetFSMManager().ChangeState("Att_BasePunch1");
		return;
	}
}

void GamePlayCharacter::FSM_Move_Walk_End(const StateInfo& _Info)
{
}


void GamePlayCharacter::FSM_Move_Dash_Start(const StateInfo& _Info)
{
	Manager_AvataManager->ChangeAvataAnimation("Move_Dash");
	Manager_StatManager->SetDash();
}

void GamePlayCharacter::FSM_Move_Dash_Update(float _DeltaTime, const StateInfo& _Info)
{
	//StatManager->GetFSMManager().ChangeState("Att_Dash");

	bool IsMove = false;
	float MoveSpeed = 1.5f;//StatManager->GetMoveSpeed();

	if (PlayerUserInterface->GetUI_KeyManager()->Input_BaseAttKey_DownAndPress())
	{
		Manager_StatManager->GetFSMManager().ChangeState("Att_Dash");
		return;
	}

	float4 Dir = PlayerUserInterface->GetUI_KeyManager()->Input_Move_Press();
	if (Dir.CompareInt2D(float4::ZERO))
	{
		Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
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

	if (PlayerUserInterface->GetUI_KeyManager()->Input_JumpKey_Down())
	{
		Manager_StatManager->GetFSMManager().ChangeState("Move_Jump");
		return;
	}
}

void GamePlayCharacter::FSM_Move_Dash_End(const StateInfo& _Info)
{
}


void GamePlayCharacter::FSM_Move_Stand_Start(const StateInfo& _Info)
{
	if (Manager_StatManager->GetEngage() < 0.f)
	{
		Manager_AvataManager->ChangeAvataAnimation("Move_Stand");
	}
	else
	{
		Manager_AvataManager->ChangeAvataAnimation("Move_Stand_Battle");
	}
	Manager_StatManager->SetStand();
}

void GamePlayCharacter::FSM_Move_Stand_Update(float _DeltaTime, const StateInfo& _Info)
{

	if (Manager_StatManager->GetEngage() < 0.f)
	{
		Manager_AvataManager->ChangeAvataAnimation("Move_Stand");
	}

	if (PlayerUserInterface->GetUI_KeyManager()->Input_AllArrow_DownAndPress())
	{
		Manager_StatManager->GetFSMManager().ChangeState("Move_Walk");
		return;
	}

	if (PlayerUserInterface->GetUI_KeyManager()->Input_JumpKey_Down())
	{
		Manager_StatManager->GetFSMManager().ChangeState("Move_Jump");
		return;
	}

	if (PlayerUserInterface->GetUI_KeyManager()->Input_BaseAttKey_DownAndPress())
	{
		Manager_StatManager->GetFSMManager().ChangeState("Att_BasePunch1");
		return;
	}
}


void GamePlayCharacter::FSM_Move_Stand_End(const StateInfo& _Info)
{

}


void GamePlayCharacter::FSM_Move_Jump_Start(const StateInfo& _Info)
{

	JumpKick_DelayTime = 0.15f;
	BaseJumpKick = false;
	EndJump = false;
	StartJump = true;
	JumpGoingDown = false;
	Manager_AvataManager->ChangeAvataAnimation("Move_JumpReady");
	Manager_StatManager->SetJump(GetTransform().GetLocalPosition());
}

void GamePlayCharacter::FSM_Move_Jump_Update(float _DeltaTime, const StateInfo& _Info)
{

	if (EndJump == true && StartJump == false)
	{
		if (Manager_AvataManager->Avata_Skin->IsEndFrame())
		{
			Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
		}
		return;
	}

	if (StartJump == true)
	{
		if (Manager_AvataManager->Avata_Skin->IsEndFrame())
		{
			Manager_AvataManager->ChangeAvataAnimation("Move_JumpUp");
			StartJump = false;
		}
		return;
	}

	if (JumpKick_DelayTime > 0.f)
	{
		JumpKick_DelayTime -= _DeltaTime;
	}
	else if (PlayerUserInterface->GetUI_KeyManager()->Input_BaseAttKey_DownAndPress() &&
		BaseJumpKick == false)
	{
		Manager_AvataManager->ChangeAvataAnimation("Att_JumpKick");
		BaseJumpKick = true;
	}

	float4 LandingPos = Manager_StatManager->LandingPostion;
	GetTransform().SetLocalMove(float4({ 0, 1 }) * Manager_StatManager->JumpHigh * _DeltaTime);

	float MoveSpeed = 1.5f;

	float4 Dir = PlayerUserInterface->GetUI_KeyManager()->Input_Move_Press();
	{
		if (Dir.y != 0.f)
		{
			Manager_StatManager->LandingPostion.y += Dir.y * DefaultMove * MoveSpeed * 0.5f * _DeltaTime;
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
			Manager_StatManager->LandingPostion.x += Dir.x * DefaultMove * MoveSpeed * _DeltaTime;
			Dir.x *= DefaultMove * MoveSpeed * _DeltaTime;
		}
		GetTransform().SetLocalMove(Dir);
	}


	if (LandingPos.y >= GetTransform().GetLocalPosition().y)
	{
		Manager_AvataManager->ChangeAvataAnimation("Move_Landing");
		GetTransform().SetLocalPosition(LandingPos);
		EndJump = true;
		return;
	}

	if (Manager_StatManager->JumpHigh <= 0.f &&
		JumpGoingDown == false &&
		BaseJumpKick == false)
	{
		Manager_AvataManager->ChangeAvataAnimation("Move_JumpDown");
		JumpGoingDown = true;
	}

}


void GamePlayCharacter::FSM_Move_Jump_End(const StateInfo& _Info)
{
	Manager_StatManager->SetEngage();
	Manager_StatManager->SetJumpEnd();
}


void GamePlayCharacter::FSM_Att_BasePunch1_Start(const StateInfo& _Info)
{
	Manager_StatManager->SetDoBaseAtt();
	Att_BaseAtt_Delay = 0.f;
	Manager_AvataManager->ChangeAvataAnimation("Att_BasePunch1");
}

void GamePlayCharacter::FSM_Att_BasePunch1_Update(float _DeltaTime, const StateInfo& _Info)
{
	if (Manager_AvataManager->Avata_Skin->IsEndFrame())
	{
		Att_BaseAtt_Delay += _DeltaTime;
		if (Att_BaseAtt_Delay > 0.2f)
		{
			Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
			return;
		}

		if (PlayerUserInterface->GetUI_KeyManager()->Input_BaseAttKey_DownAndPress())
		{
			Manager_StatManager->GetFSMManager().ChangeState("Att_BasePunch2");
			return;
		}

	}
}
void GamePlayCharacter::FSM_Att_BasePunch1_End(const StateInfo& _Info)
{
	Manager_StatManager->SetEngage();
	Manager_StatManager->SetDoBaseAttEnd();
}



void GamePlayCharacter::FSM_Att_BasePunch2_Start(const StateInfo& _Info)
{
	Manager_StatManager->SetDoBaseAtt();
	DelayPunch = false;
	Manager_AvataManager->ChangeAvataAnimation("Att_BasePunch2");
}
void GamePlayCharacter::FSM_Att_BasePunch2_Update(float _DeltaTime, const StateInfo& _Info)
{
	if (Manager_AvataManager->Avata_Skin->IsEndFrame() && DelayPunch == false)
	{
		Manager_AvataManager->ChangeAvataAnimation("Att_BasePunch2_Delay");
		DelayPunch = true;
	}
	if (DelayPunch == true)
	{
		if (Manager_AvataManager->Avata_Skin->IsEndFrame())
		{
			Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
			return;
		}

		if (PlayerUserInterface->GetUI_KeyManager()->Input_BaseAttKey_DownAndPress())
		{
			Manager_StatManager->GetFSMManager().ChangeState("Att_BasePunch3");
			return;
		}
	}
}
void GamePlayCharacter::FSM_Att_BasePunch2_End(const StateInfo& _Info)
{
	Manager_StatManager->SetEngage();
	Manager_StatManager->SetDoBaseAttEnd();
}

void GamePlayCharacter::FSM_Att_BasePunch3_Start(const StateInfo& _Info)
{
	Manager_StatManager->SetDoBaseAtt();
	DelayPunch = false;
	Manager_AvataManager->ChangeAvataAnimation("Att_BasePunch3");

}

void GamePlayCharacter::FSM_Att_BasePunch3_Update(float _DeltaTime, const StateInfo& _Info)
{
	if (Manager_AvataManager->Avata_Skin->IsEndFrame() && DelayPunch == false)
	{
		Manager_AvataManager->ChangeAvataAnimation("Att_BasePunch3_Delay");
		DelayPunch = true;
	}
	if (DelayPunch == true)
	{
		if (Manager_AvataManager->Avata_Skin->IsEndFrame())
		{
			Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
			return;
		}

		if (PlayerUserInterface->GetUI_KeyManager()->Input_BaseAttKey_DownAndPress())
		{
			Manager_StatManager->GetFSMManager().ChangeState("Att_BaseKick");
			return;
		}
	}

}

void GamePlayCharacter::FSM_Att_BasePunch3_End(const StateInfo& _Info)
{
	Manager_StatManager->SetEngage();
	Manager_StatManager->SetDoBaseAttEnd();
}


void GamePlayCharacter::FSM_Att_BaseKick_Start(const StateInfo& _Info)
{
	Manager_StatManager->SetDoBaseAtt();
	Manager_AvataManager->ChangeAvataAnimation("Att_Basekick");
}

void GamePlayCharacter::FSM_Att_BaseKick_Update(float _DeltaTime, const StateInfo& _Info)
{
	if (Manager_AvataManager->Avata_Skin->IsEndFrame())
	{
		Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
		return;
	}
}

void GamePlayCharacter::FSM_Att_BaseKick_End(const StateInfo& _Info)
{
	Manager_StatManager->SetEngage();
	Manager_StatManager->SetDoBaseAttEnd();
}


void GamePlayCharacter::FSM_Att_Dash_Start(const StateInfo& _Info)
{
	DelayPunch = false;
	Manager_StatManager->SetDash();
	Manager_StatManager->SetDoBaseAtt();
	Manager_AvataManager->ChangeAvataAnimation("Att_Dash");
}

void GamePlayCharacter::FSM_Att_Dash_Update(float _DeltaTime, const StateInfo& _Info)
{
	if (Manager_AvataManager->Avata_Skin->IsEndFrame() && DelayPunch == false)
	{
		Manager_AvataManager->ChangeAvataAnimation("Att_Dash_Delay");
		DelayPunch = true;
	}
	if (DelayPunch == true)
	{
		if (Manager_AvataManager->Avata_Skin->IsEndFrame())
		{
			Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
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

void GamePlayCharacter::FSM_Att_Dash_End(const StateInfo& _Info)
{
	Manager_StatManager->SetDashEnd();
	Manager_StatManager->SetDoBaseAttEnd();
}
