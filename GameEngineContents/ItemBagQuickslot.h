#pragma once
#include "GamePlayItemBag.h"

// Ό³Έν :
class ItemBagQuickslot : public GamePlayItemBag
{
public:
	// constrcuter destructer
	ItemBagQuickslot(GamePlayCharacter* _Owner);
	~ItemBagQuickslot();

	// delete Function
	ItemBagQuickslot(const ItemBagQuickslot& _Other) = delete;
	ItemBagQuickslot(ItemBagQuickslot&& _Other) noexcept = delete;
	ItemBagQuickslot& operator=(const ItemBagQuickslot& _Other) = delete;
	ItemBagQuickslot& operator=(ItemBagQuickslot&& _Other) noexcept = delete;

protected:

	void Update(float _DeltaTime) override;

	void OnEvent() override;

	void OffEvent() override;

	void Start() override;

	void End() override;

private:

	bool PushItembyDrag(GamePlayItem* _Item, GamePlayItemBag* _From) override;

};

