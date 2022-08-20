#include "PreCompile.h"
#include "Skill_Fighter_F_BaseKick.h"
#include "GamePlayObject.h"
#include "GamePlayCharacter.h"

Skill_Fighter_F_BaseKick::Skill_Fighter_F_BaseKick() 
{
}

Skill_Fighter_F_BaseKick::~Skill_Fighter_F_BaseKick() 
{
}

void Skill_Fighter_F_BaseKick::Start()
{
	SettingFirst(200, 1, HitPostureType::Air, HitType::Hit, { 50.f, 200.f, 0.f, 0.f });
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

void Skill_Fighter_F_BaseKick::CheckCollision()
{
	Collision_AllCollisionList[0]->IsCollision(CollisionType::CT_AABB, CollisionOrder::Monster, CollisionType::CT_AABB,
		std::bind(&Skill_Fighter_F_BaseKick::TriggerSkill, this, std::placeholders::_1, std::placeholders::_2));
}

bool Skill_Fighter_F_BaseKick::TriggerSkill_ect(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	return false;
}