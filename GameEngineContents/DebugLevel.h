#pragma once
#include <GameEngineCore/GameEngineLevel.h>

// Ό³Έν :
class DebugLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	DebugLevel();
	~DebugLevel();

	// delete Function
	DebugLevel(const DebugLevel& _Other) = delete;
	DebugLevel(DebugLevel&& _Other) noexcept = delete;
	DebugLevel& operator=(const DebugLevel& _Other) = delete;
	DebugLevel& operator=(DebugLevel&& _Other) noexcept = delete;

protected:


private:

	void Start() override;

	void Update(float _DeltaTime) override;

	void End() override {}

	// void OnEvent() {}
	// void OffEvent() {}

};

