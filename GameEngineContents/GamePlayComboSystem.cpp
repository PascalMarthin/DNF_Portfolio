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

GameEngineSoundPlayer GamePlayComboSystem::ScoreSound;

GamePlayComboSystem* GamePlayComboSystem::Before = nullptr;
GamePlayComboSystem* GamePlayComboSystem::Inst = nullptr;
GamePlayComboSystem::GamePlayComboSystem()
	: ComboScore(0)
	, ComboStack(0)
	, PushBack(false)
	, Actor_ComboSystemScore(nullptr)
	, DoEffect(false)
	, DoEffectDelay(0)
	, UsingCoin(0)
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



	{
		Texture_Dungeon_KillDraw = CreateComponent<GameEngineUIRenderer>();


		Texture_Dungeon_Kill =CreateComponent<GameEngineUIRenderer>();
		Texture_Dungeon_Kill->GetTransform().SetLocalPosition({ -130, 10 });
		Texture_Dungeon_Kill->Off();




		Texture_Dungeon_KillEffect = CreateComponent<GameEngineUIRenderer>();
		Texture_Dungeon_KillEffect->GetTransform().SetLocalPosition({ -130, 10 });
		Texture_Dungeon_KillEffect->Off();



		Texture_Dungeon_KillDraw->GetTransform().SetLocalPosition({ -130, 10 });
		Texture_Dungeon_KillDraw->CreateFrameAnimationFolder("monsterkill_grade", FrameAnimation_DESC("monsterkill_grade", 6, 8 ,0.25f, false));
		Texture_Dungeon_KillDraw->ChangeFrameAnimation("monsterkill_grade");

		std::vector<unsigned int> A = { 8, 7, 6 };
		Texture_Dungeon_KillDraw->CreateFrameAnimationFolder("monsterkill_grade_Off", FrameAnimation_DESC("monsterkill_grade", A, 0.25f, false));
		Texture_Dungeon_KillDraw->AnimationBindEnd("monsterkill_grade_Off", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->Off();
			}
		);


		Texture_Dungeon_KillDraw->ScaleToTexture();
		Texture_Dungeon_KillDraw->Off();

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
				if (vector_ComboBlank[0]->CurrentClass == ComboClass::Combo || vector_ComboBlank[0]->CurrentClass == ComboClass::Kill)
				{
					if (vector_ComboBlank[1]->CurrentClass == ComboClass::Combo || vector_ComboBlank[1]->CurrentClass == ComboClass::Kill)
					{
						for (size_t i = 2; i < 4; i++)
						{
							ChangeBlank(vector_ComboBlank[i], vector_ComboBlank[i + 1]);
							--UpdateOn;
						}
					}
					else
					{
						for (size_t i = 1; i < 4; i++)
						{
							ChangeBlank(vector_ComboBlank[i], vector_ComboBlank[i + 1]);
							--UpdateOn;
						}
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
				else if (Queue_ComboClass.front() == ComboClass::Kill)
				{
					bool ComboIsit = false;
					for (size_t i = 0; i < 5; i++)
					{
						if (vector_ComboBlank[i]->CurrentClass == ComboClass::Kill)
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

		SoundDelay = 0;

	}

	if (Texture_Dungeon_Kill->GetAccTime() > 3.f)
	{
		Texture_Dungeon_KillDraw->ChangeFrameAnimation("monsterkill_grade_Off");
		Texture_Dungeon_Kill->ReSetAccTime();
		Texture_Dungeon_Kill->Off();
	}
	


	if (KillDelay > 0)
	{
		KillDelay -= _DeltaTime;
		if (KillDelay <= 0)
		{
			KillEffect();
			KillDelay = 0;
		}
	
	}
	else if (DoEffect == true)
	{

		DoEffectDelay -= _DeltaTime * 3.f;
		if (KillFlash)
		{
			if (DoEffectDelay > 0)
			{
				Texture_Dungeon_KillEffect->On();
				Texture_Dungeon_KillEffect->SetScaleRatio(DoEffectDelay + 1.8f * (1.f - DoEffectDelay));
				Texture_Dungeon_KillEffect->GetPixelData().MulColor.a = DoEffectDelay;
				Texture_Dungeon_KillEffect->ScaleToTexture();
			}
			else
			{
				KillFlash = false;
				DoEffect = false;
				Texture_Dungeon_KillEffect->Off();
			}
		}


		if (DoEffectDelay > 0 && KillFlash == false)
		{
			Texture_Dungeon_Kill->GetPixelData().PlusColor = { DoEffectDelay ,DoEffectDelay ,DoEffectDelay ,DoEffectDelay };
			Texture_Dungeon_Kill->SetScaleRatio(1.5f * DoEffectDelay + (1.f - DoEffectDelay));
			Texture_Dungeon_Kill->ScaleToTexture();
		}
		else if(KillFlash == false)
		{
			Texture_Dungeon_Kill->GetPixelData().PlusColor = float4::ZERO;
			Texture_Dungeon_Kill->SetScaleRatio(1.f);
			Texture_Dungeon_Kill->ScaleToTexture();
			KillFlash = true;
			DoEffectDelay = 1.f;
		}

	}






	if (SoundDelay > 0.25f)
	{
		for (size_t i = 0; i < 5; i++)
		{
			if (vector_ComboBlank[i]->IsUpdate())
			{
				ComboScore_PlaySound(vector_ComboBlank[i]->CurrentClass);
			}
		}
		
		SoundDelay = -1.f;
	}
	else if (SoundDelay >= 0)
	{
		SoundDelay += _DeltaTime;
	}
}

void GamePlayComboSystem::KillEffect()
{
	DoEffect = true;
	DoEffectDelay = 1.f;
	KillFlash = false;
	ScoreSound.Stop();


	if (KillStuck == -1)
	{
		//마무리 퍼펙트
		Texture_Dungeon_Kill->SetTexture(TextureR_Monsterkill_grade->GetTexture(4));
		
		Texture_Dungeon_KillEffect->SetTexture(TextureR_Monsterkill_grade->GetTexture(4));

		ScoreSound = GameEngineSound::SoundPlayControl("hk3_perfect.ogg");
	}
	else if (KillStuck == 1)
	{
		Texture_Dungeon_Kill->SetTexture(TextureR_Monsterkill_grade->GetTexture(0));

		Texture_Dungeon_KillEffect->SetTexture(TextureR_Monsterkill_grade->GetTexture(0));

		ScoreSound = GameEngineSound::SoundPlayControl("hk3_good.ogg");
	}
	else if (KillStuck == 2)
	{
		Texture_Dungeon_Kill->SetTexture(TextureR_Monsterkill_grade->GetTexture(1));

		Texture_Dungeon_KillEffect->SetTexture(TextureR_Monsterkill_grade->GetTexture(1));


		ScoreSound = GameEngineSound::SoundPlayControl("hk3_nice.ogg");

	}
	else if (KillStuck == 3)
	{
		Texture_Dungeon_Kill->SetTexture(TextureR_Monsterkill_grade->GetTexture(2));

		Texture_Dungeon_KillEffect->SetTexture(TextureR_Monsterkill_grade->GetTexture(2));

		ScoreSound = GameEngineSound::SoundPlayControl("hk3_great.ogg");

	}
	else if (KillStuck == 4)
	{
		Texture_Dungeon_Kill->SetTexture(TextureR_Monsterkill_grade->GetTexture(3));

		Texture_Dungeon_KillEffect->SetTexture(TextureR_Monsterkill_grade->GetTexture(3));

		ScoreSound = GameEngineSound::SoundPlayControl("hk3_excellent.ogg");
	}
	else if (KillStuck == 5)
	{
		Texture_Dungeon_Kill->SetTexture(TextureR_Monsterkill_grade->GetTexture(4));

		Texture_Dungeon_KillEffect->SetTexture(TextureR_Monsterkill_grade->GetTexture(4));

	}

	Texture_Dungeon_Kill->GetPixelData().PlusColor = { 1,1,1,1 };
	Texture_Dungeon_Kill->SetScaleRatio(1.5f);
	Texture_Dungeon_Kill->ScaleToTexture();
	Texture_Dungeon_Kill->On();
	Texture_Dungeon_Kill->ReSetAccTime();
	Texture_Dungeon_KillEffect->SetScaleRatio(1.f);
	Texture_Dungeon_KillEffect->ScaleToTexture();
	Texture_Dungeon_KillEffect->GetPixelData().MulColor.a = 1.f;
	Texture_Dungeon_KillEffect->Off();




	Texture_Dungeon_KillDraw->ChangeFrameAnimation("monsterkill_grade", true);
	Texture_Dungeon_KillDraw->ScaleToTexture();
	Texture_Dungeon_KillDraw->On();


	ScoreSound.Volume(0.8f);
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


void GamePlayComboSystem::ComboScore_PlaySound(ComboClass _Class)
{
	if (_Class == ComboClass::Combo)
	{
		return;
	}

	ScoreSound.Stop();
	switch (_Class)
	{
	case ComboClass::Aerial:
		ScoreSound = GameEngineSound::SoundPlayControl("hk3_aerial.ogg", 1);
		break;
	case ComboClass::CounterHold:
		ScoreSound = GameEngineSound::SoundPlayControl("hk3_shold.ogg", 1);
		break;
	case ComboClass::GhostFrame:
		ScoreSound = GameEngineSound::SoundPlayControl("hk3_gframe.ogg", 1);
		break;
	case ComboClass::NearMiss:
		ScoreSound = GameEngineSound::SoundPlayControl("hk3_nmiss.ogg", 1);
		break;
	case ComboClass::BackAttack:
		ScoreSound = GameEngineSound::SoundPlayControl("hk3_batk.ogg", 1);
		break;
	case ComboClass::Critical:
		//ScoreSound = GameEngineSound::SoundPlayControl("hk3_excellent.ogg", 1);
		break;
	case ComboClass::Counter:
		ScoreSound = GameEngineSound::SoundPlayControl("hk3_counter.ogg", 1);
		break;
	case ComboClass::LastKill:
		ScoreSound = GameEngineSound::SoundPlayControl("hk3_okill.ogg", 1);
		break;
	case ComboClass::Kill:
		break;
	default:
		break;
	}
	ScoreSound.Volume(0.8f);
}


void GamePlayComboSystem::PlusScore(unsigned __int64 _Score)
{
	ComboScore += _Score;
	Actor_ComboSystemScore->RenewalScore(ComboScore);

	PlusCombo();
}

void GamePlayComboSystem::SetComboClass(ComboClass _Class)
{
	if (_Class == ComboClass::BeHit || _Class == ComboClass::MultiHit)
	{
		map_ComboStuck[_Class] += 1;
		return;
	}
	if (_Class == ComboClass::NearMiss)
	{
		GamePlayComboSystem::GetInst()->PlusScore(10500);
	}


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
	else if (_Class == ComboClass::Kill)
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

void GamePlayComboSystem::SetKill()
{
	++KillStuck;
	KillDelay = 1.f;
}


void GamePlayComboSystem::SetKillLast()
{
	KillStuck = -1;
	KillDelay = 1.f;

}
void GamePlayComboSystem::ComboTimeEnd()
{
	MaxComboStack = (MaxComboStack > ComboStack ? MaxComboStack : ComboStack);
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
		map_ComboStuck = GamePlayComboSystem::Before->map_ComboStuck;
		MaxComboStack = GamePlayComboSystem::Before->MaxComboStack;
		UsingCoin = GamePlayComboSystem::Before->UsingCoin;
	}
	Queue_ComboClass = std::queue<ComboClass>();


	GamePlayComboSystem::Inst = this;
	GamePlayComboSystem::Before = nullptr;
	ScoreSound.Stop();
	KillStuck = 0;
	KillDelay = 0;
	DoEffect = false;
	DoEffectDelay = 0;
	KillFlash = false;
}

void GamePlayComboSystem::LevelEndEvent()
{
	GamePlayComboSystem::Before = this;
	GamePlayComboSystem::Inst = nullptr;
	Queue_ComboClass = std::queue<ComboClass>();
	KillStuck = 0;
	KillDelay = 0;
	KillFlash = false;
}