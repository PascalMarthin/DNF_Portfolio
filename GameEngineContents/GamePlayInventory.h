#pragma once
#include "GamePlayDataBase.h"
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
struct BlankInventory
{
	//BlankInventory(GameEngineCollision* _Collision, GameEngineUIRenderer* _Renderer)
	//	: Collision_Blank(_Collision), Texture_Blank(_Renderer)
	//{
	//}

	GameEngineCollision* Collision_Blank;
	GameEngineUIRenderer* Texture_Blank;
};
class GameEngineUIRenderer;
class GameEngineCollision;
class GamePlayInventory : public GameEngineActor
{
public:
	// constrcuter destructer
	GamePlayInventory();
	~GamePlayInventory();

	// delete Function
	GamePlayInventory(const GamePlayInventory& _Other) = delete;
	GamePlayInventory(GamePlayInventory&& _Other) noexcept = delete;
	GamePlayInventory& operator=(const GamePlayInventory& _Other) = delete;
	GamePlayInventory& operator=(GamePlayInventory&& _Other) noexcept = delete;

protected:
	GameEngineUIRenderer* Texture_Inventory;

	GameEngineCollision* Collision_WindowInventory;

	std::map<float4, BlankInventory> Inventory_CurrentItem;
	std::map<float4, BlankInventory> Inventory_Blank;
	//std::map<float4, >
	void SetLevelStartItem(std::vector<InventoryData*>& Inventory);

private:
};

