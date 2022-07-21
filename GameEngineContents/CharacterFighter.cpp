#include "PreCompile.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineComponent.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include "CharacterFighter.h"
#include <GameEngineCore/GameEngineFolderTexture.h>

#define FighterAnimationInter 0.15f

std::map<std::string, FrameAnimation_DESC*> CharacterFighter::CharactorAnimation_DESCs;


CharacterFighter::CharacterFighter() 
{
}

CharacterFighter::~CharacterFighter() 
{
}


void CharacterFighter::Start()
{
	GamePlayCharacter::Start();
	for (GameEnginePlusTextureRenderer* Avata : AllAvatas)
	{
		for (auto& DESC : CharactorAnimation_DESCs)
		{
			Avata->CreateFrameAnimationFolderPlus(DESC.first, (*DESC.second));
		}
		Avata->ChangeFrameAnimationPlus("Move_Stand");
	}
	{
		Avata_Coat->SetDefaultCharactorAvata("ft_coat0000a");
		Avata_Hair_b->SetDefaultCharactorAvata("ft_hair0000a");
		Avata_Hair_a->SetDefaultCharactorAvata("ft_hair0000b");
		Avata_Pants->SetDefaultCharactorAvata("ft_pants0000d");
		Avata_Shoes->SetDefaultCharactorAvata("ft_shoes0000a");
		Avata_Skin->SetDefaultCharactorAvata("ft_body0011");
	}

}

void CharacterFighter::Update(float _DeltaTime)
{

}

void CharacterFighter::SetAnimationForFrameAnimationDESC()
{
	CharactorAnimation_DESCs["Att_Dash"] = new FrameAnimation_DESC("", 0, 4, FighterAnimationInter);
	CharactorAnimation_DESCs["Att_BasePunch1"] = new FrameAnimation_DESC("", 5, 6, FighterAnimationInter, false);
	CharactorAnimation_DESCs["Att_OneinchPunch"] = new FrameAnimation_DESC("", 7, 9, FighterAnimationInter, false);
	CharactorAnimation_DESCs["Att_Upper"] = new FrameAnimation_DESC("", 10, 16, FighterAnimationInter, false);
	CharactorAnimation_DESCs["Att_BasePunch2"] = new FrameAnimation_DESC("", 17, 20, FighterAnimationInter, false);
	CharactorAnimation_DESCs["Att_BasePunch3"] = new FrameAnimation_DESC("", 21, 28, FighterAnimationInter, false);
	CharactorAnimation_DESCs["Att_BaseKick1"] = new FrameAnimation_DESC("", 29, 35, FighterAnimationInter, false);
	CharactorAnimation_DESCs["Move_QuickStand"] = new FrameAnimation_DESC("", 36, 38, FighterAnimationInter, false);
	CharactorAnimation_DESCs["Move_Dash"] = new FrameAnimation_DESC("", 39, 46, FighterAnimationInter, true);  // ´ë½¬
	CharactorAnimation_DESCs["Move_Jump"] = new FrameAnimation_DESC("", 47, 53, FighterAnimationInter, false);
	CharactorAnimation_DESCs["Att_JumpKick"] = new FrameAnimation_DESC("", 54, 57, FighterAnimationInter, false);
	CharactorAnimation_DESCs["Att_Spire"] = new FrameAnimation_DESC("", 58, 65, FighterAnimationInter, false);
	CharactorAnimation_DESCs["Att_LowKick1"] = new FrameAnimation_DESC("", 66, 70, FighterAnimationInter, false);
	CharactorAnimation_DESCs["Att_LowKick2"] = new FrameAnimation_DESC("", 71, 75, FighterAnimationInter, false);
	CharactorAnimation_DESCs["Hit_Stand1"] = new FrameAnimation_DESC("", 76, 77, FighterAnimationInter, false);
	CharactorAnimation_DESCs["Hit_Stand2"] = new FrameAnimation_DESC("", 78, 78, FighterAnimationInter, false);
	CharactorAnimation_DESCs["Hit_Falling"] = new FrameAnimation_DESC("", 79, 79, FighterAnimationInter, false);
	CharactorAnimation_DESCs["Hit_FallUntilFloor"] = new FrameAnimation_DESC("", 80, 80, FighterAnimationInter, false);
	CharactorAnimation_DESCs["Hit_Down"] = new FrameAnimation_DESC("", 81, 85, FighterAnimationInter, false);
	CharactorAnimation_DESCs["Hit_Stand3"] = new FrameAnimation_DESC("", 84, 87, FighterAnimationInter, false);
	CharactorAnimation_DESCs["Att_Mount"] = new FrameAnimation_DESC("", 86, 93, FighterAnimationInter, false);
	CharactorAnimation_DESCs["Att_Casting"] = new FrameAnimation_DESC("", 92, 95, FighterAnimationInter, false);
	CharactorAnimation_DESCs["Att_Suplex1"] = new FrameAnimation_DESC("", 96, 100, FighterAnimationInter, false);
	CharactorAnimation_DESCs["Att_Suplex2"] = new FrameAnimation_DESC("", 101, 107, FighterAnimationInter, false);
	CharactorAnimation_DESCs["Att_Grap"] = new FrameAnimation_DESC("", 108, 108, FighterAnimationInter, false);
	CharactorAnimation_DESCs["Att_JumpKick2"] = new FrameAnimation_DESC("", 109, 112, FighterAnimationInter, false);
	CharactorAnimation_DESCs["Move_Stand"] = new FrameAnimation_DESC("", 113, 116, FighterAnimationInter, true);
	CharactorAnimation_DESCs["Att_Changing"] = new FrameAnimation_DESC("", 117, 121, FighterAnimationInter, false);
	CharactorAnimation_DESCs["Att_Throwing"] = new FrameAnimation_DESC("", 122, 127, FighterAnimationInter, false);
	CharactorAnimation_DESCs["Att_Nen"] = new FrameAnimation_DESC("", 128, 131, FighterAnimationInter, false);
	CharactorAnimation_DESCs["Move_Stand_Battle"] = new FrameAnimation_DESC("", 132, 135, FighterAnimationInter, true);
	CharactorAnimation_DESCs["Move_Walk"] = new FrameAnimation_DESC("", 136, 143, FighterAnimationInter);
	CharactorAnimation_DESCs["Att_TakeDown"] = new FrameAnimation_DESC("", 144, 146, FighterAnimationInter, false);
	CharactorAnimation_DESCs["Att_MiddleKick"] = new FrameAnimation_DESC("", 147, 150, FighterAnimationInter, false);
	CharactorAnimation_DESCs["Att_RisingUpper"] = new FrameAnimation_DESC("", 151, 153, FighterAnimationInter, false);
	CharactorAnimation_DESCs["Att_Punch_Off"] = new FrameAnimation_DESC("", 154, 156, FighterAnimationInter, false);
	CharactorAnimation_DESCs["Att_Dash_Punch1"] = new FrameAnimation_DESC("", 157, 159, FighterAnimationInter, false);
	CharactorAnimation_DESCs["Att_Dash_Punch2"] = new FrameAnimation_DESC("", 160, 160, FighterAnimationInter, false);
}

void CharacterFighter::DestroyFrameAnimationDESC()
{
	for (auto& Iter : CharacterFighter::CharactorAnimation_DESCs)
	{
		if (Iter.second != nullptr)
		{
			delete Iter.second;
			Iter.second = nullptr;
		}
	}
	CharactorAnimation_DESCs.clear();
}