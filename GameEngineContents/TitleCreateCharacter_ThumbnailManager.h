#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <vector>

// Ό³Έν :
class TitleCreateCharacterThumbnail;
class TitleCreateCharacter_ThumbnailManager : public GameEngineActor
{
public:
	// constrcuter destructer
	TitleCreateCharacter_ThumbnailManager();
	~TitleCreateCharacter_ThumbnailManager();

	// delete Function
	TitleCreateCharacter_ThumbnailManager(const TitleCreateCharacter_ThumbnailManager& _Other) = delete;
	TitleCreateCharacter_ThumbnailManager(TitleCreateCharacter_ThumbnailManager&& _Other) noexcept = delete;
	TitleCreateCharacter_ThumbnailManager& operator=(const TitleCreateCharacter_ThumbnailManager& _Other) = delete;
	TitleCreateCharacter_ThumbnailManager& operator=(TitleCreateCharacter_ThumbnailManager&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	// void End() override {}
	// void OnEvent() {}
	// void OffEvent() {}
private:
	std::vector<TitleCreateCharacterThumbnail*> Actor_AllThumbnails;
};

