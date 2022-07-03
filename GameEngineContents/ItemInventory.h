#pragma once
#include <map>
#include <list>
#include "ItemBagInventory.h"

// ���� :
class ItemInventory : public ItemBagInventory
{
public:
	// constrcuter destructer
	ItemInventory(GamePlayCharacter* _Owner);
	~ItemInventory();


	// delete Function
	ItemInventory(const ItemInventory& _Other) = delete;
	ItemInventory(ItemInventory&& _Other) noexcept = delete;
	ItemInventory& operator=(const ItemInventory& _Other) = delete;
	ItemInventory& operator=(ItemInventory&& _Other) noexcept = delete;



public:
	bool PushItembyLoot(GamePlayItem* _Item);
	// ���ٴ� ������ �ݴ� �Լ�
	// ��ĭ�� ä���ش�
	// �������� ��� �������� ���δ�




protected:

	void Update(float _DeltaTime) override;

	void OnEvent() override;

	void OffEvent() override;

	void Start() override;

	void End() override;

private:
	bool PushItembyDrag(GamePlayItem* _Item, GamePlayItemBag* _From) override;

};

