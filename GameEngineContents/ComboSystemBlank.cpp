#include "PreCompile.h"
#include "ComboSystemBlank.h"
#include "GamePlayComboSystem.h"

ComboSystemBlank::ComboSystemBlank()
	: Texture_Combo_bonus(nullptr)
	, Texture_Combo_Aerial(nullptr)
	, Texture_Combo_Effect(nullptr)
	, EndCombo(false)
	, CurrentClass(ComboClass::None)
	, FontSizeUp(false)
{

}

ComboSystemBlank::~ComboSystemBlank() 
{
}

void ComboSystemBlank::Start()
{
	Texture_Combo_bonus = CreateComponent<GameEngineUIRenderer>("Combo_bonus");
	//Texture_Combo_bonus->GetTransform().SetLocalPosition({ -77.5f, 0 });
	Texture_Combo_bonus->SetTexture(GamePlayComboSystem::TextureR_Combo_bonus->GetTexture(2));
	Texture_Combo_bonus->ScaleToTexture();
	Texture_Combo_bonus->Off();


	Texture_Combo_Aerial = CreateComponent<GameEngineUIRenderer>("Aerial");
	Texture_Combo_Aerial->GetTransform().SetLocalPosition({ -27.f , 0, -0.01f});

	Texture_Combo_Aerial->SetTexture(GamePlayComboSystem::TextureR_Combo_bonus->GetTexture(1));
	Texture_Combo_Aerial->ScaleToTexture();
	Texture_Combo_Aerial->Off();


	Texture_Combo_Effect = CreateComponent<GameEngineUIRenderer>("Combo_bonus_Effect");
	Texture_Combo_Effect->GetTransform().SetLocalPosition({ 45.f , 0 });
	Texture_Combo_Effect->SetTexture(GamePlayComboSystem::TextureR_Combo_bonus->GetTexture(0));
	Texture_Combo_Effect->ScaleToTexture();
	Texture_Combo_Effect->Off();

	float Len = -10.f;
	for (size_t i = 0; i < 3; i++)
	{
		GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>("Combo_num");
		Renderer->GetTransform().SetLocalPosition({ -Len, 0 });
		Renderer->GetTransform().SetLocalScale({ 15, 18 });
		//Renderer->SetPivot(PIVOTMODE::RIGHTTOP);
		Len += 10.f;
		Renderer->Off();
		Texture_Combo_num.push_back(Renderer);

	}

	Combo_BrightTime = 0;
	Combo_bonus_Time = 0;
	Off();
}

void ComboSystemBlank::ReSet()
{
	Texture_Combo_bonus->GetPixelData().MulColor.a = 1;
	Texture_Combo_bonus->GetTransform().SetLocalPosition({ 77.5f, 0 });
	Texture_Combo_Aerial->GetPixelData().MulColor.a = 0.7f;
	Texture_Combo_Aerial->SetScaleRatio(1.f);
	Texture_Combo_Aerial->ScaleToTexture();
	Texture_Combo_Aerial->GetTransform().SetLocalPosition({ -27.f, 0 });
	Texture_Combo_Aerial->Off();
	Texture_Combo_Effect->GetPixelData().MulColor.a = 0.8f;
	Texture_Combo_Effect->GetTransform().SetLocalPosition(float4::ZERO);
	Texture_Combo_Effect->SetScaleRatio(1.2f);
	Texture_Combo_Effect->ScaleToTexture();
	Texture_Combo_Effect->On();
	EndCombo = false;
	FontSizeUp = false;

	for (size_t i = 0; i < 3; i++)
	{
		if (Texture_Combo_num[i]->GetCurTexture() != nullptr)
		{
			Texture_Combo_num[i]->GetPixelData().MulColor.a = 1;
			Texture_Combo_num[i]->GetTransform().SetLocalPosition({ Texture_Combo_num[i]->GetTransform().GetLocalPosition().x, 0 });
			Texture_Combo_num[i]->SetScaleRatio(1.f);
			Texture_Combo_num[i]->ScaleToTexture();
		}
	}
}

void ComboSystemBlank::SetBrighting()
{
	Texture_Combo_bonus->GetPixelData().MulColor.a = 1;
	Texture_Combo_bonus->GetTransform().SetLocalPosition({ 77.5f, 0});

	Texture_Combo_Aerial->SetTexture(Texture_Combo_bonus->GetCurTexture());


	Texture_Combo_Aerial->GetPixelData().MulColor.a = 0.7f;
	Texture_Combo_Aerial->SetScaleRatio(1.f);
	Texture_Combo_Aerial->ScaleToTexture();
	Texture_Combo_Aerial->GetTransform().SetLocalPosition({-27.f, 0});
	Texture_Combo_Aerial->Off();
	Texture_Combo_Effect->GetPixelData().MulColor.a = 0.8f;
	Texture_Combo_Effect->GetTransform().SetLocalPosition(float4::ZERO);
	Texture_Combo_Effect->SetScaleRatio(1.2f);
	Texture_Combo_Effect->ScaleToTexture();
	Texture_Combo_Effect->On();
	Combo_BrightTime = 2.f;
	Combo_bonus_Time = 3.f;
	EndCombo = false;

	float Len = -10.f;
	for (size_t i = 0; i < 3; i++)
	{
		Texture_Combo_num[i]->GetPixelData().MulColor.a = 1;
		Texture_Combo_num[i]->GetTransform().SetLocalPosition({ -Len, 0});
		Len += 10.f;
		Texture_Combo_num[i]->SetScaleRatio(1.f);
	}
}
void ComboSystemBlank::SetComboClass(ComboClass _Class)
{
	CurrentClass = _Class;

	GamePlayComboSystem::GetInst()->map_ComboStuck[_Class] += 1;
	if (ComboClass::BeHit == _Class || ComboClass::MultiHit == _Class || ComboClass::None == _Class)
	{
		return;
	}
	for (size_t i = 0; i < 3; i++)
	{
		Texture_Combo_num[i]->Off();
	}


	switch (CurrentClass)
	{
	case ComboClass::Aerial:
		Texture_Combo_bonus->SetTexture(GamePlayComboSystem::TextureR_Combo_bonus->GetTexture(1));
		break;
	case ComboClass::CounterHold:
		Texture_Combo_bonus->SetTexture(GamePlayComboSystem::TextureR_Combo_bonus->GetTexture(2));
		break;
	case ComboClass::GhostFrame:
		Texture_Combo_bonus->SetTexture(GamePlayComboSystem::TextureR_Combo_bonus->GetTexture(3));
		break;
	case ComboClass::NearMiss:
		Texture_Combo_bonus->SetTexture(GamePlayComboSystem::TextureR_Combo_bonus->GetTexture(4));
		break;
	case ComboClass::Combo:
		Texture_Combo_bonus->SetTexture(GamePlayComboSystem::TextureR_Combo_bonus->GetTexture(5));
		RenewalCombo();
		break;
	case ComboClass::BackAttack:
		Texture_Combo_bonus->SetTexture(GamePlayComboSystem::TextureR_Combo_bonus->GetTexture(6));
		break;
	case ComboClass::Critical:
		Texture_Combo_bonus->SetTexture(GamePlayComboSystem::TextureR_Combo_bonus->GetTexture(7));
		break;
	case ComboClass::Counter:
		Texture_Combo_bonus->SetTexture(GamePlayComboSystem::TextureR_Combo_bonus->GetTexture(8));
		break;
	case ComboClass::LastKill:
		Texture_Combo_bonus->SetTexture(GamePlayComboSystem::TextureR_Combo_bonus->GetTexture(9));
		break;
	case ComboClass::None:
		Off();
		break;
	default:

		return;
		//MsgBoxAssert("아직 설저오디지 않았습니다");
		break;
	}
	ReSet();

	Combo_BrightTime = 0;
	Combo_bonus_Time = 3.f;

}

bool ComboSystemBlank::RenewalCombo()
{
	return RenewalCombo(GetParent<GamePlayComboSystem>()->ComboStack);
}

bool ComboSystemBlank::RenewalCombo(unsigned int _Index)
{
	if (CurrentClass != ComboClass::Combo)
	{
		return false;
		// 어썰트? 아니면 리턴?
	}
	std::string Index = std::to_string(_Index);
	for (size_t i = 0; i < 3; i++)
	{
		if (Index.empty())
		{
			Texture_Combo_num[i]->Off();
			continue;
		}
		Texture_Combo_num[i]->SetTexture(GamePlayComboSystem::TextureR_Combo_num->GetTexture(static_cast<int>(Index.back()) - 48));
		Texture_Combo_num[i]->SetScaleRatio(2.0f);
		Texture_Combo_num[i]->ScaleToTexture();
		Texture_Combo_num[i]->On();
		Texture_Combo_num[i]->GetPixelData().MulColor.a = 1;
		Texture_Combo_num[i]->GetTransform().SetLocalPosition({ Texture_Combo_num[i]->GetTransform().GetLocalPosition().x, 0 });

		Index.pop_back();
	}
	Combo_bonus_Time = 2.f;
	FontSizeUp = true;

	Texture_Combo_bonus->GetPixelData().MulColor.a = 1;
	Texture_Combo_bonus->GetTransform().SetLocalPosition({ 0 , 0 });


	return true;
}

void ComboSystemBlank::Update(float _Delta)
{

	if (FontSizeUp == true)
	{
		for (size_t i = 0; i < 3; i++)
		{
			if (Texture_Combo_num[i]->IsUpdate())
			{
				Texture_Combo_num[i]->SetScaleRatio(Texture_Combo_num[i]->GetScaleRatio() - _Delta * 10.f);
				if (Texture_Combo_num[i]->GetScaleRatio() < 1.f)
				{
					Texture_Combo_num[i]->SetScaleRatio(1.f);
					FontSizeUp = false;
				}
				Texture_Combo_num[i]->ScaleToTexture();
			}
		}
	}

	if (Combo_BrightTime > 1.f)
	{
		Texture_Combo_Effect->On();
		Texture_Combo_bonus->On();
		Texture_Combo_Effect->GetPixelData().MulColor.a = 1.f - (Combo_BrightTime - 1.f) - 0.2f;

		float Range = 77.5f * (Combo_BrightTime - 1.f);

		Texture_Combo_bonus->GetTransform().SetLocalPosition({ Range, 0 });

		Texture_Combo_Effect->SetScaleRatio(1.2f * (1 - (Combo_BrightTime - 1.f)) + 1.0f * (Combo_BrightTime - 1.f));
		Texture_Combo_Effect->GetTransform().SetLocalPosition({ 45.f + Range, 0 });

		Texture_Combo_Effect->ScaleToTexture();

		if (CurrentClass == ComboClass::Combo)
		{
			for (int i = 0; i < 3; i++)
			{
				Texture_Combo_num[i]->GetTransform().SetLocalPosition({ static_cast<float>(-(-10 + 10 * i)) + Range, 0 });
			}
		}


		Combo_BrightTime -= _Delta * 6.f;



	}
	else if (Combo_BrightTime > 0)
	{
		if (Texture_Combo_Effect->IsUpdate())
		{
			Texture_Combo_bonus->GetTransform().SetLocalPosition(float4::ZERO);
			Texture_Combo_Effect->GetPixelData().MulColor.a = 0;
			Texture_Combo_Effect->SetScaleRatio(1.0f);
			Texture_Combo_Effect->GetTransform().SetLocalPosition({ 45.f , 0 });
			Texture_Combo_Effect->ScaleToTexture();
			Texture_Combo_Effect->Off();
			Combo_BrightTime = 1.f;

			float Len = -10.f;
			for (size_t i = 0; i < 3; i++)
			{
				Texture_Combo_num[i]->GetPixelData().MulColor.a = 1;
				Texture_Combo_num[i]->GetTransform().SetLocalPosition({ -Len, 0 });
				Len += 10.f;
				Texture_Combo_num[i]->SetScaleRatio(1.f);
			}
		}

		Texture_Combo_Aerial->On();
		Texture_Combo_bonus->On();

		Texture_Combo_Aerial->GetPixelData().MulColor.a = 0.7f - (1.f - Combo_BrightTime) * 0.7f;
		Texture_Combo_Aerial->SetScaleRatio(1.f * (1 - (1.f - Combo_BrightTime)) + 1.5f * (1.f - Combo_BrightTime));
		Texture_Combo_Aerial->GetTransform().SetLocalPosition({ -((77.5f) * ((((Combo_BrightTime + 1.8f * (1.f - Combo_BrightTime)) - 1.f) * 0.5f) + 1.f)) + 77.5f , 0, 0 });

		Texture_Combo_Aerial->ScaleToTexture();
		Texture_Combo_Aerial->On();

		Combo_BrightTime -= _Delta * 6.f;
	}
	else
	{
		if (Texture_Combo_Effect->IsUpdate())
		{
			Texture_Combo_bonus->GetTransform().SetLocalPosition(float4::ZERO);
			Texture_Combo_Effect->GetPixelData().MulColor.a = 0;
			Texture_Combo_Effect->SetScaleRatio(1.0f);
			Texture_Combo_Effect->GetTransform().SetLocalPosition({ 45.f , 0 });
			Texture_Combo_Effect->ScaleToTexture();
			Texture_Combo_Effect->Off();
			Texture_Combo_Aerial->On();
			Combo_BrightTime = 0;

			float Len = -10.f;
			for (size_t i = 0; i < 3; i++)
			{
				Texture_Combo_num[i]->GetPixelData().MulColor.a = 1;
				Texture_Combo_num[i]->GetTransform().SetLocalPosition({ -Len, 0 });
				Len += 10.f;
				Texture_Combo_num[i]->SetScaleRatio(1.f);
			}

		}

		if (Texture_Combo_Aerial->IsUpdate())
		{
			Texture_Combo_bonus->GetTransform().SetLocalPosition(float4::ZERO);
			Texture_Combo_Aerial->GetPixelData().MulColor.a = 0;
			Texture_Combo_Aerial->SetScaleRatio(1.0f);
			Texture_Combo_Aerial->GetTransform().SetLocalPosition({ -27.f , 0 });
			Texture_Combo_Aerial->ScaleToTexture();
			Texture_Combo_Aerial->Off();
			Combo_BrightTime = 0;
		}


		Combo_bonus_Time -= _Delta * 2.f;

		if (Combo_bonus_Time < 0 && Combo_bonus_Time > -0.5f)
		{
			if (CurrentClass == ComboClass::Combo)
			{
				EndCombo = false;
				for (int i = 0; i < 3; i++)
				{
					Texture_Combo_num[i]->GetTransform().SetLocalPosition({ static_cast<float>(-(-10 + 10 * i)), -30.f * (0.05f + Combo_bonus_Time) });
					Texture_Combo_num[i]->GetPixelData().MulColor.a += Combo_bonus_Time;
					if (Texture_Combo_num[i]->GetPixelData().MulColor.a < 0)
					{
						Texture_Combo_num[i]->GetPixelData().MulColor.a = 0;
					}
				}
			}
			else
			{
				CurrentClass = ComboClass::None;
				EndCombo = true;
			}
		
			Texture_Combo_bonus->GetTransform().SetLocalPosition({ 0, -30.f * (0.05f + Combo_bonus_Time)});

			Texture_Combo_bonus->GetPixelData().MulColor.a += Combo_bonus_Time;
			if (Texture_Combo_bonus->GetPixelData().MulColor.a < 0)
			{
				Texture_Combo_bonus->GetPixelData().MulColor.a = 0;
			}
		}
		else if(Combo_bonus_Time <= -0.5f)
		{
			Texture_Combo_bonus->GetPixelData().MulColor.a = 0;
			Off();
			EndCombo = true;
			if (CurrentClass == ComboClass::Combo)
			{
				GetParent<GamePlayComboSystem>()->ComboTimeEnd();
			}

			CurrentClass = ComboClass::None;
		}
	}

}



void ComboSystemBlank::OnEvent()
{

}

void ComboSystemBlank::LevelStartEvent()
{
	FontSizeUp = false;
}
void ComboSystemBlank::LevelEndEvent()
{

}

