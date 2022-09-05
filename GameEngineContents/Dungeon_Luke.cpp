#include "PreCompile.h"
#include "Dungeon_Luke.h"
#include "GamePlayMonsterHPBar.h"

Luke_Stage Dungeon_Luke::CurrentStage = Luke_Stage::None;
Dungeon_Luke::Dungeon_Luke() 
	: Actor_MonsterHP(CreateActor<GamePlayMonsterHPBar>())
{
}

Dungeon_Luke::~Dungeon_Luke() 
{
}

