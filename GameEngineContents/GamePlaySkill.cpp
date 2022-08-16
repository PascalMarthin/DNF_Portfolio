#include "PreCompile.h"
#include "GamePlaySkill.h"

GamePlaySkill::GamePlaySkill() 
	: float4_HitPhysicsPower(float4::ZERO)
	, int_SkillDamage(0)
	, Enum_HitType(HitType::None)
{
}

GamePlaySkill::~GamePlaySkill() 
{
}

