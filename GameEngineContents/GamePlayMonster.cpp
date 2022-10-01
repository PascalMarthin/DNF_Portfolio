#include "PreCompile.h"
#include "GamePlayMonster.h"
#include "CharacterStatManager.h"
#include "GamePlayMonsterHPBar.h"

GamePlayMonster::GamePlayMonster() 
	: Collision_HitBody_Top(nullptr)
	, Collision_HitBody_Mid(nullptr)
	, Collision_HitBody_Bottom(nullptr)
	, Texture_Monster(nullptr)
	, GoingDownTime(0.f)
	, MonsterAbilityStat()
	, Monster_Class(MonsterClass::None)
	, Actor_Dummy(nullptr)
{
}

GamePlayMonster::~GamePlayMonster() 
{
}


void GamePlayMonster::Start()
{
	GamePlayObject::Start();
	Actor_Dummy = GetLevel()->CreateActor<GameEngineActor>();

	Manager_StatManager = CreateComponent<CharacterStatManager>();

	//Manager_StatManager->GetFSMManager().CreateStateMember
	//("Dead", std::bind(&GamePlayMonster::FSM_Dead_Update, this, std::placeholders::_1, std::placeholders::_2)
	//	, std::bind(&GamePlayMonster::FSM_Dead_Start, this, std::placeholders::_1)
	//	, std::bind(&GamePlayMonster::FSM_Dead_End, this, std::placeholders::_1));

}

void GamePlayMonster::CreateMonsterStat(unsigned int _MAXHP, float Def, float _HPLine)
{
	MonsterAbilityStat.MAXHP = _MAXHP;
	MonsterAbilityStat.HP = _MAXHP;
	MonsterAbilityStat.Def = Def;
	if (_HPLine == -1.f)
	{
		MonsterAbilityStat.MAXHPLine = static_cast<float>(_MAXHP) / 3500000.f;
	}
	MonsterAbilityStat.MAXHPLine = _HPLine;
}

void GamePlayMonster::Jump_GoingDown()
{
	if (JumpGoingDown == false && Manager_StatManager->IsAerial())
	{
		JumpGoingDown = true;
	}
}

unsigned int GamePlayMonster::SetHPFromHit(unsigned int _Damage)
{
	GamePlayMonsterHPBar::SetMonster(this);
	
	if (MonsterAbilityStat.Def > 1000.f)
	{
		MonsterAbilityStat.Def = 1000.f;
	}
	unsigned int Damage = _Damage - static_cast<unsigned int>((255.f * MonsterAbilityStat.Def) * 0.8f);

	if (MonsterAbilityStat.HP < Damage)
	{
		Dead();
		GamePlayMonsterHPBar::SetHitDamage(MonsterAbilityStat.HP);
		MonsterAbilityStat.HP = 0;
	}
	else
	{
		MonsterAbilityStat.HP -= Damage;
		GamePlayMonsterHPBar::SetHitDamage(MonsterAbilityStat.HP);
	}

	return Damage;
}

void GamePlayMonster::Dead()
{
	GetStatManager()->SetDead();
	Texture_Monster->GetPixelData().MulColor = float4::ZERO;
	Texture_Monster->GetPixelData().PlusColor = float4::WHITE;
	Texture_Monster->CurAnimationPauseOn();

	DeadDelay = 0.375f;
}
//
//void GamePlayMonster::FSM_Dead_Start(const StateInfo& _Info)
//{
//
//}
//void GamePlayMonster::FSM_Dead_Update(float _DeltaTime, const StateInfo& _Info)
//{
//
//}
//void GamePlayMonster::FSM_Dead_End(const StateInfo& _Info)
//{
//
//}


void GamePlayMonster::Update(float _Delta)
{
	if (!Manager_StatManager->IsLive())
	{
		DeadDelay -= _Delta;
		if (DeadDelay < 0)
		{
			int a = GameEngineRandom::MainRandom.RandomInt(-10, 3);
			if (a == 0)
			{
				GameEngineTextureRenderer* Renderer = Actor_Dummy->CreateComponent<GameEngineTextureRenderer>();
				Renderer->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
				Renderer->CreateFrameAnimationFolder("Stone", FrameAnimation_DESC("Stone015", 0.125f, false));
				Renderer->ChangeFrameAnimation("Stone");
				Renderer->AnimationBindEnd("Stone", [](const FrameAnimation_DESC& _DESC)
					{
						_DESC.Renderer->Death();
					});
				Renderer->ScaleToTexture();
			}
			else if (a == 1)
			{
				GameEngineTextureRenderer* Renderer = Actor_Dummy->CreateComponent<GameEngineTextureRenderer>();
				Renderer->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
				Renderer->CreateFrameAnimationFolder("Stone", FrameAnimation_DESC("Stone024", 0.125f, false));
				Renderer->ChangeFrameAnimation("Stone");
				Renderer->AnimationBindEnd("Stone", [](const FrameAnimation_DESC& _DESC)
					{
						_DESC.Renderer->Death();
					});
				Renderer->ScaleToTexture();
			}
			Off();
		}
	}
	
	//Actor_TrackingObject->GetTransform().SetLocalPosition(GetTransform().GetWorldPosition());
	for (auto& Time : All_CollTime)
	{
		if (Time.second > 0)
		{
			Time.second -= _Delta;
		}	
	}


}


void GamePlayMonster::LevelStartEvent()
{
//	GetTransform().SetLocalMove({ 0 , 0 , GetTransform().GetLocalPosition().y });
}

