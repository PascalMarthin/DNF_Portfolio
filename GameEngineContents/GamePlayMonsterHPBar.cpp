#include "PreCompile.h"
#include "GamePlayMonsterHPBar.h"
#include "GamePlayMonster.h"

GamePlayMonsterHPBar* GamePlayMonsterHPBar::CurrentActor = nullptr;

GameEngineTexture* GamePlayMonsterHPBar::Texture_NomalHPBar = nullptr;
GameEngineTexture* GamePlayMonsterHPBar::Texture_BossHPBar = nullptr;
GameEngineTexture* GamePlayMonsterHPBar::Texture_NomalHPBarEnd = nullptr;
GameEngineTexture* GamePlayMonsterHPBar::Texture_BossHPBarEnd = nullptr;

GameEngineTexture* GamePlayMonsterHPBar::Texture_BossColor = nullptr;
GameEngineTexture* GamePlayMonsterHPBar::Texture_NomalColor = nullptr;

std::vector<GameEngineTexture*> GamePlayMonsterHPBar::Vector_BossColor;
std::vector<GameEngineTexture*> GamePlayMonsterHPBar::Vector_NomalColor;


GamePlayMonsterHPBar::GamePlayMonsterHPBar() 
	: Texture_MonsterHPBar_UI(nullptr)
	, Texture_MonsterHPBar_UIEnd(nullptr)
	, Monster_Target(nullptr)
	, Mpnster_CurrentHP(-1)
	, Texture_HP1_Front(nullptr)
	, Texture_HP1_Back(nullptr)
	, Texture_HP2_Front(nullptr)
	, Texture_HP2_Back(nullptr)
	, Texture_HP1_White(nullptr)
	, Texture_HP2_White(nullptr)
	, CurrentIndex(0)
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


	Texture_MonsterHPBar_UI->SetPivot(PIVOTMODE::LEFTTOP);
	Texture_MonsterHPBar_UIEnd->SetPivot(PIVOTMODE::LEFTTOP);
	Texture_HP1_Front->SetPivot(PIVOTMODE::LEFTTOP);
	Texture_HP1_Back->SetPivot(PIVOTMODE::LEFTTOP);
	Texture_HP2_Front->SetPivot(PIVOTMODE::LEFTTOP);
	Texture_HP2_Back->SetPivot(PIVOTMODE::LEFTTOP);
	Texture_HP1_White->SetPivot(PIVOTMODE::LEFTTOP);
	Texture_HP2_White->SetPivot(PIVOTMODE::LEFTTOP);

	if (Texture_NomalHPBar == nullptr)
	{
		GamePlayMonsterHPBar::Texture_NomalHPBar = GameEngineTexture::Find("MonsterHP_NomalBar.png");
		GamePlayMonsterHPBar::Texture_BossHPBar = GameEngineTexture::Find("MonsterHP_BossBar.png");

		GamePlayMonsterHPBar::Texture_NomalHPBarEnd = GameEngineTexture::Find("MonsterHP_NomalBar_End.png");
		GamePlayMonsterHPBar::Texture_BossHPBarEnd = GameEngineTexture::Find("MonsterHP_BossBar_End.png");
		
	
		GamePlayMonsterHPBar::Vector_BossColor.push_back(GameEngineTexture::Find("MonsterHP_BossHP_Red.png"));
		GamePlayMonsterHPBar::Vector_BossColor.push_back(GameEngineTexture::Find("MonsterHP_BossHP_Orange.png"));
		GamePlayMonsterHPBar::Vector_BossColor.push_back(GameEngineTexture::Find("MonsterHP_BossHP_Green.png"));
		GamePlayMonsterHPBar::Vector_BossColor.push_back(GameEngineTexture::Find("MonsterHP_BossHP_Blue.png"));
		GamePlayMonsterHPBar::Vector_BossColor.push_back(GameEngineTexture::Find("MonsterHP_BossHP_Purple.png"));
		GamePlayMonsterHPBar::Vector_NomalColor.push_back(GameEngineTexture::Find("MonsterHP_NomalHP_Red.png"));
		GamePlayMonsterHPBar::Vector_NomalColor.push_back(GameEngineTexture::Find("MonsterHP_NomalHP_Orange.png"));
		GamePlayMonsterHPBar::Vector_NomalColor.push_back(GameEngineTexture::Find("MonsterHP_NomalHP_Green.png"));
		GamePlayMonsterHPBar::Vector_NomalColor.push_back(GameEngineTexture::Find("MonsterHP_NomalHP_Blue.png"));
		GamePlayMonsterHPBar::Vector_NomalColor.push_back(GameEngineTexture::Find("MonsterHP_NomalHP_Purple.png"));

		GamePlayMonsterHPBar::Texture_BossColor = GameEngineTexture::Find("MonsterHP_BossHP_White.png");
		GamePlayMonsterHPBar::Texture_BossColor = GameEngineTexture::Find("MonsterHP_NomalHP_White.png");
	}
	
}


void GamePlayMonsterHPBar::SetMonster(GamePlayMonster* _Monster)
{
	GamePlayMonsterHPBar* Actor = GamePlayMonsterHPBar::CurrentActor;

	if (Actor->Monster_Target == _Monster)
	{
		return;
	}

	Actor->Mpnster_CurrentHP = _Monster->GetMonsterStat()->GetHP();
	Actor->CurrentIndex = 0;

	switch (_Monster->GetMonsterClass())
	{
		case MonsterClass::Nomal:
		case MonsterClass::Named:
			Actor->Texture_MonsterHPBar_UI->SetTexture(GamePlayMonsterHPBar::Texture_NomalHPBar);
			Actor->Texture_MonsterHPBar_UI->GetTransform().SetLocalPosition({-20, 20});

			Actor->Texture_MonsterHPBar_UIEnd->SetTexture(GamePlayMonsterHPBar::Texture_NomalHPBarEnd);
			Actor->Texture_MonsterHPBar_UIEnd->GetTransform().SetLocalPosition({ 604, 5, -2.5f });

			Actor->Texture_HP1_Front->SetTexture(GamePlayMonsterHPBar::Vector_NomalColor[Actor->CurrentIndex]);
			Actor->Texture_HP1_Back->SetTexture(GamePlayMonsterHPBar::Vector_NomalColor[Actor->CurrentIndex]);

			Actor->Texture_HP2_Front->SetTexture(GamePlayMonsterHPBar::Vector_NomalColor[Actor->CurrentIndex + 1]);
			Actor->Texture_HP2_Back->SetTexture(GamePlayMonsterHPBar::Vector_NomalColor[Actor->CurrentIndex + 1]);

			Actor->Texture_HP1_White->SetTexture(GamePlayMonsterHPBar::Texture_BossColor);

			Actor->Texture_MonsterHPBar_UI->ScaleToTexture();
			Actor->Texture_MonsterHPBar_UIEnd->ScaleToTexture();
			Actor->Texture_HP1_Front->ScaleToTexture();
			Actor->Texture_HP1_Back->ScaleToTexture();
			Actor->Texture_HP1_White->ScaleToTexture();
			Actor->Texture_HP2_Front->ScaleToTexture();
			Actor->Texture_HP2_Back->ScaleToTexture();

			Actor->Texture_HP1_Front->GetTransform().SetLocalPosition({ 9, 3, 0 });
			Actor->Texture_HP1_Back->GetTransform().SetLocalPosition({ 9, 3, 0 });
			Actor->Texture_HP2_Front->GetTransform().SetLocalPosition({ 9, 3, 0 });
			Actor->Texture_HP2_Back->GetTransform().SetLocalPosition({ 9, 3, 0 });
			Actor->Texture_HP1_White->GetTransform().SetLocalPosition({ 9, 3, 0 });
			Actor->Texture_HP2_White->GetTransform().SetLocalPosition({ 9, 3, 0 });

			break;
		case MonsterClass::Boss:
			Actor->Texture_MonsterHPBar_UI->SetTexture(GamePlayMonsterHPBar::Texture_BossHPBar);

			Actor->Texture_MonsterHPBar_UIEnd->SetTexture(GamePlayMonsterHPBar::Texture_BossHPBarEnd);

			Actor->Texture_HP1_Front->SetTexture(Vector_BossColor[Actor->CurrentIndex]);
			Actor->Texture_HP1_Back->SetTexture(Vector_BossColor[Actor->CurrentIndex]);

			Actor->Texture_HP2_Front->SetTexture(Vector_BossColor[Actor->CurrentIndex + 1]);
			Actor->Texture_HP2_Back->SetTexture(Vector_BossColor[Actor->CurrentIndex + 1]);

			Actor->Texture_HP1_White->SetTexture(GamePlayMonsterHPBar::Texture_NomalColor);
			break;
		case MonsterClass::None:
		default:
			MsgBoxAssert("아직 몬스터 타입이 설정 되지 않았습니다");
			break;
	}

	Actor->Texture_HP1_Front->GetTransform().SetLocalMove({ 0, 0, -2.f });
	Actor->Texture_HP1_Back->GetTransform().SetLocalMove({ 0, 0, -1.5f });
	Actor->Texture_HP2_Front->GetTransform().SetLocalMove({ 0, 0, -1.5f });
	Actor->Texture_HP2_Back->GetTransform().SetLocalMove({ 0, 0, -0.5f });
	Actor->Texture_HP1_White->GetTransform().SetLocalMove({ 0, 0, -1.75f });
	Actor->Texture_HP2_White->GetTransform().SetLocalMove({ 0, 0, -0.75f });

}




void GamePlayMonsterHPBar::Update(float _DeltaTime)
{

}


void GamePlayMonsterHPBar::LevelStartEvent()
{
	GamePlayMonsterHPBar::CurrentActor = this;
}


void GamePlayMonsterHPBar::LevelEndEvent()
{
	GamePlayMonsterHPBar::CurrentActor = nullptr;
	Monster_Target = nullptr;
	Mpnster_CurrentHP = -1;
	CurrentIndex = 0;
	//Monster_CurrentMonsterClass = MonsterClass::None;
}