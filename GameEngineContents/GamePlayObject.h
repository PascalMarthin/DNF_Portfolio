#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include "GamePlayEnum.h"

// 설명 :
enum class UnitType
{
	None,
	Unit,
	Building,
};
class MoveManager;
class GamePlaySkill;
class GamePlayDataBase;
class CharacterStatManager;
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


	inline MoveManager* GetMoveManager() const
	{
		return Manager_MoveManager;
	}


protected:
	void Start() override;


protected:

	// ----------Manager-----------
	MoveManager* Manager_MoveManager;
	CharacterStatManager* Manager_StatManager;

	// -------------------Battle-------------------
public:
	virtual void BeHit(GamePlaySkill* _Skill, const GamePlayDataBase* _Character, int _Index);
	// virtual void BeHit(적 대미지);


	// --------------------------------------------
	UnitType Enum_UnitType;
private:
	ObjectType Enum_ObjectType;

	bool Dir_RightSide;
	float CharacterWeight;
};

