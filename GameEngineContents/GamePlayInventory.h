#pragma once
#include "GamePlayDataBase.h"
#include <GameEngineCore/GameEngineActor.h>

// ���� :
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
	friend class GamePlayDataBase;
public:
	// constrcuter destructer
	GamePlayInventory();
	~GamePlayInventory();

	// delete Function
	GamePlayInventory(const GamePlayInventory& _Other) = delete;
	GamePlayInventory(GamePlayInventory&& _Other) noexcept = delete;
	GamePlayInventory& operator=(const GamePlayInventory& _Other) = delete;
	GamePlayInventory& operator=(GamePlayInventory&& _Other) noexcept = delete;


	CollisionReturn IsItemDrag(GameEngineCollision* _This, GameEngineCollision* _Other);
	CollisionReturn CheckBlankCollision(GameEngineCollision* _This, GameEngineCollision* _Other);

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
	void SetLevelStartItem(std::vector<InventoryData*>& _Inventory)
	{
		for (auto& Blank : Inventory_CurrentItem)
		{
			if (Blank.second != nullptr)
			{
				Blank.second->Death();
				Blank.second = nullptr;
			}
		}
		Inventory_CurrentItem.clear();
		Inventory_CurrentData.clear();

		for (int i = 0; i < _Inventory.size(); i++)
		{
			//
			if (_Inventory[i] == nullptr)
			{
				continue;
			}

			ItemType* Item = CreateComponent<ItemType>("GamePlayItem");
			Item->SetDESC(_Inventory[i]->Item_DESC);
			Item->SetUITextureTransform(Inventory_Blank[i].Collision_Blank);
			Inventory_CurrentData[Item] = _Inventory[i];
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

