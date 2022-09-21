#include "PreCompile.h"
#include "GamePlayComboSystem.h"
#include "ComboSystemBlank.h"
#include "ComboSystemScore.h"

GameEngineFolderTexture* GamePlayComboSystem::TextureR_Combo_num 		 = nullptr;
GameEngineFolderTexture* GamePlayComboSystem::TextureR_Combo_bonus		 = nullptr;
GameEngineFolderTexture* GamePlayComboSystem::TextureR_Dungeon_Rank		 = nullptr;
GameEngineFolderTexture* GamePlayComboSystem::TextureR_Dungeon_score	 = nullptr;
GameEngineFolderTexture* GamePlayComboSystem::TextureR_Killpoint_num	 = nullptr;
GameEngineFolderTexture* GamePlayComboSystem::TextureR_Monster_killcount = nullptr;
GameEngineFolderTexture* GamePlayComboSystem::TextureR_Monsterkill		 = nullptr;
GameEngineFolderTexture* GamePlayComboSystem::TextureR_Monsterkill_grade = nullptr;

GamePlayComboSystem* GamePlayComboSystem::Before = nullptr;
GamePlayComboSystem* GamePlayComboSystem::Inst = nullptr;
GamePlayComboSystem::GamePlayComboSystem()
	: ComboScore(0)
	, ComboStack(0)
	, PushBack(false)
	, Actor_ComboSystemScore(nullptr)
{
}

GamePlayComboSystem::~GamePlayComboSystem() 
{
}

void GamePlayComboSystem::Start()
{
	GetTransform().SetLocalPosition({ 620 , -10 });
	GetTransform().SetLocalScale({ MonitorX, MonitorY });
	if (TextureR_Combo_num == nullptr)
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExitsChildDirectory("Resource");
		Dir.Move("Resource");
		Dir.Move("Texture");
		Dir.Move("UI");
		Dir.Move("ComboEffect");

		std::vector<GameEngineDirectory> AllTextureDir = Dir.GetRecursiveAllDirectory();

		for (GameEngineDirectory& DirIter : AllTextureDir)
		{
			GameEngineFolderTexture::Load(DirIter.GetFullPath());
		}


		TextureR_Combo_num = GameEngineFolderTexture::Find("combo_bonus_num");
		TextureR_Combo_bonus = GameEngineFolderTexture::Find("newcombo_bonus");
		TextureR_Dungeon_Rank = GameEngineFolderTexture::Find("dungeon_rank");
		TextureR_Dungeon_score = GameEngineFolderTexture::Find("dungeon_score");
		TextureR_Killpoint_num = GameEngineFolderTexture::Find("killpoint_num");
		TextureR_Monster_killcount = GameEngineFolderTexture::Find("monster_killcount");
		TextureR_Monsterkill = GameEngineFolderTexture::Find("monsterkill");
		TextureR_Monsterkill_grade = GameEngineFolderTexture::Find("monsterkill_grade");




		GamePlayComboSystem::Inst = this;
	}
	//std::vector<GameEngineUIRenderer*> vector_Texture_Combo_num;
	//std::vector<GameEngineUIRenderer*> vector_Texture_Combo_bonus;
	//std::vector<GameEngineUIRenderer*> vector_Texture_Dungeon_Rank;
	//std::vector<GameEngineUIRenderer*> vector_Texture_Dungeon_score;
	//std::vector<GameEngineUIRenderer*> vector_Texture_Killpoint_num;


	//std::vector<GameEngineUIRenderer*> vector_Texture_Monster_killcount;
	//std::vector<GameEngineUIRenderer*> vector_Texture_Monsterkill;
	//std::vector<GameEngineUIRenderer*> vector_Texture_Monsterkill_grade;
	{
		Actor_ComboSystemScore = GetLevel()->CreateActor<ComboSystemScore>();
		Actor_ComboSystemScore->SetParent(this);
		Actor_ComboSystemScore->GetTransform().SetLocalPosition({0, 5, 10});

		float Len = 18.f;
		float Hight = -30.f;

		Hight -= 35.f;
		Len = 60.f;

		Hight -= 9.f;
		for (size_t i = 0; i < 5; i++)
		{
			ComboSystemBlank* Blank = GetLevel()->CreateActor<ComboSystemBlank>();
			Blank->SetParent(this);
			Blank->GetTransform().SetLocalPosition({-77.5f, Hight, 10});
			Hight -= 16.f;
			vector_ComboBlank.push_back(Blank);
		}

	}

}

void GamePlayComboSystem::ComboShowEnd()
{
	for (size_t i = 0; i < 4; i++)
	{
		int a = 0;
		while (vector_ComboBlank[i]->CurrentClass == ComboClass::None)
		{
			if (i + a > 4)
			{
				break;
			}
			ChangeBlank(vector_ComboBlank[i], vector_ComboBlank[i + 1]);
			a++;
		}

	}
}


void GamePlayComboSystem::Update(float _DeltaTime)
{


	if (!Queue_ComboClass.empty())
	{

		ComboShowEnd();
		int UpdateOn = 0;
		for (size_t i = 0; i < 5; i++)
		{
			if (vector_ComboBlank[i]->CurrentClass != ComboClass::None)
			{
				++UpdateOn;
			}
		}

		while (!Queue_ComboClass.empty())
		{
			if (UpdateOn > 4) // 5부터 앞에서 잘라버리기
			{
				if (vector_ComboBlank[0]->CurrentClass == ComboClass::Combo)
				{
					for (size_t i = 1; i < 4; i++)
					{
						ChangeBlank(vector_ComboBlank[i], vector_ComboBlank[i + 1]);
						--UpdateOn;
					}
				}
				else
				{
					for (size_t i = 0; i < 4; i++)
					{
						ChangeBlank(vector_ComboBlank[i], vector_ComboBlank[i + 1]);
						--UpdateOn;
					}
				}

			}
			else
			{
				if (Queue_ComboClass.front() == ComboClass::Combo)
				{
					bool ComboIsit = false;
					for (size_t i = 0; i < 5; i++)
					{
						if (vector_ComboBlank[i]->CurrentClass == ComboClass::Combo)
						{
							ComboIsit = true;
							Queue_ComboClass.pop();
							break;
						}
					}

					if (ComboIsit == false)
					{
						vector_ComboBlank[UpdateOn]->SetComboClass(Queue_ComboClass.front());
						vector_ComboBlank[UpdateOn]->SetBrighting();
						vector_ComboBlank[UpdateOn]->On();
						Queue_ComboClass.pop();
					}
				}
				else
				{
					vector_ComboBlank[UpdateOn]->SetComboClass(Queue_ComboClass.front());
					vector_ComboBlank[UpdateOn]->SetBrighting();
					vector_ComboBlank[UpdateOn]->On();
					UpdateOn++;
					Queue_ComboClass.pop();
				}

				if (UpdateOn == 5)
				{
					int a = 0;
				}
			}
		}
		Queue_ComboClass = std::queue<ComboClass>();
	}

	
}

void GamePlayComboSystem::ChangeBlank(ComboSystemBlank* _After, ComboSystemBlank* _Before)
{
	_After->On();
	_After->SetComboClass(_Before->CurrentClass);

	_After->Combo_bonus_Time = 3.f;
	_After->Combo_BrightTime = _Before->Combo_BrightTime;
	_After->FontSizeUp = _Before->FontSizeUp;

	

	_Before->SetComboClass(ComboClass::None);
	_Before->Combo_bonus_Time = 0;
	_Before->Combo_BrightTime = 0;
	_Before->Off();
}

void GamePlayComboSystem::PlusScore(unsigned __int64 _Score)
{
	ComboScore += _Score;
	Actor_ComboSystemScore->RenewalScore(ComboScore);

	PlusCombo();
}

void GamePlayComboSystem::SetComboClass(ComboClass _Class)
{
	if (_Class == ComboClass::Combo)
	{
		for (size_t i = 0; i < 5; i++)
		{
			if (vector_ComboBlank[i]->CurrentClass == ComboClass::Combo)
			{
				return;
			}
		}
	}


	Queue_ComboClass.push(_Class);
}

void GamePlayComboSystem::ComboTimeEnd()
{
	ComboStack = 0;
}


void GamePlayComboSystem::PlusCombo()
{
	++ComboStack;
	if (ComboStack > 999)
	{
		ComboStack = 999;
	}

	bool ComboIsIt = true;
	for (size_t i = 0; i < 5; i++)
	{
		if (vector_ComboBlank[i]->RenewalCombo())
		{
			ComboIsIt = false;
		}
	}

	if (ComboIsIt)
	{
		Queue_ComboClass.push(ComboClass::Combo);
	}

}


void GamePlayComboSystem::LevelStartEvent()
{

	if (GamePlayComboSystem::Before != nullptr)
	{
		ComboStack = Before->ComboStack;
		ComboScore = Before->ComboScore;
	}
	Queue_ComboClass = std::queue<ComboClass>();

	GamePlayComboSystem::Inst = this;
	GamePlayComboSystem::Before = nullptr;
}

void GamePlayComboSystem::LevelEndEvent()
{
	GamePlayComboSystem::Before = this;
	GamePlayComboSystem::Inst = nullptr;
	Queue_ComboClass = std::queue<ComboClass>();
}