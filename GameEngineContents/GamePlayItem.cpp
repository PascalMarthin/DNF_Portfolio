#include "PreCompile.h"
#include "GamePlayItem.h"
#include "GamePlayCharacter.h"
#include "GamePlayItem_DESC.h"


GamePlayItem::GamePlayItem()
	: Texture_Item(nullptr)
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
	GetTransform().SetLocalScale({ 1, 1, 1 });
	Texture_Item = GetActor()->CreateComponent<GameEngineUIRenderer>();
	Texture_Item->SetParent(this);
	Collision_Item = GetActor()->CreateComponent<GameEngineCollision>();
	Collision_Item->SetParent(this);
	Collision_Item->ChangeOrder(CollisionOrder::UI_InventoryItem);
	Collision_Item->SetDebugSetting(CollisionType::CT_AABB2D, float4::BLACK);
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



//int GamePlayItem::CombineStackItem(GamePlayItem* _Item)
//{
//	Stack += _Item->Stack;
//	int Over = Stack > 99 ? Stack - 99 : 0;
//
//	if (Over == 0)
//	{
//		_Item->DestroyItem();
//		return 0;
//	}
//	else
//	{
//		Stack -= Over;
//		_Item->Stack = Over;
//		return Over;
//	}
//
//}
