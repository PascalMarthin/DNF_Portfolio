#include "PreCompile.h"
#include <GameEngineCore/GameEngineActor.h>
#include "PlayerInterface.h"
#include "InterfaceHUD.h"
#include "InterfaceItemBag.h"

PlayerInterface::PlayerInterface() 
	: PlayerHUD(nullptr)
	, PlayerItemBag(nullptr)
{
}

PlayerInterface::~PlayerInterface() 
{
}

void PlayerInterface::Start()
{
	PlayerHUD = GetLevel()->CreateActor<InterfaceHUD>();
	PlayerItemBag = GetLevel()->CreateActor<InterfaceItemBag>();
}

void PlayerInterface::Update(float _DeltaTime)
{

}