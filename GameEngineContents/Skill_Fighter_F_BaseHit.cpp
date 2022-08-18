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
	{
		GameEngineCollision* BaseHit = GetActor()->CreateComponent<GameEngineCollision>("BaseHit1");
		BaseHit->GetTransform().SetLocalScale({ 60, 70, 20 });
		BaseHit->GetTransform().SetLocalPosition({ 30, 10 });
		BaseHit->ChangeOrder(CollisionOrder::Player_Att);
		BaseHit->SetDebugSetting(CollisionType::CT_AABB, {1, 1, 0, 0.f});
		Collision_AllCollisionList.push_back(BaseHit);
	
	}

	{
		GameEngineCollision* BaseHit = GetActor()->CreateComponent<GameEngineCollision>("BaseHit2");
		BaseHit->GetTransform().SetLocalScale({ 60, 70, 40 });
		BaseHit->GetTransform().SetLocalPosition({ 30, 10, -5 });
		BaseHit->ChangeOrder(CollisionOrder::Player_Att);
		BaseHit->SetDebugSetting(CollisionType::CT_AABB, { 1, 1, 0, 0.0f });
		Collision_AllCollisionList.push_back(BaseHit);
	}

	{
		GameEngineCollision* BaseHit = GetActor()->CreateComponent<GameEngineCollision>("BaseHit3");
		BaseHit->GetTransform().SetLocalScale({ 60, 70, 40 });
		BaseHit->GetTransform().SetLocalPosition({ 30, 10, 5 });
		BaseHit->ChangeOrder(CollisionOrder::Player_Att);
		BaseHit->SetDebugSetting(CollisionType::CT_AABB, { 1, 1, 0, 0.f });
		Collision_AllCollisionList.push_back(BaseHit);
	}

}

void Skill_Fighter_F_BaseHit::Update(float _DeltaTime)
{

}

bool Skill_Fighter_F_BaseHit::TriggerSkill(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	return false;
}