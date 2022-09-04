#pragma once
#include "GamePlayDataBase.h"
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
struct BlankInventory
{
	BlankInventory()
		: Collision_Blank(nullptr)
		, Texture_Blank(nullptr)
	{

	}
	//BlankInventory(GameEngineCollision* _Collision, GameEngineUIRenderer* _Renderer)
	//	: Collision_Blank(_Collision), Texture_Blank(_Renderer)
	//{
	//}

	GameEngineCollision* Collision_Blank;
	GameEngineUIRenderer* Texture_Blank;
};
class GamePlayItem;
class GameEngineUIRenderer;
class GameEngineCollision;
class MouseCursorComponent;
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


	bool IsItemDrag(GameEngineCollision* _This, GameEngineCollision* _Other);
	bool CheckBlankCollision(GameEngineCollision* _This, GameEngineCollision* _Other);

protected:
	//void Update(float _DeltaTime) override;


	void Update(float _DeltaTime) override;

	GameEngineUIRenderer* Texture_Inventory;

	GameEngineCollision* Collision_WindowInventory;

	std::map<unsigned int, GamePlayItem*> Inventory_CurrentItem;
	std::map<unsigned int, BlankInventory> Inventory_Blank;
	//std::map<float4, >
	void SetLevelStartItem(std::vector<InventoryData*>& Inventory);
	MouseCursorComponent* Component_MouseCursorComponent;

	bool DragMode;
	int Item_DragDataIndex;
	GamePlayItem* Item_DragData;
private:
};

