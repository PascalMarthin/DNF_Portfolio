#include "PreCompile.h"
#include "GamePlaySkill.h"

GamePlaySkill::GamePlaySkill() 
	: float4_HitPhysicsPower(float4::ZERO)
	, int_SkillDamage(0)
	, int_CurrentCollision(0)
	, Enum_HitType(HitType::None)
{
}

GamePlaySkill::~GamePlaySkill() 
{
}

bool GamePlaySkill::IsHitObject(GamePlayObject* _Object, int _HitOrder)
{
	if (Object_HitList[_Object] >= _HitOrder)
	{
		return true;
	}
	else
	{
		++Object_HitList[_Object];
		return false;
	}
}

int GamePlaySkill::CheckDir(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	if (_This->GetActor()->GetTransform().GetLocalPosition().x > _Other->GetActor()->GetTransform().GetLocalPosition().x)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}