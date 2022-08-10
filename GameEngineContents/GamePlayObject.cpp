#include "PreCompile.h"
#include "GamePlayObject.h"
#include "GamePlayCharacter.h"
#include "GamePlayObjectNPC.h"
#include "MoveManager.h"

GamePlayObject::GamePlayObject() 
	: Dir_RightSide(false)
	, Manager_MoveManager(nullptr)
	, Enum_ObjectType(ObjectType::None)
	, CharacterWeight(0.f)
	, Collision_HitBody(nullptr)
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
	//Manager_CollisionManager = GetLevel()->CreateActor<CollisionManager>();
	//Manager_CollisionManager->SetParent(this);
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
		MsgBoxAssert("������Ʈ Ÿ���� �������� �ʾҽ��ϴ�")
	}
}

