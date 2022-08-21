#include "PreCompile.h"
#include "GamePlaySkill.h"
#include "GamePlayObject.h"
#include "GamePlayCharacter.h"

GamePlaySkill::GamePlaySkill()
	: int_ComboStuck(0)
	, TimePass(0.f)
	, Is_CollisionCheck(false)
	, CoolTime(0.f)
	, CurrentCoolTime(0.f)
{
}

GamePlaySkill::~GamePlaySkill() 
{
}


void GamePlaySkill::CheckCollision()
{
	Collision_AllCollisionList[int_ComboStuck]->IsCollision(CollisionType::CT_AABB, CollisionOrder::Monster, CollisionType::CT_AABB,
		std::bind(&GamePlaySkill::CollsionHitFunction, this, std::placeholders::_1, std::placeholders::_2));
}

void GamePlaySkill::CheckCollision(int _Combo)
{
	Collision_AllCollisionList[_Combo]->IsCollision(CollisionType::CT_AABB, CollisionOrder::Monster, CollisionType::CT_AABB,
		std::bind(&GamePlaySkill::CollsionHitFunction, this, std::placeholders::_1, std::placeholders::_2));
}

bool GamePlaySkill::CollsionHitFunction(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	GamePlayObject* Actor = _Other->GetActor<GamePlayObject>();

	if (GamePlaySkill::IsHitObject(Actor, Class_Power[int_ComboStuck].int_MaxHit))
	{
		return false;
	}

	TriggerSkill_ect(_This, _Other);

	Actor->BeHit(this, _Other, GamePlayCharacter::GetCurrentCharacterData(), CheckDir(_This, _Other)); //

	return false;
}


bool GamePlaySkill::IsHitObject(GamePlayObject* _Object, int _HitOrder)
{
	if (Object_HitList[_Object] >= _HitOrder)
	{
		return true;
	}
	else
	{
		Object_HitList[_Object] += 1;
		return false;
	}
}

int GamePlaySkill::CheckDir(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	if (_This->GetActor()->GetTransform().GetLocalPosition().x > _Other->GetActor()->GetTransform().GetLocalPosition().x)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}


float GamePlaySkill::FSM_Move_Helper()
{
	bool Left = false;
	bool Right = false;
	float MoveIndex = 0.f;
	GamePlayObject* Object = GetActor<GamePlayObject>();
	if (GameEngineInput::GetInst()->IsDown("Right_Arrow") || GameEngineInput::GetInst()->IsPress("Right_Arrow"))
	{
		if (Object->GetObjectDir())
		{
			MoveIndex = 6.f;
		}
		else
		{
			MoveIndex = 0.f;
		}
		Right = true;
	}

	if ((GameEngineInput::GetInst()->IsDown("Left_Arrow")) || GameEngineInput::GetInst()->IsPress("Left_Arrow"))
	{
		if (Object->GetObjectDir())
		{
			MoveIndex = 0.f;
		}
		else
		{
			MoveIndex = -6.f;
		}
		Left = true;
	}

	if (Left == true && Right == true)
	{
		MoveIndex = 0.f;
	}
	else if (Left == false && Right == false)
	{
		if (Object->GetObjectDir())
		{
			MoveIndex = 0.5f;
		}
		else
		{
			MoveIndex = -0.5f;
		}
	}
	return MoveIndex;
}

void GamePlaySkill::OnEvent()
{
	Object_HitList.clear();
	Is_CollisionCheck = false;
}

void GamePlaySkill::OffEvent()
{
	int_ComboStuck = 0;
	TimePass = 0.f;
}