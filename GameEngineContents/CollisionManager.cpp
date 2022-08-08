#include "PreCompile.h"
#include "CollisionManager.h"

CollisionManager::CollisionManager() 
	: Enum_ObjectType(ObjectType::None)
{
}

CollisionManager::~CollisionManager() 
{
}


// -------------Start-------------
void CollisionManager::Start()
{

}

GameEngineCollision* CollisionManager::CreateCollision(const std::string _Name, CollisionOrder _Order, const float4& _Scale, const float4& _Pivot)
{
	GameEngineCollision* NewCollision = CreateComponent<GameEngineCollision>(_Name);
	NewCollision->GetTransform().SetLocalScale(_Scale);
	NewCollision->GetTransform().SetLocalPosition(_Pivot);
	NewCollision->ChangeOrder(_Order);
	return NewCollision;
}

// -------------Update-------------
void CollisionManager::Update(float _DeltaTime)
{

}

