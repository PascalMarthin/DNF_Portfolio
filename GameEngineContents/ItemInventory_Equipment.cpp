#include "PreCompile.h"
#include "ItemInventory_Equipment.h"
#include "GamePlayDataBase.h"
#include "GamePlayItem.h"
#include "MouseCursorComponent.h"
#include "GamePlayItem_DESC.h"
#include "Item_Equipment.h"
#include "AvataManager.h"
#include "GameEngineUIFontRenderer.h"
#include "ItemInventory_Consumable.h"
ItemInventory_Equipment* ItemInventory_Equipment::Inst = nullptr;

ItemInventory_Equipment::ItemInventory_Equipment() 
{
}

ItemInventory_Equipment::~ItemInventory_Equipment() 
{
}


void ItemInventory_Equipment::Start()
{
	Texture_Inventory = CreateComponent<GameEngineUIRenderer>("Equipmentinventory");
	Texture_Inventory->SetTexture("Window_Iteminventory.png");
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

	{
		GameEngineUIRenderer* Texture = CreateComponent<GameEngineUIRenderer>();
		Texture->SetTexture("Window_InventoryTapOn.png");
		Texture->GetTransform().SetLocalPosition({ -100, 20 });
		Texture->ScaleToTexture();

		GameEngineUIFontRenderer* Font = CreateComponent<GameEngineUIFontRenderer>();
		Font->GetTransform().SetLocalPosition({ -100 , 20 ,-10.006f });
		Font->SetPositionMode(FontPositionMode::WORLD);
		Font->SetColor({ 1.0f, 1.0f, 1.0f, 1.0 });
		Font->SetRenderingOrder(10000);
		Font->SetText("¿Â∫Ò", "±º∏≤");
		Font->SetSize(11);
		Font->SetTopAndBotSort(TopAndBotSort::VCENTER);
		Font->SetLeftAndRightSort(LeftAndRightSort::CENTER);

		Texture = CreateComponent<GameEngineUIRenderer>();
		Texture->SetTexture("Window_InventoryTapOff.png");
		Texture->ScaleToTexture();
		Texture->GetTransform().SetLocalPosition({ -59, 20 });

		Font = CreateComponent<GameEngineUIFontRenderer>();
		Font->GetTransform().SetLocalPosition({ -59 , 20 ,-10.006f });
		Font->SetPositionMode(FontPositionMode::WORLD);
		Font->SetText("º“∫Ò", "±º∏≤");
		Font->SetColor({ 1.0f, 1.0f, 1.0f, 1.0 });
		Font->SetRenderingOrder(10000);
		Font->SetSize(11);
		Font->SetTopAndBotSort(TopAndBotSort::VCENTER);
		Font->SetLeftAndRightSort(LeftAndRightSort::CENTER);

		Collision_InventoryTapOff = CreateComponent<GameEngineCollision>();
		Collision_InventoryTapOff->GetTransform().SetLocalPosition(Texture->GetTransform().GetLocalPosition());
		Collision_InventoryTapOff->GetTransform().SetLocalScale(Texture->GetTransform().GetLocalScale());
		Collision_InventoryTapOff->ChangeOrder(CollisionOrder::UI);
	}


	// ¿Â¬¯ æ∆πŸ≈∏
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
				Collision->GetTransform().SetLocalPosition({ -102.f + (x * 33.f), 190 + (y * -34.f), -10 });

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


	if (FromItem == _Item) // ¿⁄±‚ ¿⁄Ω≈ «ÿ¡¶
	{
		unsigned int FromPos = MoveItemToInventory(-1, Inventory_CurrentData[_Item], InventoryBag::Inventory_ItemInventory_Equipment, InventoryBag::Inventory_ItemInventory_Equipment_Wear);
		All_WearEquipment_Texture[All_WearEquipment_Type[Avata->Enum_EquipmentClass]] = nullptr;
		Inventory_CurrentItem[FromPos] = _Item;
		_Item->SetUITextureTransform(Inventory_Blank[FromPos].Collision_Blank);

	}
	else // ≈∏ æ∆πŸ≈∏
	{
		All_WearEquipment_Texture[All_WearEquipment_Type[Avata->Enum_EquipmentClass]] = Avata;
		unsigned int FromPos = MoveItemToInventory(static_cast<int>(Avata->Enum_EquipmentClass), Inventory_CurrentData[_Item], InventoryBag::Inventory_ItemInventory_Equipment_Wear, InventoryBag::Inventory_ItemInventory_Equipment);

		Avata->SetUITextureTransform(All_WearEquipment_Type[Avata->Enum_EquipmentClass]);
		if (FromItem != nullptr) // πŸ≤„ƒ°±‚
		{
			Inventory_CurrentItem[FromPos] = FromItem;
			FromItem->SetUITextureTransform(Inventory_Blank[FromPos].Collision_Blank);
		}
		else // ∫Ûƒ≠ ≥÷±‚ 
		{
			Inventory_CurrentItem[FromPos] = nullptr;
		}
	}

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
		map_EquipmentstatUP.clear();

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

			for (auto& ItemStat : Item->map_Stat)
			{
				map_EquipmentstatUP[ItemStat.first] += ItemStat.second;
			}
		}
	}



	ItemInventory_Consumable::GetInst()->LevelStartEvent();
	//AvataManager::GetInst()->ReadCharacterDataBase(nullptr);

}

void ItemInventory_Equipment::Update(float _DeltaTime)
{
	GamePlayInventory::Update(_DeltaTime);
	if (GameEngineInput::GetInst()->IsDown("LMouseCLK"))
	{
		if (Collision_InventoryTapOff->IsCollision(CollisionType::CT_AABB2D, CollisionOrder::UI_UIMouse, CollisionType::CT_AABB2D))
		{
			ItemInventory_Consumable::GetInst()->On();
			Off();
		}
	}


}

void ItemInventory_Equipment::OnEvent()
{

}


void ItemInventory_Equipment::LevelStartEvent()
{
	GamePlayInventory::LevelStartEvent();
	SetLevelStartItem<Item_Equipment>(GamePlayDataBase::GetCurrentCharacterData()->GetInventoryData(InventoryBag::Inventory_ItemInventory_Equipment));
	map_EquipmentstatUP.clear();
	
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

			for (auto& ItemStat : Item->map_Stat)
			{
				map_EquipmentstatUP[ItemStat.first] += ItemStat.second;
			}
			
		}
	}




	Off();
	Inst = this;
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
	Inst = nullptr;
}