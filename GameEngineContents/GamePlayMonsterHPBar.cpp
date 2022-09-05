#include "PreCompile.h"
#include "GamePlayMonsterHPBar.h"
#include "GamePlayMonster.h"

GamePlayMonsterHPBar* GamePlayMonsterHPBar::CurrentActor = nullptr;

GameEngineTexture* GamePlayMonsterHPBar::Texture_NomalHPBar = nullptr;
GameEngineTexture* GamePlayMonsterHPBar::Texture_BossHPBar = nullptr;
GameEngineTexture* GamePlayMonsterHPBar::Texture_BossColor = nullptr;
GameEngineTexture* GamePlayMonsterHPBar::Texture_NomalColor = nullptr;

std::vector<GameEngineTexture*> GamePlayMonsterHPBar::Vector_BossColor;
std::vector<GameEngineTexture*> GamePlayMonsterHPBar::Vector_NomalColor;


GamePlayMonsterHPBar::GamePlayMonsterHPBar() 
	: Texture_MonsterHPBar_UI(nullptr)
	, Monster_Target(nullptr)
	, Mpnster_CurrentHP(-1)
	, Texture_HP1_Front(nullptr)
	, Texture_HP1_Back(nullptr)
	, Texture_HP2_Front(nullptr)
	, Texture_HP2_Back(nullptr)
	, Texture_HP_White(nullptr)
	, CurrentIndex(0)
	//, Monster_CurrentMonsterClass(MonsterClass::None)
{
}

GamePlayMonsterHPBar::~GamePlayMonsterHPBar() 
{
}

void GamePlayMonsterHPBar::Start()
{
	Texture_MonsterHPBar_UI = CreateComponent<GameEngineUIRenderer>();
	Texture_HP1_Front = CreateComponent<GameEngineUIRenderer>();
	Texture_HP1_Front->GetTransform().SetLocalPosition({ 0, 0, 0 });
	Texture_HP1_Back = CreateComponent<GameEngineUIRenderer>();
	Texture_HP1_Back->GetTransform().SetLocalPosition({ 0, 0, 0.01f });
	Texture_HP2_Front = CreateComponent<GameEngineUIRenderer>();
	Texture_HP2_Front->GetTransform().SetLocalPosition({ 0, 0, 1});
	Texture_HP2_Back = CreateComponent<GameEngineUIRenderer>();
	Texture_HP2_Back->GetTransform().SetLocalPosition({ 0, 0, 1.01f});
	Texture_HP_White = CreateComponent<GameEngineUIRenderer>();
	Texture_HP_White->GetTransform().SetLocalPosition({ 0, 0, 0.1f });

	if (Texture_NomalHPBar == nullptr)
	{
		GamePlayMonsterHPBar::Texture_NomalHPBar = GameEngineTexture::Find("MonsterHP_NomalBar.png");
		GamePlayMonsterHPBar::Texture_BossHPBar = GameEngineTexture::Find("MonsterHP_BossBar.png");
	
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
			Actor->Texture_HP1_Front->SetTexture(GamePlayMonsterHPBar::Vector_BossColor[Actor->CurrentIndex]);
			Actor->Texture_HP1_Back->SetTexture(GamePlayMonsterHPBar::Vector_BossColor[Actor->CurrentIndex]);

			Actor->Texture_HP2_Front->SetTexture(GamePlayMonsterHPBar::Vector_BossColor[Actor->CurrentIndex + 1]);
			Actor->Texture_HP2_Back->SetTexture(GamePlayMonsterHPBar::Vector_BossColor[Actor->CurrentIndex + 1]);

			Actor->Texture_HP_White->SetTexture(GamePlayMonsterHPBar::Texture_BossColor);
			break;
		case MonsterClass::Boss:
			Actor->Texture_MonsterHPBar_UI->SetTexture(GamePlayMonsterHPBar::Texture_BossHPBar);
			Actor->Texture_HP1_Front->SetTexture(Vector_NomalColor[Actor->CurrentIndex]);
			Actor->Texture_HP1_Back->SetTexture(Vector_NomalColor[Actor->CurrentIndex]);

			Actor->Texture_HP2_Front->SetTexture(Vector_NomalColor[Actor->CurrentIndex + 1]);
			Actor->Texture_HP2_Back->SetTexture(Vector_NomalColor[Actor->CurrentIndex + 1]);

			Actor->Texture_HP_White->SetTexture(GamePlayMonsterHPBar::Texture_NomalColor);
			break;
		case MonsterClass::None:
		default:
			MsgBoxAssert("아직 몬스터 타입이 설정 되지 않았습니다");
			break;
	}



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