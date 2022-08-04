#include "PreCompile.h"
#include "GamePlayItem.h"
#include "GamePlayCharacter.h"


GamePlayItem::GamePlayItem()
	: Stack(0)
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
//		MsgBoxAssert("�ִ� ������ 99���Դϴ�");
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
//		MsgBoxAssert("�ִ� ������ 99���Դϴ�");
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
	//_Character->GetItemInventory();
	//AllItemList.push_back(this);
	// �ʵ� ������ ��Ͽ��� ����
	// ���(����)������ ������� �̵�
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
