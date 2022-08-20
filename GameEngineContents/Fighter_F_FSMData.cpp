#include "PreCompile.h"
#include "GamePlayCharacter.h"
#include "GamePlayKeyManager.h"
#include "PlayerInterface.h"
#include "MoveManager.h"
#include "AvataManager.h"
#include "Skill_Fighter_F_Ham_Kick.h"
#include "Skill_Fighter_F_BaseHit.h"
#include "Skill_Fighter_F_BaseKick.h"
#include "Skill_Fighter_F_DashHit.h"
#include "Skill_Fighter_F_Upper.h"

void GamePlayCharacter::Create_Fighter_F_Default_FSManager()
{
	GameEngineCollision* Collision = nullptr;

	Manager_StatManager->GetFSMManager().CreateStateMember
	("None", [=](float _DeltaTime, const StateInfo & _Info)
	{
		Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
	});
	Manager_StatManager->GetFSMManager().CreateStateMember
	("Move_Walk", std::bind(&GamePlayCharacter::FSM_Move_Walk_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&GamePlayCharacter::FSM_Move_Walk_Start, this, std::placeholders::_1)
		, std::bind(&GamePlayCharacter::FSM_Move_Walk_End, this, std::placeholders::_1));
	Manager_StatManager->GetFSMManager().CreateStateMember
	("Move_Dash", std::bind(&GamePlayCharacter::FSM_Move_Dash_Update, this, std::placeholders::_1, std::placeholders::_2)
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
	{
		Collision_HitCollision[Collision_AllSkill::Jump_Kick].push_back(Collision = CreateComponent<GameEngineCollision>("Jump_Kick"));
		Collision->GetTransform().SetLocalScale({ 110, 90, 20 });
		Collision->GetTransform().SetLocalPosition({ 30, -100 });
		Collision->ChangeOrder(CollisionOrder::Player_Att);
		//Collision->SetDebugSetting(CollisionType::CT_AABB, float4({ 0, 255, 0, 50 }));
		Collision->Off();
	}
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
	{
		Collision_HitCollision[Collision_AllSkill::Att_Dash].push_back(Collision = CreateComponent<GameEngineCollision>("Att_Dash"));
		Collision->GetTransform().SetLocalScale({ 60, 90, 20 });
		Collision->GetTransform().SetLocalPosition({ 40, -60 });
		Collision->ChangeOrder(CollisionOrder::Player_Att);
		//Collision->SetDebugSetting(CollisionType::CT_AABB, float4({ 0, 50, 0, 0.5f }));
		Collision->Off();
	}

	Manager_StatManager->GetFSMManager().CreateStateMember
	("Att_HamKick", std::bind(&GamePlayCharacter::FSM_Att_HamKick_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&GamePlayCharacter::FSM_Att_HamKick_Start, this, std::placeholders::_1)
		, std::bind(&GamePlayCharacter::FSM_Att_HamKick_End, this, std::placeholders::_1));
	//map_AllSkill["Fighter_HamKick"] = CreateComponent<Skill_Fighter_F_Ham_Kick>();
	//map_AllSkill["Fighter_BaseHit"] = CreateComponent<Skill_Fighter_F_BaseHit>();
	//map_AllSkill["Fighter_BaseKick"] = CreateComponent<Skill_Fighter_F_BaseKick>();
	//map_AllSkill["Fighter_DashHit"] = CreateComponent<Skill_Fighter_F_DashHit>();
	//map_AllSkill["Fighter_Upper"] = CreateComponent<Skill_Fighter_F_Upper>();
	
	
	for (size_t i = 0; i < 3; i++)
	{
		GameEngineTextureRenderer* EffectRenderer = CreateComponent<GameEngineTextureRenderer>("KnockLarge" + std::to_string(i));
		EffectRenderer->CreateFrameAnimationFolder("KnockLarge", FrameAnimation_DESC("KnockLarge", 0.05f, false));
		EffectRenderer->CreateFrameAnimationFolder("None", FrameAnimation_DESC("None", 0.08f, false));
		EffectRenderer->GetTransform().SetWorldScale({160.f, 160.f});
		EffectRenderer->AnimationBindEnd("KnockLarge",
			std::bind(&GamePlayObject::Ani_BindEndOff, this, std::placeholders::_1));
		EffectRenderer->Off();
		map_NomalEffect["KnockLarge"].push_back(EffectRenderer);
	}

	for (size_t i = 0; i < 3; i++)
	{
		GameEngineTextureRenderer* EffectRenderer = CreateComponent<GameEngineTextureRenderer>("KnockSmall" + std::to_string(i));
		EffectRenderer->CreateFrameAnimationFolder("KnockSmall", FrameAnimation_DESC("KnockSmall", 0.05f, false));
		EffectRenderer->CreateFrameAnimationFolder("None", FrameAnimation_DESC("None", 0.08f, false));
		EffectRenderer->GetTransform().SetLocalScale({ 160.f, 160.f });
		EffectRenderer->AnimationBindEnd("KnockSmall",
			std::bind(&GamePlayObject::Ani_BindEndOff, this, std::placeholders::_1));
		EffectRenderer->Off();
		map_NomalEffect["KnockSmall"].push_back(EffectRenderer);
	}

	for (size_t i = 0; i < 3; i++)
	{
		GameEngineTextureRenderer* EffectRenderer = CreateComponent<GameEngineTextureRenderer>("SuperarmorBreak" + std::to_string(i));
		EffectRenderer->CreateFrameAnimationFolder("SuperarmorBreak", FrameAnimation_DESC("SuperarmorBreak", 0.05f, false));
		EffectRenderer->CreateFrameAnimationFolder("None", FrameAnimation_DESC("None", 0.08f, false));
		EffectRenderer->GetTransform().SetLocalScale({ 800.f, 600.f });
		EffectRenderer->AnimationBindEnd("SuperarmorBreak",
			std::bind(&GamePlayObject::Ani_BindEndOff, this, std::placeholders::_1));
		EffectRenderer->Off();
		map_NomalEffect["SuperarmorBreak"].push_back(EffectRenderer);
	}

	Manager_StatManager->GetFSMManager().ChangeState("None");
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
		Manager_MoveManager->SetCharacterMove(Dir * MoveSpeed * DefaultMove * _DeltaTime);
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
	float MoveSpeed = Manager_StatManager->GetMoveSpeed() * 2.2f;

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
		Manager_MoveManager->SetCharacterMove(Dir * MoveSpeed * DefaultMove * _DeltaTime);
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
	//GameEngineDebug::OutPutString(std::to_string(GetTransform().GetLocalPosition().y));
}

void GamePlayCharacter::FSM_Move_Stand_Update(float _DeltaTime, const StateInfo& _Info)
{
	if (GameEngineInput::GetInst()->IsDown("Key_F"))
	{
		Manager_StatManager->GetFSMManager().ChangeState("Att_HamKick"); 
		return;
	}

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
	Manager_MoveManager->SetJump(Manager_StatManager->GetAbilityStat()->JumpPower);
	
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
			Manager_StatManager->SetJump();
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


	float MoveSpeed = Manager_StatManager->GetMoveSpeed();
	MoveSpeed *= _Info.PrevState == "Move_Dash" ? 1.8f : 1.f;
	float4& LandingPos = Manager_MoveManager->LandingPostion;


	float4 Dir = PlayerUserInterface->GetUI_KeyManager()->Input_Move_Press();
	{
		if (Dir.y != 0.f)
		{
			//LandingPos.y += Dir.y * DefaultMove * MoveSpeed * 0.8f * _DeltaTime;
			Dir.y *= DefaultMove * MoveSpeed * _DeltaTime * 0.8f;
		}
		if (Dir.x != 0.f)
		{
			//LandingPos.x += Dir.x * DefaultMove * MoveSpeed * _DeltaTime;
			Dir.x *= DefaultMove * MoveSpeed * _DeltaTime;
		}
		LandingPos += Manager_MoveManager->SetCharacterMove(Dir);
	}


	if (BaseJumpKick == true)
	{
		if (Collision_HitCollision[Collision_AllSkill::Jump_Kick][0]->IsCollision(CollisionType::CT_AABB, CollisionOrder::Monster, CollisionType::CT_AABB))
		{
			int a = 0;
		}
	}

	//if (JumpGoingDown == true)
	//{
	//	Manager_AvataManager->ChangeAvataAnimation("Move_JumpDown");
	//	GoingDown = false;
	//}

	//if (LandingPos.y  >= GetTransform().GetWorldPosition().y )
	//{

	//	Manager_MoveManager->SetCharacterLocation(LandingPos);
	//	return;
	//}

}

void GamePlayCharacter::Jump_GoingDown()
{
	if (JumpGoingDown == false &&
		BaseJumpKick == false)
	{
		if (Manager_StatManager->IsAerial())
		{
			Manager_AvataManager->ChangeAvataAnimation("Hit_Falling");
		}
		else
		{
			Manager_AvataManager->ChangeAvataAnimation("Move_JumpDown");
		}
		JumpGoingDown = true;
	}
}

void GamePlayCharacter::LandingEnd()
{
	EndJump = true;
	if (Manager_StatManager->IsAerial())
	{

	}
	else
	{
		Manager_AvataManager->ChangeAvataAnimation("Move_Landing");
		Manager_StatManager->SetJumpEnd();
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
	SetOff(map_AllSkill["Fighter_BaseHit"]);
	map_AllSkill["Fighter_BaseHit"]->SetCollisionIndex(0);
}

void GamePlayCharacter::FSM_Att_BasePunch1_Update(float _DeltaTime, const StateInfo& _Info)
{
	SkillCollisionActive("Fighter_BaseHit", 1);

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
	SetOff(map_AllSkill["Fighter_BaseHit"]);
}



void GamePlayCharacter::FSM_Att_BasePunch2_Start(const StateInfo& _Info)
{
	Manager_StatManager->SetDoBaseAtt();
	DelayPunch = false;
	Manager_AvataManager->ChangeAvataAnimation("Att_BasePunch2");
	SetOff(map_AllSkill["Fighter_BaseHit"]);
	map_AllSkill["Fighter_BaseHit"]->SetCollisionIndex(1);
	FSM_Move_Helper();
}
void GamePlayCharacter::FSM_Att_BasePunch2_Update(float _DeltaTime, const StateInfo& _Info)
{
	if (DelayPunch == false)
	{
		SkillCollisionActive("Fighter_BaseHit", 1);
		if (Manager_AvataManager->Avata_Skin->IsEndFrame())
		{
			Manager_AvataManager->ChangeAvataAnimation("Att_BasePunch2_Delay");
			DelayPunch = true;
		}
		else if (Manager_AvataManager->Avata_Skin->GetCurrentFrameStuck() < 2)
		{
			Manager_MoveManager->SetCharacterMove({ MoveIndex * DefaultMove * 0.5f * Manager_StatManager->GetMoveSpeed() * _DeltaTime, 0 });
		}
	}
	else
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
	MoveIndex = 0.f;
	SetOff(map_AllSkill["Fighter_BaseHit"]);
}

void GamePlayCharacter::FSM_Att_BasePunch3_Start(const StateInfo& _Info)
{
	Manager_StatManager->SetDoBaseAtt();
	DelayPunch = false;
	Manager_AvataManager->ChangeAvataAnimation("Att_BasePunch3");
	SetOff(map_AllSkill["Fighter_BaseHit"]);
	map_AllSkill["Fighter_BaseHit"]->SetCollisionIndex(2);
	FSM_Move_Helper();

}

void GamePlayCharacter::FSM_Att_BasePunch3_Update(float _DeltaTime, const StateInfo& _Info)
{
	if (DelayPunch == false)
	{
		SkillCollisionActive("Fighter_BaseHit", 1);
		if (Manager_AvataManager->Avata_Skin->IsEndFrame())
		{
			Manager_AvataManager->ChangeAvataAnimation("Att_BasePunch3_Delay");
			DelayPunch = true;
		}
		else if (Manager_AvataManager->Avata_Skin->GetCurrentFrameStuck() < 2)
		{
			Manager_MoveManager->SetCharacterMove({ MoveIndex * 0.5f * DefaultMove * Manager_StatManager->GetMoveSpeed() * _DeltaTime, 0 });
		}
	}
	else 
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
	MoveIndex = 0.f;
	SetOff(map_AllSkill["Fighter_BaseHit"]);
}


void GamePlayCharacter::FSM_Att_BaseKick_Start(const StateInfo& _Info)
{
	Manager_StatManager->SetDoBaseAtt();
	Manager_AvataManager->ChangeAvataAnimation("Att_Basekick");
	SetOff(map_AllSkill["Fighter_BaseKick"]);
	FSM_Move_Helper();
}

void GamePlayCharacter::FSM_Att_BaseKick_Update(float _DeltaTime, const StateInfo& _Info)
{
	SkillCollisionActive("Fighter_BaseKick", 1);

	if (Manager_AvataManager->Avata_Skin->IsEndFrame())
	{
		Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
		return;
	}
	else if (Manager_AvataManager->Avata_Skin->GetCurrentFrameStuck() < 2)
	{
		Manager_MoveManager->SetCharacterMove({ MoveIndex * 0.7f * DefaultMove * Manager_StatManager->GetMoveSpeed() * _DeltaTime, 0 });
	}
}

void GamePlayCharacter::FSM_Att_BaseKick_End(const StateInfo& _Info)
{
	Manager_StatManager->SetEngage();
	Manager_StatManager->SetDoBaseAttEnd();
	MoveIndex = 0.f;
	SetOff(map_AllSkill["Fighter_BaseKick"]);
}

void GamePlayCharacter::FSM_Move_Helper()
{
	bool Left = false;
	bool Right = false;
	if (GameEngineInput::GetInst()->IsDown("Right_Arrow") || GameEngineInput::GetInst()->IsPress("Right_Arrow"))
	{
		if (GetObjectDir())
		{
			MoveIndex = 6.f;
		}
		else
		{
			MoveIndex = 0.f;
		}
		Right = true;
	}

	if ((GameEngineInput::GetInst()->IsDown("Left_Arrow")) || GameEngineInput::GetInst()->IsPress("Left_Arrow"))
	{
		if (GetObjectDir())
		{
			MoveIndex = 0.f;
		}
		else
		{
			MoveIndex = -6.f;
		}
		Left = true;
	}

	if (Left == true && Right == true)
	{
		MoveIndex = 0.f;
	}
	else if (Left == false && Right == false)
	{
		if (GetObjectDir())
		{
			MoveIndex = 0.5f;
		}
		else
		{
			MoveIndex = -0.5f;
		}
	}
}

void GamePlayCharacter::FSM_Att_HamKick_Start(const StateInfo& _Info)
{
	Manager_AvataManager->ChangeAvataAnimation("Att_Basekick");
}
void GamePlayCharacter::FSM_Att_HamKick_Update(float _DeltaTime, const StateInfo& _Info)
{
	if (Manager_AvataManager->Avata_Skin->IsEndFrame())
	{
		Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
		return;
	}

	SkillCollisionActive("Fighter_HamKick", 2);
	
}
void GamePlayCharacter::FSM_Att_HamKick_End(const StateInfo& _Info)
{
	SetOff(map_AllSkill["Fighter_HamKick"]);
}


void GamePlayCharacter::FSM_Att_Dash_Start(const StateInfo& _Info)
{
	DelayPunch = false;
	Manager_StatManager->SetDash();
	Manager_StatManager->SetDoBaseAtt();
	Manager_AvataManager->ChangeAvataAnimation("Att_Dash");
	SetOff(map_AllSkill["Fighter_DashHit"]);
	FSM_Move_Helper();
}

void GamePlayCharacter::FSM_Att_Dash_Update(float _DeltaTime, const StateInfo& _Info)
{

	if (DelayPunch == false)
	{
		SkillCollisionActive("Fighter_DashHit", 2);
		if (Manager_AvataManager->Avata_Skin->GetCurrentFrameStuck() < 2)
		{
			Manager_MoveManager->SetCharacterMove({ MoveIndex * DefaultMove * 0.2f * Manager_StatManager->GetMoveSpeed() * _DeltaTime, 0 });
		}
		else if (Manager_AvataManager->Avata_Skin->IsEndFrame() && DelayPunch == false)
		{
			Manager_AvataManager->ChangeAvataAnimation("Att_Dash_Delay");
			DelayPunch = true;
		}
	}
	else
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
	SetOff(map_AllSkill["Fighter_DashHit"]);
	Manager_StatManager->SetDashEnd();
	Manager_StatManager->SetDoBaseAttEnd();
}
