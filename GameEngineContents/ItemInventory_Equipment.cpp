#include "PreCompile.h"
#include "ItemInventory_Equipment.h"
#include "GamePlayDataBase.h"
#include "GamePlayItem.h"
#include "MouseCursorComponent.h"
#include "GamePlayItem_DESC.h"
#include "Item_Equipment.h"
#include "AvataManager.h"


ItemInventory_Equipment::ItemInventory_Equipment() 
{
}

ItemInventory_Equipment::~ItemInventory_Equipment() 
{
}


void ItemInventory_Equipment::Start()
{
	Texture_Inventory = CreateComponent<GameEngineUIRenderer>("Equipmentinventory");
	Texture_Inventory->SetTexture("Window_Equipmentinventory.png");
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
			for (size_t x = 0; x < 2; x++)
			{
				if (y == 2 && x == 1)
				{
					continue;
				}
				GameEngineCollision* Collision = CreateComponent<GameEngineCollision>("Wearing_Avata_Collision");
				Collision->GetTransform().SetLocalScale({ 15, 15 });
				Collision->GetTransform().SetLocalPosition({ 4.f + (x * 33.f), 169 + (y * -34.f), -10 });

				AllEquipmentClass Class = AllEquipmentClass::None;
				if (y == 0 && x == 0)
				{
					Class = AllEquipmentClass::Neck;
				}
				else if (y == 0 && x == 1)
				{
					Class = AllEquipmentClass::Coat;
				}
				else if (y == 1 && x == 0)
				{
					Class = AllEquipmentClass::Pants;
				}
				else if (y == 1 && x == 1)
				{
					Class = AllEquipmentClass::Belt;
				}
				else if (y == 2 && x == 0)
				{
					Class = AllEquipmentClass::Shoes;
				}

				All_WearEquipment_Type[Class] = Collision;
				All_WearEquipment_Texture[Collision] = nullptr;

			}
		}

		//All_WearAvata

	}


}

void ItemInventory_Equipment::Mouse_RClick(GamePlayItem* _Item)
{
	//unsigned int Pos = FindGamePlayItem(_Item);
	Item_Equipment* Avata = dynamic_cast<Item_Equipment*>(_Item);
	GamePlayItem* FromItem = All_WearEquipment_Texture[All_WearEquipment_Type[Avata->Enum_EquipmentClass]];


	if (FromItem == _Item) // 자기 자신 해제
	{
		unsigned int FromPos = MoveItemToInventory(-1, Inventory_CurrentData[_Item], InventoryBag::Inventory_ItemInventory_Equipment, InventoryBag::Inventory_ItemInventory_Equipment_Wear);
		All_WearEquipment_Texture[All_WearEquipment_Type[Avata->Enum_EquipmentClass]] = nullptr;
		Inventory_CurrentItem[FromPos] = _Item;
		_Item->SetUITextureTransform(Inventory_Blank[FromPos].Collision_Blank);

	}
	else // 타 아바타
	{
		All_WearEquipment_Texture[All_WearEquipment_Type[Avata->Enum_EquipmentClass]] = Avata;
		unsigned int FromPos = MoveItemToInventory(static_cast<int>(Avata->Enum_EquipmentClass), Inventory_CurrentData[_Item], InventoryBag::Inventory_ItemInventory_Equipment_Wear, InventoryBag::Inventory_ItemInventory_Equipment);

		Avata->SetUITextureTransform(All_WearEquipment_Type[Avata->Enum_EquipmentClass]);
		if (FromItem != nullptr) // 바꿔치기
		{
			Inventory_CurrentItem[FromPos] = FromItem;
			FromItem->SetUITextureTransform(Inventory_Blank[FromPos].Collision_Blank);
		}
		else // 빈칸 넣기 
		{
			Inventory_CurrentItem[FromPos] = nullptr;
		}
	}
	//AvataManager::GetInst()->ReadCharacterDataBase(nullptr);

}

void ItemInventory_Equipment::OnEvent()
{

}


void ItemInventory_Equipment::LevelStartEvent()
{
	GamePlayInventory::LevelStartEvent();
	SetLevelStartItem<Item_Equipment>(GamePlayDataBase::GetCurrentCharacterData()->GetInventoryData(InventoryBag::Inventory_ItemInventory_Equipment));

	{
		std::vector<InventoryData*>& WearingAvata = GamePlayDataBase::GetCurrentCharacterData()->GetInventoryData(InventoryBag::Inventory_ItemInventory_Equipment_Wear);
		for (int i = 0; i < WearingAvata.size(); i++)
		{
			//
			if (WearingAvata[i] == nullptr)
			{
				continue;
			}

			Item_Equipment* Item = CreateComponent<Item_Equipment>("GamePlayItem");
			Item->SetDESC(WearingAvata[i]->Item_DESC);
			Item->SetUITextureTransform(All_WearEquipment_Type[static_cast<AllEquipmentClass>(i)]);
			Inventory_CurrentData[Item] = WearingAvata[i];
			All_WearEquipment_Texture[All_WearEquipment_Type[static_cast<AllEquipmentClass>(i)]] = Item;
		}
	}




	Off();
}

void ItemInventory_Equipment::LevelEndEvent()
{
	for (auto& GameItem : All_WearEquipment_Texture)
	{
		if (GameItem.second != nullptr)
		{
			GameItem.second->Death();
			GameItem.second = nullptr;
		}
	}

	All_WearEquipment_Texture.clear();


	GamePlayInventory::LevelEndEvent();

}