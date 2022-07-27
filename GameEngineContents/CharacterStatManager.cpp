#include "PreCompile.h"
#include <GameEngineCore/GameEngineStateManager.h>
#include "CharacterStatManager.h"
#include "GamePlayEnum.h"

CharacterStatManager::CharacterStatManager() 
	: PlayerCurrentState(0x0)
	, CanAction(false)
	, CanMove(false)
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
	FSMManager.Update(_DeltaTime);
}


//Player_Character_ALive = 0x00,// ����								
//Player_Character_Action = 0x01,// �ൿ����							
//Player_Character_Move = 0x02,// �̵�����							
//Player_Character_InAir = 0x03,// ����								
//Player_Character_BaseAtt = 0x04,// �⺻����							
//Player_Character_DoSkill = 0x05,// ��ų���							
//Player_Character_Casting = 0x06,// ĳ����								
//Player_Character_Charging = 0x07,// ��¡								
//Player_Character_Invincibility = 0x08,// ����								
//Player_Character_Evasion = 0x09,// ����ȸ��(�ǰ�����X)					
//Player_Character_Superarmor = 0x0a,// ���۾Ƹ�							
//Player_Character_BeHit = 0x0b,// ����								
//Player_Character_BeAir = 0x0c,// ���߿� ��							
//Player_Character_BeDown = 0x0d,// �ٿ�								
//Player_Character_BeHold = 0x0e  // ����		

