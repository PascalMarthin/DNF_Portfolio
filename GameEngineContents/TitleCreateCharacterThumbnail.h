#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "GamePlayEnum.h"

// Ό³Έν :
class TitleCreateCharacterThumbnail : public GameEngineActor
{
public:
	// constrcuter destructer
	TitleCreateCharacterThumbnail();
	~TitleCreateCharacterThumbnail();

	// delete Function
	TitleCreateCharacterThumbnail(const TitleCreateCharacterThumbnail& _Other) = delete;
	TitleCreateCharacterThumbnail(TitleCreateCharacterThumbnail&& _Other) noexcept = delete;
	TitleCreateCharacterThumbnail& operator=(const TitleCreateCharacterThumbnail& _Other) = delete;
	TitleCreateCharacterThumbnail& operator=(TitleCreateCharacterThumbnail&& _Other) noexcept = delete;

	void SetCharacterThumbnail(AllCharacterClass _Class);
	inline void SetCursorSelectOff()
	{
		Texture_CursorSelect->Off();
	}
	inline void SetCursorSelectOn()
	{
		Texture_CursorSelect->On();
	}
	inline AllCharacterClass GetAllCharacterClass()
	{
		return Enum_Class;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	// void End() override {}
	// void OnEvent() {}
	// void OffEvent() {}
	void SetThumbnailClass();

private:
	GameEngineTextureRenderer* Texture_CursorLocate;
	GameEngineTextureRenderer* Texture_CursorSelect;
	GameEngineTextureRenderer* Texture_Thumbnails;

	GameEngineCollision* Collision_Thumbnails;
	AllCharacterClass Enum_Class;
};

