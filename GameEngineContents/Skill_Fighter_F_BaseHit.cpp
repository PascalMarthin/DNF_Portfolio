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

	int_SkillDamage = 100;
	Enum_HitType = HitType::Air;
	float4_HitPhysicsPower = { 10.f, 0, 0, 50.f };
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
	Collision_AllCollisionList[int_CurrentCollision]->IsCollision(CollisionType::CT_AABB, CollisionOrder::Monster, CollisionType::CT_AABB,
		std::bind(&Skill_Fighter_F_BaseHit::TriggerSkill, this, std::placeholders::_1, std::placeholders::_2));
}

bool Skill_Fighter_F_BaseHit::TriggerSkill(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	GamePlayObject* Actor = _Other->GetActor<GamePlayObject>();

	if (GamePlaySkill::IsHitObject(Actor, 1))
	{
		return false;
	}

	Actor->BeHit(this, GamePlayCharacter::GetCurrentCharacterData(), CheckDir(_This, _Other));

	/*switch (int_CurrentCollision)
	{
	case 0:
		break;

	case 1:
		break;

	case 2:
		break;

	case 3:
		break;

	default:
		break;
	}*/


	return false;
}