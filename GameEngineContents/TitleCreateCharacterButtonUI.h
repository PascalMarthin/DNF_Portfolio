#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>
// Ό³Έν :
class ButtonComponent;
class TitleCreateCharacterButtonUI : public GameEngineActor
{
public:
	// constrcuter destructer
	TitleCreateCharacterButtonUI();
	~TitleCreateCharacterButtonUI();

	// delete Function
	TitleCreateCharacterButtonUI(const TitleCreateCharacterButtonUI& _Other) = delete;
	TitleCreateCharacterButtonUI(TitleCreateCharacterButtonUI&& _Other) noexcept = delete;
	TitleCreateCharacterButtonUI& operator=(const TitleCreateCharacterButtonUI& _Other) = delete;
	TitleCreateCharacterButtonUI& operator=(TitleCreateCharacterButtonUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	// void End() override {}
	// void OnEvent() {}
	// void OffEvent() {}
private:
	ButtonComponent* Actor_CreateCharacterButton;

	GameEngineTextureRenderer* Texture_BackButton;
	GameEngineCollision* Collision_BackButton;
};

