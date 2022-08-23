#include "PreCompile.h"
#include <GameEngineCore/GameEngineStateManager.h>
#include "CharacterStatManager.h"
#include "GamePlayDataBase.h"
#include "GamePlayEnum.h"
#include "GamePlayCharacter.h"
#include "GamePlayMonster.h"



CharacterStatManager::CharacterStatManager() 
	: PlayerCurrentState(0x0)
	, Time_CurrentEngage(0.f)
	, CurrentPlayerAbilityStat(nullptr)
	, CurrentMonsterAbilityStat(nullptr)
{
}

CharacterStatManager::~CharacterStatManager() 
{

}

void CharacterStatManager::Start()
{
	SettingFirstTime();
}

void CharacterStatManager::SettingFirstTime()
{

	GamePlayObject* Object = GetParent<GamePlayObject>();
	switch (Object->GetObjectType())
	{
	case ObjectType::Character:
		SetCharacter_Fighter_F();
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
		MsgBoxAssert("���� �������� �ʾҰų� Class ������ �ȵǾ��ֽ��ϴ�")
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

	if (!IsLive() || CurrentPlayerAbilityStat->HP < 0.f)
	{
		// ���
	}


	//�������� �ý������� �����ϴ°�?????
}


//Player_Character_ALive = 0x00,// ����								
//Player_Character_Action = 0x01,// �ൿ����							
//Player_Character_Move = 0x02,// �̵�����							
//Player_Character_Jump = 0x03,// ����								
//Player_Character_BaseAtt = 0x04,// �⺻����							
//Player_Character_DoSkill = 0x05,// ��ų���							
//Player_Character_Casting = 0x06,// ĳ����								
//Player_Character_Charging = 0x07,// ��¡								
//Player_Character_Invincibility = 0x08,// ����								
//Player_Character_Evasion = 0x09,// ����ȸ��(�ǰ�����X)					
//Player_Character_Superarmor = 0x0a,// ���۾Ƹ�							
//Player_Character_BeHit = 0x0b,// ����								
//Player_Character_Aerial = 0x0c,// ���߿� ��							
//Player_Character_BeDown = 0x0d,// �ٿ�								
//Player_Character_BeHold = 0x0e  // ����		

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




void CharacterStatManager::LevelStartEvent()
{
	;
	switch (GetParent<GamePlayObject>()->GetObjectType())
	{
	case ObjectType::Character:
	{
		SetCharacter_Fighter_F();
		CurrentPlayerAbilityStat = GamePlayCharacter::GetCurrentCharacterData()->GetAbilityStat();
		CurrentMonsterAbilityStat = nullptr;
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



}

void CharacterStatManager::LevelEndEvent()
{
	CurrentPlayerAbilityStat = nullptr;

	PlayerCurrentState = 0x0;
	Time_CurrentEngage = 0.f;
}