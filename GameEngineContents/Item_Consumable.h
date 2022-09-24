#pragma once
#include "GamePlayItem.h"

// ���� :
class CharacterStatManager;
class Item_Consumable : public GamePlayItem
{
public:
	friend class ItemInventory_Consumable;
	// constrcuter destructer
	Item_Consumable();
	~Item_Consumable();

	// delete Function
	Item_Consumable(const Item_Consumable& _Other) = delete;
	Item_Consumable(Item_Consumable&& _Other) noexcept = delete;
	Item_Consumable& operator=(const Item_Consumable& _Other) = delete;
	Item_Consumable& operator=(Item_Consumable&& _Other) noexcept = delete;


	//void Item_Effect(CharacterStatManager* _Manager);
protected:
	void Start() override;


	void AfterSetDesc() override;
private:
	std::function<bool(CharacterStatManager*)> Item_Effect;


	bool Function_Level1Up(CharacterStatManager* _Manager);
	bool Function_s_HPPotion(CharacterStatManager* _Manager);
	bool Function_m_HPPotion(CharacterStatManager* _Manager);
	bool Function_L_HPPotion(CharacterStatManager* _Manager);
	bool Function_s_MPPotion(CharacterStatManager* _Manager);
	bool Function_m_MPPotion(CharacterStatManager* _Manager);
	bool Function_L_MPPotion(CharacterStatManager* _Manager);

};


