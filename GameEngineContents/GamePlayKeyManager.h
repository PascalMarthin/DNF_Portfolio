#pragma once
#include <GameEngineCore/GameEngineComponent.h>

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

protected:
	void Start() override;

	// void End() override {}
	// void OnEvent() {}
	// void OffEvent() {}
protected:
	virtual void CheckKeyByMove(float _DeltaTime, float _MoveSpeed);
	virtual void CheckKeyBySkill(float _DeltaTime, float _MoveSpeed) {}
	virtual void CheckKeyByInterface(float _DeltaTime, float _MoveSpeed);


	GamePlayCharacter* Player;

	CharacterStatManager** PlayerStatManager;
	PlayerInterface** PlayerUserInterface;
private:


};

