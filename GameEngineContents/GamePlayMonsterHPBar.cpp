#include "PreCompile.h"
#include "GamePlayMonsterHPBar.h"
#include "GamePlayMonster.h"

GamePlayMonsterHPBar* GamePlayMonsterHPBar::CurrentActor = nullptr;

GameEngineTexture* GamePlayMonsterHPBar::Texture_NomalHPBar = nullptr;
GameEngineTexture* GamePlayMonsterHPBar::Texture_BossHPBar = nullptr;
GameEngineTexture* GamePlayMonsterHPBar::Texture_NomalHPBarEnd = nullptr;
GameEngineTexture* GamePlayMonsterHPBar::Texture_BossHPBarEnd = nullptr;

GameEngineFolderTexture* GamePlayMonsterHPBar::TextureFolder_HPFont = nullptr;

GameEngineTexture* GamePlayMonsterHPBar::Texture_BossColor = nullptr;
GameEngineTexture* GamePlayMonsterHPBar::Texture_NomalColor = nullptr;

std::vector<GameEngineTexture*> GamePlayMonsterHPBar::Vector_BossColor;
std::vector<GameEngineTexture*> GamePlayMonsterHPBar::Vector_NomalColor;


GamePlayMonsterHPBar::GamePlayMonsterHPBar() 
	: Texture_MonsterHPBar_UI(nullptr)
	, Texture_MonsterHPBar_UIEnd(nullptr)
	, Monster_Target(nullptr)
	, Monster_CurrentHP(-1)
	, Monster_GoalHPLine(0)
	, Monster_BeforeHPLine(0)
	, Texture_HP1_Front(nullptr)
	, Texture_HP1_Back(nullptr)
	, Texture_HP2_Front(nullptr)
	, Texture_HP2_Back(nullptr)
	, Texture_HP1_White(nullptr)
	, Texture_HP2_White(nullptr)
	, HP1Front(true)
	, FlashTime(0.f)
	, DecreaseTime(0.f)
	, Texture_MonsterHP_Delete(nullptr)
	, DeathBlink(0.f)
	, MaxSpeed(0)
	, FrameSpeed(0)
	, Texture_HP1_Black(nullptr)
	, Texture_HP2_Black(nullptr)
	//, Monster_CurrentMonsterClass(MonsterClass::None)
{
}

GamePlayMonsterHPBar::~GamePlayMonsterHPBar() 
{
}

void GamePlayMonsterHPBar::Start()
{
	GetTransform().SetLocalPosition({ -600, 200 });

	Texture_MonsterHPBar_UI = CreateComponent<GameEngineUIRenderer>();
	Texture_MonsterHPBar_UIEnd = CreateComponent<GameEngineUIRenderer>();
	Texture_HP1_Front = CreateComponent<GameEngineUIRenderer>();
	Texture_HP1_Front->GetTransform().SetLocalPosition({ 0, 0, -2.f });
	Texture_HP1_Back = CreateComponent<GameEngineUIRenderer>();
	Texture_HP1_Back->GetTransform().SetLocalPosition({ 0, 0, -1.5f });
	Texture_HP2_Front = CreateComponent<GameEngineUIRenderer>();
	Texture_HP2_Front->GetTransform().SetLocalPosition({ 0, 0, -1.5f});
	Texture_HP2_Back = CreateComponent<GameEngineUIRenderer>();
	Texture_HP2_Back->GetTransform().SetLocalPosition({ 0, 0, -0.5f});
	Texture_HP1_White = CreateComponent<GameEngineUIRenderer>();
	Texture_HP1_White->GetTransform().SetLocalPosition({ 0, 0, -1.75f });
	Texture_HP2_White = CreateComponent<GameEngineUIRenderer>();
	Texture_HP2_White->GetTransform().SetLocalPosition({ 0, 0, -0.75f });


	Texture_HP1_Black = CreateComponent<GameEngineUIRenderer>();
	Texture_HP1_Black->GetTransform().SetLocalPosition({ 0, 0, -1.6f });
	Texture_HP2_Black = CreateComponent<GameEngineUIRenderer>();
	Texture_HP2_Black->GetTransform().SetLocalPosition({ 0, 0, -0.6f });

	Texture_HP1_Black->GetPixelData().MulColor = { 0,0,0,0.5f };
	Texture_HP2_Black->GetPixelData().MulColor = { 0,0,0,0.5f };

	Texture_MonsterHP_Delete = CreateComponent<GameEngineUIRenderer>();
	Texture_MonsterHP_Delete->SetTexture("MonsterHP_ODelete.png");
	Texture_MonsterHP_Delete->ScaleToTexture();
	Texture_MonsterHP_Delete->GetTransform().SetLocalPosition({ -6, 6, -3.f });
	Texture_MonsterHP_Delete->Off();

	for (size_t i = 0; i < 5; i++)
	{
		GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>();
		//Renderer->SetPivot(PIVOTMODE::RIGHTTOP);
		All_HPFont.push_back(Renderer);
	}
	

	Texture_MonsterHPBar_UI->SetPivot(PIVOTMODE::LEFTTOP);
	Texture_MonsterHPBar_UIEnd->SetPivot(PIVOTMODE::LEFTTOP);
	Texture_HP1_Front->SetPivot(PIVOTMODE::LEFTTOP);
	Texture_HP1_Back->SetPivot(PIVOTMODE::LEFTTOP);
	Texture_HP2_Front->SetPivot(PIVOTMODE::LEFTTOP);
	Texture_HP2_Back->SetPivot(PIVOTMODE::LEFTTOP);
	Texture_HP1_White->SetPivot(PIVOTMODE::LEFTTOP);
	Texture_HP2_White->SetPivot(PIVOTMODE::LEFTTOP);
	Texture_HP1_Black->SetPivot(PIVOTMODE::LEFTTOP);
	Texture_HP2_Black->SetPivot(PIVOTMODE::LEFTTOP);

	if (Texture_NomalHPBar == nullptr)
	{
		GamePlayMonsterHPBar::Texture_NomalHPBar = GameEngineTexture::Find("MonsterHP_NomalBar.png");
		GamePlayMonsterHPBar::Texture_BossHPBar = GameEngineTexture::Find("MonsterHP_BossBar.png");

		GamePlayMonsterHPBar::Texture_NomalHPBarEnd = GameEngineTexture::Find("MonsterHP_NomalBar_End.png");
		GamePlayMonsterHPBar::Texture_BossHPBarEnd = GameEngineTexture::Find("MonsterHP_BossBar_End.png");
		
		GamePlayMonsterHPBar::TextureFolder_HPFont = GameEngineFolderTexture::Find("MonsterHPFont");
	
		GamePlayMonsterHPBar::Vector_BossColor.push_back(GameEngineTexture::Find("MonsterHP_BossHP_Purple.png"));
		GamePlayMonsterHPBar::Vector_BossColor.push_back(GameEngineTexture::Find("MonsterHP_BossHP_Red.png"));
		GamePlayMonsterHPBar::Vector_BossColor.push_back(GameEngineTexture::Find("MonsterHP_BossHP_Orange.png"));
		GamePlayMonsterHPBar::Vector_BossColor.push_back(GameEngineTexture::Find("MonsterHP_BossHP_Green.png"));
		GamePlayMonsterHPBar::Vector_BossColor.push_back(GameEngineTexture::Find("MonsterHP_BossHP_Blue.png"));
		GamePlayMonsterHPBar::Vector_NomalColor.push_back(GameEngineTexture::Find("MonsterHP_NomalHP_Purple.png"));
		GamePlayMonsterHPBar::Vector_NomalColor.push_back(GameEngineTexture::Find("MonsterHP_NomalHP_Red.png"));
		GamePlayMonsterHPBar::Vector_NomalColor.push_back(GameEngineTexture::Find("MonsterHP_NomalHP_Orange.png"));
		GamePlayMonsterHPBar::Vector_NomalColor.push_back(GameEngineTexture::Find("MonsterHP_NomalHP_Green.png"));
		GamePlayMonsterHPBar::Vector_NomalColor.push_back(GameEngineTexture::Find("MonsterHP_NomalHP_Blue.png"));

		GamePlayMonsterHPBar::Texture_BossColor = GameEngineTexture::Find("MonsterHP_NomalHP_White.png");
		GamePlayMonsterHPBar::Texture_NomalColor = GameEngineTexture::Find("MonsterHP_NomalHP_White.png");
	}
	
}


void GamePlayMonsterHPBar::SetMonster_InMember(GamePlayMonster* _Monster)
{
	if (Monster_Target == _Monster)
	{
		return;
	}

	Monster_Target = _Monster;
	Monster_CurrentHP = Monster_Target->GetMonsterStat()->GetHP();
	Monster_GoalHPLine = static_cast<int>(((static_cast<float>(Monster_CurrentHP) * Monster_Target->GetMonsterStat()->GetMaxHPLine()) / _Monster->GetMonsterStat()->GetMAXHP()) * 100.f);
	if (Monster_GoalHPLine >= 1000000)
	{
		Monster_GoalHPLine = 999999;
	}
	Monster_BeforeHPLine = Monster_GoalHPLine;

	{
		for (auto& Clear : All_MonsterCategory)
		{
			Clear->Death();
		}
		All_MonsterCategory.clear();
		float Pos = 28.f;
		for (auto& Category : Monster_Target->GetMonsterCategory())
		{
			GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>();
			switch (Category)
			{
			case MonsterCategory::None:
				break;
			case MonsterCategory::Human:
				Renderer->SetFolderTextureToIndex("MonsterCategory", 0);
				break;
			case MonsterCategory::Machine:
				Renderer->SetFolderTextureToIndex("MonsterCategory", 1);
				break;
			default:
				break;
			}
			Renderer->ScaleToTexture();
			Renderer->GetTransform().SetLocalPosition({ Pos , 14.f });
			Pos += Renderer->GetCurTexture()->GetScale().x + 2.f;

			All_MonsterCategory.push_back(Renderer);
		}
	}



	HP1Front = true;

	switch (Monster_Target->GetMonsterClass())
	{
	case MonsterClass::Nomal:
	case MonsterClass::Named:
	{
		Texture_MonsterHPBar_UI->SetTexture(GamePlayMonsterHPBar::Texture_NomalHPBar);
		Texture_MonsterHPBar_UI->GetTransform().SetLocalPosition({ -20, 20 });

		Texture_MonsterHPBar_UIEnd->SetTexture(GamePlayMonsterHPBar::Texture_NomalHPBarEnd);
		Texture_MonsterHPBar_UIEnd->GetTransform().SetLocalPosition({ 604, 5, -2.5f });

		Texture_MonsterHPBar_UI->ScaleToTexture();
		Texture_MonsterHPBar_UIEnd->ScaleToTexture();

		SetHPTexture();


		float Ratio = static_cast<float>(Monster_BeforeHPLine % 100) * 0.01f;
		const float4& Scale = Texture_HP1_Front->GetTransform().GetLocalScale();
		Texture_HP1_Front->GetTransform().SetLocalScale({ Scale.x * Ratio, Scale.y });
		Texture_HP1_Back->GetTransform().SetLocalScale({ Scale.x * Ratio, Scale.y });


		Texture_HP1_Front->GetTransform().SetLocalPosition({ 9, 3, 0 });
		Texture_HP1_Back->GetTransform().SetLocalPosition({ 9, 3, 0 });
		Texture_HP2_Front->GetTransform().SetLocalPosition({ 9, 3, 0 });
		Texture_HP2_Back->GetTransform().SetLocalPosition({ 9, 3, 0 });
		Texture_HP1_White->GetTransform().SetLocalPosition({ 9, 3, 0 });
		Texture_HP2_White->GetTransform().SetLocalPosition({ 9, 3, 0 });
		Texture_HP1_Black->GetTransform().SetLocalPosition({ 9, 3, 0 });
		Texture_HP2_Black->GetTransform().SetLocalPosition({ 9, 3, 0 });

		Texture_HP1_Front->ScaleToTexture();
		Texture_HP1_Back->ScaleToTexture();
		Texture_HP2_Front->ScaleToTexture();
		Texture_HP2_Back->ScaleToTexture();

		SetHPStack();

		Texture_HP1_White->SetTexture(GamePlayMonsterHPBar::Texture_NomalColor);
		Texture_HP1_White->GetTransform().SetLocalScale(Texture_HP1_Back->GetTransform().GetLocalScale());
		Texture_HP2_White->SetTexture(GamePlayMonsterHPBar::Texture_NomalColor);
		Texture_HP2_White->GetTransform().SetLocalScale(Texture_HP2_Back->GetTransform().GetLocalScale());

		Texture_HP1_Black->SetTexture(GamePlayMonsterHPBar::Texture_NomalColor);
		Texture_HP1_Black->GetTransform().SetLocalScale(Texture_HP1_Back->GetTransform().GetLocalScale());
		Texture_HP2_Black->SetTexture(GamePlayMonsterHPBar::Texture_NomalColor);
		Texture_HP2_Black->GetTransform().SetLocalScale(Texture_HP2_Back->GetTransform().GetLocalScale());


		Texture_HP1_Black->GetPixelData().MulColor = { 0,0,0,0.5f };
		Texture_HP2_Black->GetPixelData().MulColor = { 0,0,0,0.5f };


		Texture_HP1_White->GetPixelData().MulColor = { 1,1,1,1 };
		Texture_HP2_White->GetPixelData().MulColor = { 1,1,1,1 };
	}

		break;
	case MonsterClass::Boss:
		Texture_MonsterHPBar_UI->SetTexture(GamePlayMonsterHPBar::Texture_BossHPBar);
		
		Texture_MonsterHPBar_UIEnd->SetTexture(GamePlayMonsterHPBar::Texture_BossHPBarEnd);
		
		//Texture_HP1_Front->SetTexture(Vector_BossColor[CurrentIndex]);
		//Texture_HP1_Back->SetTexture(Vector_BossColor[CurrentIndex]);
		//
		//Texture_HP2_Front->SetTexture(Vector_BossColor[CurrentIndex + 1]);
		//Texture_HP2_Back->SetTexture(Vector_BossColor[CurrentIndex + 1]);
		
		Texture_HP1_White->SetTexture(GamePlayMonsterHPBar::Texture_NomalColor);
		break;
	case MonsterClass::None:
	default:
		MsgBoxAssert("아직 몬스터 타입이 설정 되지 않았습니다");
		break;
	}


	{
		Texture_HP1_Front->GetTransform().SetLocalMove({ 0, 0, -2.f });
		Texture_HP1_Back->GetTransform().SetLocalMove({ 0, 0, -1.5f });
		Texture_HP2_Front->GetTransform().SetLocalMove({ 0, 0, -1.0f });
		Texture_HP2_Back->GetTransform().SetLocalMove({ 0, 0, -0.5f });
		Texture_HP1_White->GetTransform().SetLocalMove({ 0, 0, -1.75f });
		Texture_HP2_White->GetTransform().SetLocalMove({ 0, 0, -0.75f });
		Texture_HP1_Black->GetTransform().SetLocalMove({ 0, 0, -1.6f });
		Texture_HP2_Black->GetTransform().SetLocalMove({ 0, 0, -0.6f });
	}

	DeathBlink = 0.f;
	FlashTime = 0.f;
	Texture_MonsterHP_Delete->Off();
	SetHPBarRatioTexture_Front(Monster_BeforeHPLine - Monster_GoalHPLine);
}

void GamePlayMonsterHPBar::SetHPTexture()
{

	int CurrentIndex = (Monster_BeforeHPLine / 100) % 5;

	switch (Monster_Target->GetMonsterClass())
	{
	case MonsterClass::Nomal:
	case MonsterClass::Named:
	{
		GameEngineUIRenderer* FrontRnderer_First = HP1Front ? Texture_HP1_Front : Texture_HP2_Front;
		GameEngineUIRenderer* BackRnderer_First = HP1Front ? Texture_HP1_Back : Texture_HP2_Back;

		GameEngineUIRenderer* FrontRnderer_Second = HP1Front ? Texture_HP2_Front : Texture_HP1_Front;
		GameEngineUIRenderer* BackRnderer_Second = HP1Front ? Texture_HP2_Back : Texture_HP1_Back;


		FrontRnderer_First->SetTexture(GamePlayMonsterHPBar::Vector_NomalColor[CurrentIndex]);
		BackRnderer_First->SetTexture(GamePlayMonsterHPBar::Vector_NomalColor[CurrentIndex]);
		
		CurrentIndex = CurrentIndex <= 0 ? 4 : CurrentIndex - 1;

		FrontRnderer_Second->SetTexture(GamePlayMonsterHPBar::Vector_NomalColor[CurrentIndex]);
		BackRnderer_Second->SetTexture(GamePlayMonsterHPBar::Vector_NomalColor[CurrentIndex]);


	}
	case MonsterClass::Boss:
		break;
	case MonsterClass::None:
	default:
		MsgBoxAssert("아직 몬스터 타입이 설정 되지 않았습니다");
		break;
	}
}

void GamePlayMonsterHPBar::SetHPStack()
{
	std::string HPStack = std::to_string(Monster_BeforeHPLine / 100);
	if (HPStack.size() == 1 && HPStack[0] == '0')
	{
		for (auto& Font : All_HPFont)
		{
			Font->Off();
		}
		return;
	}

	switch (Monster_Target->GetMonsterClass())
	{
	case MonsterClass::Nomal:
	case MonsterClass::Named:
	{
		{
			float Range = 595.f;
			for (int i = static_cast<int>(HPStack.size()) - 1; i >= 0; i--)
			{
				All_HPFont[HPStack.size() - 1 - i]->On();
				All_HPFont[HPStack.size() - 1 - i]->SetTexture(TextureFolder_HPFont->GetTexture(HPStack[i] - 48));
				All_HPFont[HPStack.size() - 1 - i]->ScaleToTexture();
				All_HPFont[HPStack.size() - 1 - i]->GetTransform().SetLocalPosition({ Range , 17 });
				Range -= 18.f;

				if (i == 0)
				{
					All_HPFont[HPStack.size()]->On();
					All_HPFont[HPStack.size()]->SetTexture(TextureFolder_HPFont->GetTexture(11));
					All_HPFont[HPStack.size()]->ScaleToTexture();
					All_HPFont[HPStack.size()]->GetTransform().SetLocalPosition({ Range , 17 });

					for (size_t i = HPStack.size() + 1; i < 5; i++)
					{
						All_HPFont[i]->Off();
					}
				}
			}
		}
	}
	case MonsterClass::Boss:
		break;
	case MonsterClass::None:
	default:
		MsgBoxAssert("아직 몬스터 타입이 설정 되지 않았습니다");
		break;
	}
}


void GamePlayMonsterHPBar::Update(float _DeltaTime)
{

	if (Monster_Target != nullptr)
	{

		if (FlashTime > 0.f)
		{
			FlashTime -= _DeltaTime;

			float Color = (1.f - ((0.2f - FlashTime) / 0.2f));


			Texture_HP1_White->GetPixelData().MulColor = { 1,1,1,Color };
			Texture_HP2_White->GetPixelData().MulColor = { 1,1,1,Color };
		}


		if (Monster_BeforeHPLine > Monster_GoalHPLine)
		{
			DecreaseTime += _DeltaTime;
			if (DecreaseTime > FrameSpeed)
			{
				//int Index = static_cast<int>(static_cast<float>(Monster_BeforeHPLine) * (1.0f - (DecreaseTime / 0.3f)) + static_cast<float>(Monster_GoalHPLine * (DecreaseTime / 0.3f)));
				//int Index = Monster_BeforeHPLine - Monster_GoalHPLine;

				SetDecreaseHP(MaxSpeed);

				SetHPBarRatioTexture_Front(Monster_BeforeHPLine - Monster_GoalHPLine);
				SetHPTexture();
				SetHPStack();

				DecreaseTime = 0.f;
			}

		}

		if (Monster_GoalHPLine <= 0)
		{
			if (DeathBlink <= 0)
			{
				Texture_MonsterHP_Delete->OnOffSwitch();
				DeathBlink = 0.5f;
			}
			else
			{
				DeathBlink -= _DeltaTime;
			}

		}
	}


	//if (FlashTime > 0)
	//{
	//	FlashTime 
	//}
}

void GamePlayMonsterHPBar::SetDecreaseHP(int _Decrease)
{
	// float 끼리 연산하니 문제가 많아 int 사용
	int Before = Monster_BeforeHPLine % 100;



 	while (_Decrease > 0)
	{
		if (0 == Before)
		{
			Before = 100;
		}
		if (0 > Before - _Decrease)
		{
			SwitchingHP1and2();
			if (HP1Front)
			{
				Texture_HP2_Back->ScaleToTexture();
				Texture_HP2_Black->ScaleToTexture();
			}
			else
			{
				Texture_HP1_Back->ScaleToTexture();
				Texture_HP1_Black->ScaleToTexture();
			}

			if (Monster_BeforeHPLine < static_cast<unsigned int>(Before))
			{
				_Decrease = 0;
				Monster_BeforeHPLine = 0;
			}
			else
			{
				_Decrease -= Before;
				Monster_BeforeHPLine -= Before;
				Before = Monster_BeforeHPLine % 100;
			}


		}
		else
		{
			if (HP1Front)
			{
				Texture_HP1_Back->ScaleToTexture();
				const float4& Scale = Texture_HP1_Back->GetTransform().GetLocalScale();
				Texture_HP1_Back->GetTransform().SetLocalScale({ Scale.x * (static_cast<float>(Before - _Decrease) * 0.01f),Scale.y });
				Texture_HP1_Black->GetTransform().SetLocalScale({ Scale.x * (static_cast<float>(Before - _Decrease) * 0.01f),Scale.y });
			}
			else
			{
				Texture_HP2_Back->ScaleToTexture();
				const float4& Scale = Texture_HP2_Back->GetTransform().GetLocalScale();
				Texture_HP2_Back->GetTransform().SetLocalScale({ Scale.x * (static_cast<float>(Before - _Decrease) * 0.01f),Scale.y });
				Texture_HP2_Black->GetTransform().SetLocalScale({ Scale.x * (static_cast<float>(Before - _Decrease) * 0.01f),Scale.y });
			}

			if (Monster_BeforeHPLine < static_cast<unsigned int>(_Decrease))
			{
				_Decrease = 0;
				Monster_BeforeHPLine = 0;
			}
			else
			{
				Monster_BeforeHPLine -= _Decrease;
				_Decrease -= _Decrease;
			}

		}
	}

	if (Monster_BeforeHPLine < 100)
	{
		if (HP1Front)
		{
			Texture_HP2_Back->GetTransform().SetLocalScale(float4::ZERO);
			Texture_HP2_Black->GetTransform().SetLocalScale(float4::ZERO);
		}
		else
		{
			Texture_HP1_Back->GetTransform().SetLocalScale(float4::ZERO);
			Texture_HP1_Black->GetTransform().SetLocalScale(float4::ZERO);
		}
	}
	

}



void GamePlayMonsterHPBar::SetHitDamage_InMember(unsigned int _CurrentHP)
{
	unsigned int Damage = Monster_CurrentHP - _CurrentHP;
	if (Damage >= 0)
	{


		Monster_CurrentHP = _CurrentHP;
		Monster_GoalHPLine = static_cast<int>(((static_cast<float>(Monster_CurrentHP) * Monster_Target->GetMonsterStat()->GetMaxHPLine()) / Monster_Target->GetMonsterStat()->GetMAXHP()) * 100.f);

		Texture_HP1_White->GetPixelData().MulColor = { 1,1,1,1 };
		Texture_HP2_White->GetPixelData().MulColor = { 1,1,1,1 };

		Texture_HP1_White->GetTransform().SetLocalScale(Texture_HP1_Front->GetTransform().GetLocalScale());
		Texture_HP2_White->GetTransform().SetLocalScale(Texture_HP2_Front->GetTransform().GetLocalScale());

		SetHPBarRatioTexture_Front(Monster_BeforeHPLine - Monster_GoalHPLine);

		if ((Monster_BeforeHPLine - Monster_GoalHPLine) > 1000)
		{
			MaxSpeed = 95;
			FrameSpeed = 0.09f;
		}
		else if ((Monster_BeforeHPLine - Monster_GoalHPLine) > 500)
		{
			MaxSpeed = 60;
			FrameSpeed = 0.05f;
		}
		else if ((Monster_BeforeHPLine - Monster_GoalHPLine) > 100)
		{
			MaxSpeed = 1;
			FrameSpeed = 0;
		}
		else
		{
			MaxSpeed = 1;
			FrameSpeed = 0.02f;
		}
			

		

		//MaxSpeed = 10;  // 최대 속도 조절

		
		if (FlashTime > 0)
		{
			FlashTime = 0.12f;
		}
		else
		{
			FlashTime = 0.2f;
		}
		DecreaseTime = 0.0f;
		//if ()
		//{

		//}
		//else
		//{
		//	Monster_BeforeHPLine = static_cast<float>(BeforeHPLine);
		//}
		
		Texture_MonsterHP_Delete->Off();


	}
	else
	{
		MsgBoxAssert("의외의 예외 파악용");
	}
}

bool GamePlayMonsterHPBar::SetHPBarRatioTexture_Front(int _Ratio)
{
	GameEngineUIRenderer* TargetRenderer_First = HP1Front ? Texture_HP1_Front : Texture_HP2_Front;
	GameEngineUIRenderer* TargetRenderer_Second = HP1Front ? Texture_HP2_Front : Texture_HP1_Front;
	GameEngineUIRenderer* TargetRenderer_White_First = HP1Front ? Texture_HP1_White : Texture_HP2_White;
	GameEngineUIRenderer* TargetRenderer_White_Second = HP1Front ? Texture_HP2_White : Texture_HP1_White;
	

	GameEngineTexture* TargetTexture = Monster_Target->GetMonsterClass() == MonsterClass::Boss ? Vector_BossColor[0] : Vector_NomalColor[0];


	if (_Ratio > 100)
	{
		TargetRenderer_First->GetTransform().SetLocalScale(float4::ZERO);
		TargetRenderer_Second->GetTransform().SetLocalScale(float4::ZERO);
	}
	else if(_Ratio <= 100 && _Ratio >= 0)
	{
		int HPLineIndex = Monster_GoalHPLine % 100;
		if (100 - HPLineIndex <= _Ratio)
		{
			TargetRenderer_Second->GetTransform().SetLocalScale({ TargetTexture->GetScale().x * static_cast<float>(HPLineIndex) * 0.01f, TargetTexture->GetScale().y });
		
			TargetRenderer_First->GetTransform().SetLocalScale(float4::ZERO);
		}
		else
		{
			TargetRenderer_First->GetTransform().SetLocalScale({ TargetTexture->GetScale().x * static_cast<float>(HPLineIndex) * 0.01f, TargetTexture->GetScale().y });
			TargetRenderer_Second->ScaleToTexture();
		}

		if (Monster_BeforeHPLine == Monster_GoalHPLine)
		{
			if (HP1Front)
			{
				Texture_HP1_Back->GetTransform().SetLocalScale({ TargetTexture->GetScale().x * static_cast<float>(HPLineIndex) * 0.01f, TargetTexture->GetScale().y });
				Texture_HP1_Black->GetTransform().SetLocalScale({ TargetTexture->GetScale().x * static_cast<float>(HPLineIndex) * 0.01f, TargetTexture->GetScale().y });
				Texture_HP1_White->GetTransform().SetLocalScale({ TargetTexture->GetScale().x * static_cast<float>(HPLineIndex) * 0.01f, TargetTexture->GetScale().y });
			}
			else
			{
				Texture_HP2_Back->GetTransform().SetLocalScale({ TargetTexture->GetScale().x * static_cast<float>(HPLineIndex) * 0.01f, TargetTexture->GetScale().y });
				Texture_HP2_Black->GetTransform().SetLocalScale({ TargetTexture->GetScale().x * static_cast<float>(HPLineIndex) * 0.01f, TargetTexture->GetScale().y });
				Texture_HP2_White->GetTransform().SetLocalScale({ TargetTexture->GetScale().x * static_cast<float>(HPLineIndex) * 0.01f, TargetTexture->GetScale().y });
			}
		}
	}

	if (Monster_BeforeHPLine < 100)
	{
		TargetRenderer_Second->GetTransform().SetLocalScale(float4::ZERO);
		TargetRenderer_White_Second->GetTransform().SetLocalScale(float4::ZERO);
	}

	return true;

}


void GamePlayMonsterHPBar::SwitchingHP1and2()
{
	const std::vector<GameEngineTexture*>& HPTexture = Monster_Target->GetMonsterClass() == MonsterClass::Boss ? Vector_BossColor : Vector_NomalColor;

	if (HP1Front)
	{
		Texture_HP1_Front->GetTransform().SetLocalMove({0, 0, 1.f});
		Texture_HP1_Back->GetTransform().SetLocalMove({ 0, 0, 1.f });
		Texture_HP1_White->GetTransform().SetLocalMove({ 0, 0, 1.f });
		Texture_HP1_Black->GetTransform().SetLocalMove({ 0, 0, 1.f });

		Texture_HP2_Front->GetTransform().SetLocalMove({ 0, 0, -1.f });
		Texture_HP2_Back->GetTransform().SetLocalMove({ 0, 0,  -1.f });
		Texture_HP2_White->GetTransform().SetLocalMove({ 0, 0,  -1.f });
		Texture_HP2_Black->GetTransform().SetLocalMove({ 0, 0, -1.f });


		HP1Front = false;
	}
	else
	{
		Texture_HP2_Front->GetTransform().SetLocalMove({ 0, 0, 1.f });
		Texture_HP2_Back->GetTransform().SetLocalMove({ 0, 0, 1.f });
		Texture_HP2_White->GetTransform().SetLocalMove({ 0, 0, 1.f });
		Texture_HP2_Black->GetTransform().SetLocalMove({ 0, 0, 1.f });


		Texture_HP1_Front->GetTransform().SetLocalMove({ 0, 0, -1.f });
		Texture_HP1_Back->GetTransform().SetLocalMove({ 0, 0, -1.f });
		Texture_HP1_White->GetTransform().SetLocalMove({ 0, 0, -1.f });
		Texture_HP1_Black->GetTransform().SetLocalMove({ 0, 0, -1.f });


		HP1Front = true;
	}
}
//Texture_HP1_Front = CreateComponent<GameEngineUIRenderer>();
//Texture_HP1_Front->GetTransform().SetLocalPosition({ 0, 0, -2.f });
//Texture_HP1_Back = CreateComponent<GameEngineUIRenderer>();
//Texture_HP1_Back->GetTransform().SetLocalPosition({ 0, 0, -1.5f });
//Texture_HP2_Front = CreateComponent<GameEngineUIRenderer>();
//Texture_HP2_Front->GetTransform().SetLocalPosition({ 0, 0, -1.5f });
//Texture_HP2_Back = CreateComponent<GameEngineUIRenderer>();
//Texture_HP2_Back->GetTransform().SetLocalPosition({ 0, 0, -0.5f });
//Texture_HP1_White = CreateComponent<GameEngineUIRenderer>();
//Texture_HP1_White->GetTransform().SetLocalPosition({ 0, 0, -1.75f });
//Texture_HP2_White = CreateComponent<GameEngineUIRenderer>();
//Texture_HP2_White->GetTransform().SetLocalPosition({ 0, 0, -0.75f });


void GamePlayMonsterHPBar::LevelStartEvent()
{
	GamePlayMonsterHPBar::CurrentActor = this;
}


void GamePlayMonsterHPBar::LevelEndEvent()
{
	GamePlayMonsterHPBar::CurrentActor = nullptr;
	Monster_Target = nullptr;
	Monster_CurrentHP = -1;

	Monster_BeforeHPLine = 0;
	Monster_GoalHPLine = 0;
	FlashTime = 0.f;
	DecreaseTime = 0.f;
	Texture_MonsterHP_Delete->Off();
	DeathBlink = 0.f;
	MaxSpeed = 0;
	FrameSpeed = 0;
	for (auto& Iter : All_MonsterCategory)
	{
		Iter->Death();
		Iter = nullptr;
	}
	//Monster_CurrentMonsterClass = MonsterClass::None;
}