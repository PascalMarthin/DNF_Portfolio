#include "PreCompile.h"
#include "ComboSystemScore.h"
#include "GamePlayComboSystem.h"

ComboSystemScore* ComboSystemScore::BeforeInst = nullptr;



ComboSystemScore::ComboSystemScore()
	: Renewal(false)
	, NoInputTime(5.f)
	, CurrentRank(RankClass::None)
	, Texture_Dungeon_Rank(nullptr)
	, Texture_Dungeon_RankColor(nullptr)
	, Texture_Dungeon_Effect(nullptr)
	, ScoreDelay(0)
	, DoEffect(false)
	, DoEffectDelay(0)

{
}

ComboSystemScore::~ComboSystemScore() 
{
}

void ComboSystemScore::Start()
{
	//GetTransform().SetLocalScale({ 2.f, 2.f });
	Texture_Dungeon_Rank = CreateComponent<GameEngineUIRenderer>("Dungeon_Rank");
	Texture_Dungeon_Rank->GetTransform().SetLocalPosition({ 0, -15.f });
	Texture_Dungeon_Rank->SetPivot(PIVOTMODE::RIGHT);
	Texture_Dungeon_Rank->Off();
	Texture_Dungeon_RankColor = CreateComponent<GameEngineUIRenderer>("Dungeon_RankColor");
	Texture_Dungeon_RankColor->GetTransform().SetLocalPosition({-3, -13.f, -5});
	Texture_Dungeon_RankColor->SetPivot(PIVOTMODE::RIGHT);
	Texture_Dungeon_RankColor->Off();
	Texture_Dungeon_Effect = CreateComponent<GameEngineUIRenderer>("Dungeon_Effect");
	Texture_Dungeon_Effect->SetTexture(GamePlayComboSystem::TextureR_Dungeon_Rank->GetTexture(16));
	Texture_Dungeon_Effect->SetScaleRatio(1.8f);
	Texture_Dungeon_Effect->ScaleToTexture();
	Texture_Dungeon_Effect->GetTransform().SetLocalPosition({ -35.f, 0, -5.01f });
	Texture_Dungeon_Effect->GetPixelData().MulColor.a = 0.95f;
	Texture_Dungeon_Effect->GetPixelData().PlusColor = {0.85f, 0.85f ,0.85f , 0.3f};
	//Texture_Dungeon_Effect->SetPivot(PIVOTMODE::RIGHT);
	Texture_Dungeon_Effect->Off();





	for (size_t i = 0; i < 7; i++)
	{
		GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>("Dungeon_score");
		Renderer->SetPivot(PIVOTMODE::RIGHTTOP);
		Renderer->GetTransform().SetLocalPosition({ 18.f * -static_cast<float>(i), -28.f });
		Renderer->GetTransform().SetLocalScale({ 23, 30 });
		Renderer->Off();
		vector_Texture_Dungeon_score.push_back(Renderer);
	}

}

void ComboSystemScore::Update(float _Delta)
{

	if (NoInputTime < 0)
	{
		//Texture_Dungeon_Rank->GetPixelData().MulColor.a = 0.7f;
		//Texture_Dungeon_RankColor->GetPixelData().MulColor.a = 0.7f;
		//Texture_Dungeon_Effect->GetPixelData().MulColor.a = 0.7f;
		//for (auto& Renderer : vector_Texture_Dungeon_score)
		//{
		//	Renderer->GetPixelData().MulColor.a = 0.7f;
		//}
	}
	else
	{
		NoInputTime -= _Delta;
	}

	if (DoEffect == true)
	{
		if (DoEffectDelay > 1.f)
		{
			Texture_Dungeon_Rank->On();
			DoEffectDelay -= _Delta * 2.f;
			if (DoEffectDelay <= 1.f)
			{
				Texture_Dungeon_Rank->SetScaleRatio(1.f);
				Texture_Dungeon_Rank->GetTransform().SetLocalPosition({0,-15.f,0});
				Texture_Dungeon_Rank->GetPixelData().PlusColor = float4::ZERO;
				DoEffectDelay = 1.f;
				/*Texture_Dungeon_Rank->GetTransform*/

			}
			else 
			{
				Texture_Dungeon_Rank->SetScaleRatio(2.f * (1.f - (2.f - DoEffectDelay)) + (2.f - DoEffectDelay));
				Texture_Dungeon_Rank->GetTransform().SetLocalPosition({ 0,-15.f,-5.1f });

				float Color = (1.f - (2.f - (DoEffectDelay)) * 1.2f);
				if (Color < 0)
				{
					Color = 0;
				}
				Texture_Dungeon_Rank->GetPixelData().PlusColor = { Color ,Color , Color ,0 };
			}

			Texture_Dungeon_Rank->ScaleToTexture();
		}
		else if (DoEffectDelay > 0)
		{
			Texture_Dungeon_RankColor->On();
			DoEffectDelay -= _Delta * 2.f;
			if (DoEffectDelay < 0)
			{
				Texture_Dungeon_RankColor->SetScaleRatio(1.f);
				Texture_Dungeon_RankColor->GetPixelData().MulColor.a = 1.f;
				Texture_Dungeon_Effect->GetPixelData().PlusColor.a = 0;
				Texture_Dungeon_Effect->Off();
				DoEffectDelay = 0;
				DoEffect = false;
			}
			else
			{
				Texture_Dungeon_RankColor->SetScaleRatio(DoEffectDelay + 2.3f * (1.f - DoEffectDelay));
				Texture_Dungeon_RankColor->GetPixelData().MulColor.a = DoEffectDelay;
			}
			Texture_Dungeon_RankColor->ScaleToTexture();
		}

		if (DoEffectDelay < 1.8f && DoEffectDelay != 0)
		{
			Texture_Dungeon_Effect->GetTransform().SetLocalRotate({ 0, 0, -_Delta * 150.f });
			Texture_Dungeon_Effect->SetScaleRatio(1.8f * (1.f - ((1.8f - DoEffectDelay) / 1.8f)) + 0.5f * ((1.8f - DoEffectDelay) / 1.8f));
			Texture_Dungeon_Effect->GetPixelData().MulColor.a = 0.95f * (1.f - ((1.8f - DoEffectDelay) / 1.8f));
			Texture_Dungeon_Effect->GetPixelData().PlusColor.a = 0.3f;
			
			Texture_Dungeon_Effect->GetTransform().SetLocalPosition({ -35.f * (1.f - ((1.8f - DoEffectDelay) / 1.8f)), -10.f * DoEffectDelay, -5.01f });
			Texture_Dungeon_Effect->ScaleToTexture();
			Texture_Dungeon_Effect->On();
		}
	}
	else
	{
		FillRankColor();
	}

	if (Renewal == true)
	{
		if (vector_Texture_Dungeon_score[0]->GetPixelData().PlusColor.r > 0)
		{
			for (size_t i = 0; i < vector_Texture_Dungeon_score.size(); i++)
			{
				vector_Texture_Dungeon_score[i]->GetPixelData().PlusColor.r -= _Delta * 8.f;
				vector_Texture_Dungeon_score[i]->GetPixelData().PlusColor.g -= _Delta * 8.f;
				vector_Texture_Dungeon_score[i]->GetPixelData().PlusColor.b -= _Delta * 8.f;
				//vector_Texture_Dungeon_score[i]->GetPixelData().PlusColor.a -= _Delta * 8.f;

				if (vector_Texture_Dungeon_score[i]->GetPixelData().PlusColor.r < 0)
				{
					vector_Texture_Dungeon_score[i]->GetPixelData().PlusColor.r = 0;
					vector_Texture_Dungeon_score[i]->GetPixelData().PlusColor.g = 0;
					vector_Texture_Dungeon_score[i]->GetPixelData().PlusColor.b = 0;
					vector_Texture_Dungeon_score[i]->GetPixelData().PlusColor.a = 0;
				}
			}
		}
		if (ScoreDelay < 0)
		{
			ScoreDelay += _Delta * 10.f;
			float Move = LikePushbuttonPower * (1.f + ScoreDelay);
			if (ScoreDelay >= 0)
			{
				Move = LikePushbuttonPower;
				ScoreDelay = 0;
			}

			for (size_t i = 0; i < vector_Texture_Dungeon_score.size(); i++)
			{
				vector_Texture_Dungeon_score[i]->GetTransform().SetLocalPosition({ (18.f * -static_cast<float>(i)) + Move,  -30.f - Move });
			}
		}
		else if(ScoreDelay >= 0 && ScoreDelay < 1)
		{
			ScoreDelay += _Delta * 10.f;
			float Move = LikePushbuttonPower * ScoreDelay;
			if (ScoreDelay >= 1)
			{
				Move = LikePushbuttonPower;
				ScoreDelay = 1;
				Renewal = false;
			}

			for (size_t i = 0; i < vector_Texture_Dungeon_score.size(); i++)
			{
				vector_Texture_Dungeon_score[i]->GetTransform().SetLocalPosition({ (18.f * -static_cast<float>(i) + LikePushbuttonPower) - Move,  -30.f - LikePushbuttonPower + Move });
			}
		}
	}
}

void ComboSystemScore::FillRankColor()
{
	unsigned __int64 Score = GamePlayComboSystem::GetInst()->ComboScore;
	float SliceY = 0;
	if (Score > 5000000)
	{
		SliceY = 0;
		//SSS
	}
	else if (Score > 2500000)
	{

		SliceY = static_cast<float>(Score - 2500000) / static_cast<float>(5000000 - 2500000);


		//SS
	}
	else if (Score > 1000000)
	{
		SliceY = static_cast<float>(Score - 1000000) / static_cast<float>(2500000 - 1000000);

		//S
	}
	else if (Score > 500000)
	{
		SliceY = static_cast<float>(Score - 500000) / static_cast<float>(1000000 - 500000);
		//A
	}
	else if (Score > 250000)
	{
		SliceY = static_cast<float>(Score - 250000) / static_cast<float>(500000 - 250000);
		//B
	}
	else if (Score > 100000)
	{
		SliceY = static_cast<float>(Score - 100000) / static_cast<float>(250000 - 100000);
		//C
	}
	else if (Score > 50000)
	{
		SliceY = static_cast<float>(Score - 50000) / static_cast<float>(100000 - 50000);
		//D
	}
	else
	{
		SliceY = static_cast<float>(Score) / static_cast<float>(50000);

		//F
	}

	Texture_Dungeon_RankColor->GetPixelData().Slice.y = 1.f - SliceY;
}

void ComboSystemScore::RenewalScore(unsigned __int64 _Score)
{
	unsigned __int64 Score = _Score;
	if (Score > 9999999)
	{
		Score = 9999999;
	}
	for (auto& Score : vector_Texture_Dungeon_score)
	{
		Score->Off();
	}

	std::string Combo = std::to_string(Score);
	int i = 0;
	while (Combo.size() != 0)
	{
		vector_Texture_Dungeon_score[i]->SetTexture(GamePlayComboSystem::TextureR_Dungeon_score->GetTexture(static_cast<int>(Combo.back()) - 48));
		vector_Texture_Dungeon_score[i]->ScaleToTexture();
		vector_Texture_Dungeon_score[i]->GetPixelData().PlusColor = {1, 1, 1, 0};

		vector_Texture_Dungeon_score[i]->On();
		Combo.pop_back();
		++i;
		if (i >= 7)
		{
			break;
		}
	}


	Texture_Dungeon_Rank->GetPixelData().MulColor.a = 1.f;
	Texture_Dungeon_RankColor->GetPixelData().MulColor.a = 1.f;

	//Texture_Dungeon_Effect->GetPixelData().MulColor.a = 1.f;

	for (auto& Renderer : vector_Texture_Dungeon_score)
	{
		Renderer->GetPixelData().MulColor.a = 1.f;
	}

	Renewal = true;
	ScoreDelay = -1.0f;

	RenewalRank(Score);
	NoInputTime = 10.f;

}


void ComboSystemScore::RenewalRank(unsigned __int64 _Score)
{
	RankClass Before = CurrentRank;
	if (_Score > 5000000)
	{
		CurrentRank = RankClass::SSS;
		//SSS
	}
	else if (_Score > 2500000)
	{
		CurrentRank = RankClass::SS;
		//SS
	}
	else if (_Score > 1000000)
	{
		CurrentRank = RankClass::S;
		//S
	}
	else if (_Score > 500000)
	{
		CurrentRank = RankClass::A;
		//A
	}
	else if (_Score > 250000)
	{
		CurrentRank = RankClass::B;
		//B
	}
	else if (_Score > 100000)
	{
		CurrentRank = RankClass::C;
		//C
	}
	else if (_Score > 50000)
	{
		CurrentRank = RankClass::D;
		//D
	}
	else
	{
		CurrentRank = RankClass::F;
		//F
	}

	SetRankTexure(CurrentRank);
	if (Before != CurrentRank)
	{
		EffectPlus();
	}
}

void ComboSystemScore::EffectPlus()
{
	DoEffect = true;
	DoEffectDelay = 2.f;

	Texture_Dungeon_Rank->SetScaleRatio(1.f);
	Texture_Dungeon_Rank->GetTransform().SetLocalPosition({ 0,0,0 });
	Texture_Dungeon_Rank->GetPixelData().PlusColor = float4::ZERO;

	Texture_Dungeon_RankColor->SetScaleRatio(1.f);
	Texture_Dungeon_RankColor->GetPixelData().MulColor.a = 1.f;
	Texture_Dungeon_Effect->GetTransform().SetLocalRotation({ 0, 0, 0 });
	Texture_Dungeon_Effect->GetTransform().SetLocalPosition({ -35.f, 0, -5.01f });

	Texture_Dungeon_RankColor->Off();
}

void ComboSystemScore::SetRankTexure(RankClass _Rank)
{
	switch (_Rank)
	{
	case RankClass::SSS:
		Texture_Dungeon_Rank->SetTexture(GamePlayComboSystem::TextureR_Dungeon_Rank->GetTexture(0));
		Texture_Dungeon_RankColor->SetTexture(GamePlayComboSystem::TextureR_Dungeon_Rank->GetTexture(1));
		break;
	case RankClass::SS:
		Texture_Dungeon_Rank->SetTexture(GamePlayComboSystem::TextureR_Dungeon_Rank->GetTexture(2));
		Texture_Dungeon_RankColor->SetTexture(GamePlayComboSystem::TextureR_Dungeon_Rank->GetTexture(3));
		break;
	case RankClass::S:
		Texture_Dungeon_Rank->SetTexture(GamePlayComboSystem::TextureR_Dungeon_Rank->GetTexture(4));
		Texture_Dungeon_RankColor->SetTexture(GamePlayComboSystem::TextureR_Dungeon_Rank->GetTexture(5));
		break;
	case RankClass::A:
		Texture_Dungeon_Rank->SetTexture(GamePlayComboSystem::TextureR_Dungeon_Rank->GetTexture(6));
		Texture_Dungeon_RankColor->SetTexture(GamePlayComboSystem::TextureR_Dungeon_Rank->GetTexture(7));
		break;
	case RankClass::B:
		Texture_Dungeon_Rank->SetTexture(GamePlayComboSystem::TextureR_Dungeon_Rank->GetTexture(8));
		Texture_Dungeon_RankColor->SetTexture(GamePlayComboSystem::TextureR_Dungeon_Rank->GetTexture(9));
		break;
	case RankClass::C:
		Texture_Dungeon_Rank->SetTexture(GamePlayComboSystem::TextureR_Dungeon_Rank->GetTexture(10));
		Texture_Dungeon_RankColor->SetTexture(GamePlayComboSystem::TextureR_Dungeon_Rank->GetTexture(11));
		break;
	case RankClass::D:
		Texture_Dungeon_Rank->SetTexture(GamePlayComboSystem::TextureR_Dungeon_Rank->GetTexture(12));
		Texture_Dungeon_RankColor->SetTexture(GamePlayComboSystem::TextureR_Dungeon_Rank->GetTexture(13));
		break;
	case RankClass::F:
		Texture_Dungeon_Rank->SetTexture(GamePlayComboSystem::TextureR_Dungeon_Rank->GetTexture(14));
		Texture_Dungeon_RankColor->SetTexture(GamePlayComboSystem::TextureR_Dungeon_Rank->GetTexture(15));
		break;
	case RankClass::None:
	default:
		MsgBoxAssert("랭크를 아직 설정하지 않았습니다")
		break;
	}
	Texture_Dungeon_Rank->ScaleToTexture();
	Texture_Dungeon_RankColor->ScaleToTexture();
	Texture_Dungeon_Rank->On();
	Texture_Dungeon_RankColor->On();
}


void ComboSystemScore::LevelStartEvent()
{
	NoInputTime = 0;
	Renewal = false;
	DoEffect = false;
	DoEffectDelay = 0;


	if (BeforeInst == nullptr || BeforeInst->CurrentRank == RankClass::None)
	{
		//CurrentRank = RankClass::F;
		//SetRankTexure(CurrentRank);
	}
	BeforeInst = nullptr;
}
void ComboSystemScore::LevelEndEvent()
{
	BeforeInst = this;

}