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
	SettingFirst(100, 1, HitPostureType::Air, HitType::Hit, { 50, 500.f, 0, 0 });


	GameEngineCollision* Upper = GetActor()->CreateComponent<GameEngineCollision>("Upper");
	Upper->GetTransform().SetLocalScale({ 60.f, 60.f, 30.f });
	Upper->GetTransform().SetLocalPosition({ 30, 20.f, 0 });
	Upper->SetDebugSetting(CollisionType::CT_AABB, { 0, 0 ,0, 0 });
	Collision_AllCollisionList.push_back(Upper);
	Off();

	//GameEngineDebug::OutPutString(std::to_string(Collision_HamerKick->GetTransform().GetWorldScale().z));
}

void Skill_Fighter_F_Upper::CheckCollision()
{
	Collision_AllCollisionList[0]->IsCollision(CollisionType::CT_AABB, CollisionOrder::Monster, CollisionType::CT_AABB,
		std::bind(&Skill_Fighter_F_Upper::TriggerSkill, this, std::placeholders::_1, std::placeholders::_2));
}

bool Skill_Fighter_F_Upper::TriggerSkill_ect(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	return false;
}