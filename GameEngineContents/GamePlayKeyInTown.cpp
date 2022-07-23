#include "PreCompile.h"
#include <GameEngineBase/GameEngineInput.h>
#include "CharacterStatManager.h"
#include "GamePlayCharacter.h"
#include "GamePlayKeyInTown.h"

GamePlayKeyInTown::GamePlayKeyInTown() 
{
}

GamePlayKeyInTown::~GamePlayKeyInTown() 
{
}

void GamePlayKeyInTown::Start()
{
	GamePlayKeyManager::Start();
}

void GamePlayKeyInTown::Update(float _DeltaTime)
{
	float Speed = 2.f;//Player->GetMoveSpeed();

	CheckKeyByMove(_DeltaTime, Speed);
	CheckKeyBySkill(_DeltaTime, Speed);
	CheckKeyByInterface(_DeltaTime, Speed);

}

void GamePlayKeyInTown::CheckKeyByMove(float _DeltaTime, float _MoveSpeed)
{
	bool IsMove = false;
	if (GameEngineInput::GetInst()->IsPress("UP_Arrow") == true)
	{
		IsMove = true;
		Player->GetTransform().SetLocalMove(float4({ 0, DefaultMove }) * _MoveSpeed * _DeltaTime);
		Player->ChangeAvataAnimation("Move_Walk");
	}

	if (GameEngineInput::GetInst()->IsPress("Down_Arrow") == true)
	{
		IsMove = true;
		Player->GetTransform().SetLocalMove(float4({ 0, -DefaultMove }) * _MoveSpeed * _DeltaTime);
		Player->ChangeAvataAnimation("Move_Walk");
	}

	if (GameEngineInput::GetInst()->IsPress("Left_Arrow") == true)
	{
		IsMove = true;
		Player->GetTransform().SetLocalMove(float4({ -DefaultMove, 0 }) * _MoveSpeed * _DeltaTime);
		Player->GetTransform().PixLocalNegativeX();
		Player->ChangeAvataAnimation("Move_Walk");
	}

	if (GameEngineInput::GetInst()->IsPress("Right_Arrow") == true)
	{
		IsMove = true;
		Player->GetTransform().SetLocalMove(float4({ DefaultMove, 0 }) * _MoveSpeed * _DeltaTime);
		Player->GetTransform().PixLocalPositiveX();
		Player->ChangeAvataAnimation("Move_Walk");
	}

	if (IsMove == false)
	{
		Player->ChangeAvataAnimation("Move_Stand");
	}
}

//GameEngineInput::GetInst()->CreateKey("Jump", 'C');
//GameEngineInput::GetInst()->CreateKey("Key_Upper", 'Z');
//GameEngineInput::GetInst()->CreateKey("SpaceBar", VK_SPACE);
//GameEngineInput::GetInst()->CreateKey("UP_Arrow", VK_UP);
//GameEngineInput::GetInst()->CreateKey("Down_Arrow", VK_DOWN);
//GameEngineInput::GetInst()->CreateKey("Left_Arrow", VK_LEFT);
//GameEngineInput::GetInst()->CreateKey("Right_Arrow", VK_RIGHT);

void GamePlayKeyInTown::CheckKeyBySkill(float _DeltaTime, float _MoveSpeed)
{
	bool IsAction = false;
	if (GameEngineInput::GetInst()->IsPress("BaseAtt") == true)
	{
		IsAction = true;
		Player->ChangeAvataAnimation("Att_BasePunch1");
	}

	if (GameEngineInput::GetInst()->IsPress("Jump") == true)
	{
		int a = 0;
	}

}
// µð¹ö±×