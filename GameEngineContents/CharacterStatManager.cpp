#include "PreCompile.h"
#include <GameEngineCore/GameEngineStateManager.h>
#include "CharacterStatManager.h"
#include "GamePlayEnum.h"
#include "GamePlayCharacter.h"

const float Gravitational_Constant = 9.8f;

CharacterStatManager::CharacterStatManager() 
	: PlayerCurrentState(0x0)
	, CanAction(false)
	, CanMove(false)
	, JumpPower(600.f)
	, JumpHigh(0.f)
	, CurrentGravitIndex(-1.f)
	, JumpTime(0.f)
	, CurrentEngageTime(0.f)
	, CharacterWeight(-180.f)
	, RightSide(true)
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
	CharacterClass Class = GetParent<GamePlayCharacter>()->GetPlayerClass();
	SetCharacter_Fighter_F();

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
	PlayerCurrentState = (0x0);
	CanAction = false;
	CanMove = false;
	JumpPower = 600.f;
	JumpHigh = 0.f;
	CurrentGravitIndex = -1.f;
	JumpTime = 0.f;
	CurrentEngageTime = 0.f;
	CharacterWeight = -180.f;

}

void CharacterStatManager::Update(float _DeltaTime)
{
	CurrentEngageTime -= _DeltaTime;

	if (IsJump())
	{
		JumpTime += _DeltaTime;
		if (JumpHigh > -650)
		{
			JumpHigh = ((CharacterWeight * JumpTime * Gravitational_Constant) * JumpTime + JumpPower);
		}
		// Y = x(ax);
		// y = �ӷ�
		// x = ���� �ð�
		// 
	}
	FSMManager.Update(_DeltaTime);

	//GameEngineDebug::OutPutString(std::to_string(PlayerCurrentState));
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
//Player_Character_BeAir = 0x0c,// ���߿� ��							
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

void CharacterStatManager::SetJump(const float4& _StartJumpPos)
{
	PlayerCurrentState |= CharacterStat::Player_Character_Jump;
	JumpHigh = 0.f;
	CurrentGravitIndex = -1.f;
	JumpTime = 0.f;
	LandingPostion = _StartJumpPos;
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

float CharacterStatManager::GetMoveSpeed() const
{
	if (IsDash())
	{
		return PlayerStat.MoveSpeed * 1.8f;
	}
	else
	{
		return PlayerStat.MoveSpeed;
	}
}


void CharacterStatManager::OnEvent() 
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