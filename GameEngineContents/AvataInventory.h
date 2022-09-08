#pragma once
#include "GamePlayInventory.h"

// Ό³Έν :
class Item_Avata;
class AvataInventory : public GamePlayInventory
{
public:
	// constrcuter destructer
	AvataInventory();
	~AvataInventory();

	// delete Function
	AvataInventory(const AvataInventory& _Other) = delete;
	AvataInventory(AvataInventory&& _Other) noexcept = delete;
	AvataInventory& operator=(const AvataInventory& _Other) = delete;
	AvataInventory& operator=(AvataInventory&& _Other) noexcept = delete;


	void Mouse_RClick(GamePlayItem* _Item) override;
protected:
	void Start() override;
	//void Update(float _DeltaTime) override;

	// void End() override {}
	void OnEvent() override;
	// void OffEvent() override {}

	void LevelStartEvent() override;
	//void LevelEndEvent() override;
private:
	std::map<AllAvataClass, GameEngineCollision*> All_WearAvata_Type;
	std::map<GameEngineCollision*, InventoryData*> All_WearAvata_Texture;

	inline void MoveInventory(unsigned int _Pos, InventoryData* _Item) override
	{
		MoveItem(_Pos, _Item, InventoryBag::Inventory_Avata);
	}

};

