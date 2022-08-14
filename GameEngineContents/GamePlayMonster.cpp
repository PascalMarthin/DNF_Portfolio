#include "PreCompile.h"
#include "GamePlayMonster.h"

GamePlayMonster::GamePlayMonster() 
	: Collision_HitBody(nullptr)
	, Texture_Monster(nullptr)
{
}

GamePlayMonster::~GamePlayMonster() 
{
}

void GamePlayMonster::OnEvent()
{
	GetTransform().SetLocalMove({ 0 , 0 , GetTransform().GetLocalPosition().y });
}