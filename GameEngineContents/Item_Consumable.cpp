#include "PreCompile.h"
#include "Item_Consumable.h"
#include "CharacterStatManager.h"
#include "GamePlayItem_DESC.h"

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
	switch (Desc_ItemDesc->GetItemCode())
	{
	case GamePlayItemCode::Debug_Weapon:
		break;
	case GamePlayItemCode::Level1Up:
		Item_Effect = std::bind(&Item_Consumable::Function_Level1Up, this, std::placeholders::_1);
		break;
	case GamePlayItemCode::Equipment_Upgrade12:
		break;
	case GamePlayItemCode::Error:
		break;
	case GamePlayItemCode::Empty:
		break;
	default:
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