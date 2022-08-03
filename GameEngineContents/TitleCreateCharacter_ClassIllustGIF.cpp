#include "PreCompile.h"
#include "TitleCreateCharacter_ClassIllustGIF.h"
#include "GamePlayEnum.h"

TitleCreateCharacter_ClassIllustGIF::TitleCreateCharacter_ClassIllustGIF()
	: FolderTexture_CurrentGIF(nullptr)
	, FolderTexture_BackBufferGIF(nullptr)
	, ChangeGIF(false)
	, Float_TextureBackDelay(0.f)
{
}

TitleCreateCharacter_ClassIllustGIF::~TitleCreateCharacter_ClassIllustGIF() 
{
}

void TitleCreateCharacter_ClassIllustGIF::Start()
{
	FolderTexture_CurrentGIF = CreateComponent<GameEngineTextureRenderer>();
	FolderTexture_BackBufferGIF = CreateComponent<GameEngineTextureRenderer>();
	FolderTexture_CurrentGIF->GetTransform().SetLocalScale({ 1067, 600 });
	FolderTexture_BackBufferGIF->GetTransform().SetLocalScale({ 1067, 600 });
	FolderTexture_BackBufferGIF->SetTexture("Null.png");

}
void TitleCreateCharacter_ClassIllustGIF::Update(float _DeltaTime)
{
	if (ChangeGIF)
	{
		Float_TextureBackDelay += _DeltaTime;
		FolderTexture_CurrentGIF->GetTransform().SetLocalMove({ -1200.f * _DeltaTime, 0 });
		FolderTexture_BackBufferGIF->GetTransform().SetLocalMove({ -1200.f * _DeltaTime, 0 });
		FolderTexture_BackBufferGIF->GetColorData().PlusColor = { 0, 0, 0 , -Float_TextureBackDelay * 2.f };
		if (FolderTexture_CurrentGIF->GetTransform().GetLocalPosition().x < 0.f )
		{
			FolderTexture_CurrentGIF->GetTransform().SetLocalPosition({0, 0, 5});
			FolderTexture_BackBufferGIF->GetTransform().SetLocalPosition({ 0 , 0 , 10});
			FolderTexture_BackBufferGIF->GetTransform().SetLocalPosition({ 0 , 0 , ZSortOrder::BackGround + 10 });
			FolderTexture_BackBufferGIF->ChangeFrameAnimation(CurrentAnimationName);
			FolderTexture_BackBufferGIF->GetColorData().PlusColor = { float4::ZERO };
			ChangeGIF = false;
		}
	}
}

void TitleCreateCharacter_ClassIllustGIF::CreateClassIllustGIF(const std::string& _AnimationName, const std::string& _Name)
{
	FolderTexture_CurrentGIF->CreateFrameAnimationFolder(_AnimationName, FrameAnimation_DESC(_Name , 0.04f));
	FolderTexture_BackBufferGIF->CreateFrameAnimationFolder(_AnimationName, FrameAnimation_DESC(_Name, 0.04f));
}

void TitleCreateCharacter_ClassIllustGIF::SetClassIllustGIF(const std::string& _AnimationName)
{
	CurrentAnimationName = _AnimationName;
	FolderTexture_CurrentGIF->ChangeFrameAnimation(_AnimationName);

	FolderTexture_CurrentGIF->GetTransform().SetLocalPosition({GameEngineWindow::GetScale().hx(), 0});
	FolderTexture_BackBufferGIF->GetTransform().SetLocalPosition({ 0 , 0 , 10 });
	Float_TextureBackDelay = 0.f;
	ChangeGIF = true;
}