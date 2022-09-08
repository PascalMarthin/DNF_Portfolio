#include "PreCompile.h"
#include "AvataInventory.h"
#include "GamePlayDataBase.h"
#include "GamePlayItem.h"
#include "MouseCursorComponent.h"
#include "GamePlayItem_DESC.h"
#include "Item_Avata.h"

AvataInventory::AvataInventory() 
{
}

AvataInventory::~AvataInventory() 
{
}

void AvataInventory::Start()
{
	Texture_Inventory = CreateComponent<GameEngineUIRenderer>("Avatainventory");
	Texture_Inventory->SetTexture("Window_Avatainventory.png");
	Texture_Inventory->ScaleToTexture();
	Texture_Inventory->GetTransform().SetLocalPosition({ 0, 0, 10 });

	{
		Collision_WindowInventory = CreateComponent<GameEngineCollision>();
		Collision_WindowInventory->GetTransform().SetLocalPosition({ 0, 258 , 0 });
		Collision_WindowInventory->GetTransform().SetLocalScale({ 258, 23 , 0 });
		Collision_WindowInventory->SetDebugSetting(CollisionType::CT_AABB, float4::BLUE);
		//Collision_WindowInventory->SetParent(Texture_Inventory);
	}
	// Blank
	{
		for (int y = 0; y > -6; y--)
		{
			for (int x = (-3); x < 5; x++)
			{
				GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>("Inventory_Blank");
				Renderer->SetTexture("Inventory_Blank.png");
				Renderer->ScaleToTexture();
				Renderer->GetTransform().SetLocalPosition({ static_cast<float>(30 * x) - 15,static_cast<float>(30 * y) - 12.f , 5 });
				GameEngineCollision* Collision = CreateComponent<GameEngineCollision>();
				Collision->GetTransform().SetLocalScale(Renderer->GetTransform().GetLocalScale() * 0.125f);
				Collision->GetTransform().SetLocalPosition(Renderer->GetTransform().GetLocalPosition());
				Collision->SetDebugSetting(CollisionType::CT_AABB2D, { 0.5f, 0.5f, 0, 0.5f });
				Collision->ChangeOrder(CollisionOrder::UI_InventoryBlank);


				Inventory_Blank[x + 3 + y * -8].Collision_Blank = Collision;
				Inventory_Blank[x + 3 + y * -8].Texture_Blank = Renderer;
			}
		}
	}


	// 장착 아바타
	{


		for (size_t y = 0; y < 3; y++)
		{
			for (size_t x = 0; x < 4; x++)
			{
				if (y == 2 && x == 0)
				{
					continue;
				}
				GameEngineCollision* Collision = CreateComponent<GameEngineCollision>("Wearing_Avata_Collision");
				Collision->GetTransform().SetLocalScale({ 15, 15 });
				Collision->GetTransform().SetLocalPosition({ 4.f + (x * 33.f), 169 + (y * -34.f), -10 });

				AllAvataClass Class = AllAvataClass::None;
				if (y == 0 && x == 0)
				{
					Class = AllAvataClass::Weapon;
				}
				else if(y == 0 && x == 1)
				{
					Class = AllAvataClass::Hair;
				}
				else if (y == 0 && x == 2)
				{
					Class = AllAvataClass::Cap;
				}
				else if (y == 0 && x == 3)
				{
					Class = AllAvataClass::Face;
				}
				else if (y == 1 && x == 1)
				{
					Class = AllAvataClass::Neck;
				}
				else if (y == 1 && x == 2)
				{
					Class = AllAvataClass::Coat;
				}
				else if (y == 1 && x == 3)
				{
					Class = AllAvataClass::Skin;
				}
				else if (y == 2 && x == 1)
				{
					Class = AllAvataClass::Belt;
				}
				else if (y == 2 && x == 2)
				{
					Class = AllAvataClass::Pants;
				}
				else if (y == 2 && x == 3)
				{
					Class = AllAvataClass::Shoes;
				}

				All_WearAvata_Type[Class] = Collision;
				All_WearAvata_Texture[Collision] = nullptr;
				
			}
		}

		//All_WearAvata

	}

}

void AvataInventory::Mouse_RClick(GamePlayItem* _Item)
{
	if (_Item->GetItemDesc()->GetItemType() != GamePlayItemType::Avatar)
	{
		MsgBoxAssert("아바타 인벤토리에 알수없는 형식의 아이템이 존재합니다")
	}

	Item_Avata* Avata = dynamic_cast<Item_Avata*>(_Item);


}



void AvataInventory::LevelStartEvent()
{
	SetLevelStartItem(GamePlayDataBase::GetCurrentCharacterData()->GetInventoryData(InventoryBag::Inventory_Avata));
	if (Component_MouseCursorComponent == nullptr)
	{
		const std::list<GameEngineActor*>& ActorList = GetLevel()->GetGroup(ActorOrder::Mouse);
		Component_MouseCursorComponent = dynamic_cast<MouseCursorComponent*>(ActorList.front());
	}


	if (Component_MouseCursorComponent == nullptr)
	{
		MsgBoxAssert("마우스포인터가 설정되지 않았습니다");
	}
	Off();

}

void AvataInventory::LevelEndEvent()
{
	for (auto& Blank : Inventory_CurrentItem)
	{
		Blank.second->Death();
		Blank.second = nullptr;
	}
	DragMode = false;
	Item_DragData = nullptr;
	Item_DragDataIndex = -1;
}