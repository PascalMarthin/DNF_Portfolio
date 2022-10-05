#include "PreCompile.h"
#include "GamePlayComboSystem.h"
#include "GamePlayResultWindow.h"

GamePlayResultWindow::GamePlayResultWindow() 
{
}

GamePlayResultWindow::~GamePlayResultWindow() 
{
}

void GamePlayResultWindow::Start()
{
	GetTransform().SetLocalPosition({ 430, 80 });

	Texteure_RankWindow = CreateComponent<GameEngineUIRenderer>();
	Texteure_RankWindow->SetTexture("Result_Window.png");
	Texteure_RankWindow->GetTransform().SetLocalScale({ 270, 500 });
//	Texteure_RankWindow->ScaleToTexture();
	Texteure_RankWindow->GetTransform().SetLocalPosition({ 0, -100 });


	Texteure_Result = CreateComponent<GameEngineUIRenderer>();
	Texteure_Result->SetTexture("Result_Result.png");
	Texteure_Result->ScaleToTexture();
	Texteure_Result->GetTransform().SetLocalPosition({ 0, 200 });

	Texteure_Rank = CreateComponent<GameEngineUIRenderer>();
	Texteure_Rank->SetTexture("Result_Rank.png");
	Texteure_Rank->ScaleToTexture();
	Texteure_Rank->GetTransform().SetLocalPosition({ 30, 70 });


	Texteure_RankScore = CreateComponent<GameEngineUIRenderer>();
	Texteure_RankScore->SetTexture("Result_RankScore.png");
	Texteure_RankScore->ScaleToTexture();
	Texteure_RankScore->GetTransform().SetLocalPosition({ 0, 60 });


	Texteure_ComboResult = CreateComponent<GameEngineUIRenderer>();
	Texteure_ComboResult->SetTexture("Result_ComboResult.png");
	//Texteure_ComboResult->GetTransform().SetLocalScale({ 248, 120 });
	Texteure_ComboResult->GetTransform().SetLocalPosition({0, -50 });
	Texteure_ComboResult->SetScaleRatio(0.83f);
	Texteure_ComboResult->ScaleToTexture();

	Texteure_RankSSS = CreateComponent<GameEngineUIRenderer>();
	//Texteure_RankSSS->SetTexture("Result_RankF.png");
	Texteure_RankSSS->GetTransform().SetLocalPosition({ 0, 100 });

	if (GamePlayComboSystem::GetInst() != nullptr)
	{
		unsigned int Score = GamePlayComboSystem::GetInst()->ComboScore;
		if (Score > 5000000)
		{
			Texteure_RankSSS->SetTexture("Result_RankSSS.png");
			//SSS
		}
		else if (Score > 2500000)
		{
			Texteure_RankSSS->SetTexture("Result_RankSS.png");
			//SS
		}
		else if (Score > 1000000)
		{
			Texteure_RankSSS->SetTexture("Result_RankS.png");
			//S
		}
		else if (Score > 500000)
		{
			Texteure_RankSSS->SetTexture("Result_RankA.png");
			//A
		}
		else if (Score > 250000)
		{
			Texteure_RankSSS->SetTexture("Result_RankB.png");
			//B
		}
		else if (Score > 100000)
		{
			Texteure_RankSSS->SetTexture("Result_RankC.png");
			//C
		}
		else if (Score > 50000)
		{
			Texteure_RankSSS->SetTexture("Result_RankD.png");
			//D
		}
		else
		{
			Texteure_RankSSS->SetTexture("Result_RankF.png");
			//F
		}
		Texteure_RankSSS->ScaleToTexture();



	;

	}

	{
		GameEngineUIFontRenderer* Font = CreateComponent<GameEngineUIFontRenderer>();
		Font->SetRenderingOrder(10000);
		Font->SetColor({ 1.f,  1,  1, 1.0 });
		Font->SetPositionMode(FontPositionMode::WORLD);
		Font->GetTransform().SetLocalPosition({ 70, 36 });
		Font->SetSize(12.f);
		Font->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		Font->SetTopAndBotSort(TopAndBotSort::VCENTER);
		Font->SetText(std::to_string(GamePlayComboSystem::GetInst()->ComboScore), "±¼¸²");


		Font = CreateComponent<GameEngineUIFontRenderer>();
		Font->SetRenderingOrder(10000);
		Font->SetColor({ 1.f,  1,  1, 1.0 });
		Font->SetPositionMode(FontPositionMode::WORLD);
		Font->GetTransform().SetLocalPosition({ 70,-14 });
		Font->SetSize(12.f);
		Font->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		Font->SetTopAndBotSort(TopAndBotSort::VCENTER);
		Font->SetText(std::to_string(GamePlayComboSystem::GetInst()->MaxComboStack), "±¼¸²");

		Font = CreateComponent<GameEngineUIFontRenderer>();
		Font->SetRenderingOrder(10000);
		Font->SetColor({ 1.f,  1,  1, 1.0 });
		Font->SetPositionMode(FontPositionMode::WORLD);
		Font->GetTransform().SetLocalPosition({70,-32});
		Font->SetSize(12.f);
		Font->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		Font->SetTopAndBotSort(TopAndBotSort::VCENTER);
		Font->SetText(std::to_string(GamePlayComboSystem::GetInst()->map_ComboStuck[ComboClass::Counter] + GamePlayComboSystem::GetInst()->map_ComboStuck[ComboClass::CounterHold]), "±¼¸²");

		Font = CreateComponent<GameEngineUIFontRenderer>();
		Font->SetRenderingOrder(10000);
		Font->SetColor({ 1.f,  1,  1, 1.0 });
		Font->SetPositionMode(FontPositionMode::WORLD);
		Font->GetTransform().SetLocalPosition({ 70,-50 });
		Font->SetSize(12.f);
		Font->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		Font->SetTopAndBotSort(TopAndBotSort::VCENTER);
		Font->SetText(std::to_string(GamePlayComboSystem::GetInst()->map_ComboStuck[ComboClass::MultiHit]), "±¼¸²");

		Font = CreateComponent<GameEngineUIFontRenderer>();
		Font->SetRenderingOrder(10000);
		Font->SetColor({ 1.f,  1,  1, 1.0 });
		Font->SetPositionMode(FontPositionMode::WORLD);
		Font->GetTransform().SetLocalPosition({ 70, -68 });
		Font->SetSize(12.f);
		Font->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		Font->SetTopAndBotSort(TopAndBotSort::VCENTER);
		Font->SetText(std::to_string(GamePlayComboSystem::GetInst()->map_ComboStuck[ComboClass::BeHit]), "±¼¸²");
		//Font->SetText("0", "±¼¸²");

	}



	//Texteure_RankSmall = CreateComponent<GameEngineUIRenderer>();
	//Texteure_RankSmall->SetTexture("ResultRank_A.png");
	//Texteure_RankSmall->ScaleToTexture();
	//Texteure_RankSmall->GetTransform().SetLocalPosition({ 0, 100 });
	StartDelay = 0;
}
void GamePlayResultWindow::Update(float _Time)
{
	StartDelay += _Time * 5.f;
	if (StartDelay > 1.f)
	{
		GetTransform().SetLocalPosition({ 430, 80 });
	}
	else
	{
		
		GetTransform().SetLocalPosition(float4::Lerp({ 900, 80 }, {430, 80}, StartDelay));
	}



}
