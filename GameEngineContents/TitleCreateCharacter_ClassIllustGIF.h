#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineFolderTexture.h>

// Ό³Έν :
class TitleCreateCharacter_ClassIllustGIF : public GameEngineActor
{
public:
	// constrcuter destructer
	TitleCreateCharacter_ClassIllustGIF();
	~TitleCreateCharacter_ClassIllustGIF();

	// delete Function
	TitleCreateCharacter_ClassIllustGIF(const TitleCreateCharacter_ClassIllustGIF& _Other) = delete;
	TitleCreateCharacter_ClassIllustGIF(TitleCreateCharacter_ClassIllustGIF&& _Other) noexcept = delete;
	TitleCreateCharacter_ClassIllustGIF& operator=(const TitleCreateCharacter_ClassIllustGIF& _Other) = delete;
	TitleCreateCharacter_ClassIllustGIF& operator=(TitleCreateCharacter_ClassIllustGIF&& _Other) noexcept = delete;

	void CreateClassIllustGIF(const std::string& _AnimationName , const std::string& _TextureName);
	void SetClassIllustGIF(const std::string& _AnimationName);
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	// void End() override {}
	// void OnEvent() {}
	void OffEvent() override;
private:
	GameEngineTextureRenderer* FolderTexture_CurrentGIF;
	GameEngineTextureRenderer* FolderTexture_BackBufferGIF;
	float Float_TextureBackDelay;
	bool ChangeGIF;
	std::string CurrentAnimationName;
};

