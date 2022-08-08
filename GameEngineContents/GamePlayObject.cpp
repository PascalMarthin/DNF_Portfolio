#include "PreCompile.h"
#include "GamePlayObject.h"
#include "GamePlayCharacter.h"
#include "GamePlayObjectNPC.h"
#include "MoveManager.h"
#include "CollisionManager.h"

GamePlayObject::GamePlayObject() 
	: Dir_RightSide(false)
	, Manager_MoveManager(nullptr)
	, Enum_ObjectType(ObjectType::None)
	, CharacterWeight(0.f)
{
	//GetTransform().SetLocalPosition();
}

GamePlayObject::~GamePlayObject() 
{
}

void GamePlayObject::Start()
{
	GetTransform().SetLocalScale({ MonitorX, MonitorY });
	Manager_MoveManager = CreateComponent<MoveManager>();
	Manager_CollisionManager = GetLevel()->CreateActor<CollisionManager>();
	Manager_CollisionManager->SetParent(this);
	CharacterWeight = 170.f;
	if (dynamic_cast<GamePlayCharacter*>(this))
	{
		Enum_ObjectType = ObjectType::Character;
	}
	else if (dynamic_cast<GamePlayObjectNPC*>(this))
	{
		Enum_ObjectType = ObjectType::NPC;
	}

	if (Enum_ObjectType == ObjectType::None)
	{
		MsgBoxAssert("오브젝트 타입이 설정되지 않았습니다")
	}
}

