#pragma once
#include <map>
#include <list>
#include <vector>
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include "ItemBagInventory.h"

// 설명 :
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
	// 땅바닥 아이템 줍는 함수
	// 빈칸에 채워준다
	// 스택형인 경우 차곡차곡 쌓인다




protected:

	void Update(float _DeltaTime) override;

	void OnEvent() override {} // 사운드 재생

	void OffEvent() override {} // 사운드 재생

	void Start() override;

	void End() override;

private:
	bool PushItembyDrag(GamePlayItem* _Item, GamePlayItemBag* _From) override;

	std::list<std::vector<>>

};

