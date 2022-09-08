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
	void OffEvent() override;


	void LevelStartEvent() override;
	void LevelEndEvent() override;

	GameEngineUIRenderer* Texture_Inventory;

	GameEngineCollision* Collision_WindowInventory;

	std::map<GamePlayItem*, InventoryData*> Inventory_CurrentData;
	std::map<unsigned int, GamePlayItem*> Inventory_CurrentItem;
	std::map<unsigned int, BlankInventory> Inventory_Blank;
	//std::map<float4, >

	inline unsigned int FindGamePlayItem(GamePlayItem* _Item) const
	{
		for (auto& Map : Inventory_CurrentItem)
		{
			if (Map.second == _Item)
			{
				return Map.first;
			}
		}
		return -1;
	}


	template<typename ItemType>
	void SetLevelStartItem(std::vector<InventoryData*>& Inventory)
	{
		for (int i = 0; i < Inventory.size(); i++)
		{
			//
			if (Inventory[i] == nullptr)
			{
				continue;
			}

			ItemType* Item = CreateComponent<ItemType>("GamePlayItem");
			Item->SetDESC(Inventory[i]->Item_DESC);
			Item->SetTransform(Inventory_Blank[i].Texture_Blank);
			Inventory_CurrentData[Item] = Inventory[i];
			Inventory_CurrentItem[i] = Item;
		}
	}


	



	MouseCursorComponent* Component_MouseCursorComponent;

	bool DragMode;
	int Item_DragDataIndex;
	GamePlayItem* Item_DragData;


	void MoveItem(unsigned int _Pos, InventoryData* _Item, InventoryBag _Bag);
	unsigned int MoveItemToInventory(unsigned int _Pos, InventoryData* _Item, InventoryBag _ToBag, InventoryBag _FromBag);
private:


	virtual void MoveInventory(unsigned int _Pos, InventoryData* _Item) = 0;

	virtual void Mouse_RClick(GamePlayItem* _Item) {}


};

