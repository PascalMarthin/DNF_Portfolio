#include "PreCompile.h"
#include <GameEngineCore/GameEngineActor.h>
#include "PlayerInterface.h"
#include "InterfaceHUD.h"

PlayerInterface::PlayerInterface() 
	: PlayerHUD(nullptr)
{
}

PlayerInterface::~PlayerInterface() 
{
}

void PlayerInterface::Start()
{
	PlayerHUD = GetLevel()->CreateActor<InterfaceHUD>();

}

void PlayerInterface::Update(float _DeltaTime)
{

}