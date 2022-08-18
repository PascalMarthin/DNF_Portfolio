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
	int_SkillDamage = 100;
	Enum_HitType = HitType::Air;
	float4_HitPhysicsPower = { 200, 800, 0, 0 };

	GameEngineCollision* Collision_HamerKick = GetActor()->CreateComponent<GameEngineCollision>("Ham_Kick");
	Collision_HamerKick->GetTransform().SetLocalScale({100.f, 100.f, 40.f});
	Collision_HamerKick->GetTransform().SetLocalPosition({30, -10.f, 0});
	Collision_HamerKick->SetDebugSetting(CollisionType::CT_AABB, {0, 0 ,0, 0});
	Collision_AllCollisionList.push_back(Collision_HamerKick);
	Off();

	//GameEngineDebug::OutPutString(std::to_string(Collision_HamerKick->GetTransform().GetWorldScale().z));
}

void Skill_Fighter_F_Ham_Kick::Update(float _DeltaTime)
{
	Collision_AllCollisionList[0]->IsCollision(CollisionType::CT_AABB, CollisionOrder::Monster, CollisionType::CT_AABB,
		std::bind(&Skill_Fighter_F_Ham_Kick::TriggerSkill, this, std::placeholders::_1, std::placeholders::_2));
}

bool Skill_Fighter_F_Ham_Kick::TriggerSkill(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	GamePlayObject* Actor = _Other->GetActor<GamePlayObject>();
	for (auto Object : Object_HitList)
	{
		if (Object == Actor)
		{
			return false;
		}
	}

	int DirIndex = 0;
	if (_This->GetActor()->GetTransform().GetLocalPosition().x > _Other->GetActor()->GetTransform().GetLocalPosition().x)
	{
		DirIndex = -1;
	}
	else
	{
		DirIndex = 1;
	}

	Actor->BeHit(this, GamePlayCharacter::GetCurrentCharacterData(), DirIndex); //
	Object_HitList.push_back(Actor);
	return false;
}

