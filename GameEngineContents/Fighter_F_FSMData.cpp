#include "PreCompile.h"
#include "GamePlayCharacter.h"
#include "GamePlayKeyManager.h"
#include "PlayerInterface.h"
#include "MoveManager.h"
#include "AvataManager.h"
#include "CharacterSkillManager.h"
#include "Skill_Fighter_F_BaseHit.h"
#include "Skill_Fighter_F_DashHit.h"
#include "GamePlayNPCInteraction.h"
#include "GamePlayObjectNPC.h"
#include "GamePlayInteractionWindow.h"
#include "GameEngineUIFontRenderer.h"
#include "GamePlayComboSystem.h"

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


	Manager_StatManager->GetFSMManager().CreateStateMember
	("Interaction", std::bind(&GamePlayCharacter::FSM_Interaction_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&GamePlayCharacter::FSM_Interaction_Start, this, std::placeholders::_1)
		, std::bind(&GamePlayCharacter::FSM_Interaction_End, this, std::placeholders::_1));

	Manager_StatManager->GetFSMManager().CreateStateMember
	("Hit_Aerial", std::bind(&GamePlayCharacter::FSM_Hit_Aerial_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&GamePlayCharacter::FSM_Hit_Aerial_Start, this, std::placeholders::_1)
		, std::bind(&GamePlayCharacter::FSM_Hit_Aerial_End, this, std::placeholders::_1));

	Manager_StatManager->GetFSMManager().CreateStateMember
	("Hit_Aerial_GoingDown", std::bind(&GamePlayCharacter::FSM_Hit_Aerial_GoingDown_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&GamePlayCharacter::FSM_Hit_Aerial_GoingDown_Start, this, std::placeholders::_1)
		, std::bind(&GamePlayCharacter::FSM_Hit_Aerial_GoingDown_End, this, std::placeholders::_1));

	Manager_StatManager->GetFSMManager().CreateStateMember
	("Hit_Down", std::bind(&GamePlayCharacter::FSM_Hit_Down_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&GamePlayCharacter::FSM_Hit_Down_Start, this, std::placeholders::_1)
		, std::bind(&GamePlayCharacter::FSM_Hit_Down_End, this, std::placeholders::_1));

	Manager_StatManager->GetFSMManager().CreateStateMember
	("Hit_Stand", std::bind(&GamePlayCharacter::FSM_Hit_Stand_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&GamePlayCharacter::FSM_Hit_Stand_Start, this, std::placeholders::_1)
		, std::bind(&GamePlayCharacter::FSM_Hit_Stand_End, this, std::placeholders::_1));

	Manager_StatManager->GetFSMManager().CreateStateMember
	("Move_Sit", std::bind(&GamePlayCharacter::FSM_Move_Sit_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&GamePlayCharacter::FSM_Move_Sit_Start, this, std::placeholders::_1)
		, std::bind(&GamePlayCharacter::FSM_Move_Sit_End, this, std::placeholders::_1));

	Manager_StatManager->GetFSMManager().CreateStateMember
	("Dead", std::bind(&GamePlayCharacter::FSM_Dead_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&GamePlayCharacter::FSM_Dead_Start, this, std::placeholders::_1)
		, std::bind(&GamePlayCharacter::FSM_Dead_End, this, std::placeholders::_1));

	

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

	//if (_Info.PrevState == "Dead")
	//{
	//	Manager_StatManager->SetInvincibility();
	//}


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
		Manager_StatManager->SetAerialEnd();
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
		Manager_AvataManager->CreateVision();
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
	Manager_StatManager->SetDoSkill();
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
	Skill_CurrentSkill->EndSkill(Manager_StatManager, Manager_MoveManager, Manager_AvataManager);
	Skill_CurrentSkill->Off();
	Manager_StatManager->SetDoSkillEnd();
	Manager_AvataManager->SetAllAvataAutoControl();

}


void GamePlayCharacter::FSM_Interaction_Start(const StateInfo& _Info)
{
	GamePlayNPCInteraction::GetInst()->SetNPCInteractionMenu(NPC_Interaction);
	Manager_AvataManager->ChangeAvataAnimation("Move_Stand");
}
void GamePlayCharacter::FSM_Interaction_Update(float _DeltaTime, const StateInfo& _Info)
{
	//if (Collision_NPCCanInteraction->IsCollision(CollisionType::CT_SPHERE, CollisionOrder::NPC_Interaction, CollisionType::CT_SPHERE,
	//	std::bind(&GamePlayCharacter::NPCInteraction, this, std::placeholders::_1, std::placeholders::_2)))
	//{

	//}
	//else if (NPC_Interaction != nullptr)
	//{
	//	NPC_Interaction->SetOutLineOff();
	//	NPC_Interaction = nullptr;
	//}
	if (GameEngineInput::GetInst()->IsUp("ESC"))
	{

		Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
		return;
	}


	if (GamePlayNPCInteraction::GetInst()->CheckInput() == InteractOption::Exit)
	{
		GamePlayObjectNPC::SetVoice(NPC_Interaction->map_NPCVoice[InteractOptionNPCVoice::Off][GameEngineRandom::MainRandom.RandomInt(0, NPC_Interaction->map_NPCVoice[InteractOptionNPCVoice::Off].size() - 1)]);
		Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
	}
	


	 
}
void GamePlayCharacter::FSM_Interaction_End(const StateInfo& _Info)
{
	GamePlayNPCInteraction::GetInst()->EndInteraction();


}


void GamePlayCharacter::FSM_Hit_Aerial_Start(const StateInfo& _Info)
{
	Manager_MoveManager->SetAerial();
	Manager_StatManager->SetAerial();
	Manager_AvataManager->ChangeAvataAnimation("Hit_Stand1");
	JumpGoingDown = false;
}
void GamePlayCharacter::FSM_Hit_Aerial_Update(float _DeltaTime, const StateInfo& _Info)
{
	if (JumpGoingDown == true)
	{
		Manager_StatManager->GetFSMManager().ChangeState("Hit_Aerial_GoingDown");
	}
}
void GamePlayCharacter::FSM_Hit_Aerial_End(const StateInfo& _Info)
{
	JumpGoingDown = false;
}

void GamePlayCharacter::FSM_Hit_Aerial_GoingDown_Start(const StateInfo& _Info)
{
	Manager_AvataManager->ChangeAvataAnimation("Hit_Falling");

}
void GamePlayCharacter::FSM_Hit_Aerial_GoingDown_Update(float _DeltaTime, const StateInfo& _Info)
{
	if (!Manager_StatManager->IsAerial())
	{
		Manager_StatManager->SetDown();
	}
}
void GamePlayCharacter::FSM_Hit_Aerial_GoingDown_End(const StateInfo& _Info)
{

}


void GamePlayCharacter::FSM_Hit_Down_Start(const StateInfo& _Info)
{
	Manager_AvataManager->ChangeAvataAnimation("Hit_Down");
	DownWait = 0.6f;
}
void GamePlayCharacter::FSM_Hit_Down_Update(float _DeltaTime, const StateInfo& _Info)
{
	DownWait -= _DeltaTime;
	if (DownWait <= 0.f)
	{
		Manager_StatManager->SetDownEnd();
		Manager_StatManager->GetFSMManager().ChangeState("Move_Sit");
	}
}
void GamePlayCharacter::FSM_Hit_Down_End(const StateInfo& _Info)
{
	DownWait = 0.f;
}



void GamePlayCharacter::FSM_Hit_Stand_Start(const StateInfo& _Info)
{
	if (!Manager_StatManager->IsHold())
	{
		switch (GameEngineRandom::MainRandom.RandomInt(0, 3))
		{
		case 0:
			GamePlayCharacter::SetVoice("ft_dmg_01.ogg");
			break;
		case 1:
			GamePlayCharacter::SetVoice("ft_dmg_02.ogg");
			break;
		case 2:
			GamePlayCharacter::SetVoice("ft_dmg_03.ogg");
			break;
		case 3:
			GamePlayCharacter::SetVoice("ft_dmg_04.ogg");
			break;
		default:
			break;
		}
	}

	if (_Info.PrevState == "Move_Jump")
	{
		Manager_StatManager->SetJumpEnd();
		Manager_StatManager->SetAerial();
		Manager_StatManager->GetFSMManager().ChangeState("Hit_Aerial");
	}

	if (_Info.PrevState == "Hit_Stand" && GameEngineRandom::MainRandom.RandomInt(0, 1) == 1)
	{
		Manager_AvataManager->ChangeAvataAnimation("Hit_Stand1");
	}
	else
	{
		Manager_AvataManager->ChangeAvataAnimation("Hit_Stand2");
	}


}
void GamePlayCharacter::FSM_Hit_Stand_Update(float _DeltaTime, const StateInfo& _Info)
{
	if (!Manager_StatManager->IsBeHit())
	{
		Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
	}
}
void GamePlayCharacter::FSM_Hit_Stand_End(const StateInfo& _Info)
{

}



void GamePlayCharacter::FSM_Move_Sit_Start(const StateInfo& _Info)
{
	Manager_AvataManager->ChangeAvataAnimation("Move_QuickStand");
	Manager_StatManager->SetInvincibility();
}
void GamePlayCharacter::FSM_Move_Sit_Update(float _DeltaTime, const StateInfo& _Info)
{
	if (Manager_AvataManager->GetAvata_Skin()->IsEndFrame())
	{
		Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
	}
}
void GamePlayCharacter::FSM_Move_Sit_End(const StateInfo& _Info)
{
	Manager_StatManager->SetInvincibilityEnd();
}

void GamePlayCharacter::FSM_Dead_Start(const StateInfo& _Info)
{
	DeadDelay = 0;
	DeadFlashDelay = 0;
	Manager_StatManager->SetInvincibility();
	Manager_AvataManager->ChangeAvataAnimation("Hit_Down");

	SetVoice("ft_die.ogg");
	if (Texture_Daed_Window == nullptr)
	{
		GameEngineActor* Actor = GetLevel()->CreateActor<GameEngineActor>();

		Texture_Daed_Window = CreateComponent<GameEngineUIRenderer>(); 
		Texture_Daed_Window->SetTexture("Daed_Window.png");
		Texture_Daed_Window->SetScaleRatio(1.2f);
		Texture_Daed_Window->ScaleToTexture();
		Texture_Daed_Window->Off();
		Texture_Daed_Window->SetParent(Actor);
		

		Texture_Dead_Font = CreateComponent<GameEngineUIFontRenderer>();
	//	Texture_Dead_Font->SetPositionMode(FontPositionMode::WORLD);
	//	Texture_Dead_Font->GetTransform().SetLocalPosition({ GetLevel()->GetMainCameraActorTransform().GetWorldPosition().x, GetLevel()->GetMainCameraActorTransform().GetWorldPosition().y - 10, -10});
		Texture_Dead_Font->SetRenderingOrder(0);
		Texture_Dead_Font->SetColor(float4::WHITE);
		Texture_Dead_Font->SetSize(12.f);
		Texture_Dead_Font->SetLeftAndRightSort(LeftAndRightSort::CENTER);
		Texture_Dead_Font->SetTopAndBotSort(TopAndBotSort::VCENTER);
		Texture_Dead_Font->SetParent(Actor);
		Texture_Dead_Font->SetScreenPostion({ GameEngineWindow::GetScale().hx(), GameEngineWindow::GetScale().hy() + 12});
		Texture_Dead_Font->SetText("'x'키를 눌러 코인을 사용하세요", "굴림");
		Texture_Dead_Font->Off();

		Texture_Dead_Coin = CreateComponent<GameEngineUIFontRenderer>();
		Texture_Dead_Coin->SetRenderingOrder(0);
	//	Texture_Dead_Coin->SetPositionMode(FontPositionMode::WORLD);
	//	Texture_Dead_Font->GetTransform().SetLocalPosition({ GetLevel()->GetMainCameraActorTransform().GetWorldPosition().x + 30, GetLevel()->GetMainCameraActorTransform().GetWorldPosition().y - 40, -10 });
	//	Texture_Dead_Coin->GetTransform().SetLocalPosition({0, -100, -10});
		Texture_Dead_Coin->SetColor(float4::WHITE);
		Texture_Dead_Coin->SetSize(15.f);
		Texture_Dead_Coin->SetLeftAndRightSort(LeftAndRightSort::CENTER);
		Texture_Dead_Coin->SetTopAndBotSort(TopAndBotSort::VCENTER);
		Texture_Dead_Coin->SetText(std::to_string(Manager_StatManager->GetAbilityStat()->Coin), "굴림");
		Texture_Dead_Coin->SetScreenPostion({ GameEngineWindow::GetScale().hx() + 30, GameEngineWindow::GetScale().hy() + 40 });
		Texture_Dead_Coin->SetParent(Actor);
		Texture_Dead_Coin->Off();
	}
	Texture_Daed_Window->Off();
}
void GamePlayCharacter::FSM_Dead_Update(float _DeltaTime, const StateInfo& _Info)
{	
	if (DeadDelay < 1.f)
	{
		DeadDelay += _DeltaTime;
		DeadFlashDelay += _DeltaTime;

		if (DeadDelay > 1.f)
		{
			const std::vector<GameEnginePlusTextureRenderer*>& Avatas = Manager_AvataManager->GetAllAvatas();
			for (auto& Avata : Avatas)
			{
				Avata->On();
			}
			Texture_Daed_Window->On();
			Texture_Dead_Font->On();
			Texture_Dead_Coin->On();
		}
		else if (DeadFlashDelay > 0.125f)
		{
			const std::vector<GameEnginePlusTextureRenderer*>& Avatas = Manager_AvataManager->GetAllAvatas();
			for (auto& Avata : Avatas)
			{
				Avata->IsUpdateRef() = !(Avata->IsUpdateRef());
			}
			DeadFlashDelay = 0;
		}

	}
	else
	{
		if (PlayerUserInterface->GetUI_KeyManager()->Input_BaseAttKey_DownAndPress())
		{
			GameEngineSound::SoundPlayOneShot("buff_icon.ogg");
			GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();


			GamePlayComboSystem::GetInst()->PlusCoin();

			Renderer->CreateFrameAnimationFolder("Blast1", FrameAnimation_DESC("Blast1", 0.125f, false));
			Renderer->AnimationBindEnd("Blast1", [](const FrameAnimation_DESC& _DESC)
				{
					_DESC.Renderer->Death();
				});
			Renderer->ChangeFrameAnimation("Blast1");
			Renderer->ScaleToTexture();
			Renderer->GetTransform().SetLocalPosition({0, -100});
			Renderer->SetPivot(PIVOTMODE::BOT);

			Manager_StatManager->GetAbilityStat()->HP = Manager_StatManager->GetAbilityStat()->MAXHP;
			Manager_StatManager->GetAbilityStat()->MP = Manager_StatManager->GetAbilityStat()->MAXMP;
			Manager_StatManager->SetLive();
			Manager_StatManager->GetAbilityStat()->Coin -= 1;
			Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");

			return;
		}
	}


}
void GamePlayCharacter::FSM_Dead_End(const StateInfo& _Info)
{
	Texture_Daed_Window->Off();
	Texture_Dead_Font->Off();
	Texture_Dead_Coin->Off();
	Manager_StatManager->SetInvincibilityEnd();
	//Collision_Body->On();
}