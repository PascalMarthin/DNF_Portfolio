#include "PreCompile.h"
#include "Skill_Fighter_F_Ham_Kick.h"
#include "GamePlayObject.h"
#include "GamePlayCharacter.h"


Skill_Fighter_F_Ham_Kick::Skill_Fighter_F_Ham_Kick() 
{
}

Skill_Fighter_F_Ham_Kick::~Skill_Fighter_F_Ham_Kick() 
{
}

void Skill_Fighter_F_Ham_Kick::Start()
{
	SettingFirst(100, 1, HitPostureType::Air, HitType::Hit, { 500, 300, 0, 0 });


	GameEngineCollision* Collision_HamerKick = GetActor()->CreateComponent<GameEngineCollision>("Ham_Kick");
	Collision_HamerKick->GetTransform().SetLocalScale({100.f, 100.f, 40.f});
	Collision_HamerKick->GetTransform().SetLocalPosition({30, -10.f, 0});
	Collision_HamerKick->SetDebugSetting(CollisionType::CT_AABB, {0, 0 ,0, 0});
	Collision_AllCollisionList.push_back(Collision_HamerKick);
	Off();

	//GameEngineDebug::OutPutString(std::to_string(Collision_HamerKick->GetTransform().GetWorldScale().z));
}

void Skill_Fighter_F_Ham_Kick::CheckCollision()
{
	Collision_AllCollisionList[0]->IsCollision(CollisionType::CT_AABB, CollisionOrder::Monster, CollisionType::CT_AABB,
		std::bind(&Skill_Fighter_F_Ham_Kick::TriggerSkill, this, std::placeholders::_1, std::placeholders::_2));
}

bool Skill_Fighter_F_Ham_Kick::TriggerSkill_ect(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	return false;
}