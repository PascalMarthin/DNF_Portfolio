#include "PreCompile.h"
#include "ItemInventory_Consumable.h"
#include "GamePlayDataBase.h"
#include "GamePlayItem.h"
#include "MouseCursorComponent.h"
#include "Item_Consumable.h"
#include "CharacterStatManager.h"
#include "ItemInventory_Equipment.h"
#include "GameEngineUIFontRenderer.h"
#include "Item_Equipment.h"

ItemInventory_Consumable* ItemInventory_Consumable::Inst = nullptr;

ItemInventory_Consumable::ItemInventory_Consumable()
	: Collision_InventoryTapOff(nullptr)

{
}

ItemInventory_Consumable::~ItemInventory_Consumable() 
{
}

void ItemInventory_Consumable::Start()
{
	Texture_Inventory = CreateComponent<GameEngineUIRenderer>("ItemInventory_Consumable");
	Texture_Inventory->SetTexture("Window_Iteminventory.png");
	Texture_Inventory->ScaleToTexture();
	Texture_Inventory->GetTransform().SetLocalPosition({ 0, 0, 10 });
	//Texture_Inventory->GetPixelData().MulColor = { 1, 1, 1, 0.8f };


	{
		Collision_WindowInventory = CreateComponent<GameEngineCollision>();
		Collision_WindowInventory->GetTransform().SetLocalPosition({ 0, 258 , 0});
		Collision_WindowInventory->GetTransform().SetLocalScale({ 258, 23 , 0 });
		Collision_WindowInventory->SetDebugSetting(CollisionType::CT_AABB, float4::BLUE);
		//Collision_WindowInventory->SetParent(Texture_Inventory);
	}

	{
		GameEngineUIRenderer* Texture = CreateComponent<GameEngineUIRenderer>();
		Texture->SetTexture("Window_InventoryTapOn.png");
		Texture->GetTransform().SetLocalPosition({ -59, 20 });
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
		Texture->GetTransform().SetLocalPosition({-100, 20});

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
				Collision->GetTransform().SetLocalScale(Renderer->GetTransform().GetLocalScale() * 0.125f);
				Collision->GetTransform().SetLocalPosition(Renderer->GetTransform().GetLocalPosition());
				Collision->SetDebugSetting(CollisionType::CT_AABB2D, {0.5f, 0.5f, 0, 0.5f});
				Collision->ChangeOrder(CollisionOrder::UI_InventoryBlank);

				//Renderer->GetPixelData().MulColor = { 1, 1, 1, 0.5f };
				

				Inventory_Blank[x + 3 + y * -8].Collision_Blank = Collision;
				Inventory_Blank[x + 3 + y * -8].Texture_Blank = Renderer;
			}
		}
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

void ItemInventory_Consumable::Update(float _Time)
{
	GamePlayInventory::Update(_Time);
	if (GameEngineInput::GetInst()->IsDown("LMouseCLK"))
	{
		if (Collision_InventoryTapOff->IsCollision(CollisionType::CT_AABB2D, CollisionOrder::UI_UIMouse, CollisionType::CT_AABB2D))
		{
			ItemInventory_Equipment::GetInst()->On();
			Off();
		}
	}

	
}

void ItemInventory_Consumable::Mouse_RClick(GamePlayItem* _Item)
{
	//unsigned int Pos = FindGamePlayItem(_Item);
	Item_Consumable* Consumable = dynamic_cast<Item_Consumable*>(_Item);
	Consumable->Item_Effect(CharacterStatManager::GetInst());
	Consumable->

	///*if (Pos == -1 )
	//{
	//	{
	//		if (FromItem == nullptr)
	//		{
	//			MsgBoxAssert("?????????????????!!??")
	//		}
	//	}
	//}*/




}

void ItemInventory_Consumable::OnEvent()
{

}


void ItemInventory_Consumable::LevelStartEvent()
{
	GamePlayInventory::LevelStartEvent();
	SetLevelStartItem<Item_Consumable>(GamePlayDataBase::GetCurrentCharacterData()->GetInventoryData(InventoryBag::Inventory_ItemInventory_Consumable));

	for (auto& GameItem : All_WearEquipment_Texture)
	{
		if (GameItem.second != nullptr)
		{
			GameItem.second->Death();
			GameItem.second = nullptr;
		}
	}
	All_WearEquipment_Texture.clear();

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

	Inst = this;
}

void ItemInventory_Consumable::LevelEndEvent()
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