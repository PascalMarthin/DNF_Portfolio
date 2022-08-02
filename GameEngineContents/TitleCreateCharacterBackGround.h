#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include "GamePlayEnum.h"

// Ό³Έν :
class TitleCreateCharacterBackGround : public GameEngineActor
{
public:
	// constrcuter destructer
	TitleCreateCharacterBackGround();
	~TitleCreateCharacterBackGround();

	// delete Function
	TitleCreateCharacterBackGround(const TitleCreateCharacterBackGround& _Other) = delete;
	TitleCreateCharacterBackGround(TitleCreateCharacterBackGround&& _Other) noexcept = delete;
	TitleCreateCharacterBackGround& operator=(const TitleCreateCharacterBackGround& _Other) = delete;
	TitleCreateCharacterBackGround& operator=(TitleCreateCharacterBackGround&& _Other) noexcept = delete;

	void SetChangeClass(GameEngineTexture* _Texture);
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	// void End() override {}
	// void OnEvent() {}
	// void OffEvent() {}
private:
	GameEngineTextureRenderer* Texture_BackGround;
};

