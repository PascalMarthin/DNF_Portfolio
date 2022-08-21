#include "PreCompile.h"
#include "Skill_Fighter_F_Bungwon.h"
#include "GamePlayObject.h"
#include "GamePlayCharacter.h"


Skill_Fighter_F_Bungwon::Skill_Fighter_F_Bungwon() 
	: MoveDistance(0.f)
	, Att_Bungwon_Delay(0.f)
{
}

Skill_Fighter_F_Bungwon::~Skill_Fighter_F_Bungwon() 
{
}


void Skill_Fighter_F_Bungwon::Start()
{
	Class_Power.push_back(SkillComboPower(180, 1, { 50.f, 0.f, 0, 70.f }, HitPostureType::Standing, HitType::Hit));

	{
		GameEngineCollision* BaseHit = GetActor()->CreateComponent<GameEngineCollision>("BaseHit1");
		BaseHit->GetTransform().SetLocalScale({ 80, 60, 20 });
		BaseHit->GetTransform().SetLocalPosition({ 30, 20 });
		BaseHit->ChangeOrder(CollisionOrder::Player_Att);
		BaseHit->SetDebugSetting(CollisionType::CT_AABB, { 1, 1, 0, 0.f });
		Collision_AllCollisionList.push_back(BaseHit);
	}
	Off();

}

void Skill_Fighter_F_Bungwon::Update(float _DeltaTime)
{

}

bool Skill_Fighter_F_Bungwon::ActiveSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime)
{
	if (_Avata->GetAvata_Skin()->GetCurrentFrameStuck() == 1)
	{
		Att_Bungwon_Delay += _DeltaTime;
		CheckCollision();
		if (Is_CollisionCheck == false)
		{
			Is_CollisionCheck = true;
			_Avata->SetAllAvataManualControl();
			//_Avata->ChangeFrame_Manual(1);
		}

		if (Att_Bungwon_Delay >= _Avata->GetAvata_Skin()->GetFrameAnimation()->GetInfo().Inter * 2.f)
		{
			//_Avata->ChangeFrame_Manual(2);
			_Avata->SetAllAvataAutoControl(false);
		}
		else
		{
			float4 Pos = GetActor()->GetTransform().GetWorldPosition();
			Pos -= float4::LerpLimit(Pos, { Pos.x + (MoveDistance * DefaultMove * 0.1f), Pos.y, Pos.z }, Att_Bungwon_Delay * 3.f );
			_Move->SetCharacterMove({ -Pos.x, 0 });
		}
	}

	if (_Avata->GetAvata_Skin()->IsEndFrame())
	{
		Off();
		return true;
	}
	return false;
}

bool Skill_Fighter_F_Bungwon::TriggerSkill_ect(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	return false;
}

void Skill_Fighter_F_Bungwon::StartSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata)
{
	_Avata->ChangeAvataAnimation("Att_Punch_Off");
	MoveDistance = FSM_Move_Helper();
	MoveDistance *= 0.5f;
	Att_Bungwon_Delay = 0.f;

}




