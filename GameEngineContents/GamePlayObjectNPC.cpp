#include "PreCompile.h"
#include "GamePlayObjectNPC.h"
#include "GamePlayEnum.h"

GamePlayObjectNPC::GamePlayObjectNPC() 
{
}

GamePlayObjectNPC::~GamePlayObjectNPC() 
{
}

void GamePlayObjectNPC::Start()
{
	GetTransform().SetLocalScale({MonitorX, MonitorY });
}