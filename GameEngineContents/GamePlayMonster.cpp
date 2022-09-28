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
		GamePlayMonsterHPBar::SetHitDamage(0);
	}
	else
	{
		MonsterAbilityStat.HP -= Damage;
		GamePlayMonsterHPBar::SetHitDamage(MonsterAbilityStat.HP);
	}

	return Damage;
}


void GamePlayMonster::Update(float _Delta)
{
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

