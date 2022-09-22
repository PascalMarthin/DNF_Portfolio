#include "PreCompile.h"
#include "Item_Consumable.h"
#include "CharacterStatManager.h"
#include "GamePlayItem_DESC.h"
#include "HealHPAni.h"

Item_Consumable::Item_Consumable() 
	: Item_Effect(nullptr)
{
}

Item_Consumable::~Item_Consumable() 
{
}

void Item_Consumable::Start()
{
	GamePlayItem::Start();

}

void Item_Consumable::AfterSetDesc()
{
	//s_HPPotion = 2100,
	//	m_HPPotion,
	//	L_HPPotion,

	//	s_MPPotion,
	//	m_MPPotion,
	//	L_MPPotion,


	switch (Desc_ItemDesc->GetItemCode())
	{
	case GamePlayItemCode::Debug_Weapon:
		break;
	case GamePlayItemCode::Level1Up:
		Item_Effect = std::bind(&Item_Consumable::Function_Level1Up, this, std::placeholders::_1);
		break;
	case GamePlayItemCode::Equipment_Upgrade12:
		break;
	case GamePlayItemCode::s_HPPotion:
		Item_Effect = std::bind(&Item_Consumable::Function_s_HPPotion, this, std::placeholders::_1);
		break;
	case GamePlayItemCode::m_HPPotion:
		Item_Effect = std::bind(&Item_Consumable::Function_m_HPPotion, this, std::placeholders::_1);
		break;
	case GamePlayItemCode::L_HPPotion:
		Item_Effect = std::bind(&Item_Consumable::Function_L_HPPotion, this, std::placeholders::_1);
		break;
	case GamePlayItemCode::s_MPPotion:
		Item_Effect = std::bind(&Item_Consumable::Function_s_MPPotion, this, std::placeholders::_1);
		break;
	case GamePlayItemCode::m_MPPotion:
		Item_Effect = std::bind(&Item_Consumable::Function_m_MPPotion, this, std::placeholders::_1);
		break;
	case GamePlayItemCode::L_MPPotion:
		Item_Effect = std::bind(&Item_Consumable::Function_L_MPPotion, this, std::placeholders::_1);
		break;

	}

}

//void Item_Consumable::Item_Effect(CharacterStatManager* _Manager)
//{
//	switch (Desc_ItemDesc->GetItemCode())
//	{
//	case GamePlayItemCode::Error:
//		break;
//	case GamePlayItemCode::Empty:
//		break;
//	case GamePlayItemCode::Debug_Weapon:
//		break;
//	case GamePlayItemCode::Level1Up:
//		break;
//	case GamePlayItemCode::Equipment_Upgrade12:
//		break;
//
//	default:
//		break;
//	}
//}

void Item_Consumable::Function_Level1Up(CharacterStatManager* _Manager)
{
	_Manager->LevelUp();
}

void Item_Consumable::Function_s_HPPotion(CharacterStatManager* _Manager)
{
	_Manager->HealHP(1000, HPMPEnum::HP);
}
void Item_Consumable::Function_m_HPPotion(CharacterStatManager* _Manager)
{
	_Manager->HealHP(10000, HPMPEnum::HP);
}
void Item_Consumable::Function_L_HPPotion(CharacterStatManager* _Manager)
{
	_Manager->HealHP(50000, HPMPEnum::HP);
}
void Item_Consumable::Function_s_MPPotion(CharacterStatManager* _Manager)
{
	_Manager->HealHP(1000, HPMPEnum::MP);
}
void Item_Consumable::Function_m_MPPotion(CharacterStatManager* _Manager)
{
	_Manager->HealHP(5000, HPMPEnum::MP);
}
void Item_Consumable::Function_L_MPPotion(CharacterStatManager* _Manager)
{
	_Manager->HealHP(10000, HPMPEnum::MP);
}
