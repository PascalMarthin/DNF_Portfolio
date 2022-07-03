#pragma once
#include "ItemBagInventory.h"

// Ό³Έν :
class AvatarInventory : public ItemBagInventory
{
public:
	// constrcuter destructer
	AvatarInventory(GamePlayCharacter* _Owner);
	~AvatarInventory();

	// delete Function
	AvatarInventory(const AvatarInventory& _Other) = delete;
	AvatarInventory(AvatarInventory&& _Other) noexcept = delete;
	AvatarInventory& operator=(const AvatarInventory& _Other) = delete;
	AvatarInventory& operator=(AvatarInventory&& _Other) noexcept = delete;

protected:

	void Update(float _DeltaTime) override;

	void OnEvent() override;

	void OffEvent() override;

	void Start() override;

	void End() override;

private:

	bool PushItembyDrag(GamePlayItem* _Item, GamePlayItemBag* _From) override;

};

