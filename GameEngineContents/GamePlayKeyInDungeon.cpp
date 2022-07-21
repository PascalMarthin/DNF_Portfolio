#include "PreCompile.h"
#include "GamePlayKeyInDungeon.h"
#include "GamePlayCharacter.h"

GamePlayKeyInDungeon::GamePlayKeyInDungeon() 
{
}

GamePlayKeyInDungeon::~GamePlayKeyInDungeon() 
{
}

void GamePlayKeyInDungeon::Start()
{
	Off();
}

void GamePlayKeyInDungeon::Update(float _DeltaTime)
{

}

void GamePlayKeyInDungeon::CheckKeyByMove(float _DeltaTime, float _MoveSpeed)
{
	bool IsMove = false;
	// 임시 생성 -> 캐릭터 내 스탯 확인으로 교체예정
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


void GamePlayKeyInDungeon::CheckKeyBySkill(float _DeltaTime, float _MoveSpeed)
{
	if (GameEngineInput::GetInst()->IsPress("BaseAtt") == true)
	{
		int a = 0;
	}

	if (GameEngineInput::GetInst()->IsPress("Jump") == true)
	{
		int a = 0;
	}

}

void GamePlayKeyInDungeon::CheckKeyByInterface(float _DeltaTime, float _MoveSpeed)
{

}