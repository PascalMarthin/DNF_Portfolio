#include "PreCompile.h"
#include "MoveManager.h"
#include "GamePlayObject.h"
#include "GamePlayCharacter.h"
#include "CharacterStatManager.h"
#include "GamePlayEnum.h"

const float Gravitational_Constant = 9.8f;

MoveManager::MoveManager() 
	: ParentCharacter(nullptr)
	, JumpPower(600.f)
	, JumpHigh(0.f)
	, CurrentGravitIndex(-1.f)
	, JumpTime(0.f)
{
}

MoveManager::~MoveManager() 
{
}


// --------------Start-------------
void MoveManager::Start()
{
	ParentCharacter = GetParent<GamePlayObject>();
	if (ParentCharacter == nullptr)
	{
		MsgBoxAssert("생성 순서가 다릅니다")
	}
}




// -------------Update------------------
void MoveManager::Update(float _DeltaTime)
{
	if (ManagerStat != nullptr )
	{
		if (ManagerStat->IsJump())
		{
			JumpTime += _DeltaTime;
			if (JumpHigh > -650)
			{
				JumpHigh = (-(ParentCharacter->GetCharacterWeight()  * JumpTime * Gravitational_Constant) * JumpTime + JumpPower);
			}
			SetCharacterMove(float4({ 0, 1 }) * JumpHigh * _DeltaTime);
		}
		// Y = x(ax);
		// y = 속력
		// x = 점프 시간
		// 
	}
}


void MoveManager::SetCharacterMove(const float4& _Move)
{
	// 이동 가능 여부 확인

	if (_Move.x > 0.f)
	{
		ParentCharacter->SetRightDir();
	}
	else if (_Move.x < 0.f)
	{
		ParentCharacter->SetLeftDir();
	}
	float4 Move = _Move;
	Move.y *= 0.8f;
	ParentCharacter->GetTransform().SetLocalMove(Move);
}

void MoveManager::SetCharacterLocation(const float4& _Pos)
{
	ParentCharacter->GetTransform().SetLocalPosition(_Pos);
}

void MoveManager::SetJump(const float4& _StartJumpPos)
{
	JumpHigh = 0.f;
	CurrentGravitIndex = -1.f;
	JumpTime = 0.f;
	LandingPostion = _StartJumpPos;
}

void MoveManager::OnEvent()
{
	JumpHigh = 0.f;
	CurrentGravitIndex = -1.f;
	JumpTime = 0.f;

	if (ParentCharacter->GetObjectType() == ObjectType::Character)
	{
		GamePlayCharacter* Character = dynamic_cast<GamePlayCharacter*>(ParentCharacter);
		ManagerStat = Character->GetStatManager();
	}
}