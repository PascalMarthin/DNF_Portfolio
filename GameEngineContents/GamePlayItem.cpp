#include "PreCompile.h"
#include "GamePlayItem.h"
#include "GamePlayCharacter.h"
#include "GamePlayItem_DESC.h"


GamePlayItem::GamePlayItem()
	: Stack(0)
	, Field(false)
	, Texture_Item(nullptr)
	, Collision_Item(nullptr)
	, Desc_ItemDesc(nullptr)
{
	
}

GamePlayItem::~GamePlayItem() 
{

}

void GamePlayItem::Start()
{
	GetTransform().SetLocalPosition({ 0, 0, -1 });
	//GetTransform().SetLocalScale({ 1, 1, 1 });
	Texture_Item = GetActor()->CreateComponent<GameEngineUIRenderer>();
	Collision_Item = GetActor()->CreateComponent<GameEngineCollision>();
	Collision_Item->ChangeOrder(CollisionOrder::UI_InventoryItem);
}

void GamePlayItem::SetDESC(GamePlayItem_DESC* _DESC)
{
	Desc_ItemDesc = _DESC;
	SetThumbnail();
}

void GamePlayItem::SetTransform(GameEngineTransformBase* _Parent)
{
	Texture_Item->GetTransform().SetLocalPosition(_Parent->GetTransform().GetLocalPosition());
	Texture_Item->ScaleToTexture();
	Collision_Item->GetTransform().SetLocalPosition(_Parent->GetTransform().GetLocalPosition());
	Collision_Item->GetTransform().SetLocalScale(Texture_Item->GetTransform().GetLocalScale());
}

void GamePlayItem::SetThumbnail()
{
	Texture_Item->SetTexture(Desc_ItemDesc->GetItemIcon());
}


void GamePlayItem::Update(float _DeltaTime)
{

	//GameEngineDebug::OutPutString(std::to_string(GetTransform().GetWorldPosition().x) + " / " + std::to_string(GetTransform().GetWorldPosition().y));
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
