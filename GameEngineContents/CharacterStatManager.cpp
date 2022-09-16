#include "PreCompile.h"
#include <GameEngineCore/GameEngineStateManager.h>
#include "CharacterStatManager.h"
#include "GamePlayDataBase.h"
#include "GamePlayEnum.h"
#include "GamePlayCharacter.h"
#include "GamePlayMonster.h"
#include "StatWindow.h"
#include "GameSkillBuff.h"
#include "CharacterSkillManager.h"


CharacterStatManager* CharacterStatManager::Inst = nullptr;
CharacterStatManager::CharacterStatManager() 
	: PlayerCurrentState(0x0)
	, Time_CurrentEngage(0.f)
	, CurrentPlayerAbilityStat(nullptr)
	, CurrentMonsterAbilityStat(nullptr)
	, LevelUpTime(0)
	, Manager_SkillManager(nullptr)
{
}

CharacterStatManager::~CharacterStatManager() 
{

}

void CharacterStatManager::Start()
{
	//SetOrder(static_cast<int>(ActorOrder::Manager));
	SettingFirstTime();

}

void CharacterStatManager::SettingFirstTime()
{

	GamePlayObject* Object = GetParent<GamePlayObject>();
	switch (Object->GetObjectType())
	{
	case ObjectType::Character:
		SetCharacter_Fighter_F();
		{
			GameEngineTextureRenderer* LevelUp = Object->CreateComponent<GameEngineTextureRenderer>();
			LevelUp->CreateFrameAnimationFolder("LevelEffect", FrameAnimation_DESC("Level_grounda",0.125f ,false));
			LevelUp->ChangeFrameAnimation("LevelEffect");
			LevelUp->ScaleToTexture();
			LevelUp->GetTransform().SetLocalPosition({0, -50, 5});
			LevelUp->AnimationBindEnd("LevelEffect", 
				[](const FrameAnimation_DESC& _Desc)
				{
					_Desc.Renderer->Off();
				});
			LevelUp->GetPipeLine()->SetOutputMergerBlend("TransparentBlend");
			LevelUp->GetPixelData().MulColor.a = 1.f;
			LevelUp->Off();
			Texture_LevelUp.push_back(LevelUp);

			LevelUp = Object->CreateComponent<GameEngineTextureRenderer>();
			LevelUp->CreateFrameAnimationFolder("LevelEffect", FrameAnimation_DESC("Level_groundb", 0.125f, false));
			LevelUp->ChangeFrameAnimation("LevelEffect");
			LevelUp->ScaleToTexture();
			LevelUp->GetTransform().SetLocalPosition({ 0, -50, 5 });
			LevelUp->GetPixelData().MulColor = { 0.9f, 0.9f, 1.5f, 1.f };
			LevelUp->GetPixelData().PlusColor.a = 1.f;
			LevelUp->AnimationBindEnd("LevelEffect",
				[](const FrameAnimation_DESC& _Desc)
				{
					_Desc.Renderer->Off();
				});
			LevelUp->GetPipeLine()->SetOutputMergerBlend("TransparentBlend");
			LevelUp->Off();
			Texture_LevelUp.push_back(LevelUp);

			LevelUp = Object->CreateComponent<GameEngineTextureRenderer>();
			LevelUp->CreateFrameAnimationFolder("LevelEffect", FrameAnimation_DESC("Level_lighta", 0.125f, false));
			LevelUp->ChangeFrameAnimation("LevelEffect");
			LevelUp->GetTransform().SetLocalPosition({ 0, 280 });
			LevelUp->ScaleToTexture();
			LevelUp->AnimationBindEnd("LevelEffect",
				[](const FrameAnimation_DESC& _Desc)
				{
					_Desc.Renderer->Off();
				});
			LevelUp->Off();
			LevelUp->GetPipeLine()->SetOutputMergerBlend("TransparentBlend");
			Texture_LevelUp.push_back(LevelUp);

			LevelUp = Object->CreateComponent<GameEngineTextureRenderer>();
			LevelUp->CreateFrameAnimationFolder("LevelEffect", FrameAnimation_DESC("Level_particle", 0.125f, false));
			LevelUp->ChangeFrameAnimation("LevelEffect");
			LevelUp->ScaleToTexture();
			LevelUp->AnimationBindEnd("LevelEffect",
				[](const FrameAnimation_DESC& _Desc)
				{
					_Desc.Renderer->Off();
				});
			LevelUp->GetPipeLine()->SetOutputMergerBlend("TransparentBlend");
			LevelUp->Off();
			Texture_LevelUp.push_back(LevelUp);

			LevelUp = Object->CreateComponent<GameEngineTextureRenderer>();
			LevelUp->CreateFrameAnimationFolder("LevelEffect", FrameAnimation_DESC("Level_shock", 0.15f, false));
			LevelUp->ChangeFrameAnimation("LevelEffect");
			LevelUp->ScaleToTexture();
			LevelUp->AnimationBindEnd("LevelEffect",
				[](const FrameAnimation_DESC& _Desc)
				{
					_Desc.Renderer->Off();
				});
			LevelUp->GetPipeLine()->SetOutputMergerBlend("TransparentBlend");
			LevelUp->Off();
			Texture_LevelUp.push_back(LevelUp);

			LevelUp = Object->CreateComponent<GameEngineTextureRenderer>();
			LevelUp->SetFolderTextureToIndex("Levelup_Font", 0);
			LevelUp->GetTransform().SetLocalPosition({0, 40});
			LevelUp->ScaleToTexture();
			LevelUp->Off();
			Texture_LevelUp.push_back(LevelUp);

		}
		{
			Window_Stat = Object->GetLevel()->CreateActor<StatWindow>(ActorOrder::Window);
		}

		break;
	case ObjectType::Monster:


		break;
	case ObjectType::NPC:
		break;
	case ObjectType::None:
		break;
	case ObjectType::Custom:
		break;
	default:
		break;
	}
	//CharacterClass Class = GetParent<GamePlayCharacter>()->GetPlayerClass();

	/*switch (Class)
	{
		break;
	case CharacterClass::Fighter_F:

		break;
	case CharacterClass::None:
	default:
		MsgBoxAssert("아직 구현되지 않았거나 Class 설정이 안되어있습니다")
		break;
	}*/
}

void CharacterStatManager::SetCharacter_Fighter_F()
{
	PlayerCurrentState = (0x01);
	Time_CurrentEngage = 0.f;
}

void CharacterStatManager::Update(float _DeltaTime)
{
	Time_CurrentEngage -= _DeltaTime;

	FSMManager.Update(_DeltaTime);

	if (Texture_LevelUp[5]->IsUpdate())
	{
		LevelUpTime += _DeltaTime;
		if (LevelUpTime > 3.f)
		{
			Texture_LevelUp[5]->Off();
		}


		Texture_LevelUp[5]->GetPixelData().MulColor.a += _DeltaTime;
		if (Texture_LevelUp[5]->GetPixelData().MulColor.a > 1.f)
		{
			Texture_LevelUp[5]->GetPixelData().MulColor.a = 1.f;
		}
		//float4::LerpLimit()
	}

	CurrentPlayerAbilityStat->SetRefreshbyLevel();
	std::map<AllSkillEnum, std::map<StatClass, int>>& StatBuff = Manager_SkillManager->Static_StatBuff;
	if (!StatBuff.empty())
	{
		
		for (auto& Buff : StatBuff)
		{
			for (auto& Stat : Buff.second)
			{
				switch (Stat.first)
				{
				case StatClass::MAXHP:
					CurrentPlayerAbilityStat->MAXHP += Stat.second;
					break;
				case StatClass::MAXMP:
					CurrentPlayerAbilityStat->MAXMP += Stat.second;
					break;
				case StatClass::Physical_Armor:
					CurrentPlayerAbilityStat->Physical_Armor += Stat.second;
					break;
				case StatClass::Magcial_Armor:
					CurrentPlayerAbilityStat->Magcial_Armor += Stat.second;
					break;
				case StatClass::STR:
					CurrentPlayerAbilityStat->STR += Stat.second;
					break;
				case StatClass::INT:
					CurrentPlayerAbilityStat->INT += Stat.second;
					break;
				case StatClass::Health:
					CurrentPlayerAbilityStat->Health += Stat.second;
					break;
				case StatClass::SPI:
					CurrentPlayerAbilityStat->SPI += Stat.second;
					break;
				case StatClass::Physical_Damage:
					CurrentPlayerAbilityStat->Physical_Damage += Stat.second;
					break;
				case StatClass::Magcial_Damage:
					CurrentPlayerAbilityStat->Magcial_Damage += Stat.second;
					break;
				case StatClass::Independent_Damage:
					CurrentPlayerAbilityStat->Independent_Damage += Stat.second;
					break;
				case StatClass::Physical_Critical:
					CurrentPlayerAbilityStat->Physical_Critical += Stat.second;
					break;
				case StatClass::Magcial_Critical:
					CurrentPlayerAbilityStat->Magcial_Critical += Stat.second;
					break;
				case StatClass::Accuracy:
					CurrentPlayerAbilityStat->Accuracy += Stat.second;
					break;
				case StatClass::Evasion:
					CurrentPlayerAbilityStat->Evasion += Stat.second;
					break;
				default:
					break;
				}
			}
		}
	}
	Window_Stat->RefreshStat();

	if (!IsLive() || CurrentPlayerAbilityStat->HP < 0.f)
	{
		// 사망
	}


	//역경직을 시스템으로 봐야하는가?????
}


//Player_Character_ALive = 0x00,// 생존								
//Player_Character_Action = 0x01,// 행동가능							
//Player_Character_Move = 0x02,// 이동가능							
//Player_Character_Jump = 0x03,// 공중								
//Player_Character_BaseAtt = 0x04,// 기본공격							
//Player_Character_DoSkill = 0x05,// 스킬사용							
//Player_Character_Casting = 0x06,// 캐스팅								
//Player_Character_Charging = 0x07,// 차징								
//Player_Character_Invincibility = 0x08,// 무적								
//Player_Character_Evasion = 0x09,// 절대회피(피격판정X)					
//Player_Character_Superarmor = 0x0a,// 슈퍼아머							
//Player_Character_BeHit = 0x0b,// 경직								
//Player_Character_Aerial = 0x0c,// 공중에 뜸							
//Player_Character_BeDown = 0x0d,// 다운								
//Player_Character_BeHold = 0x0e  // 잡힘		

void CharacterStatManager::SetWalk()
{
	PlayerCurrentState |= CharacterStat::Player_Character_Move;
	PlayerCurrentState &= ~(CharacterStat::Player_Character_Dash);

}

void CharacterStatManager::SetWalkEnd()
{
	PlayerCurrentState &= ~(CharacterStat::Player_Character_Move);
}

void CharacterStatManager::SetDash()
{
	PlayerCurrentState |= CharacterStat::Player_Character_Dash;
	PlayerCurrentState &= ~(CharacterStat::Player_Character_Move);
}

void CharacterStatManager::SetDashEnd()
{
	PlayerCurrentState &= ~(CharacterStat::Player_Character_Dash);
}

void CharacterStatManager::SetStand()
{
	PlayerCurrentState &= ~(CharacterStat::Player_Character_Dash | CharacterStat::Player_Character_Move);
}

void CharacterStatManager::SetJump()
{
	PlayerCurrentState |= CharacterStat::Player_Character_Jump;
}

void CharacterStatManager::SetJumpEnd()
{
	PlayerCurrentState &= ~CharacterStat::Player_Character_Jump;
}

void CharacterStatManager::SetAerial()
{
	PlayerCurrentState |= CharacterStat::Player_Character_Aerial;
}
void CharacterStatManager::SetAerialEnd()
{
	PlayerCurrentState &= ~CharacterStat::Player_Character_Aerial;
}

void CharacterStatManager::SetDoBaseAtt()
{
	PlayerCurrentState |= CharacterStat::Player_Character_BaseAtt;
	PlayerCurrentState &= ~(CharacterStat::Player_Character_Dash);
	PlayerCurrentState &= ~(CharacterStat::Player_Character_Move);
}

void CharacterStatManager::SetDoBaseAttEnd()
{
	PlayerCurrentState &= ~(CharacterStat::Player_Character_BaseAtt);
}

void CharacterStatManager::SetCanAction()
{
	PlayerCurrentState |= 0b0000000111101110;
}

void CharacterStatManager::SetCantAction()
{
	PlayerCurrentState &= ~0b0000000111101110;
}

void CharacterStatManager::SetHit_Stand()
{
	if (!IsSuperarmor())
	{
		if (IsAerial())
		{
			FSMManager.ChangeState("Hit_Aerial");
			SetCantAction();
		}
		else
		{
			FSMManager.ChangeState("Hit_Stand");
			PlayerCurrentState |= CharacterStat::Player_Character_BeHit;
			SetCantAction();
		}
	}
}

void CharacterStatManager::SetHit_StandEnd()
{
	PlayerCurrentState &= ~CharacterStat::Player_Character_BeHit;
	SetCanAction();
}

void CharacterStatManager::SetHit_BlowUp()
{
	if (!IsSuperarmor())
	{
		FSMManager.ChangeState("Hit_Aerial");
		PlayerCurrentState &= ~CharacterStat::Player_Character_BeHit;
		SetCantAction();
	}
}

void CharacterStatManager::SetHold()
{
	if (IsAerial())
	{
		FSMManager.ChangeState("Hit_Aerial");
		SetCantAction();
	}
	else
	{
		FSMManager.ChangeState("Hit_Stand");
		PlayerCurrentState |= CharacterStat::Player_Character_BeHit;
		SetCantAction();
	}

	PlayerCurrentState |= CharacterStat::Player_Character_BeHold;
}

void CharacterStatManager::SetHoldEnd()
{
	PlayerCurrentState &= ~CharacterStat::Player_Character_BeHold;
}

void CharacterStatManager::SetDown()
{
	PlayerCurrentState &= ~CharacterStat::Player_Character_Aerial;
	PlayerCurrentState &= ~CharacterStat::Player_Character_BeHit;
	PlayerCurrentState |= CharacterStat::Player_Character_BeDown;
	SetCantAction();
	FSMManager.ChangeState("Hit_Down");
}
void CharacterStatManager::SetDownEnd()
{
	PlayerCurrentState &= ~CharacterStat::Player_Character_BeDown;
	SetCanAction();
}

void CharacterStatManager::SetDoSkill()
{
	PlayerCurrentState |= CharacterStat::Player_Character_DoSkill;
}
void CharacterStatManager::SetDoSkillEnd()
{
	PlayerCurrentState &= ~CharacterStat::Player_Character_DoSkill;
}

void CharacterStatManager::SetCasting()
{
	PlayerCurrentState |= CharacterStat::Player_Character_Casting;
}

void CharacterStatManager::SetCastingEnd()
{
	PlayerCurrentState &= ~CharacterStat::Player_Character_Casting;
}

void CharacterStatManager::LevelUp()
{
	CurrentPlayerAbilityStat->Level += 1;
	CurrentPlayerAbilityStat->EXP = 0;
	CurrentPlayerAbilityStat->SetRefreshbyLevel();
	Window_Stat->RefreshStat();
	LevelUpTime = 0;

	Texture_LevelUp[0]->ChangeFrameAnimation("LevelEffect", true);
	Texture_LevelUp[0]->On();

	Texture_LevelUp[1]->ChangeFrameAnimation("LevelEffect", true);
	Texture_LevelUp[1]->On();

	Texture_LevelUp[2]->ChangeFrameAnimation("LevelEffect", true);
	Texture_LevelUp[2]->On();

	Texture_LevelUp[3]->ChangeFrameAnimation("LevelEffect", true);
	Texture_LevelUp[3]->On();

	Texture_LevelUp[4]->ChangeFrameAnimation("LevelEffect", true);
	Texture_LevelUp[4]->On();

	Texture_LevelUp[5]->GetPixelData().MulColor.a = 0.f;
	Texture_LevelUp[5]->On();
}




void CharacterStatManager::LevelStartEvent()
{
	
	switch (GetParent<GamePlayObject>()->GetObjectType())
	{
	case ObjectType::Character:
	{
		SetCharacter_Fighter_F();
		CurrentPlayerAbilityStat = GamePlayCharacter::GetCurrentCharacterData()->GetAbilityStat();
		CurrentMonsterAbilityStat = nullptr;


		Manager_SkillManager = GetParent<GamePlayCharacter>()->GetSkillManager();
	}
		break;
	case ObjectType::Monster:
		CurrentPlayerAbilityStat = nullptr;
		CurrentMonsterAbilityStat = GetParent<GamePlayMonster>()->GetMonsterStat();
		break;
	case ObjectType::NPC:
		break;
	case ObjectType::None:
		break;
	case ObjectType::Custom:
		break;
	default:
		break;
	}

	CharacterStatManager::Inst = this;

}

void CharacterStatManager::LevelEndEvent()
{
	CurrentPlayerAbilityStat = nullptr;

	PlayerCurrentState = 0x0;
	Time_CurrentEngage = 0.f;
	//List_ActiveBuff.clear();

	CharacterStatManager::Inst = nullptr;
}