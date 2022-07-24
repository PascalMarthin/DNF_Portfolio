#pragma once
#include <map>
#include <list>
#include <vector>
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include "ItemBagInventory.h"

// ���� :
class ItemInventory : public ItemBagInventory
{
public:
	// constrcuter destructer
	ItemInventory();
	~ItemInventory();


	// delete Function
	ItemInventory(const ItemInventory& _Other) = delete;
	ItemInventory(ItemInventory&& _Other) noexcept = delete;
	ItemInventory& operator=(const ItemInventory& _Other) = delete;
	ItemInventory& operator=(ItemInventory&& _Other) noexcept = delete;



public:
	// ���ٴ� ������ �ݴ� �Լ�
	// ��ĭ�� ä���ش�
	// �������� ��� �������� ���δ�




protected:

	void Update(float _DeltaTime) override;

	void OnEvent() override {} // ���� ���

	void OffEvent() override {} // ���� ���

	void Start() override;

	void End() override;

private:
	bool PushItembyDrag(GamePlayItem* _Item, GamePlayItemBag* _From) override;

	std::list<std::vector<>>

};

