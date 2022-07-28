#include "PreCompile.h"
#include <GameEngineCore/GameEngineStateManager.h>
#include "CharacterStatManager.h"
#include "GamePlayEnum.h"

const float Gravitational_Constant = 9.8f;

CharacterStatManager::CharacterStatManager() 
	: PlayerCurrentState(0x0)
	, CanAction(false)
	, CanMove(false)
	, JumpPower(500.f)
	, CurrentJumpIndex(0.f)
	, CurrentGravitIndex(-1.f)
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
	if (IsJump())
	{
		CurrentGravitIndex *= (Gravitational_Constant * _DeltaTime);
		CurrentJumpIndex += CurrentGravitIndex;
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
}
void CharacterStatManager::SetJump()
{
	PlayerCurrentState |= CharacterStat::Player_Character_Jump;
	CurrentJumpIndex = JumpPower;
	CurrentGravitIndex = -1.f;

}