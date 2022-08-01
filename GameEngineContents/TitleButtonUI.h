#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>
// Ό³Έν :
class TitleButtonUI : public GameEngineActor
{
public:
	// constrcuter destructer
	TitleButtonUI();
	~TitleButtonUI();

	// delete Function
	TitleButtonUI(const TitleButtonUI& _Other) = delete;
	TitleButtonUI(TitleButtonUI&& _Other) noexcept = delete;
	TitleButtonUI& operator=(const TitleButtonUI& _Other) = delete;
	TitleButtonUI& operator=(TitleButtonUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	// void End() override {}
	// void OnEvent() {}
	// void OffEvent() {}

private:
	GameEngineTextureRenderer* Texture_Button_GameStart;
	GameEngineTextureRenderer* Texture_Button_CreateCharacter;
	GameEngineCollision* Collision_Button_GameStart;
	GameEngineCollision* Collision_Button_CreateCharacter;

	bool Check_Collision_Button_GameStart();
	bool Check_Collision_Button_CreateCharacter();
};

