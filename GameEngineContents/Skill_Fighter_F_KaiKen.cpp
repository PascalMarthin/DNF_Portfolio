#include "PreCompile.h"
#include "Skill_Fighter_F_KaiKen.h"
#include "GamePlayCharacter.h"

Skill_Fighter_F_KaiKen::Skill_Fighter_F_KaiKen() 
{
}

Skill_Fighter_F_KaiKen::~Skill_Fighter_F_KaiKen() 
{
}
void Skill_Fighter_F_KaiKen::Start()
{
	CreateCastingTexture(1.f);
	
}

bool Skill_Fighter_F_KaiKen::ActiveSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime)
{
	switch (int_ComboStuck)
	{
	case 2:
		CastingEnd(_Stat, _Avata);
		_Avata->CreateEctAvata("Keiken", "Skill_Keiken");
		_Stat->SetBuff(this);
		_Stat->GetStatBuffList()[StatClass::STR]["Keiken"] = (static_cast<__int64>(500)* GetSkillLevel());// 스킬 레벨에 따라서?
		BuffTime = 60.f;
		return true;
		break;
	default:
		break;
	}
	return false;
}

bool Skill_Fighter_F_KaiKen::BuffUpdate(CharacterStatManager* _Stat) 
{

}

void Skill_Fighter_F_KaiKen::BuffEnd()
{
	GetActor<GamePlayCharacter>()->GetAvataManager()->DestroyEctAvata("Keiken");
}

void Skill_Fighter_F_KaiKen::StartSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata)
{
	int_ComboStuck = 0;
	Casting(_Stat, _Avata);

}
