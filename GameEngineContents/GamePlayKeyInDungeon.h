#pragma once
#include "GamePlayKeyManager.h"

// Ό³Έν :
class GamePlayCharacter;
class GamePlayKeyInDungeon : public GamePlayKeyManager
{
public:
	// constrcuter destructer
	GamePlayKeyInDungeon();
	~GamePlayKeyInDungeon();

	// delete Function
	GamePlayKeyInDungeon(const GamePlayKeyInDungeon& _Other) = delete;
	GamePlayKeyInDungeon(GamePlayKeyInDungeon&& _Other) noexcept = delete;
	GamePlayKeyInDungeon& operator=(const GamePlayKeyInDungeon& _Other) = delete;
	GamePlayKeyInDungeon& operator=(GamePlayKeyInDungeon&& _Other) noexcept = delete;

protected:
	void Start() override;

	void Update(float _DeltaTime) override;

	// void End() override {}
	// void OnEvent() {}
	// void OffEvent() {}
protected:
	void CheckKeyByMove(float _DeltaTime, float _MoveSpeed) override;
	void CheckKeyBySkill(float _DeltaTime, float _MoveSpeed) override;
	void CheckKeyByInterface(float _DeltaTime, float _MoveSpeed) override;

private:

};

