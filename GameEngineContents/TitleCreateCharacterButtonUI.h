#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>
// ���� :
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

	inline ButtonComponent* GetCreateCharacterButton()
	{
		return Actor_CreateCharacterButton;
	}
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	// void End() override {}
	//void OnEvent() override;
	// void OffEvent() {}
private:
	ButtonComponent* Actor_CreateCharacterButton;
	ButtonComponent* Actor_GoBackButton;

	GameEngineTextureRenderer* Texture_BackButton;
	GameEngineCollision* Collision_BackButton;
};

