#include "PreCompile.h"
#include "CharacterSkillManager.h"
#include "GamePlayDataBase.h"
#include "SkillHeader.h"

std::map <std::string, float> CharacterSkillManager::Staic_CoolTime;

CharacterSkillManager::CharacterSkillManager() 
	/*Input_SkillSlot_01(nullptr)
	, Input_SkillSlot_02(nullptr)
	, Input_SkillSlot_03(nullptr)
	, Input_SkillSlot_04(nullptr)
	, Input_SkillSlot_05(nullptr)
	, Input_SkillSlot_06(nullptr)
	, Input_SkillSlot_07(nullptr)
	, Input_SkillSlot_08(nullptr)
	, Input_SkillSlot_09(nullptr)
	, Input_SkillSlot_10(nullptr)
	, Input_SkillSlot_11(nullptr)
	, Input_SkillSlot_12(nullptr)
	, Input_SkillSlot_13(nullptr)
	, Input_SkillSlot_14(nullptr)*/
{
}

CharacterSkillManager::~CharacterSkillManager() 
{
}

void CharacterSkillManager::Start()
{
	// Debug
	List_AllSkill["Fighter_HamKick"] = GetActor()->CreateComponent<Skill_Fighter_F_Ham_Kick>();
	Staic_CoolTime["Fighter_HamKick"] = 0.f;
	List_AllSkill["Fighter_Upper"] = GetActor()->CreateComponent<Skill_Fighter_F_Upper>();
	Staic_CoolTime["Fighter_Upper"] = 0.f;
	List_AllSkill["Fighter_Bungwon"] = GetActor()->CreateComponent<Skill_Fighter_F_Bungwon>();
	Staic_CoolTime["Fighter_Bungwon"] = 0.f;
	List_AllSkill["Fighter_LowKick"] = GetActor()->CreateComponent<Skill_Fighter_F_LowKick>();
	Staic_CoolTime["Fighter_LowKick"] = 0.f;
	List_AllSkill["Fighter_CrashLowKick"] = GetActor()->CreateComponent<Skill_Fighter_F_CrashLowKick>();
	Staic_CoolTime["Fighter_CrashLowKick"] = 0.f;
	List_AllSkill["Fighter_ClosePunch"] = GetActor()->CreateComponent<Skill_Fighter_F_ClosePunch>();
	Staic_CoolTime["Fighter_ClosePunch"] = 0.f;
	List_AllSkill["Fighter_LightingDance"] = GetActor()->CreateComponent<Skill_Fighter_F_LightingDance>();
	Staic_CoolTime["Fighter_LightingDance"] = 0.f;
	List_AllSkill["Fighter_F_Rising"] = GetActor()->CreateComponent<Skill_Fighter_F_Rising>();
	Staic_CoolTime["Fighter_F_Rising"] = 0.f;
	List_AllSkill["Fighter_F_KaiKen"] = GetActor()->CreateComponent<Skill_Fighter_F_KaiKen>();
	Staic_CoolTime["Fighter_F_KaiKen"] = 0.f;
	

	

	map_SkillSlot['Q'] = nullptr;
	map_SkillSlot['W'] = nullptr;
	map_SkillSlot['E'] = nullptr;
	map_SkillSlot['R'] = nullptr;
	map_SkillSlot['T'] = nullptr;
	map_SkillSlot['Y'] = nullptr;
	map_SkillSlot['A'] = nullptr;
	map_SkillSlot['S'] = nullptr;
	map_SkillSlot['D'] = nullptr;
	map_SkillSlot['F'] = nullptr;
	map_SkillSlot['G'] = nullptr;
	map_SkillSlot['H'] = nullptr;
	//map_SkillSlot['A'] = nullptr;
	//map_SkillSlot['A'] = nullptr;
	//map_SkillSlot['A'] = nullptr;

	//map_SkillSlot['A'] = ;
	//map_SkillSlot["Fighter_BaseHit"] = CreateComponent<Skill_Fighter_F_BaseHit>();
	//map_SkillSlot["Fighter_BaseKick"] = CreateComponent<Skill_Fighter_F_BaseKick>();
	//map_SkillSlot["Fighter_DashHit"] = CreateComponent<Skill_Fighter_F_DashHit>();
	//map_SkillSlot["Fighter_Upper"] = CreateComponent<Skill_Fighter_F_Upper>();

	//---------------------
}

GamePlaySkill* CharacterSkillManager::PossibleSkillReturn(char _Char)
{
	if (map_SkillSlot[_Char] == nullptr || map_SkillSlot[_Char]->CurrentCoolTime > 0.f)
	{
		return nullptr;
	}
	return map_SkillSlot[_Char];
}

void CharacterSkillManager::Update(float _DeltaTime)
{
	for (auto& CoolTime : List_AllSkill)
	{
		if (CoolTime.second->CurrentCoolTime <= 0.f)
		{
			CoolTime.second->CurrentCoolTime -= _DeltaTime;
		}
	}
	
}

void CharacterSkillManager::LevelStartEvent()
{
	for (auto& Skill : List_AllSkill)
	{
		Skill.second->CurrentCoolTime = Staic_CoolTime[Skill.first];
	}	

	map_SkillSlot['Q'] = nullptr;
	map_SkillSlot['W'] = nullptr;
	map_SkillSlot['E'] = List_AllSkill["Fighter_LightingDance"];
	map_SkillSlot['R'] = nullptr;
	map_SkillSlot['T'] = nullptr;
	map_SkillSlot['Y'] = List_AllSkill["Fighter_F_KaiKen"];
	map_SkillSlot['A'] = List_AllSkill["Fighter_ClosePunch"];
	map_SkillSlot['S'] = List_AllSkill["Fighter_Upper"];
	map_SkillSlot['D'] = List_AllSkill["Fighter_Bungwon"];
	map_SkillSlot['F'] = List_AllSkill["Fighter_F_Rising"];
	map_SkillSlot['G'] = List_AllSkill["Fighter_LowKick"];
	map_SkillSlot['H'] = List_AllSkill["Fighter_CrashLowKick"];

	GamePlayDataBase::GetCurrentCharacterData();
}


void CharacterSkillManager::LevelEndEvent()
{
	for (auto& CoolTime : List_AllSkill)
	{
		Staic_CoolTime[CoolTime.first] = CoolTime.second->CurrentCoolTime;
	}

	GamePlayDataBase::GetCurrentCharacterData();
}

//void CharacterSkillManager::OnEvent()
//{
//
//}
//
//void CharacterSkillManager::OffEvent()
//{
	//Input_SkillSlot_01 = nullptr;
	//Input_SkillSlot_02 = nullptr;
	//Input_SkillSlot_03 = nullptr;
	//Input_SkillSlot_04 = nullptr;
	//Input_SkillSlot_05 = nullptr;
	//Input_SkillSlot_06 = nullptr;
	//Input_SkillSlot_07 = nullptr;
	//Input_SkillSlot_08 = nullptr;
	//Input_SkillSlot_09 = nullptr;
	//Input_SkillSlot_10 = nullptr;
	//Input_SkillSlot_11 = nullptr;
	//Input_SkillSlot_12 = nullptr;
	//Input_SkillSlot_13 = nullptr;
	//Input_SkillSlot_14 = nullptr;
//}