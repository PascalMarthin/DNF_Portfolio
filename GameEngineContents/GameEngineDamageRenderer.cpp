#include "PreCompile.h"
#include "GameEngineDamageRenderer.h"

//#include "GameEngineTexture.h"
//#include "GameEngineFolderTexture.h"


std::list<GameEngineDamageRenderer*> GameEngineDamageRenderer::Static_AllDamageRenderer;
GameEngineDamageRenderer::GameEngineDamageRenderer()
	: Critical(false)
	, CurrentTime(1.5f)
	, MaxDamage(false)
	, CheckTimeEvent(0b0)
	, FontSize(1.f)
{
}

GameEngineDamageRenderer::~GameEngineDamageRenderer() 
{
}




void GameEngineDamageRenderer::Start()
{
	for (size_t i = 0; i < 10; i++)
	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>("DamageFont");
		Renderer->GetTransform().SetLocalPosition({0, 0, -10.f - i});
		All_Font.push_back(Renderer);
			
	}
}

void GameEngineDamageRenderer::SetDamage(unsigned int _Damage)
{
	FontSize = 1.2f;
	if (_Damage > 99999999)
	{
		MaxDamage = true;
		{
			GetTransform().SetLocalMove({ 0, 0, -100.f });
			All_Font[0]->SetFolderTextureToIndex("MaxDamageFont", 0);
			All_Font[0]->GetTransform().SetLocalPosition({0, 0, -2});
			All_Font[1]->SetFolderTextureToIndex("MaxDamageFont", 1);
			All_Font[1]->GetTransform().SetLocalPosition({ 0, 0, 0 });
			All_Font[2]->SetFolderTextureToIndex("MaxDamageFont", 2);
			All_Font[2]->GetTransform().SetLocalPosition({ 0, 0, -1 });

			All_Font[0]->ScaleToTexture();
			All_Font[1]->ScaleToTexture();
			All_Font[2]->ScaleToTexture();

			for (size_t i = 3; i < 8; i++)
			{
				All_Font[i]->Death();
				All_Font[i] = nullptr;
			}
		}

	}
	else
	{
		std::string Damage = std::to_string(_Damage);
		float XPos = 0.f;

		for (size_t i = 0; i < Damage.size(); i++)
		{

			//-80
			//int Pow = static_cast<int>(pow(10, i - 1));
			int DamagePow = Damage[Damage.size() - i - 1] - 48;

			if (Critical == false)
			{
				All_Font[i]->SetFolderTextureToIndex("CriticalFont", DamagePow);

				XPos += 2;
				if (DamagePow == 1)
				{
					XPos += 6;
				}
			}
			else
			{
				All_Font[i]->SetFolderTextureToIndex("NomalFont", DamagePow);
				switch (DamagePow)
				{
				case 6:
					XPos += 1;
					break;
				case 7:
					XPos += 2;
					break;
				default:
					break;
				}
			}

			All_Font[i]->ScaleToTexture();

			XPos -= All_Font[i]->GetTransform().GetLocalScale().x - 5;
			All_Font[i]->GetTransform().SetLocalPosition({ XPos, 0 , 0 });
			All_Font[i]->SetPivot(PIVOTMODE::LEFTTOP);
		}
	}

	GameEngineDamageRenderer::SetPrintingFont(this);
	GameEngineDamageRenderer::Static_AllDamageRenderer.push_back(this);
}

void GameEngineDamageRenderer::SetPrintingFont(GameEngineDamageRenderer* _FontRenderer)
{
	float Hight = _FontRenderer->GetTextureSize().y;
	for (GameEngineDamageRenderer* Renderer : Static_AllDamageRenderer)
	{
		Renderer->GetTransform().SetLocalMove({ 0, Hight, 0 });
	}
}



void GameEngineDamageRenderer::Update(float _Delta)
{
	CurrentTime -= _Delta;
	//Interval -= _Delta;
	if (CurrentTime <= 0.f) // AccDeath를 안쓰는 이유 : 죽는 시간을 내가 원할때 하고 싶어서
	{
		FontEnd();
	}
	else if (CurrentTime <= 0.25f) // Disappear
	{
		LastTime();
	}
	else if (CurrentTime <= 1.25f) // 크기 조절
	{
		SecondTime();

	}
	else if (CurrentTime <= 1.5f) // 흰색 바탕에 커짐
	{
		FirstTime();
		if (MaxDamage == true)
		{
			if (CurrentTime <= 1.35f)
			{
				All_Font[2]->GetTransform().SetLocalPosition({ 0, 0, -3.f });
			}
			float LerpTime = ((1.5f - CurrentTime) / 0.25f);

			{
				All_Font[0]->SetScaleRatio(5.f * (1 - LerpTime) + 1.f * LerpTime);
				All_Font[0]->ScaleToTexture();
				All_Font[0]->GetPixelData().MulColor = { 1, 1, 1, 0.2f * (1 - LerpTime) + 1.f * LerpTime };
			}

			{
				All_Font[1]->SetScaleRatio(2.f * (1 - LerpTime) + 1.f * LerpTime);
				All_Font[1]->ScaleToTexture();
				All_Font[1]->GetPixelData().MulColor = { 1, 1, 1, 0.6f * (1 - LerpTime) + 1.f * LerpTime };
			}

		}
		else
		{
			GetTransform().SetLocalScale(FontSize * 0.5f * (1.0f - ((1.5f - CurrentTime) * 4.f)) + FontSize * ((1.5f - CurrentTime) * 5.f)); // Lerp
		}
		
	}
	GetTransform().SetLocalMove({ 0, 50.f * _Delta, 0.1f * _Delta }); // 시간이 렌더링 순위는 지날수록 뒤로
}

void GameEngineDamageRenderer::FirstTime()
{
	if (CheckTimeEvent & DamageFontEvent::FirstTime)
	{
		return;
	}
	if (MaxDamage == true)
	{
		All_Font[0]->SetScaleRatio(5.f);
		All_Font[0]->ScaleToTexture();
		All_Font[0]->GetPixelData().MulColor = { 1, 1, 1, 0.2f };

		All_Font[0]->SetScaleRatio(2.f);
		All_Font[0]->ScaleToTexture();
		All_Font[1]->GetPixelData().MulColor = { 1, 1, 1, 0.6f };
	}
	else
	{
		for (GameEngineTextureRenderer* Renderer : All_Font)
		{
			if (Renderer->GetCurTexture() == nullptr)
			{
				break;
			}
			Renderer->GetPixelData().PlusColor = { 1, 1, 1, 0.f };
		}
		GetTransform().SetLocalScale({ FontSize * 0.5f, FontSize * 0.5f });
	}

	CheckTimeEvent |= DamageFontEvent::FirstTime;
}
void GameEngineDamageRenderer::SecondTime()
{
	if (CheckTimeEvent & DamageFontEvent::SecondTime)
	{
		return;
	}

	if (MaxDamage == true)
	{
		All_Font[0]->SetScaleRatio(1.f);
		All_Font[0]->ScaleToTexture();
		All_Font[0]->GetPixelData().MulColor = float4::WHITE;
		All_Font[0]->GetTransform().SetLocalPosition({ 0, 0, -2.f });

		All_Font[1]->SetScaleRatio(1.f);
		All_Font[1]->ScaleToTexture();
		All_Font[1]->GetPixelData().MulColor = float4::WHITE;

		All_Font[2]->GetTransform().SetLocalPosition({ 0, 0, -1.f });
	}
	else
	{
		for (GameEngineTextureRenderer* Renderer : All_Font)
		{
			if (Renderer->GetCurTexture() == nullptr)
			{
				break;
			}
			Renderer->GetPixelData().PlusColor = float4::ZERO;
		}
		GetTransform().SetLocalScale(FontSize);
	}

	CheckTimeEvent |= DamageFontEvent::SecondTime;
}
void GameEngineDamageRenderer::LastTime()
{
	if (CheckTimeEvent & DamageFontEvent::LastTime)
	{
		return;
	}
	CheckTimeEvent |= DamageFontEvent::LastTime;
}


void GameEngineDamageRenderer::FontEnd()
{
	GameEngineDamageRenderer::Static_AllDamageRenderer.remove(this);
	Death();
}