#pragma once
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include "GamePlayItemBag.h"

// Ό³Έν :
class ItemBagInventory : public GamePlayItemBag
{
public:
	// constrcuter destructer
	~ItemBagInventory();

	// delete Function
	ItemBagInventory(const ItemBagInventory& _Other) = delete;
	ItemBagInventory(ItemBagInventory&& _Other) noexcept = delete;
	ItemBagInventory& operator=(const ItemBagInventory& _Other) = delete;
	ItemBagInventory& operator=(ItemBagInventory&& _Other) noexcept = delete;

protected:
	ItemBagInventory();

	GameEngineTextureRenderer* Inventory_Window;

	std::map<std::string, std::vector<GameEngineTextureRenderer*>> ItemBlankRenderer;

	void Start() override;
	void Update(float _DeltaTime) override;
private:


};

