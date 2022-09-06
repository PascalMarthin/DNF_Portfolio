#include "PreCompile.h"
#include "GamePlayCharacter.h"
#include "GamePlayKeyManager.h"
#include "PlayerInterface.h"
#include "MoveManager.h"
#include "AvataManager.h"
#include "CharacterSkillManager.h"
#include "Skill_Fighter_F_BaseHit.h"
#include "Skill_Fighter_F_DashHit.h"

void GamePlayCharacter::Create_Fighter_F_Default_FSManager()
{
	GameEngineCollision* Collision = nullptr;
	Manager_SkillManager = CreateComponent<CharacterSkillManager>();

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
	("Att_BaseHit", std::bind(&GamePlayCharacter::FSM_Att_BaseHit_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&GamePlayCharacter::FSM_Att_BaseHit_Start, this, std::placeholders::_1)
		, std::bind(&GamePlayCharacter::FSM_Att_BaseHit_End, this, std::placeholders::_1));

	Manager_StatManager->GetFSMManager().CreateStateMember
	("Att_Skill", std::bind(&GamePlayCharacter::FSM_Att_Skill_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&GamePlayCharacter::FSM_Att_Skill_Start, this, std::placeholders::_1)
		, std::bind(&GamePlayCharacter::FSM_Att_Skill_End, this, std::placeholders::_1));

	Skill_BaseHit = CreateComponent<Skill_Fighter_F_BaseHit>();
	Skill_BaseDashAtt = CreateComponent<Skill_Fighter_F_DashHit>();
		

	//map_AllSkill["Fighter_HamKick"] = CreateComponent<Skill_Fighter_F_Ham_Kick>();
	//map_AllSkill["Fighter_BaseHit"] = CreateComponent<Skill_Fighter_F_BaseHit>();
	//map_AllSkill["Fighter_BaseKick"] = CreateComponent<Skill_Fighter_F_BaseKick>();
	//map_AllSkill["Fighter_DashHit"] = CreateComponent<Skill_Fighter_F_DashHit>();
	//map_AllSkill["Fighter_Upper"] = CreateComponent<Skill_Fighter_F_Upper>();
	
	
	for (size_t i = 0; i < 3; i++)
	{
		GameEngineTextureRenderer* EffectRenderer = CreateComponent<GameEngineTextureRenderer>("KnockLarge" + std::to_string(i));
		EffectRenderer->CreateFrameAnimationFolder("KnockLarge", FrameAnimation_DESC("KnockLarge", 0.1f, false));
		EffectRenderer->CreateFrameAnimationFolder("None", FrameAnimation_DESC("None", 0.08f, false));
		EffectRenderer->GetTransform().SetLocalScale({160.f , 160.f });
		EffectRenderer->AnimationBindEnd("KnockLarge",
			std::bind(&GamePlayObject::Ani_BindEndOff, this, std::placeholders::_1));
		EffectRenderer->GetTransform().PixLocalNegativeX();
		EffectRenderer->Off();
		map_NomalEffect["KnockLarge"].push_back(EffectRenderer);
	}

	for (size_t i = 0; i < 3; i++)
	{
		GameEngineTextureRenderer* EffectRenderer = CreateComponent<GameEngineTextureRenderer>("KnockSmall" + std::to_string(i));
		EffectRenderer->CreateFrameAnimationFolder("KnockSmall", FrameAnimation_DESC("KnockSmall", 0.1f, false));
		EffectRenderer->CreateFrameAnimationFolder("None", FrameAnimation_DESC("None", 0.08f, false));
		EffectRenderer->GetTransform().SetLocalScale({ 160.f, 160.f });
		EffectRenderer->AnimationBindEnd("KnockSmall",
			std::bind(&GamePlayObject::Ani_BindEndOff, this, std::placeholders::_1));
		EffectRenderer->GetTransform().PixLocalNegativeX();
		EffectRenderer->Off();
		map_NomalEffect["KnockSmall"].push_back(EffectRenderer);
	}

	for (size_t i = 0; i < 3; i++)
	{
		GameEngineTextureRenderer* EffectRenderer = CreateComponent<GameEngineTextureRenderer>("SuperarmorBreak" + std::to_string(i));
		EffectRenderer->CreateFrameAnimationFolder("SuperarmorBreak", FrameAnimation_DESC("SuperarmorBreak", 0.1f, false));
		EffectRenderer->CreateFrameAnimationFolder("None", FrameAnimation_DESC("None", 0.08f, false));
		EffectRenderer->GetTransform().SetLocalScale({ 800.f, 600.f });
		EffectRenderer->AnimationBindEnd("SuperarmorBreak",
			std::bind(&GamePlayObject::Ani_BindEndOff, this, std::placeholders::_1));
		EffectRenderer->GetTransform().PixLocalNegativeX();
		EffectRenderer->Off();
		map_NomalEffect["SuperarmorBreak"].push_back(EffectRenderer);
	}

	Manager_StatManager->GetFSMManager().ChangeState("None");
}


void GamePlayCharacter::FSM_Move_Walk_Start(const StateInfo& _Info)
{
	Skill_CurrentSkill = nullptr;
	Manager_AvataManager->ChangeAvataAnimation("Move_Walk");
	Manager_StatManager->SetWalk();
}

void GamePlayCharacter::FSM_Move_Walk_Update(float _DeltaTime, const StateInfo& _Info)
{
	if (Skill_CurrentSkill = PlayerUserInterface->GetUI_KeyManager()->Input_SkillKeyCheck(Manager_SkillManager))
	{
		Manager_StatManager->GetFSMManager().ChangeState("Att_Skill");
		return;
	}

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
		Manager_StatManager->GetFSMManager().ChangeState("Att_BaseHit");
		return;
	}
}

void GamePlayCharacter::FSM_Move_Walk_End(const StateInfo& _Info)
{
}


void GamePlayCharacter::FSM_Move_Dash_Start(const StateInfo& _Info)
{
	Skill_CurrentSkill = nullptr;
	Manager_AvataManager->ChangeAvataAnimation("Move_Dash");
	Manager_StatManager->SetDash();
}

void GamePlayCharacter::FSM_Move_Dash_Update(float _DeltaTime, const StateInfo& _Info)
{
	//StatManager->GetFSMManager().ChangeState("Att_Dash");
	if (Skill_CurrentSkill = PlayerUserInterface->GetUI_KeyManager()->Input_SkillKeyCheck(Manager_SkillManager))
	{
		Manager_StatManager->GetFSMManager().ChangeState("Att_Skill");
		return;
	}

	bool IsMove = false;
	float MoveSpeed = Manager_StatManager->GetMoveSpeed() * 2.2f;

	if (PlayerUserInterface->GetUI_KeyManager()->Input_BaseAttKey_DownAndPress())
	{
		Manager_StatManager->GetFSMManager().ChangeState("Att_BaseHit");
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
	Skill_CurrentSkill = nullptr;
	//GameEngineDebug::OutPutString(std::to_string(GetTransform().GetLocalPosition().y));
}

void GamePlayCharacter::FSM_Move_Stand_Update(float _DeltaTime, const StateInfo& _Info)
{
	//if (GameEngineInput::GetInst()->IsDown("Key_F"))
	//{
	//	Manager_StatManager->GetFSMManager().ChangeState("Att_HamKick"); 
	//	return;
	//}
	if (Skill_CurrentSkill = PlayerUserInterface->GetUI_KeyManager()->Input_SkillKeyCheck(Manager_SkillManager))
	{
		Manager_StatManager->GetFSMManager().ChangeState("Att_Skill");
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
		Manager_StatManager->GetFSMManager().ChangeState("Att_BaseHit");
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


void GamePlayCharacter::FSM_Att_BaseHit_Start(const StateInfo& _Info)
{
	Manager_StatManager->SetDoBaseAtt();

	if (_Info.PrevState == "Move_Dash")
	{
		Skill_BaseDashAtt->On();
		Skill_BaseDashAtt->StartSkill(Manager_StatManager, Manager_MoveManager, Manager_AvataManager);
		Function_BaseAtt = Skill_BaseDashAtt->Get_SkillAction();
	}
	else
	{
		Skill_BaseHit->On();
		Skill_BaseHit->StartSkill(Manager_StatManager, Manager_MoveManager, Manager_AvataManager);
		Function_BaseAtt = Skill_BaseHit->Get_SkillAction();
	}
	//SetOff(map_AllSkill["Fighter_BaseHit"]);
	//map_AllSkill["Fighter_BaseHit"]->SetCollisionIndex(0);
}
void GamePlayCharacter::FSM_Att_BaseHit_Update(float _DeltaTime, const StateInfo& _Info)
{
	if (Skill_CurrentSkill = PlayerUserInterface->GetUI_KeyManager()->Input_SkillKeyCheck(Manager_SkillManager))
	{
		Skill_BaseHit->Off();
		Manager_StatManager->GetFSMManager().ChangeState("Att_Skill");
		return;
	}

	if (Function_BaseAtt(Manager_StatManager, Manager_MoveManager, Manager_AvataManager, _DeltaTime))
	{
		Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
	}
}
void GamePlayCharacter::FSM_Att_BaseHit_End(const StateInfo& _Info)
{

}


void GamePlayCharacter::FSM_Att_Skill_Start(const StateInfo& _Info)
{
	if (Skill_CurrentSkill == nullptr)
	{
		Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
		// 임파서블
		return;
	}
	Skill_CurrentSkill->On();
	Skill_CurrentSkill->StartSkill(Manager_StatManager, Manager_MoveManager, Manager_AvataManager);
	Function_CurrentSkill = Skill_CurrentSkill->Get_SkillAction();

}
void GamePlayCharacter::FSM_Att_Skill_Update(float _DeltaTime, const StateInfo& _Info)
{

	if (Function_CurrentSkill(Manager_StatManager, Manager_MoveManager, Manager_AvataManager, _DeltaTime))
	{
		Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
	}
	
}
void GamePlayCharacter::FSM_Att_Skill_End(const StateInfo& _Info)
{

}

