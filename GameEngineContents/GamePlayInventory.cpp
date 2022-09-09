#include "PreCompile.h"
#include "GamePlayInventory.h"
#include "GamePlayItem_DESC.h"
#include "GamePlayItem.h"
#include "MouseCursorComponent.h"

GamePlayInventory::GamePlayInventory() 
	: Texture_Inventory(nullptr)
	, Collision_WindowInventory(nullptr)
	, Component_MouseCursorComponent(nullptr)
	, DragMode(false)
	, Item_DragData(nullptr)
	, Item_DragDataIndex(0)
{
}

GamePlayInventory::~GamePlayInventory() 
{
}

void GamePlayInventory::Update(float _DeltaTime)
{

	if (GameEngineInput::GetInst()->IsPress("LMouseCLK"))
	{
		if (Collision_WindowInventory->IsCollision(CollisionType::CT_AABB2D, CollisionOrder::UI_UIMouse, CollisionType::CT_AABB2D,
			[](GameEngineCollision* _This, GameEngineCollision* _Other)
			{
				if (_Other->GetNameConstRef() == "Collision_UICam_MouseCursor")
				{
					return true;
				}
				else
				{
					return false;
				}

			}))
		{
			GetTransform().SetLocalMove(GetLevel()->GetUICamera()->GetMouseWorldDir());
		}
	}

	if (DragMode == false)
	{
		if (GameEngineInput::GetInst()->IsDown("LMouseCLK"))
		{
			if (Component_MouseCursorComponent->GetUICamMouseCursor()->IsCollision(CollisionType::CT_AABB2D, CollisionOrder::UI_InventoryItem, CollisionType::CT_AABB2D,
				std::bind(&GamePlayInventory::IsItemDrag, this, std::placeholders::_1, std::placeholders::_2)))
			{
				DragMode = true;

				for (auto& Item : Inventory_CurrentItem)
				{
					if (Item.second == Item_DragData)
					{
						Item_DragDataIndex = Item.first;
					}
				}
				if (Item_DragDataIndex == -1)
				{
					MsgBoxAssert("예외 발생");
				}
			}
		}
		else if (GameEngineInput::GetInst()->IsUp("RMouseCLK"))
		{
			if (Component_MouseCursorComponent->GetUICamMouseCursor()->IsCollision(CollisionType::CT_AABB2D, CollisionOrder::UI_InventoryItem, CollisionType::CT_AABB2D,
				std::bind(&GamePlayInventory::IsItemDrag, this, std::placeholders::_1, std::placeholders::_2)))
			{
				Mouse_RClick(Item_DragData);
				Item_DragData = nullptr;
			}
		}
	}
	else
	{
		if (GameEngineInput::GetInst()->IsPress("LMouseCLK"))
		{
			const float4& Pos = Item_DragData->GetTransform().GetLocalPosition();
			if (Item_DragData != nullptr)
			{
				Item_DragData->SetUITextureTransform(Component_MouseCursorComponent->GetUIMouseTexture());
			}
			int a = 0;
		}
		else if (GameEngineInput::GetInst()->IsUp("LMouseCLK"))
		{
			Item_DragData->GetCollision()->IsCollision(CollisionType::CT_AABB2D, CollisionOrder::UI_InventoryBlank, CollisionType::CT_AABB2D,
				std::bind(&GamePlayInventory::CheckBlankCollision, this, std::placeholders::_1, std::placeholders::_2));

			Item_DragData->SetUITextureTransform(Inventory_Blank[Item_DragDataIndex].Collision_Blank);
			Inventory_CurrentItem[Item_DragDataIndex] = Item_DragData;
			

			MoveInventory(Item_DragDataIndex, Inventory_CurrentData[Item_DragData]);

			DragMode = false;
			Item_DragData = nullptr;
			Item_DragDataIndex = -1;
		}
	}

	

	//else if (GameEngineInput::GetInst()->IsPress("MouseCLK"))
	//{

	//}
}



bool GamePlayInventory::IsItemDrag(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	Item_DragData = _Other->GetActor<GamePlayItem>();

	return true;
}
bool GamePlayInventory::CheckBlankCollision(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	for (auto& Blank : Inventory_Blank)
	{
		if (Blank.second.Collision_Blank == _Other)
		{
			if (Inventory_CurrentItem[Blank.first] == nullptr)
			{
				Inventory_CurrentItem[Item_DragDataIndex] = nullptr;

			}
			else
			{
				Inventory_CurrentItem[Item_DragDataIndex] = Inventory_CurrentItem[Blank.first];
				Inventory_CurrentItem[Item_DragDataIndex]->SetUITextureTransform(Inventory_Blank[Item_DragDataIndex].Collision_Blank);
				MoveInventory(Item_DragDataIndex, Inventory_CurrentData[Inventory_CurrentItem[Item_DragDataIndex]]);
			}
			Item_DragDataIndex = Blank.first;
			return true;
		}

	}
	return false;
}




void GamePlayInventory::MoveItem(unsigned int _Pos, InventoryData* _Item, InventoryBag _Bag)
{
	std::vector<InventoryData*>& Inventory = GamePlayDataBase::GetCurrentCharacterData()->GetInventoryData(_Bag);
	
	unsigned int BeforePos = 0;

	if (Inventory[_Pos] == nullptr)
	{
		for (; BeforePos < Inventory.size(); BeforePos++)
		{
			if (Inventory[BeforePos] == _Item)
			{
				Inventory[_Pos] = _Item;
				Inventory[BeforePos] = nullptr;
				return;
			}
		}

		MsgBoxAssert("오류, 해당되는 아이템이 인벤토리 내에 없습니다")
	}
	else
	{
		for (; BeforePos < Inventory.size(); BeforePos++)
		{
			if (Inventory[BeforePos] == _Item)
			{
				Inventory[BeforePos] = Inventory[_Pos];
				Inventory[_Pos] = _Item;
				return;
			}
		}
		MsgBoxAssert("오류, 해당되는 아이템이 인벤토리 내에 없습니다")
	}

}


unsigned int GamePlayInventory::MoveItemToInventory(unsigned int _Pos, InventoryData* _Item, InventoryBag _ToBag, InventoryBag _FromBag)
{
	std::vector<InventoryData*>& ToInventory = GamePlayDataBase::GetCurrentCharacterData()->GetInventoryData(_ToBag);
	std::vector<InventoryData*>& FromInventory = GamePlayDataBase::GetCurrentCharacterData()->GetInventoryData(_FromBag);

	unsigned int BeforePos = 0;

	if (_Pos == -1)
	{
		for (; BeforePos < ToInventory.size() ; ++BeforePos)
		{
			if (ToInventory[BeforePos] == nullptr)
			{
				for (int i = 0; i < FromInventory.size(); ++i)
				{
					if (FromInventory[i] == _Item)
					{
						ToInventory[BeforePos] = _Item;
						FromInventory[i] = nullptr;
						return BeforePos;
					}
				}
			}
		}
	}
	else
	{
		if (ToInventory[_Pos] == nullptr)
		{
			for (; BeforePos < FromInventory.size(); BeforePos++)
			{
				if (FromInventory[BeforePos] == _Item)
				{
					ToInventory[_Pos] = _Item;
					FromInventory[BeforePos] = nullptr;
					return BeforePos;
				}
			}

			MsgBoxAssert("오류, 해당되는 아이템이 인벤토리 내에 없습니다")
		}
		else
		{
			for (; BeforePos < FromInventory.size(); BeforePos++)
			{
				if (FromInventory[BeforePos] == _Item)
				{
					FromInventory[BeforePos] = ToInventory[_Pos];
					ToInventory[_Pos] = _Item;
					return BeforePos;
				}
			}
			MsgBoxAssert("오류, 해당되는 아이템이 인벤토리 내에 없습니다")
		}
	}
	return BeforePos;
}


// --------------------LevelEvent---------------

void GamePlayInventory::OffEvent()
{

}



void GamePlayInventory::LevelStartEvent()
{
	if (Component_MouseCursorComponent == nullptr)
	{
		const std::list<GameEngineActor*>& ActorList = GetLevel()->GetGroup(ActorOrder::Mouse);
		Component_MouseCursorComponent = dynamic_cast<MouseCursorComponent*>(ActorList.front());
	}


	if (Component_MouseCursorComponent == nullptr)
	{
		MsgBoxAssert("마우스포인터가 설정되지 않았습니다");
	}
}


void GamePlayInventory::LevelEndEvent()
{
	for (auto& Blank : Inventory_CurrentItem)
	{
		if (Blank.second != nullptr)
		{
			Blank.second->Death();
			Blank.second = nullptr;
		}
	}
	Inventory_CurrentItem.clear();
	Inventory_CurrentData.clear();
	DragMode = false;
	Item_DragData = nullptr;
	Item_DragDataIndex = -1;
}