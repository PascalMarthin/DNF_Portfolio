#include "PreCompile.h"
#include "Skill_Fighter_F_DashHit.h"
#include "GamePlayObject.h"
#include "GamePlayCharacter.h"

Skill_Fighter_F_DashHit::Skill_Fighter_F_DashHit() 
	: DelayPunch(false)
	, MoveDistance(0.f)
{
}

Skill_Fighter_F_DashHit::~Skill_Fighter_F_DashHit() 
{
}

void Skill_Fighter_F_DashHit::Start()
{
	Class_Power.push_back(SkillComboPower(150, 1, { 50, 100.f, 0, 0 }, HitPostureType::Aerial, HitType::Hit));
	{
		GameEngineCollision* Upper = GetActor()->CreateComponent<GameEngineCollision>("DashHit");
		Upper->GetTransform().SetLocalScale({ 60.f, 60.f, 30.f });
		Upper->GetTransform().SetLocalPosition({ 30, 20.f, 0 });
		Upper->SetDebugSetting(CollisionType::CT_AABB, { 0, 0 ,0, 0 });
		Collision_AllCollisionList.push_back(Upper);
	}
	Off();

	//GameEngineDebug::OutPutString(std::to_string(Collision_HamerKick->GetTransform().GetWorldScale().z));
}

bool Skill_Fighter_F_DashHit::ActiveSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime)
{
	switch (int_ComboStuck)
	{
	case 0:
		{
			if (DelayPunch == false)
			{
				if (_Avata->GetAvata_Skin()->GetCurrentFrameStuck() < 2)
				{
					if (Is_CollisionCheck == false && _Avata->GetAvata_Skin()->GetCurrentFrameStuck() == 1)
					{
						CheckCollision();
						Is_CollisionCheck = true;
					}
					_Move->SetCharacterMove({ MoveDistance * DefaultMove * 0.2f * _Stat->GetMoveSpeed() * _DeltaTime, 0 });
				}
				else if (_Avata->GetAvata_Skin()->IsEndFrame())
				{
					_Avata->ChangeAvataAnimation("Att_Dash_Delay");
					DelayPunch = true;
				}
			}
			else
			{
				if (_Avata->GetAvata_Skin()->IsEndFrame())
				{
					Off();
					return true;
				}
			}
			return false;
		}
	default:
		break;
	}
	return false;
}

bool Skill_Fighter_F_DashHit::TriggerSkill_ect(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	return false;
}

void Skill_Fighter_F_DashHit::StartSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata)
{
	switch (int_ComboStuck)
	{
	case 0:
	{
		DelayPunch = false;
		_Avata->ChangeAvataAnimation("Att_Dash");
		MoveDistance = FSM_Move_Helper();
	}
	break;
	break;
	default:
		break;
	}

}





//void GamePlayCharacter::FSM_Att_Dash_Start(const StateInfo& _Info)
//{
//	DelayPunch = false;
//	Manager_StatManager->SetDash();
//	Manager_StatManager->SetDoBaseAtt();
//	Manager_AvataManager->ChangeAvataAnimation("Att_Dash");
//	SetOff(map_AllSkill["Fighter_DashHit"]);
//	FSM_Move_Helper();
//}
//
//void GamePlayCharacter::FSM_Att_Dash_Update(float _DeltaTime, const StateInfo& _Info)
//{
//
//	if (DelayPunch == false)
//	{
//		SkillCollisionActive("Fighter_DashHit", 2);
//		if (Manager_AvataManager->Avata_Skin->GetCurrentFrameStuck() < 2)
//		{
//			Manager_MoveManager->SetCharacterMove({ MoveIndex * DefaultMove * 0.2f * Manager_StatManager->GetMoveSpeed() * _DeltaTime, 0 });
//		}
//		else if (Manager_AvataManager->Avata_Skin->IsEndFrame() && DelayPunch == false)
//		{
//			Manager_AvataManager->ChangeAvataAnimation("Att_Dash_Delay");
//			DelayPunch = true;
//		}
//	}
//	else
//	{
//		if (Manager_AvataManager->Avata_Skin->IsEndFrame())
//		{
//			Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
//			return;
//		}
//
//		//if (GameEngineInput::GetInst()->IsDown("BaseAtt") ||
//		//	GameEngineInput::GetInst()->IsPress("BaseAtt"))
//		//{
//		//	StatManager->GetFSMManager().ChangeState("Att_BaseKick");
//		//	return;
//		//}
//	}
//}
//
//void GamePlayCharacter::FSM_Att_Dash_End(const StateInfo& _Info)
//{
//	SetOff(map_AllSkill["Fighter_DashHit"]);
//	Manager_StatManager->SetDashEnd();
//	Manager_StatManager->SetDoBaseAttEnd();
//}