#include "PreCompile.h"
#include "Skill_Fighter_F_BaseHit.h"
#include "GamePlayObject.h"
#include "GamePlayCharacter.h"


Skill_Fighter_F_BaseHit::Skill_Fighter_F_BaseHit()
	: MoveDistance(0.f)
	, DelayPunch(false)
{
}

Skill_Fighter_F_BaseHit::~Skill_Fighter_F_BaseHit() 
{
}

void Skill_Fighter_F_BaseHit::Start()
{
	Class_Power.push_back(SkillComboPower(100, 1, { 50.f, 50.f, 0, 40.f }, HitPostureType::Standing, HitType::Hit));
	Class_Power.push_back(SkillComboPower(120, 1, { 50.f, 50.f, 0, 50.f }, HitPostureType::Standing, HitType::Hit));
	Class_Power.push_back(SkillComboPower(150, 1, { 50.f, 50.f, 0, 50.f }, HitPostureType::Standing, HitType::Hit));
	Class_Power.push_back(SkillComboPower(200, 1, { 50.f, 200.f, 0, 0.f }, HitPostureType::Aerial, HitType::Hit));

	{
		GameEngineCollision* BaseHit = GetActor()->CreateComponent<GameEngineCollision>("BaseHit1");
		BaseHit->GetTransform().SetLocalScale({ 60, 60, 20 });
		BaseHit->GetTransform().SetLocalPosition({ 30, 20 });
		BaseHit->ChangeOrder(CollisionOrder::Player_Att);
		BaseHit->SetDebugSetting(CollisionType::CT_AABB, {1, 1, 0, 0.f});
		Collision_AllCollisionList.push_back(BaseHit);
	
	}

	{
		GameEngineCollision* BaseHit = GetActor()->CreateComponent<GameEngineCollision>("BaseHit2");
		BaseHit->GetTransform().SetLocalScale({ 60, 60, 40 });
		BaseHit->GetTransform().SetLocalPosition({ 30, 20, -5 });
		BaseHit->ChangeOrder(CollisionOrder::Player_Att);
		BaseHit->SetDebugSetting(CollisionType::CT_AABB, { 1, 1, 0, 0.0f });
		Collision_AllCollisionList.push_back(BaseHit);
	}

	{
		GameEngineCollision* BaseHit = GetActor()->CreateComponent<GameEngineCollision>("BaseHit3");
		BaseHit->GetTransform().SetLocalScale({ 60, 60, 40 });
		BaseHit->GetTransform().SetLocalPosition({ 30, 20, 5 });
		BaseHit->ChangeOrder(CollisionOrder::Player_Att);
		BaseHit->SetDebugSetting(CollisionType::CT_AABB, { 1, 1, 0, 0.f });
		Collision_AllCollisionList.push_back(BaseHit);
	}
	{
		GameEngineCollision* BaseKick = GetActor()->CreateComponent<GameEngineCollision>("BaseKick");
		BaseKick->GetTransform().SetLocalScale({ 100.f, 100.f, 40.f });
		BaseKick->GetTransform().SetLocalPosition({ 30, -10.f, 0 });
		BaseKick->ChangeOrder(CollisionOrder::Player_Att);
		BaseKick->SetDebugSetting(CollisionType::CT_AABB, { 1, 1, 0, 0.f });
		Collision_AllCollisionList.push_back(BaseKick);
	}

	Off();

}


bool Skill_Fighter_F_BaseHit::ActiveSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime)
{
	switch (int_ComboStuck)
	{
	case 0:
		{
			if (Is_CollisionCheck == false && _Avata->GetAvata_Skin()->GetCurrentFrameStuck() == 1)
			{
				CheckCollision();
				Is_CollisionCheck = true;
			}
		
			if (_Avata->GetAvata_Skin()->IsEndFrame())
			{
				Att_BaseAtt_Delay += _DeltaTime;
				if (Att_BaseAtt_Delay > 0.2f)
				{
					Off();
					return true;
				}
		
				if (GameEngineInput::GetInst()->IsDown("BaseAtt") || GameEngineInput::GetInst()->IsPress("BaseAtt"))
				{
					On();
					++int_ComboStuck;
					StartSkill(_Stat, _Move, _Avata);
					return false;
				}

			}
			return false;
		}
		break;
	case 1:
		{
			if (DelayPunch == false)
			{
				if (Is_CollisionCheck == false && _Avata->GetAvata_Skin()->GetCurrentFrameStuck() == 1)
				{
					CheckCollision();
					Is_CollisionCheck = true;
				}

				if (_Avata->GetAvata_Skin()->IsEndFrame())
				{
					_Avata->ChangeAvataAnimation("Att_BasePunch2_Delay");
					DelayPunch = true;
				}
				else if (_Avata->GetAvata_Skin()->GetCurrentFrameStuck() < 2)
				{
					_Move->SetCharacterMove({ MoveDistance * DefaultMove * 0.5f * _Stat->GetMoveSpeed() * _DeltaTime, 0 });
				}
			}
			else
			{
				if (_Avata->GetAvata_Skin()->IsEndFrame())
				{
					DelayPunch = false;
					Off();
					return true;
				}
			
				if (GameEngineInput::GetInst()->IsDown("BaseAtt") || GameEngineInput::GetInst()->IsPress("BaseAtt"))
				{
					On();
					++int_ComboStuck;
					StartSkill(_Stat, _Move, _Avata);
					return false;
				}
			}
			return false;
		}
		break;
	case 2:
		{
			if (DelayPunch == false)
			{
				if (Is_CollisionCheck == false && _Avata->GetAvata_Skin()->GetCurrentFrameStuck() == 1)
				{
					CheckCollision();
					Is_CollisionCheck = true;
				}

				if (_Avata->GetAvata_Skin()->IsEndFrame())
				{
					_Avata->ChangeAvataAnimation("Att_BasePunch3_Delay");
					DelayPunch = true;
				}
				else if (_Avata->GetAvata_Skin()->GetCurrentFrameStuck() < 2)
				{
					_Move->SetCharacterMove({ MoveDistance * DefaultMove * 0.5f * _Stat->GetMoveSpeed() * _DeltaTime, 0 });
				}
			}
			else
			{
				if (_Avata->GetAvata_Skin()->IsEndFrame())
				{
					DelayPunch = false;
					Off();
					return true;
				}
			
				if (GameEngineInput::GetInst()->IsDown("BaseAtt") || GameEngineInput::GetInst()->IsPress("BaseAtt"))
				{
					On();
					++int_ComboStuck;
					StartSkill(_Stat, _Move, _Avata);
					return false;
				}
			}
			return false;
		}
		break;
	case 3:
		{
			if (Is_CollisionCheck == false && _Avata->GetAvata_Skin()->GetCurrentFrameStuck() == 1)
			{
				CheckCollision();
				Is_CollisionCheck = true;
			}
			if (_Avata->GetAvata_Skin()->IsEndFrame())
			{
				Off();
				return true;
			}
			else if (_Avata->GetAvata_Skin()->GetCurrentFrameStuck() < 2)
			{
				_Move->SetCharacterMove({ MoveDistance * 0.7f * DefaultMove * _Stat->GetMoveSpeed() * _DeltaTime, 0 });
			}
			return false;
		}

		break;
	default:
		break;
	}
	MsgBoxAssert("예외 발생");
	return true;
}

bool Skill_Fighter_F_BaseHit::TriggerSkill_ect(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	return false;
}

void Skill_Fighter_F_BaseHit::StartSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata) 
{
	switch (int_ComboStuck)
	{
	case 0:
		{
			_Avata->ChangeAvataAnimation("Att_BasePunch1");
			Att_BaseAtt_Delay = 0.f;
		}
	break;
	case 1:
		{
			_Avata->ChangeAvataAnimation("Att_BasePunch2");
			DelayPunch = false;
			MoveDistance = FSM_Move_Helper();
		}
		break;
	case 2:
		{
			_Avata->ChangeAvataAnimation("Att_BasePunch3");
			DelayPunch = false;
			MoveDistance = FSM_Move_Helper();
		}
		break;
	case 3:
		{
			_Avata->ChangeAvataAnimation("Att_Basekick");
			DelayPunch = false;
			MoveDistance = FSM_Move_Helper();
		}
		break;
	default:
		break;
	}

}





//void GamePlayCharacter::FSM_Att_BasePunch1_Start(const StateInfo& _Info)
//{
//	Manager_StatManager->SetDoBaseAtt();
//	Att_BaseAtt_Delay = 0.f;
//	Manager_AvataManager->ChangeAvataAnimation("Att_BasePunch1");
//	SetOff(map_AllSkill["Fighter_BaseHit"]);
//	map_AllSkill["Fighter_BaseHit"]->SetCollisionIndex(0);
//}
//
//void GamePlayCharacter::FSM_Att_BasePunch1_Update(float _DeltaTime, const StateInfo& _Info)
//{
//	SkillCollisionActive("Fighter_BaseHit", 1);
//
//	if (Manager_AvataManager->Avata_Skin->IsEndFrame())
//	{
//		Att_BaseAtt_Delay += _DeltaTime;
//		if (Att_BaseAtt_Delay > 0.2f)
//		{
//			Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
//			return;
//		}
//
//		if (PlayerUserInterface->GetUI_KeyManager()->Input_BaseAttKey_DownAndPress())
//		{
//			Manager_StatManager->GetFSMManager().ChangeState("Att_BasePunch2");
//			return;
//		}
//
//	}
//
//}
//void GamePlayCharacter::FSM_Att_BasePunch1_End(const StateInfo& _Info)
//{
//	Manager_StatManager->SetEngage();
//	Manager_StatManager->SetDoBaseAttEnd();
//	SetOff(map_AllSkill["Fighter_BaseHit"]);
//}
//
//
//
//void GamePlayCharacter::FSM_Att_BasePunch2_Start(const StateInfo& _Info)
//{
//	Manager_StatManager->SetDoBaseAtt();
//	DelayPunch = false;
//	Manager_AvataManager->ChangeAvataAnimation("Att_BasePunch2");
//	SetOff(map_AllSkill["Fighter_BaseHit"]);
//	map_AllSkill["Fighter_BaseHit"]->SetCollisionIndex(1);
//	FSM_Move_Helper();
//}
//void GamePlayCharacter::FSM_Att_BasePunch2_Update(float _DeltaTime, const StateInfo& _Info)
//{
//	if (DelayPunch == false)
//	{
//		SkillCollisionActive("Fighter_BaseHit", 1);
//		if (Manager_AvataManager->Avata_Skin->IsEndFrame())
//		{
//			Manager_AvataManager->ChangeAvataAnimation("Att_BasePunch2_Delay");
//			DelayPunch = true;
//		}
//		else if (Manager_AvataManager->Avata_Skin->GetCurrentFrameStuck() < 2)
//		{
//			Manager_MoveManager->SetCharacterMove({ MoveIndex * DefaultMove * 0.5f * Manager_StatManager->GetMoveSpeed() * _DeltaTime, 0 });
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
//		if (PlayerUserInterface->GetUI_KeyManager()->Input_BaseAttKey_DownAndPress())
//		{
//			Manager_StatManager->GetFSMManager().ChangeState("Att_BasePunch3");
//			return;
//		}
//	}
//
//
//}
//void GamePlayCharacter::FSM_Att_BasePunch2_End(const StateInfo& _Info)
//{
//	Manager_StatManager->SetEngage();
//	Manager_StatManager->SetDoBaseAttEnd();
//	MoveIndex = 0.f;
//	SetOff(map_AllSkill["Fighter_BaseHit"]);
//}
//
//void GamePlayCharacter::FSM_Att_BasePunch3_Start(const StateInfo& _Info)
//{
//	Manager_StatManager->SetDoBaseAtt();
//	DelayPunch = false;
//	Manager_AvataManager->ChangeAvataAnimation("Att_BasePunch3");
//	SetOff(map_AllSkill["Fighter_BaseHit"]);
//	map_AllSkill["Fighter_BaseHit"]->SetCollisionIndex(2);
//	FSM_Move_Helper();
//
//}
//
//void GamePlayCharacter::FSM_Att_BasePunch3_Update(float _DeltaTime, const StateInfo& _Info)
//{
//	if (DelayPunch == false)
//	{
//		SkillCollisionActive("Fighter_BaseHit", 1);
//		if (Manager_AvataManager->Avata_Skin->IsEndFrame())
//		{
//			Manager_AvataManager->ChangeAvataAnimation("Att_BasePunch3_Delay");
//			DelayPunch = true;
//		}
//		else if (Manager_AvataManager->Avata_Skin->GetCurrentFrameStuck() < 2)
//		{
//			Manager_MoveManager->SetCharacterMove({ MoveIndex * 0.5f * DefaultMove * Manager_StatManager->GetMoveSpeed() * _DeltaTime, 0 });
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
//		if (PlayerUserInterface->GetUI_KeyManager()->Input_BaseAttKey_DownAndPress())
//		{
//			Manager_StatManager->GetFSMManager().ChangeState("Att_BaseKick");
//			return;
//		}
//	}
//
//}
//
//void GamePlayCharacter::FSM_Att_BasePunch3_End(const StateInfo& _Info)
//{
//	Manager_StatManager->SetEngage();
//	Manager_StatManager->SetDoBaseAttEnd();
//	MoveIndex = 0.f;
//	SetOff(map_AllSkill["Fighter_BaseHit"]);
//}
//
//
//void GamePlayCharacter::FSM_Att_BaseKick_Start(const StateInfo& _Info)
//{
//	Manager_StatManager->SetDoBaseAtt();
//	Manager_AvataManager->ChangeAvataAnimation("Att_Basekick");
//	SetOff(map_AllSkill["Fighter_BaseKick"]);
//	FSM_Move_Helper();
//}
//
//void GamePlayCharacter::FSM_Att_BaseKick_Update(float _DeltaTime, const StateInfo& _Info)
//{
//	SkillCollisionActive("Fighter_BaseKick", 1);
//
//	if (Manager_AvataManager->Avata_Skin->IsEndFrame())
//	{
//		Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
//		return;
//	}
//	else if (Manager_AvataManager->Avata_Skin->GetCurrentFrameStuck() < 2)
//	{
//		Manager_MoveManager->SetCharacterMove({ MoveIndex * 0.7f * DefaultMove * Manager_StatManager->GetMoveSpeed() * _DeltaTime, 0 });
//	}
//}
//
//void GamePlayCharacter::FSM_Att_BaseKick_End(const StateInfo& _Info)
//{
//	Manager_StatManager->SetEngage();
//	Manager_StatManager->SetDoBaseAttEnd();
//	MoveIndex = 0.f;
//	SetOff(map_AllSkill["Fighter_BaseKick"]);
//}

