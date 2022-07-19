#include "PreCompile.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineComponent.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include "CharacterFighter.h"
#include "CharacterUIKeyManager.h"
#include <GameEngineCore/GameEngineFolderTexture.h>

#define FighterAnimationInter 0.15f
CharacterFighter::CharacterFighter() 
{
}

CharacterFighter::~CharacterFighter() 
{
}


void CharacterFighter::Start()
{
	GamePlayCharacter::Start();
	if (GamePlayCharacter::CharactorIndex <= 1)
	{
		SetAnimationForFrameAnimationDESC();
	}

}

void CharacterFighter::SetAnimationForFrameAnimationDESC()
{
		Fighter_F_Animation["Att_Dash"			   ] = FrameAnimation_DESC("", 0, 2, FighterAnimationInter, false);
		Fighter_F_Animation["Att_BasePunch1"	   ] = FrameAnimation_DESC("", 3, 4, FighterAnimationInter, false);
		Fighter_F_Animation["Att_OneinchPunch"	   ] = FrameAnimation_DESC("", 5, 7, FighterAnimationInter, false);
		Fighter_F_Animation["Att_Upper"			   ] = FrameAnimation_DESC("", 8, 14, FighterAnimationInter, false);
		Fighter_F_Animation["Att_BasePunch2"	   ] = FrameAnimation_DESC("", 15, 18, FighterAnimationInter, false);
		Fighter_F_Animation["Att_BasePunch3"	   ] = FrameAnimation_DESC("", 19, 26, FighterAnimationInter, false);
		Fighter_F_Animation["Att_BaseKick1"		   ] = FrameAnimation_DESC("", 27, 33, FighterAnimationInter, false);
		Fighter_F_Animation["Move_QuickStand"	   ] = FrameAnimation_DESC("", 34, 36, FighterAnimationInter, false);
		Fighter_F_Animation["Move_Dash"			   ] = FrameAnimation_DESC("", 37, 44, FighterAnimationInter, true);  // ´ë½¬
		Fighter_F_Animation["Move_Jump"			   ] = FrameAnimation_DESC("", 45, 51, FighterAnimationInter, false);
		Fighter_F_Animation["Att_JumpKick"		   ] = FrameAnimation_DESC("", 52, 55, FighterAnimationInter, false);
		Fighter_F_Animation["Att_Spire"			   ] = FrameAnimation_DESC("", 56, 63, FighterAnimationInter, false);
		Fighter_F_Animation["Att_LowKick1"		   ] = FrameAnimation_DESC("", 64, 68, FighterAnimationInter, false);
		Fighter_F_Animation["Att_LowKick2"		   ] = FrameAnimation_DESC("", 69, 73, FighterAnimationInter, false);
		Fighter_F_Animation["Hit_Stand1"		   ] = FrameAnimation_DESC("", 74, 75, FighterAnimationInter, false);
		Fighter_F_Animation["Hit_Stand2"]			 = FrameAnimation_DESC("", 76, 76, FighterAnimationInter, false);
		Fighter_F_Animation["Hit_Falling"]			 = FrameAnimation_DESC("", 77, 77, FighterAnimationInter, false);
		Fighter_F_Animation["Hit_FallUntilFloor"   ] = FrameAnimation_DESC("", 78, 79, FighterAnimationInter, false);
		Fighter_F_Animation["Hit_Down"			   ] = FrameAnimation_DESC("", 79, 81, FighterAnimationInter, false);
		Fighter_F_Animation["Hit_Stand3"		   ] = FrameAnimation_DESC("", 82, 83, FighterAnimationInter, false);
		Fighter_F_Animation["Att_Mount"			   ] = FrameAnimation_DESC("", 84, 89, FighterAnimationInter, false);
		Fighter_F_Animation["Att_Casting"		   ] = FrameAnimation_DESC("", 90, 93, FighterAnimationInter, false);
		Fighter_F_Animation["Att_Suplex1"		   ] = FrameAnimation_DESC("", 94, 98, FighterAnimationInter, false);
		Fighter_F_Animation["Att_Suplex2"		   ] = FrameAnimation_DESC("", 99, 105, FighterAnimationInter, false);
		Fighter_F_Animation["Att_Grap"]				= FrameAnimation_DESC("", 106, 106, FighterAnimationInter, false);
		Fighter_F_Animation["Att_JumpKick2"		   ] = FrameAnimation_DESC("", 107, 110, FighterAnimationInter, false);
		Fighter_F_Animation["Move_Stand"		   ] = FrameAnimation_DESC("", 111, 114, FighterAnimationInter, true);
		Fighter_F_Animation["Att_Changing"		   ] = FrameAnimation_DESC("", 115, 119, FighterAnimationInter, false);
		Fighter_F_Animation["Att_Throwing"		   ] = FrameAnimation_DESC("", 120, 125, FighterAnimationInter, false);
		Fighter_F_Animation["Att_Nen"			   ] = FrameAnimation_DESC("", 126, 129, FighterAnimationInter, false);
		Fighter_F_Animation["Move_Stand_Battle"	   ] = FrameAnimation_DESC("", 130, 133, FighterAnimationInter, true);
		Fighter_F_Animation["Move_Walk"			   ] = FrameAnimation_DESC("", 134, 141, FighterAnimationInter, false);
		Fighter_F_Animation["Att_TakeDown"		   ] = FrameAnimation_DESC("", 142, 144, FighterAnimationInter, false);
		Fighter_F_Animation["Att_MiddleKick"	   ] = FrameAnimation_DESC("", 145, 148, FighterAnimationInter, false);
		Fighter_F_Animation["Att_RisingUpper"	   ] = FrameAnimation_DESC("", 149, 151, FighterAnimationInter, false);
		Fighter_F_Animation["Att_Punch_Off"		   ] = FrameAnimation_DESC("", 152, 154, FighterAnimationInter, false);
		Fighter_F_Animation["Att_Dash_Punch1"	   ] = FrameAnimation_DESC("", 155, 157, FighterAnimationInter, false);
		Fighter_F_Animation["Att_Dash_Punch2"	   ] = FrameAnimation_DESC("", 158, 158, FighterAnimationInter, false);
}

void CharacterFighter::Update(float _DeltaTime)
{

}
