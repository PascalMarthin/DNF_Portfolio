#include "PreCompile.h"
#include "Skill_Fighter_F_KaiKen.h"
#include "GamePlayCharacter.h"
#include "CharacterSkillManager.h"

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
		_Avata->CreateEctAvata(AllSkillEnum::Fighter_F_KaiKen, "Skill_Keiken", { 0.9f, 0.25f, 0.25f, 0.8f });
		GetActor<GamePlayCharacter>()->GetSkillManager()->InsertBuff( AllSkillEnum::Fighter_F_KaiKen, 20.f);
		GetActor<GamePlayCharacter>()->GetSkillManager()->InsertBuffStat(AllSkillEnum::Fighter_F_KaiKen, StatClass::STR, (static_cast<__int64>(500) * GetSkillLevel()));
		return true;
		break;
	default:
		break;
	}
	return false;
}

bool Skill_Fighter_F_KaiKen::BuffUpdate(CharacterStatManager* _Stat) 
{
	return false;
}

void Skill_Fighter_F_KaiKen::BuffEnd()
{
	GamePlayCharacter* Character = GetActor<GamePlayCharacter>();
	Character->GetAvataManager()->DestroyEctAvata(AllSkillEnum::Fighter_F_KaiKen);
	//Character->GetStatManager()->DestroyBuffStat(AllSkillEnum::Fighter_F_KaiKen);
}

void Skill_Fighter_F_KaiKen::StartSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata)
{
	int_ComboStuck = 0;
	Casting(_Stat, _Avata);
}
