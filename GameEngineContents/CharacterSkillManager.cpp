#include "PreCompile.h"
#include "CharacterSkillManager.h"
#include "GamePlayDataBase.h"
#include "SkillHeader.h"

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
	List_AllSkill["Fighter_BaseHit"] = GetActor()->CreateComponent<Skill_Fighter_F_BaseHit>();
	List_AllSkill["Fighter_BaseKick"] = GetActor()->CreateComponent<Skill_Fighter_F_BaseKick>();
	List_AllSkill["Fighter_DashHit"] = GetActor()->CreateComponent<Skill_Fighter_F_DashHit>();
	List_AllSkill["Fighter_Upper"] = GetActor()->CreateComponent<Skill_Fighter_F_Upper>();

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

	map_SkillSlot['A'] = ;
	map_SkillSlot["Fighter_BaseHit"] = CreateComponent<Skill_Fighter_F_BaseHit>();
	map_SkillSlot["Fighter_BaseKick"] = CreateComponent<Skill_Fighter_F_BaseKick>();
	map_SkillSlot["Fighter_DashHit"] = CreateComponent<Skill_Fighter_F_DashHit>();
	map_SkillSlot["Fighter_Upper"] = CreateComponent<Skill_Fighter_F_Upper>();

	//---------------------
}

void CharacterSkillManager::Update(float _DeltaTime)
{

}

void CharacterSkillManager::LevelStartEvent()
{
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