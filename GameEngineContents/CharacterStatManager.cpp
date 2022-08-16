#include "PreCompile.h"
#include <GameEngineCore/GameEngineStateManager.h>
#include "CharacterStatManager.h"
#include "GamePlayDataBase.h"
#include "GamePlayEnum.h"
#include "GamePlayCharacter.h"



CharacterStatManager::CharacterStatManager() 
	: PlayerCurrentState(0x0)
	, Time_CurrentEngage(0.f)
	, CurrentAbilityStat(nullptr)
	, Time_BeHit(float4::ZERO)
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
	//CharacterClass Class = GetParent<GamePlayCharacter>()->GetPlayerClass();
	SetCharacter_Fighter_F();

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

	if (!IsLive() || CurrentAbilityStat->HP < 0.f)
	{
		// 사망
	}

	if (Time_BeHit.z > 0)
	{
		Time_BeHit.z -= _DeltaTime * 100.f * CurrentAbilityStat->Hit_Recovery;
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
//Player_Character_BeAir = 0x0c,// 공중에 뜸							
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

void CharacterStatManager::SetHit(const float4& _HitTime, float _Damge)
{
	if (!IsSuperarmor())
	{
		PlayerCurrentState |= CharacterStat::Player_Character_BeHit;
		PlayerCurrentState &= ~0b0000000111101110;
		FSMManager.ChangeState("Hit_Stand1");
	}
	Time_BeHit = _HitTime;
	CurrentAbilityStat->HP -= _Damge;
	if (true)
	{

	}
}



void CharacterStatManager::OnEvent() 
{
	SetCharacter_Fighter_F();
	CurrentAbilityStat = GamePlayCharacter::GetCurrentCharacterData()->GetAbilityStat();

}

void CharacterStatManager::OffEvent()
{
	CurrentAbilityStat = nullptr;

	PlayerCurrentState = 0x0;
	Time_CurrentEngage = 0.f;
	Time_BeHit = float4::ZERO;
}