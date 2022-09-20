#include "PreCompile.h"
#include "GamePlayComboSystem.h"

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
	, ComboDelay(0)
	, BrightIndex(0)

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
		for (size_t i = 0; i < 3; i++)
		{
			GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>("Dungeon_Rank");
			Renderer->SetPivot(PIVOTMODE::RIGHTTOP);
			Renderer->Off();
			vector_Texture_Dungeon_Rank.push_back(Renderer);
		}
		vector_Texture_Dungeon_Rank[0]->SetTexture(TextureR_Dungeon_Rank->GetTexture(0));
		vector_Texture_Dungeon_Rank[0]->ScaleToTexture();
		vector_Texture_Dungeon_Rank[0]->On();

		float Len = 18.f;
		float Hight = -30.f;
		for (size_t i = 0; i < 7; i++)
		{
			GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>("Dungeon_score");
			Renderer->SetPivot(PIVOTMODE::RIGHTTOP);
			Renderer->GetTransform().SetLocalPosition({ Len * -static_cast<float>(i), Hight });
			Renderer->GetTransform().SetLocalScale({ 23, 30 });
			Renderer->Off();
			vector_Texture_Dungeon_score.push_back(Renderer);
		}

		Hight -= 35.f;
		Len = 60.f;

		{
			//GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>("Combo_num");
			//Renderer->GetTransform().SetLocalPosition({ 0, Hight });
			//Renderer->SetTexture(TextureR_Combo_bonus->GetTexture(5));
			//Renderer->SetPivot(PIVOTMODE::RIGHTTOP);
			//Renderer->ScaleToTexture();
			//Renderer->On();
			//vector_Texture_Combo_num.push_back(Renderer);
		}
		for (size_t i = 1; i < 4; i++)
		{
			GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>("Combo_num");
			Renderer->GetTransform().SetLocalPosition({ -Len, Hight });
			Renderer->GetTransform().SetLocalScale({ 15, 18});
			Renderer->SetPivot(PIVOTMODE::RIGHTTOP);
			Len += 10.f;
			//Renderer->Off();
			vector_Texture_Combo_num.push_back(Renderer);
		}



		//vector_Texture_Combo_num[1]->SetTexture(TextureR_Combo_num->GetTexture(7));
		//vector_Texture_Combo_num[1]->ScaleToTexture();
		//vector_Texture_Combo_num[1]->On();

		//vector_Texture_Combo_num[2]->SetTexture(TextureR_Combo_num->GetTexture(1));
		//vector_Texture_Combo_num[2]->ScaleToTexture();
		//vector_Texture_Combo_num[2]->On();

		Hight -= 9.f;
		for (size_t i = 0; i < 5; i++)
		{
			GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>("Combo_bonus");
			Renderer->SetPivot(PIVOTMODE::RIGHT);
			Renderer->GetTransform().SetLocalPosition({ 0, Hight });
			Renderer->SetTexture(TextureR_Combo_bonus->GetTexture(2));
			Renderer->ScaleToTexture();
			Renderer->Off();
			vector_Texture_Combo_bonus.push_back(Renderer);

			Renderer = CreateComponent<GameEngineUIRenderer>("Aerial");
			Renderer->GetTransform().SetLocalPosition({ 0, Hight });
			Renderer->SetPivot(PIVOTMODE::RIGHT);
			Renderer->SetTexture(TextureR_Combo_bonus->GetTexture(1));
			Renderer->ScaleToTexture();
			Renderer->Off();
			vector_Texture_Combo_Aerial.push_back(Renderer);
			

			GameEngineUIRenderer* Effect = CreateComponent<GameEngineUIRenderer>("Combo_bonus_Effect");
			Effect->GetTransform().SetLocalPosition({ 45, Hight });
			Effect->SetPivot(PIVOTMODE::RIGHT);
			Effect->SetTexture(TextureR_Combo_bonus->GetTexture(0));
			Effect->ScaleToTexture();
			Effect->Off();
			vector_Texture_Combo_Effect.push_back(Effect);

			Hight -= 16.f;
		}


	}

}



void GamePlayComboSystem::Update(float _DeltaTime)
{
	if (ComboDelay > 0)
	{
		ComboDelay -= _DeltaTime;
	}
	else
	{
		ComboStack = 0;
		for (size_t i = 0; i < 4; i++)
		{
			//vector_Texture_Combo_num[i]->Off();
		}
	}

	if (!Queue_ComboClass.empty())
	{
		int UpdateOn = 0;
		for (size_t i = 0; i < 5; i++)
		{
			if (vector_Texture_Combo_bonus[i]->IsUpdate())
			{
				++UpdateOn;
			}
		}

		while (!Queue_ComboClass.empty())
		{
			if (UpdateOn > 4) // 5부터 앞에서 잘라버리기
			{
				if (vector_Texture_Combo_bonus[0]->GetCurTexture() == TextureR_Combo_bonus->GetTexture(5))
				{
					for (size_t i = 1; i < 4; i++)
					{
						vector_Texture_Combo_bonus[i]->SetTexture(vector_Texture_Combo_bonus[i + 1]->GetCurTexture());
					}
				}
				else
				{
					for (size_t i = 0; i < 4; i++)
					{
						vector_Texture_Combo_bonus[i]->SetTexture(vector_Texture_Combo_bonus[i + 1]->GetCurTexture());
					}
				}
				--UpdateOn;
			}
			else
			{
				if (Queue_ComboClass.front() == ComboClass::Combo)
				{
					bool IsCombo = false;
					for (size_t i = 0; i < 5; i++)
					{
						if (vector_Texture_Combo_bonus[i]->GetCurTexture() == TextureR_Combo_bonus->GetTexture(5))
						{
							IsCombo = true;
							Queue_ComboClass.pop();
							break;
						}
					}

					if (IsCombo)
					{
						RenewalCombo();
						continue;
					}
				}
				vector_Texture_Combo_bonus[UpdateOn]->SetTexture(GetComboClass(Queue_ComboClass.front()));
				vector_Texture_Combo_bonus[UpdateOn]->ScaleToTexture();
				vector_Texture_Combo_bonus[UpdateOn]->On();
				SetBrighting(UpdateOn);
				UpdateOn++;
				Queue_ComboClass.pop();

			}
		}


		for (size_t i = 0; i < 5; i++)
		{
			if (vector_Texture_Combo_bonus[i]->GetCurTexture() == TextureR_Combo_bonus->GetTexture(5))
			{
				for (size_t j = 0; j < vector_Texture_Combo_num.size(); j++)
				{
					vector_Texture_Combo_num[j]->GetTransform().SetLocalPosition({ vector_Texture_Combo_num[j]->GetTransform().GetLocalPosition().x, -65.f + (-16.f * i),  vector_Texture_Combo_num[j]->GetTransform().GetLocalPosition().z });
				}
				break;
			}
		}


		BrightIndex = 0;
		Queue_ComboClass = std::queue<ComboClass>();
	}
	else if(BrightIndex < 1)
	{
		BrightIndex -= _DeltaTime;
		for (size_t i = 0; i < 5; i++)
		{
			if (vector_Texture_Combo_Aerial[i]->GetPixelData().MulColor.a > 0)
			{
				vector_Texture_Combo_Aerial[i]->GetPixelData().MulColor.a -= _DeltaTime;
				vector_Texture_Combo_Effect[i]->GetPixelData().MulColor.a -= _DeltaTime;
			}
		}

	}
	
}


void GamePlayComboSystem::SetBrighting(int _Pos)
{
	vector_Texture_Combo_Aerial[_Pos]->GetPixelData().MulColor.a = 1;
	vector_Texture_Combo_Aerial[_Pos]->On();
	vector_Texture_Combo_Effect[_Pos]->GetPixelData().MulColor.a = 1;
	vector_Texture_Combo_Effect[_Pos]->On();
}

void GamePlayComboSystem::PlusScore(unsigned __int64 _Score)
{
	ComboScore += _Score;
	RenewalScore();


	PlusCombo();
}

void GamePlayComboSystem::SetComboClass(ComboClass _Class)
{

	//if (Queue_ComboClass.size() > 4)
	//{
	//	Queue_ComboClass.pop();
	//}
	Queue_ComboClass.push(_Class);
}

void GamePlayComboSystem::PlusCombo()
{
	ComboDelay = 2.0f;
	++ComboStack;
	if (ComboStack > 999)
	{
		ComboStack = 999;
	}
	RenewalCombo();

}

void GamePlayComboSystem::RenewalCombo()
{
	for (auto& bonus : vector_Texture_Combo_bonus)
	{
		if (bonus->GetCurTexture() == TextureR_Combo_bonus->GetTexture(5))
		{
			std::string Index = std::to_string(ComboStack);
			for (size_t i = 0; i < 3; i++)
			{
				if (Index.empty())
				{
					vector_Texture_Combo_num[i]->Off();
					continue;
				}
				vector_Texture_Combo_num[i]->SetTexture(TextureR_Combo_num->GetTexture(static_cast<int>(Index.back()) - 48));
				vector_Texture_Combo_num[i]->On();

				Index.pop_back();
			}
			return;
		}
	}

	if (ComboStack > 1)
	{
		SetComboClass(ComboClass::Combo);
	}



	
}

void GamePlayComboSystem::RenewalScore()
{
	unsigned __int64 Score = ComboScore;
	if (Score > 9999999)
	{
		Score = 9999999;
	}
	std::string Combo = std::to_string(Score);
	int i = 0;
	while (Combo.size() != 0)
	{
		vector_Texture_Dungeon_score[i]->SetTexture(TextureR_Dungeon_score->GetTexture(static_cast<int>(Combo.back()) - 48));
		vector_Texture_Dungeon_score[i]->ScaleToTexture();
		vector_Texture_Dungeon_score[i]->On();
		Combo.pop_back();
		++i;
		if (i >= 7)
		{
			break;
		}
	}

	RenewalRank(Score);


}

void GamePlayComboSystem::RenewalRank(unsigned __int64 _Score)
{
	if (_Score > 5000000)
	{

		//SSS
	}  
	else if (_Score > 2500000)
	{
		//SS
	}
	else if (_Score > 1000000)
	{
		//S
	}
	else if (_Score > 500000)
	{
		//A
	}
	else if (_Score > 250000)
	{
		//B
	}
	else if (_Score > 100000)
	{
		//C
	}
	else if (_Score > 50000)
	{
		//D
	}
	else if (_Score > 10000)
	{
		//E
	}
	else if (_Score > 1000)
	{
		//F
	}
	
}

void GamePlayComboSystem::LevelStartEvent()
{

	if (GamePlayComboSystem::Before != nullptr)
	{
		ComboStack = Before->ComboStack;
		ComboScore = Before->ComboScore;
	}
	ComboDelay = 1.f;
	BrightIndex = 0;
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