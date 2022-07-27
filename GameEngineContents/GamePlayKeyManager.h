#pragma once
#include <queue>
#include <GameEngineCore/GameEngineComponent.h>
#include "GamePlayEnum.h"

// Ό³Έν :
class CharacterStatManager;
class GamePlayCharacter;
class PlayerInterface;
class GamePlayKeyManager : public GameEngineComponent
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


protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	// void End() override {}
	//void OnEvent();
	// void OffEvent() {}
protected:
	virtual void CheckKeyByWalk(float _DeltaTime, float _MoveSpeed);
	virtual void CheckKeyBySkill(float _DeltaTime, float _MoveSpeed) {}
	virtual void CheckKeyByInterface(float _DeltaTime, float _MoveSpeed);

	EngineInput CurrentMoveInput;
	EngineInput CurrentDoubleMoveInput;
	float InputDeltaTime;
private:

};

