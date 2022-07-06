#include "PreCompile.h"
#include "GamePlayItem.h"
#include "GamePlayItemBag.h"
#include "GamePlayCharacter.h"

GamePlayItem::GamePlayItem()
	: ItemBag(nullptr)
	, ItemCode(GamePlayItemCode::Error)
	, Stack(0)
	, Field(false)
{
	
}

GamePlayItem::~GamePlayItem() 
{

}

void GamePlayItem::Start()
{

}

void GamePlayItem::Update(float _DeltaTime)
{

}

void GamePlayItem::End()
{

}

//GamePlayItem* GamePlayItem::CreateItemByDrop(const GamePlayItemCode _ItemCode, float4& _Pos, int _Stack)
//{
//	if (_Stack > 99)
//	{
//		MsgBoxAssert("최대 스택은 99개입니다");
//		return nullptr;
//	}
//	GamePlayItem* NewDropItem = new GamePlayItem(_ItemCode, _Pos);
//	NewDropItem->Field = true;
//	NewDropItem->Stack = _Stack;
//	AllFieldItemList.push_back(NewDropItem);
//
//	return NewDropItem;
//}
//// static
//
//GamePlayItem* GamePlayItem::CreateItemByBag(const GamePlayItemCode _ItemCode, float4& _Pos, GamePlayItemBag* _ItemBag, int _Stack)
//{
//	if (_Stack > 99)
//	{
//		MsgBoxAssert("최대 스택은 99개입니다");
//		return nullptr;
//	}
//	GamePlayItem* NewBagItem = new GamePlayItem(_ItemCode, _Pos);
//	//NewBagItem->Field = false;
//	NewBagItem->Stack = _Stack;
//	NewBagItem->ItemBag = _ItemBag;
//
//	AllItemList.push_back(NewBagItem);
//
//	return NewBagItem;
//}
// static
//
//void GamePlayItem::DestroyAllFieldItem()
//{
//	for (GamePlayItem* Item : AllFieldItemList)
//	{
//		if (Item != nullptr)
//		{
//			Item->Death();
//			//Item = nullptr;
//		}
//	}
//	AllFieldItemList.clear();
//}
// static

// static

GamePlayItemType GamePlayItem::CheckItemType()
{
	GamePlayItemType IndexType = GamePlayItemType::Unknown;

	{
		int IntType = static_cast<int>(ItemCode);
		if (0 <= IntType && IntType < 100)
		{
			IndexType = GamePlayItemType::Debug;
		}
		else if (100 <= IntType && IntType < 5000)
		{
			if (100 <= IntType && IntType < 1000)
			{
				IndexType = GamePlayItemType::Equipment;
			}
			if (1000 <= IntType && IntType < 2000)
			{
				IndexType = GamePlayItemType::Stuff;
			}
			if (2000 <= IntType && IntType < 3000)
			{
				IndexType = GamePlayItemType::Consumable;
			}
			if (3000 <= IntType && IntType < 4000)
			{
				IndexType = GamePlayItemType::Avatar;
			}
			if (4000 <= IntType && IntType < 5000)
			{
				IndexType = GamePlayItemType::Pet;
			}
		
		}
	}
	//    0 ~   99 디버그
	//  100 ~  999 장비
	// 1000 ~ 1999 재료
	// 2000 ~ 2999 소비
	// 3000 ~ 3999 아바타
	// 4000 ~ 4999 펫
	ItemType = IndexType;

	return ItemType;
}


void GamePlayItem::DestroyItem()
{
	//if (Field == true)
	//{
	//	GamePlayItem::AllFieldItemList.remove(this);
	//}
	//else
	//{
		//GamePlayItem::AllItemList.remove(this);
	//}
}

void GamePlayItem::PickupFieldItem(GamePlayCharacter* _Character)
{
	Field = false;
	//AllFieldItemList.remove(this);
	_Character->GetItemInventory();
	//AllItemList.push_back(this);
	// 필드 아이템 목록에서 삭제
	// 모든(소유)아이템 목록으로 이동
}

int GamePlayItem::CombineStackItem(GamePlayItem* _Item)
{
	Stack += _Item->Stack;
	int Over = Stack > 99 ? Stack - 99 : 0;

	if (Over == 0)
	{
		_Item->DestroyItem();
		return 0;
	}
	else
	{
		Stack -= Over;
		_Item->Stack = Over;
		return Over;
	}

}