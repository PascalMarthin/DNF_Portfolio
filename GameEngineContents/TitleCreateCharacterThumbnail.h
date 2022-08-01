#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>

// Ό³Έν :
class TitleCreateCharacter_ThumbnailManager;
class TitleCreateCharacterThumbnail : public GameEngineActor
{
	friend TitleCreateCharacter_ThumbnailManager;
public:
	// constrcuter destructer
	TitleCreateCharacterThumbnail();
	~TitleCreateCharacterThumbnail();

	// delete Function
	TitleCreateCharacterThumbnail(const TitleCreateCharacterThumbnail& _Other) = delete;
	TitleCreateCharacterThumbnail(TitleCreateCharacterThumbnail&& _Other) noexcept = delete;
	TitleCreateCharacterThumbnail& operator=(const TitleCreateCharacterThumbnail& _Other) = delete;
	TitleCreateCharacterThumbnail& operator=(TitleCreateCharacterThumbnail&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	// void End() override {}
	// void OnEvent() {}
	// void OffEvent() {}
private:
	GameEngineTextureRenderer* Texture_CursorLocate;
	GameEngineTextureRenderer* Texture_CursorSelect;
	GameEngineTextureRenderer* Texture_Thumbnails;

	GameEngineCollision* Collision_Thumbnails;
};

