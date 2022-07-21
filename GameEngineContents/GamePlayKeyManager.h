#pragma once
#include <GameEngineCore/GameEngineComponent.h>

// Ό³Έν :
class GamePlayCharacter;
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

	void Update(float _DeltaTime) override;

	// void End() override {}
	// void OnEvent() {}
	// void OffEvent() {}
private:
	void CheckKeyByMove(float _DeltaTime, float _MoveSpeed);
	void CheckKeyBySkill(float _DeltaTime, float _MoveSpeed);
	void CheckKeyByInterface(float _DeltaTime, float _MoveSpeed);


private:
	GamePlayCharacter* Player;


};

