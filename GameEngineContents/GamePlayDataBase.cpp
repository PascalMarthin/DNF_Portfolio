#include "PreCompile.h"
#include "GamePlayDataBase.h"

std::map<AllCharacterClass, std::map<std::string, FrameAnimation_DESC*>> GamePlayDataBase::CharacterAnimation_DESCs;
GamePlayDataBase* GamePlayDataBase::CurrentCharacterData = nullptr;

GamePlayDataBase::GamePlayDataBase(CharacterFormerClass _Class, const std::string& _Name)
	: Enum_FormerClass(_Class)
	, NickName(_Name)
	, CurrentMap(TownMap::None)
{

}

GamePlayDataBase::~GamePlayDataBase() 
{
	if (!DataBase_InventoryData.empty())
	{
		for (auto& ItemData : DataBase_InventoryData)
		{
			for (auto& InventoryDataIter : ItemData.second)
			{
				delete InventoryDataIter;
			}
		}
		DataBase_InventoryData.clear();
	}
}

void GamePlayDataBase::SetAnimationForFrameAnimationDESC(AllCharacterClass _Class)
{
	switch (_Class)
	{
	case AllCharacterClass::Fighter_F:
		if (CharacterAnimation_DESCs[AllCharacterClass::Fighter_F].empty())
		{
			CreateFighter_F_Animation();
		}
		break;
	case AllCharacterClass::None:
	case AllCharacterClass::Swordman_M:
	case AllCharacterClass::Swordman_F:
	case AllCharacterClass::Fighter_M:
	case AllCharacterClass::Gunner_M:
	case AllCharacterClass::Gunner_F:
	case AllCharacterClass::Mage_M:
	case AllCharacterClass::Mage_F:
	case AllCharacterClass::Priest_M:
	case AllCharacterClass::Priest_F:
	case AllCharacterClass::Thief:
	case AllCharacterClass::Knight:
	case AllCharacterClass::Demoniclancer:
	case AllCharacterClass::Gunblader:
	case AllCharacterClass::Darknight:
	case AllCharacterClass::Creator:
	case AllCharacterClass::AllCharacterClass_Max:
		default:
		break;
	}
}

void GamePlayDataBase::CreateFighter_F_Animation()
{
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Att_Dash"] = new FrameAnimation_DESC("", 0, 2, 0.1f, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Att_Dash_Delay"] = new FrameAnimation_DESC("", 3, 4, 0.1f, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Att_BasePunch1"] = new FrameAnimation_DESC("", 5, 6, 0.1f, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Att_OneinchPunch"] = new FrameAnimation_DESC("", 7, 9, FighterAnimationInter , false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Att_Upper"] = new FrameAnimation_DESC("", 10, 16, FighterAnimationInter, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Att_BasePunch2"] = new FrameAnimation_DESC("", 17, 19, 0.06f, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Att_BasePunch2_Delay"] = new FrameAnimation_DESC("", 20, 20, 0.08f, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Att_BasePunch3"] = new FrameAnimation_DESC("", 21, 25, 0.04f, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Att_BasePunch3_Delay"] = new FrameAnimation_DESC("", 26, 28, 0.1f, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Att_BaseKick"] = new FrameAnimation_DESC("", 29, 35, 0.06f, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Move_QuickStand"] = new FrameAnimation_DESC("", 36, 38, FighterAnimationInter, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Move_Dash"] = new FrameAnimation_DESC("", 39, 46, 0.07f, true);  // �뽬
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Move_JumpReady"] = new FrameAnimation_DESC("", 47, 47, 0.08f, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Move_JumpUp"] = new FrameAnimation_DESC("", 48, 49, 0.09f, true);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Move_JumpDown"] = new FrameAnimation_DESC("", 50, 51, 0.09f, true);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Move_Landing"] = new FrameAnimation_DESC("", 52, 53, 0.03f, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Att_JumpKick"] = new FrameAnimation_DESC("", 54, 57, FighterAnimationInter, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Att_Spire"] = new FrameAnimation_DESC("", 58, 65, FighterAnimationInter, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Att_LowKick1"] = new FrameAnimation_DESC("", 66, 70, 0.05f, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Att_LowKick2"] = new FrameAnimation_DESC("", 71, 75, FighterAnimationInter, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Hit_Stand1"] = new FrameAnimation_DESC("", 76, 77, FighterAnimationInter, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Hit_Stand2"] = new FrameAnimation_DESC("", 78, 78, FighterAnimationInter, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Hit_Falling"] = new FrameAnimation_DESC("", 79, 79, FighterAnimationInter, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Hit_FallUntilFloor"] = new FrameAnimation_DESC("", 80, 80, FighterAnimationInter, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Hit_Down"] = new FrameAnimation_DESC("", 81, 85, FighterAnimationInter, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Hit_Stand3"] = new FrameAnimation_DESC("", 84, 87, FighterAnimationInter, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Att_Mount"] = new FrameAnimation_DESC("", 86, 93, FighterAnimationInter, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Att_Casting"] = new FrameAnimation_DESC("", 92, 95, FighterAnimationInter, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Att_Suplex1"] = new FrameAnimation_DESC("", 96, 100, FighterAnimationInter, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Att_Suplex2"] = new FrameAnimation_DESC("", 101, 107, FighterAnimationInter, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Att_Grap"] = new FrameAnimation_DESC("", 108, 108, FighterAnimationInter, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Att_JumpKick2"] = new FrameAnimation_DESC("", 109, 112, FighterAnimationInter, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Move_Stand"] = new FrameAnimation_DESC("", 113, 116, 0.15f, true);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Att_Changing"] = new FrameAnimation_DESC("", 117, 121, FighterAnimationInter, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Att_Throwing"] = new FrameAnimation_DESC("", 122, 127, FighterAnimationInter, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Att_Nen"] = new FrameAnimation_DESC("", 128, 131, FighterAnimationInter, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Move_Stand_Battle"] = new FrameAnimation_DESC("", 132, 135, FighterAnimationInter, true);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Move_Walk"] = new FrameAnimation_DESC("", 136, 143, FighterAnimationInter);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Att_TakeDown"] = new FrameAnimation_DESC("", 144, 146, FighterAnimationInter, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Att_MiddleKick"] = new FrameAnimation_DESC("", 147, 150, FighterAnimationInter, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Att_RisingUpper"] = new FrameAnimation_DESC("", 151, 153, FighterAnimationInter, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Att_Punch_Off"] = new FrameAnimation_DESC("", 154, 156, FighterAnimationInter, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Att_Dash_Punch1"] = new FrameAnimation_DESC("", 157, 159, FighterAnimationInter, false);
	CharacterAnimation_DESCs[AllCharacterClass::Fighter_F]["Att_Dash_Punch2"] = new FrameAnimation_DESC("", 160, 160, FighterAnimationInter, false);
}

void GamePlayDataBase::DestroyFrameAnimationDESC()
{
	for (auto& ClassIter : GamePlayDataBase::CharacterAnimation_DESCs)
	{
		for (auto& Desc : ClassIter.second)
		{
			if (Desc.second != nullptr)
			{
				delete Desc.second;
				Desc.second = nullptr;
			}
		}
	}
	CharacterAnimation_DESCs.clear();
}