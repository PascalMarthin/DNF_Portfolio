#include "PreCompile.h"
#include "Skill_Fighter_F_BaseHit.h"
#include "GamePlayObject.h"
#include "GamePlayCharacter.h"


Skill_Fighter_F_BaseHit::Skill_Fighter_F_BaseHit() 
{
}

Skill_Fighter_F_BaseHit::~Skill_Fighter_F_BaseHit() 
{
}

void Skill_Fighter_F_BaseHit::Start()
{
	SettingFirst(100, 1, HitPostureType::Standing, HitType::Hit ,{ 50.f, 0, 0, 50.f });
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

	Off();

}

void Skill_Fighter_F_BaseHit::CheckCollision()
{
	Collision_AllCollisionList[int_CurrentCollision]->IsCollision(CollisionType::CT_AABB, CollisionOrder::Monster, CollisionType::CT_AABB,
		std::bind(&Skill_Fighter_F_BaseHit::TriggerSkill, this, std::placeholders::_1, std::placeholders::_2));
}

bool Skill_Fighter_F_BaseHit::TriggerSkill_ect(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	return false;
}