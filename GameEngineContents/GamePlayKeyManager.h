#pragma once
#include <queue>
#include <GameEngineBase/GameEngineMath.h>
#include <GameEngineCore/GameEngineTransformComponent.h>
#include "GamePlayEnum.h"

// Ό³Έν :
class CharacterStatManager;
class GamePlayCharacter;
class PlayerInterface;
class GamePlaySkill;
class CharacterSkillManager;
class GamePlayKeyManager : public GameEngineTransformComponent
{
public:
	// constrcuter destructer
	GamePlayKeyManager();
	~GamePlayKeyManager();

	// delete Function
	GamePlayKeyManager(const GamePlayKeyManager& _Other) = delete;
	GamePlayKeyManager(GamePlayKeyManager&& _Other) noexcept = delete;
	GamePlayKeyManager& operator=(const GamePlayKeyManager& _Other) = delete;
	GamePlayKeyManager& operator=(GamePlayKeyManager&& _Other) noexcept = delete;

	inline EngineInput GetMoveKeyInput() const
	{
		return CurrentMoveInput;
	}
	inline EngineInput GetDoubleMoveKeyInput() const
	{
		return CurrentDoubleMoveInput;
	}

	inline EngineInput GetPushInput_UPDown() const
	{
		return CrrentPushInput_UPDown;
	}
	inline EngineInput GetPushInput_LeftRight() const
	{
		return CrrentPushInput_LeftRight;
	}



	bool Input_AllArrow_DownAndPress() const;
	bool Input_JumpKey_Down() const;
	bool Input_BaseAttKey_DownAndPress() const;
	GamePlaySkill* Input_SkillKeyCheck(CharacterSkillManager* _SkillManager) const;

	float4 Input_Move_Press();
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	// void End() override {}
	void OnEvent();
	// void OffEvent() {}
protected:
	virtual void CheckKeyByWalk(float _DeltaTime, float _MoveSpeed);
	virtual void CheckKeyBySkill(float _DeltaTime, float _MoveSpeed) {}
	virtual void CheckKeyByInterface(float _DeltaTime, float _MoveSpeed);

	EngineInput CurrentMoveInput;
	EngineInput CurrentDoubleMoveInput;
	EngineInput CrrentPushInput_UPDown;
	EngineInput CrrentPushInput_LeftRight;
	float InputDeltaTime;



private:


};

