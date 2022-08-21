#include "PreCompile.h"
#include "Skill_Fighter_F_Upper.h"
#include "GamePlayObject.h"
#include "GamePlayCharacter.h"

Skill_Fighter_F_Upper::Skill_Fighter_F_Upper() 
{
}

Skill_Fighter_F_Upper::~Skill_Fighter_F_Upper() 
{
}


void Skill_Fighter_F_Upper::Start()
{
	SetCoolTime(3.f);
	Class_Power.push_back(SkillComboPower(170, 1, { 80, 500.f, 0, 0 }, HitPostureType::Aerial, HitType::Hit));
	GameEngineCollision* Upper = GetActor()->CreateComponent<GameEngineCollision>("Upper");
	Upper->GetTransform().SetLocalScale({ 60.f, 50.f, 30.f });
	Upper->GetTransform().SetLocalPosition({ 30, 20.f, 0 });
	Upper->SetDebugSetting(CollisionType::CT_AABB, { 0, 0 ,0, 0 });
	Collision_AllCollisionList.push_back(Upper);
	Off();

	//GameEngineDebug::OutPutString(std::to_string(Collision_HamerKick->GetTransform().GetWorldScale().z));
}

bool Skill_Fighter_F_Upper::ActiveSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime)
{
	if (Is_CollisionCheck == false && _Avata->GetAvata_Skin()->GetCurrentFrameStuck() == 3)
	{
		CheckCollision();
		Is_CollisionCheck = true;
	}
	if (_Avata->GetAvata_Skin()->GetCurrentFrameStuck() < 5 && _Avata->GetAvata_Skin()->GetCurrentFrameStuck() > 1)
	{
		_Move->SetCharacterMove({( GetActor<GamePlayObject>()->GetObjectDir() ? 1.f : -1.f ) * (2.f)* DefaultMove* _Stat->GetMoveSpeed()* _DeltaTime, 0});
		return false;
	}
	if (_Avata->GetAvata_Skin()->IsEndFrame())
	{
		Off();
		return true;
	}
	return false;
}


void Skill_Fighter_F_Upper::StartSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata)
{
	_Avata->ChangeAvataAnimation("Att_Upper");
}

bool Skill_Fighter_F_Upper::TriggerSkill_ect(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	return false;
}