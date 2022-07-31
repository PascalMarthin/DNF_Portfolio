#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>

// Ό³Έν :
class SelectCharacterLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	SelectCharacterLevel();
	~SelectCharacterLevel();

	// delete Function
	SelectCharacterLevel(const SelectCharacterLevel& _Other) = delete;
	SelectCharacterLevel(SelectCharacterLevel&& _Other) noexcept = delete;
	SelectCharacterLevel& operator=(const SelectCharacterLevel& _Other) = delete;
	SelectCharacterLevel& operator=(SelectCharacterLevel&& _Other) noexcept = delete;

protected:
	void Start() override;

	void Update(float _DeltaTime) override;

	void End() override {}

	// void OnEvent() {}
	// void OffEvent() {}
private:

};

