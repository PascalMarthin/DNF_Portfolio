#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "GamePlayEnum.h"

// Ό³Έν :
class CollisionManager : public GameEngineActor
{
public:
	// constrcuter destructer
	CollisionManager();
	~CollisionManager();

	// delete Function
	CollisionManager(const CollisionManager& _Other) = delete;
	CollisionManager(CollisionManager&& _Other) noexcept = delete;
	CollisionManager& operator=(const CollisionManager& _Other) = delete;
	CollisionManager& operator=(CollisionManager&& _Other) noexcept = delete;

	inline void SetObjectType(ObjectType _Type)
	{
		Enum_ObjectType = _Type;
	}
	inline ObjectType GetObjectType() const
	{
		return Enum_ObjectType;
	}

	GameEngineCollision* CreateCollision(const std::string _Name, CollisionOrder _Order, const float4& _Scale, const float4& _Pivot = float4::ZERO);
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	// void End() override {}
	// void OnEvent() override {}
	// void OffEvent() override {}
private:
	std::vector<GameEngineCollision*> AllCollision;
	ObjectType Enum_ObjectType;
};

