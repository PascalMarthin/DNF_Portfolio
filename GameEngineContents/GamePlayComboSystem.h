#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class GamePlayComboSystem : public GameEngineActor
{
public:
	GamePlayComboSystem();
	~GamePlayComboSystem();

	GamePlayComboSystem(const GamePlayComboSystem& _Other) = delete;
	GamePlayComboSystem(GamePlayComboSystem&& _Other) noexcept = delete;
	GamePlayComboSystem& operator=(const GamePlayComboSystem& _Other) = delete;
	GamePlayComboSystem& operator=(GamePlayComboSystem&& _Other) noexcept = delete;

protected:
	void Start() override {}

	void Update(float _Delta) override {}

private:

};

