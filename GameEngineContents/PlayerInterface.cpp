#include "PreCompile.h"
#include <GameEngineCore/GameEngineActor.h>
#include "PlayerInterface.h"
#include "InterfaceHUD.h"
#include "InterfaceItemBag.h"
#include "GamePlayKeyManager.h"

PlayerInterface::PlayerInterface() 
	: PlayerHUD(nullptr)
	, PlayerItemBag(nullptr)
	, KeyManager(nullptr)
{
}

PlayerInterface::~PlayerInterface() 
{
}

void PlayerInterface::Start()
{

	KeyManager = CreateComponent<GamePlayKeyManager>();


	PlayerHUD = GetLevel()->CreateActor<InterfaceHUD>();
	PlayerItemBag = GetLevel()->CreateActor<InterfaceItemBag>();


}

void PlayerInterface::Update(float _DeltaTime)
{

}