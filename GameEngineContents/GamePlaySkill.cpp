#include "PreCompile.h"
#include "GamePlaySkill.h"
#include "GamePlayObject.h"
#include "GamePlayCharacter.h"

GamePlaySkill::GamePlaySkill()
	: float4_HitPhysicsPower(float4::ZERO)
	, int_SkillDamage(0)
	, int_CurrentCollision(0)
	, Enum_HitPostureType(HitPostureType::None)
	, int_MaxHit(1)
	, Enum_HitType(HitType::None)
{
}

GamePlaySkill::~GamePlaySkill() 
{
}

void GamePlaySkill::SettingFirst(unsigned int _Damage, unsigned int _MaxHitObject, HitPostureType _Type, HitType _HitType, const float4& _Power)
{
	Enum_HitPostureType = _Type;
	int_SkillDamage = _Damage;
	int_MaxHit = _MaxHitObject;
	float4_HitPhysicsPower = _Power;
	Enum_HitType = _HitType;
}

bool GamePlaySkill::TriggerSkill(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	GamePlayObject* Actor = _Other->GetActor<GamePlayObject>();

	if (GamePlaySkill::IsHitObject(Actor, int_MaxHit))
	{
		return false;
	}

	TriggerSkill_ect(_This, _Other);

	Actor->BeHit(this, _Other, GamePlayCharacter::GetCurrentCharacterData(), CheckDir(_This, _Other)); //

	return false;
}


bool GamePlaySkill::IsHitObject(GamePlayObject* _Object, int _HitOrder)
{
	if (Object_HitList[_Object] >= _HitOrder)
	{
		return true;
	}
	else
	{
		Object_HitList[_Object] += 1;
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

void GamePlaySkill::OnEvent()
{
	Object_HitList.clear();
	CheckCollision();
}

void GamePlaySkill::OffEvent()
{
	int_CurrentCollision = 0;
}