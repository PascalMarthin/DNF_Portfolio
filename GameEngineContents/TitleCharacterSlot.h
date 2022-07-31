#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class TitleCharacterSlot : public GameEngineActor
{
public:
	// constrcuter destructer
	TitleCharacterSlot();
	~TitleCharacterSlot();

	// delete Function
	TitleCharacterSlot(const TitleCharacterSlot& _Other) = delete;
	TitleCharacterSlot(TitleCharacterSlot&& _Other) noexcept = delete;
	TitleCharacterSlot& operator=(const TitleCharacterSlot& _Other) = delete;
	TitleCharacterSlot& operator=(TitleCharacterSlot&& _Other) noexcept = delete;

protected:
	void Start() override;

	void Update(float _DeltaTime) override;

	// void End() override {}
	// void OnEvent() {}
	// void OffEvent() {}
private:
	GameEngineTextureRenderer* Slot_Border;
	GameEngineTextureRenderer* Magic_Circle;

};

