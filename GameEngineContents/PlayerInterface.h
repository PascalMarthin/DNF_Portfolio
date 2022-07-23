#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class InterfaceHUD;
class PlayerInterface : public GameEngineActor
{
public:
	// constrcuter destructer
	PlayerInterface();
	~PlayerInterface();

	// delete Function
	PlayerInterface(const PlayerInterface& _Other) = delete;
	PlayerInterface(PlayerInterface&& _Other) noexcept = delete;
	PlayerInterface& operator=(const PlayerInterface& _Other) = delete;
	PlayerInterface& operator=(PlayerInterface&& _Other) noexcept = delete;

protected:
	void Start() override;

	void Update(float _DeltaTime) override;

	// void End() override {}
	// void OnEvent() {}
	// void OffEvent() {}

private:
	InterfaceHUD* PlayerHUD;


};

