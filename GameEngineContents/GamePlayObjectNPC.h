#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class GamePlayObjectNPC : public GameEngineActor
{
public:
	// constrcuter destructer
	GamePlayObjectNPC();
	~GamePlayObjectNPC();

	// delete Function
	GamePlayObjectNPC(const GamePlayObjectNPC& _Other) = delete;
	GamePlayObjectNPC(GamePlayObjectNPC&& _Other) noexcept = delete;
	GamePlayObjectNPC& operator=(const GamePlayObjectNPC& _Other) = delete;
	GamePlayObjectNPC& operator=(GamePlayObjectNPC&& _Other) noexcept = delete;

protected:
	void Start() override;
	//void Update(float _DeltaTime) override;

	// void End() override {}
	// void OnEvent() override {}
	// void OffEvent() override {}

private:

};

