#pragma once
#include <GameEngineCore/GameEngineActor.h>
// Ό³Έν :
class ItemBagEquipmentWindow;
class ItemBagInventory;
class ItemBagQuickslot;
class ItemInventory;
class AvatarInventory;
class PetInventory;
class InterfaceItemBag : public GameEngineActor
{
public:
	// constrcuter destructer
	InterfaceItemBag();
	~InterfaceItemBag();

	// delete Function
	InterfaceItemBag(const InterfaceItemBag& _Other) = delete;
	InterfaceItemBag(InterfaceItemBag&& _Other) noexcept = delete;
	InterfaceItemBag& operator=(const InterfaceItemBag& _Other) = delete;
	InterfaceItemBag& operator=(InterfaceItemBag&& _Other) noexcept = delete;

	inline ItemBagEquipmentWindow* GetEquipment() const
	{
		return PlayerEquipment;
	}
	inline ItemBagQuickslot* GetQuickslot() const
	{
		return PlayerQuickslot;
	}
	inline ItemInventory* GetItemInventory() const
	{
		return PlayerItemInventory;
	}
	inline AvatarInventory* GetAvatarInventory() const
	{
		return PlayerAvatarInventory;
	}
	inline PetInventory* GetPetInventory() const
	{
		return PlayerPetInventory;
	}


protected:
	void Start() override;

	void Update(float _DeltaTime) override;

	// void End() override {}
	// void OnEvent() {}
	// void OffEvent() {}

private:

	ItemBagEquipmentWindow* PlayerEquipment;
	ItemBagQuickslot* PlayerQuickslot;
	ItemInventory* PlayerItemInventory;
	AvatarInventory* PlayerAvatarInventory;
	PetInventory* PlayerPetInventory;

};

