#include "PreCompile.h"
#include "GamePlayMonster.h"
#include "CharacterStatManager.h"

GamePlayMonster::GamePlayMonster() 
	: Collision_HitBody(nullptr)
	, Texture_Monster(nullptr)
	, GoingDownTime(0.f)
{
}

GamePlayMonster::~GamePlayMonster() 
{
}


void GamePlayMonster::Start()
{
	GamePlayObject::Start();
	Manager_StatManager = CreateComponent<CharacterStatManager>();
}

void GamePlayMonster::CreateMonsterStat(unsigned int _MAXHP, float Def)
{
	MonsterAbilityStat.MAXHP = _MAXHP;
	MonsterAbilityStat.HP = _MAXHP;
	MonsterAbilityStat.Def = Def;
}

void GamePlayMonster::Jump_GoingDown()
{
	if (JumpGoingDown == false && Manager_StatManager->IsAerial())
	{
		JumpGoingDown = true;
	}
}

void GamePlayMonster::LevelStartEvent()
{
	GetTransform().SetLocalMove({ 0 , 0 , GetTransform().GetLocalPosition().y });
}

