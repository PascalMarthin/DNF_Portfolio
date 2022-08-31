#include "PreCompile.h"
#include "ItemInventory.h"
#include "GamePlayDataBase.h"
#include "GamePlayItem.h"
#include "MouseCursorComponent.h"

ItemInventory::ItemInventory()

{
}

ItemInventory::~ItemInventory() 
{
}

void ItemInventory::Start()
{
	Texture_Inventory = CreateComponent<GameEngineUIRenderer>("ItemInventory");
	Texture_Inventory->SetTexture("Window_Iteminventory.png");
	Texture_Inventory->ScaleToTexture();
	Texture_Inventory->GetTransform().SetLocalPosition({ 0, 0, 10 });

	{
		Collision_WindowInventory = CreateComponent<GameEngineCollision>();
		Collision_WindowInventory->GetTransform().SetLocalPosition({ 0, 258 , 0});
		Collision_WindowInventory->GetTransform().SetLocalScale({ 258, 23 , 0 });
		Collision_WindowInventory->SetDebugSetting(CollisionType::CT_AABB, float4::BLUE);
		//Collision_WindowInventory->SetParent(Texture_Inventory);
	}
	{
		for (int y = 0; y > -6; y--)
		{
			for (int x = (-3); x < 5; x++)
			{
				GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>("Inventory_Blank");
				Renderer->SetTexture("Inventory_Blank.png");
				Renderer->ScaleToTexture();
				Renderer->GetTransform().SetLocalPosition({static_cast<float>(30 * x) - 15,static_cast<float>(30 * y) -12.f , 5});
				GameEngineCollision* Collision = CreateComponent<GameEngineCollision>();
				Collision->GetTransform().SetLocalScale(Renderer->GetTransform().GetLocalPosition().Half());
				Collision->GetTransform().SetLocalPosition(Renderer->GetTransform().GetLocalPosition());
				Collision->SetDebugSetting(CollisionType::CT_AABB2D, {0.5f, 0.5f, 0, 0.5f});
				Collision->ChangeOrder(CollisionOrder::UI_InventoryBlank);
				

				Inventory_Blank[x + 3 + y * -8].Collision_Blank = Collision;
				Inventory_Blank[x + 3 + y * -8].Texture_Blank = Renderer;
			}
		}
	}
	
}

void ItemInventory::Update(float _DeltaTime)
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
			Component_MouseCursorComponent->GetMouseCursor()->IsCollision(CollisionType::CT_AABB2D, CollisionOrder::UI_InventoryItem, CollisionType::CT_AABB2D),
				std::bind(&GamePlayInventory::IsItemDrag, this, std::placeholders::_1, std::placeholders::_2);
		}
	}
	else
	{
		if (GameEngineInput::GetInst()->IsPress("LMouseCLK"))
		{
			if (Item_DragData != nullptr)
			{
				Item_DragData->SetTransform(Component_MouseCursorComponent->GetMouseCursor());
			}
		}
		else if (GameEngineInput::GetInst()->IsUp("LMouseCLK"))
		{
			DragMode = false;
			Item_DragData = nullptr;
		}
	}

	//else if (GameEngineInput::GetInst()->IsPress("MouseCLK"))
	//{

	//}
}


void ItemInventory::LevelStartEvent()
{
	SetLevelStartItem(GamePlayDataBase::GetCurrentCharacterData()->GetInventoryData(InventoryBag::Inventory_ItemInventory_Consumable));
	if (Component_MouseCursorComponent == nullptr)
	{
		const std::list<GameEngineActor*>& ActorList = GetLevel()->GetGroup(0);
		for (auto& Actor : ActorList)
		{
			if (Actor->GetNameConstRef() == "Component_Mouse")
			{
				Component_MouseCursorComponent = dynamic_cast<MouseCursorComponent*>(Actor);
				break;
			}
		}

	}


	if (Component_MouseCursorComponent == nullptr)
	{
		MsgBoxAssert("마우스포인터가 설정되지 않았습니다");
	}
	
}

void ItemInventory::LevelEndEvent()
{
	for (auto& Blank : Inventory_CurrentItem)
	{
		Blank.second->Death();
		Blank.second = nullptr;
	}
	DragMode = false;
	Item_DragData = nullptr;
}