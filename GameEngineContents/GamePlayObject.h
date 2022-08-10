#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include "GamePlayEnum.h"

// Ό³Έν :
class MoveManager;
class GamePlayObject : public GameEngineActor
{
public:
	// constrcuter destructer
	GamePlayObject();
	~GamePlayObject();

	// delete Function
	GamePlayObject(const GamePlayObject& _Other) = delete;
	GamePlayObject(GamePlayObject&& _Other) noexcept = delete;
	GamePlayObject& operator=(const GamePlayObject& _Other) = delete;
	GamePlayObject& operator=(GamePlayObject&& _Other) noexcept = delete;

	//inline float4& GetPosToInGame()
	//{
	//	return ObjectPos;
	//}
	inline void SetRightDir()
	{
		GetTransform().PixLocalPositiveX();
		Dir_RightSide = true;
	}
	inline void SetLeftDir()
	{
		GetTransform().PixLocalNegativeX();
		Dir_RightSide = false;
	}

	inline bool GetObjectDir() const
	{
		return Dir_RightSide;
	}

	inline float GetCharacterWeight() const
	{
		return CharacterWeight;
	}
	inline ObjectType GetObjectType() const
	{
		return Enum_ObjectType;
	}

	inline GameEngineCollision* GetBodyCollision() const
	{
		return Collision_HitBody;
	}


protected:
	void Start() override;


protected:
	MoveManager* Manager_MoveManager;

	//--------------------Collision---------------
	GameEngineCollision* Collision_HitBody;
	//CollisionManager* Manager_CollisionManager;

private:
	//float4 ObjectPos;
	ObjectType Enum_ObjectType;

	bool Dir_RightSide;
	float CharacterWeight;
};

