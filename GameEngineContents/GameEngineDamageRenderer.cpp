#include "PreCompile.h"
#include "GameEngineDamageRenderer.h"

//#include "GameEngineTexture.h"
//#include "GameEngineFolderTexture.h"

GameEngineFolderTexture* GameEngineDamageRenderer::Folder_NumberTexture_Critical = nullptr;
GameEngineFolderTexture* GameEngineDamageRenderer::Folder_NumberTexture_Nomal = nullptr;
GameEngineFolderTexture* GameEngineDamageRenderer::Folder_NumberTexture_PlayerHitFont = nullptr;

 GameEngineFolderTexture* GameEngineDamageRenderer::Folder_NumberTexture_HPCureFont = nullptr;
 GameEngineFolderTexture* GameEngineDamageRenderer::Folder_NumberTexture_MPCureFont = nullptr;

 GameEngineFolderTexture* GameEngineDamageRenderer::Folder_NumberTexture_TrueDamage = nullptr;

std::list<GameEngineDamageRenderer*> GameEngineDamageRenderer::Static_AllDamageRenderer;
GameEngineDamageRenderer::GameEngineDamageRenderer()
	:  CurrentCastingTime(1.5f)
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
		GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>("DamageFont");
		Renderer->GetTransform().SetLocalPosition({0, 0, -10.f - i});
		Renderer->ChangeCamera(CAMERAORDER::UIFont);
		Renderer->Off();
		All_Font.push_back(Renderer);
			
	}

	if (GameEngineDamageRenderer::Folder_NumberTexture_Critical == nullptr)
	{
		GameEngineDamageRenderer::Folder_NumberTexture_Critical = GameEngineFolderTexture::Find("CriticalFont");
		GameEngineDamageRenderer::Folder_NumberTexture_Nomal = GameEngineFolderTexture::Find("NomalFont");

		GameEngineDamageRenderer::Folder_NumberTexture_HPCureFont = GameEngineFolderTexture::Find("HPCureFont");
		GameEngineDamageRenderer::Folder_NumberTexture_MPCureFont = GameEngineFolderTexture::Find("MPCureFont");
		GameEngineDamageRenderer::Folder_NumberTexture_PlayerHitFont = GameEngineFolderTexture::Find("PlayerHitFont");

		GameEngineDamageRenderer::Folder_NumberTexture_TrueDamage = GameEngineFolderTexture::Find("TrueDamageFont");
	}
}

void GameEngineDamageRenderer::SetDamage(unsigned int _Damage, DamageFontClass _Class)
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
			All_Font[0]->On();
			All_Font[1]->On();
			All_Font[2]->On();

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

			switch (_Class)
			{
			case DamageFontClass::MPHeal:
				All_Font[i]->SetTexture(Folder_NumberTexture_MPCureFont->GetTexture(DamagePow));
				XPos += 2;
				break;
			case DamageFontClass::HPHeal:
				All_Font[i]->SetTexture(Folder_NumberTexture_HPCureFont->GetTexture(DamagePow));
				XPos += 2;
				break;
			case DamageFontClass::NomalDamage:
				All_Font[i]->SetTexture(Folder_NumberTexture_Nomal->GetTexture(DamagePow));
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
				break;
			case DamageFontClass::Critical:
				All_Font[i]->SetTexture(Folder_NumberTexture_Critical->GetTexture(DamagePow));

				XPos += 2;
				if (DamagePow == 1)
				{
					XPos += 6;
				}
				break;

			case DamageFontClass::PlayerHit:
				All_Font[i]->SetTexture(Folder_NumberTexture_PlayerHitFont->GetTexture(DamagePow));
				//XPos += 2;
				if (DamagePow == 1)
				{
					XPos += 6;
				}
				break;

			case DamageFontClass::TrueDamage:
				All_Font[i]->SetTexture(Folder_NumberTexture_TrueDamage->GetTexture(DamagePow));
				//XPos += 2;
				All_Font[i]->SetScaleRatio(0.75f);
	/*			if (DamagePow == 1)
				{
					XPos += 1;
				}*/
				break;

			//case DamageFontClass::AddDamage:
			//	All_Font[i]->SetTexture(Folder_NumberTexture_Nomal->GetTexture(DamagePow));
			//	switch (DamagePow)
			//	{
			//	case 6:
			//		XPos += 1;
			//		break;
			//	case 7:
			//		XPos += 2;
			//		break;
			//	default:
			//		break;
			//	}
			//	break;
				break;
			

			default:
				break;
			}

			All_Font[i]->ScaleToTexture();

			XPos -= All_Font[i]->GetTransform().GetLocalScale().x - 5;
			All_Font[i]->GetTransform().SetLocalPosition({ XPos, 0 , 0 });
			All_Font[i]->SetPivot(PIVOTMODE::LEFTTOP);
			All_Font[i]->On();
		}
	}

	GameEngineDamageRenderer::SetPrintingFont(this);
	GameEngineDamageRenderer::Static_AllDamageRenderer.push_back(this);
}


void GameEngineDamageRenderer::SetDamage(unsigned int _Damage, const std::vector<float>& _AddDamage ,DamageFontClass _Class)
{
	FontSize = 1.2f;
	if (_Damage > 99999999)
	{
		MaxDamage = true;
		{
			GetTransform().SetLocalMove({ 0, 0, -100.f });
			All_Font[0]->SetFolderTextureToIndex("MaxDamageFont", 0);
			All_Font[0]->GetTransform().SetLocalPosition({ 0, 0, -2 });
			All_Font[1]->SetFolderTextureToIndex("MaxDamageFont", 1);
			All_Font[1]->GetTransform().SetLocalPosition({ 0, 0, 0 });
			All_Font[2]->SetFolderTextureToIndex("MaxDamageFont", 2);
			All_Font[2]->GetTransform().SetLocalPosition({ 0, 0, -1 });

			All_Font[0]->ScaleToTexture();
			All_Font[1]->ScaleToTexture();
			All_Font[2]->ScaleToTexture();
			All_Font[0]->On();
			All_Font[1]->On();
			All_Font[2]->On();

			for (size_t i = 3; i < 8; i++)
			{
				All_Font[i]->Death();
				All_Font[i] = nullptr;
			}
		}
		GameEngineDamageRenderer::SetPrintingFont(this);
		GameEngineDamageRenderer::Static_AllDamageRenderer.push_back(this);
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

			switch (_Class)
			{
			case DamageFontClass::NomalDamage:
				All_Font[i]->SetTexture(Folder_NumberTexture_Nomal->GetTexture(DamagePow));
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
				break;
			case DamageFontClass::Critical:
				All_Font[i]->SetTexture(Folder_NumberTexture_Critical->GetTexture(DamagePow));

				XPos += 2;
				if (DamagePow == 1)
				{
					XPos += 6;
				}
				break;

			case DamageFontClass::TrueDamage:
				All_Font[i]->SetTexture(Folder_NumberTexture_TrueDamage->GetTexture(DamagePow));
				//XPos += 2;
				All_Font[i]->SetScaleRatio(0.75f);
				/*			if (DamagePow == 1)
							{
								XPos += 1;
							}*/
				break;

				//case DamageFontClass::AddDamage:
				//	All_Font[i]->SetTexture(Folder_NumberTexture_Nomal->GetTexture(DamagePow));
				//	switch (DamagePow)
				//	{
				//	case 6:
				//		XPos += 1;
				//		break;
				//	case 7:
				//		XPos += 2;
				//		break;
				//	default:
				//		break;
				//	}
				//	break;
				break;


			default:
				break;
			}

			All_Font[i]->ScaleToTexture();

			XPos -= All_Font[i]->GetTransform().GetLocalScale().x - 5;
			All_Font[i]->GetTransform().SetLocalPosition({ XPos, 0 , 0 });
			All_Font[i]->SetPivot(PIVOTMODE::LEFTTOP);
			All_Font[i]->On();
		}

		GameEngineDamageRenderer::SetPrintingFont(this);
		GameEngineDamageRenderer::Static_AllDamageRenderer.push_back(this);

		float BigDamageScale = -XPos;

		float HightY = 14.f;
		for (int i = 0; i < _AddDamage.size(); i++)
		{
			std::string Damage = std::to_string(static_cast<int>(static_cast<float>(_Damage) * _AddDamage[i]));
			float XPos = 0;



			for (int j = 0; j < Damage.size(); j++)
			{
				//-80
				//int Pow = static_cast<int>(pow(10, i - 1));
				int DamagePow = Damage[Damage.size() - j - 1] - 48;

				All_AddFont[i].push_back(CreateComponent<GameEngineUIRenderer>());
				All_AddFont[i][j]->GetTransform().SetLocalPosition({0, 0, -10.f - i});
				All_AddFont[i][j]->ChangeCamera(CAMERAORDER::UIFont);
				All_AddFont[i][j]->Off();

				All_AddFont[i][j]->SetScaleRatio(0.65f);
				switch (_Class)
				{
				case DamageFontClass::TrueDamage:
					All_AddFont[i][j]->SetTexture(Folder_NumberTexture_TrueDamage->GetTexture(DamagePow));
					break;
				default:
					All_AddFont[i][j]->SetTexture(Folder_NumberTexture_Nomal->GetTexture(DamagePow));
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
					break;

					break;
				}



				All_AddFont[i][j]->ScaleToTexture();

				XPos -= All_AddFont[i][j]->GetTransform().GetLocalScale().x - 5;
				All_AddFont[i][j]->GetTransform().SetLocalPosition({ XPos, -HightY - HightY * static_cast<float>(i) , 0 });
				All_AddFont[i][j]->SetPivot(PIVOTMODE::LEFTTOP);
				All_AddFont[i][j]->On();


				GetTransform().SetLocalMove({0, HightY });

				//GameEngineDamageRenderer::SetPrintingFontAddDamage(this);
			}

			float Len = (BigDamageScale + XPos) * -0.5f;

			for (size_t k = 0; k < All_AddFont[i].size(); k++)
			{
				All_AddFont[i][k]->GetTransform().SetLocalMove({ Len, 0 });
			}

		}
	}


}



void GameEngineDamageRenderer::SetPrintingFont(GameEngineDamageRenderer* _FontRenderer)
{
	float Hight = _FontRenderer->GetTextureSize().y;
	for (GameEngineDamageRenderer* Renderer : Static_AllDamageRenderer)
	{
		Renderer->GetTransform().SetLocalMove({ 0, Hight, 0 });
		if (_FontRenderer->GetTransform().GetWorldPosition().y - Renderer->GetTransform().GetWorldPosition().y > -8.f)
		{
			Renderer->GetTransform().SetLocalMove({ 0, 5.f, 0 });
		}
	}
}

void GameEngineDamageRenderer::SetPrintingFontAddDamage(GameEngineDamageRenderer* _FontRenderer)
{
	float Hight = 6.f;
	for (GameEngineDamageRenderer* Renderer : Static_AllDamageRenderer)
	{
		Renderer->GetTransform().SetLocalMove({ 0, Hight, 0 });
		//if (_FontRenderer->GetTransform().GetWorldPosition().y - Renderer->GetTransform().GetWorldPosition().y > -8.f)
		//{
		//	Renderer->GetTransform().SetLocalMove({ 0, 5.f, 0 });
		//}
	}
}



void GameEngineDamageRenderer::Update(float _Delta)
{
	CurrentCastingTime -= _Delta;
	//Interval -= _Delta;
	if (CurrentCastingTime <= 0.f) // AccDeath를 안쓰는 이유 : 죽는 시간을 내가 원할때 하고 싶어서
	{
		FontEnd();
	}
	else if (CurrentCastingTime <= 0.25f) // Disappear
	{
		LastTime();
	}
	else if (CurrentCastingTime <= 1.25f) // 크기 조절
	{
		SecondTime();

	}
	else if (CurrentCastingTime <= 1.5f) // 흰색 바탕에 커짐
	{
		FirstTime();
		if (MaxDamage == true)
		{
			if (CurrentCastingTime <= 1.35f)
			{
				All_Font[2]->GetTransform().SetLocalPosition({ 0, 0, -3.f });
			}
			float LerpTime = ((1.5f - CurrentCastingTime) / 0.25f);

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
			GetTransform().SetLocalScale(FontSize * 0.5f * (1.0f - ((1.5f - CurrentCastingTime) * 4.f)) + FontSize * ((1.5f - CurrentCastingTime) * 5.f)); // Lerp
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