#include "PreCompile.h"
#include <GameEngineCore/GameEngineStateManager.h>
#include "CharacterStatManager.h"
#include "GamePlayEnum.h"

const float Gravitational_Constant = 9.8f;

CharacterStatManager::CharacterStatManager() 
	: PlayerCurrentState(0x0)
	, CanAction(false)
	, CanMove(false)
	, JumpPower(400.f)
	, JumpHigh(0.f)
	, CurrentGravitIndex(-1.f)
	, JumpTime(0.f)
	, CurrentEngageTime(0.f)
{
}

CharacterStatManager::~CharacterStatManager() 
{

}

void CharacterStatManager::Start()
{

}

void CharacterStatManager::Update(float _DeltaTime)
{
	CurrentEngageTime -= _DeltaTime;

	if (IsJump())
	{
		JumpTime += _DeltaTime;
		if (JumpHigh > -650)
		{
			JumpHigh = ((-200.f * JumpTime * Gravitational_Constant) * JumpTime + JumpPower * 1.2f);
		}
		// Y = x(ax);
		// y = 속력
		// x = 점프 시간
		// 
	}
	FSMManager.Update(_DeltaTime);
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

void CharacterStatManager::SetMove()
{
	PlayerCurrentState |= CharacterStat::Player_Character_Move;
	PlayerCurrentState &= ~(CharacterStat::Player_Character_Dash);

}

void CharacterStatManager::SetDash()
{
	PlayerCurrentState |= CharacterStat::Player_Character_Dash;
	PlayerCurrentState &= ~(CharacterStat::Player_Character_Move);
}

void CharacterStatManager::SetStand()
{
	PlayerCurrentState &= ~(CharacterStat::Player_Character_Dash | CharacterStat::Player_Character_Move);
}

void CharacterStatManager::SetJump(const float4& _StartJumpPos)
{
	PlayerCurrentState |= CharacterStat::Player_Character_Jump;
	JumpHigh = 0.f;
	CurrentGravitIndex = -1.f;
	JumpTime = 0.f;
	LandingPostion = _StartJumpPos;
}

float CharacterStatManager::GetMoveSpeed() const
{
	if (IsDash())
	{
		return PlayerStat.MoveSpeed * 1.5f;
	}
	else
	{
		return PlayerStat.MoveSpeed;
	}
}

void CharacterStatManager::OffEvent() 
{
	PlayerCurrentState =0x0;
	CanAction = false;
	CanMove = false;
	JumpPower = 0.f;
	JumpHigh = 0.f;
	CurrentGravitIndex = -1.f;
	JumpTime = 0.f;
	CurrentEngageTime = 0.f;
}