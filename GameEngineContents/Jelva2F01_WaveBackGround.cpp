#include "PreCompile.h"
#include "Jelva2F01_WaveBackGround.h"

Jelva2F01_WaveBackGround::Jelva2F01_WaveBackGround() 
{
}

Jelva2F01_WaveBackGround::~Jelva2F01_WaveBackGround() 
{
}

void Jelva2F01_WaveBackGround::Start()
{
	for (size_t i = 0; i < 3; i++)
	{
		GameEngineTextureRenderer* Wave = CreateComponent<GameEngineTextureRenderer>();
		Wave->SetTexture("Jelva_Sea.png");
		Wave->ScaleToTexture();
		Wave->GetTransform().SetLocalPosition({ 400.f + 662.f * i , -255.f , 3.f });

		Wave = CreateComponent<GameEngineTextureRenderer>();
		Wave->CreateFrameAnimationFolder("Jelva_SeaWave", FrameAnimation_DESC("Jelva_Sea", 0.15f));
		Wave->ChangeFrameAnimation("Jelva_SeaWave");
		Wave->ScaleToTexture();
		Wave->GetTransform().SetLocalPosition({ 400.f + 609.f * i , -255.f , 2.f });
	}
}

void Jelva2F01_WaveBackGround::Update(float _DeltaTime)
{

}