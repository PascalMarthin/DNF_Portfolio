#include "PreCompile.h"
#include "GameEngineDamageRenderer.h"

//#include "GameEngineTexture.h"
//#include "GameEngineFolderTexture.h"


std::list<GameEngineDamageRenderer*> GameEngineDamageRenderer::Static_AllDamageRenderer;
GameEngineDamageRenderer::GameEngineDamageRenderer()
	: Critical(false)
	, CurrentTime(1.5f)
	, Interval(0.f)
	, CheckTimeEvent(0b0)
{
}

GameEngineDamageRenderer::~GameEngineDamageRenderer() 
{
}




void GameEngineDamageRenderer::Start()
{
	for (size_t i = 0; i < 10; i++)
	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>("Font");
		Renderer->GetTransform().SetLocalPosition({0, 0, -10.f - i});
		All_Font.push_back(Renderer);
			
	}
}

void GameEngineDamageRenderer::SetDamage(unsigned int _Damage)
{
	std::string Damage = std::to_string(_Damage);
	float XPos = 0.f;


	for (size_t i = Damage.size() ; i > 0; i--)
	{

		int Pow = static_cast<int>(pow(10, i - 1));
		int DamagePow = _Damage / Pow;
	
		if (Critical == true)
		{
			All_Font[Damage.size() - i]->SetFolderTextureToIndex("CriticalFont", DamagePow);

		}
		else
		{
			All_Font[Damage.size() - i]->SetFolderTextureToIndex("NomalFont", DamagePow);
		}
		_Damage -= DamagePow * Pow;

		All_Font[Damage.size() - i]->ScaleToTexture();
		XPos += All_Font[Damage.size() - i]->GetTransform().GetLocalScale().x - 8.f;
		All_Font[Damage.size() - i]->GetTransform().SetLocalPosition({ XPos, 0 , 0});
		All_Font[Damage.size() - i]->SetPivot(PIVOTMODE::RIGHTTOP);
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
	Interval -= _Delta;
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
		GetTransform().SetLocalScale(0.5f * (1.0f - ((1.5f - CurrentTime) * 4.f)) + 1.2f * ((1.5f - CurrentTime) * 4.f)); // Lerp
	}
	GetTransform().SetLocalMove({ 0, 35.f * _Delta, 0.1f * _Delta }); // 시간이 렌더링 순위는 지날수록 뒤로
}

void GameEngineDamageRenderer::FirstTime()
{
	if (CheckTimeEvent & DamageFontEvent::FirstTime)
	{
		return;
	}

	for (GameEngineTextureRenderer* Renderer : All_Font)
	{
		if (Renderer->GetCurTexture() == nullptr)
		{
			break;
		}
		Renderer->GetPixelData().PlusColor = { 1, 1, 1, 0.f };
	}
	GetTransform().SetLocalScale({0.5f, 0.5f});
}
void GameEngineDamageRenderer::SecondTime()
{
	if (CheckTimeEvent & DamageFontEvent::SecondTime)
	{
		return;
	}

	for (GameEngineTextureRenderer* Renderer : All_Font)
	{
		if (Renderer->GetCurTexture() == nullptr)
		{
			break;
		}
		Renderer->GetPixelData().PlusColor = float4::ZERO;
	}
	GetTransform().SetLocalScale(float4::WHITE);
}
void GameEngineDamageRenderer::LastTime()
{
	if (CheckTimeEvent & DamageFontEvent::LastTime)
	{
		return;
	}
}


void GameEngineDamageRenderer::FontEnd()
{
	GameEngineDamageRenderer::Static_AllDamageRenderer.remove(this);
	Death();
}