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


	// -------------OnOff--------------------
	static inline void SetOn(GameEngineUpdateObject* _Object)
	{
		if (_Object->IsUpdate())
		{
			return;
		}
		else
		{
			_Object->On();
		}
	}
	static inline void SetOff(GameEngineUpdateObject* _Object)
	{
		if (!_Object->IsUpdate())
		{
			return;
		}
		else
		{
			_Object->Off();
		}
	}
	
	virtual inline float4 GetScale()
	{
		return GetTransform().GetLocalScale();
	}


	//-------------------------
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

	inline void SetDirSwitch()
	{
		if (Dir_RightSide)
		{
			GetTransform().PixLocalNegativeX();
		}
		else
		{
			GetTransform().PixLocalPositiveX();
		}
		Dir_RightSide = !Dir_RightSide;
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
	inline CharacterStatManager* GetStatManager() const
	{
		return Manager_StatManager;
	}



protected:
	void Start() override;


protected:

	// ----------Manager-----------
	MoveManager* Manager_MoveManager;
	CharacterStatManager* Manager_StatManager;

	// -------------------Battle-------------------
public:
	virtual void BeHit(GamePlaySkill* _Skill, GameEngineCollision* _HitCollision, GamePlayObject* _HitObject, int _Index, unsigned int _Damage);
	virtual void BeHitHold();
	virtual void BeHitEnd();
	// virtual void BeHit(적 대미지);
	virtual void Jump_GoingDown() 
	{
		JumpGoingDown = true;
	};

	virtual void LandingEnd() {}
	virtual void LandingEnd_Down() {}
	//virtual void LandingEnd_Down() {}

	void SetDamage(unsigned int _Damage);
	virtual unsigned int  SetHPFromHit(unsigned int _Damage) { return 0; }


	virtual void SetFSManager() {}


protected:
	bool JumpGoingDown;
	float DownWait;
	// ------------------Effect--------------------
public:
	void Ani_BindEndOff(const FrameAnimation_DESC& _Desc);

protected:
	std::map<std::string, std::vector<GameEngineTextureRenderer*>> map_NomalEffect;
	
	
private:
	void HitEffect(GameEngineTextureRenderer* _Texture, GameEngineCollision* _HitCollision, const std::string& _AniName);

protected:
	// --------------------------------------------
	UnitType Enum_UnitType;
	ObjectType Enum_ObjectType;
	float CharacterWeight;
private:

	bool Dir_RightSide;
};

