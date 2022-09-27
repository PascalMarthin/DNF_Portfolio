#include "PreCompile.h"
#include "AvataInventory.h"
#include "GamePlayDataBase.h"
#include "GamePlayItem.h"
#include "MouseCursorComponent.h"
#include "GamePlayItem_DESC.h"
#include "Item_Avata.h"
#include "AvataManager.h"

AvataInventory* AvataInventory::Inst = nullptr;
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
	//unsigned int Pos = FindGamePlayItem(_Item);
	Item_Avata* Avata = dynamic_cast<Item_Avata*>(_Item);
	GamePlayItem* FromItem = All_WearAvata_Texture[All_WearAvata_Type[Avata->Enum_AvataClass]];
	///*if (Pos == -1 )
	//{
	//	{
	//		if (FromItem == nullptr)
	//		{
	//			MsgBoxAssert("?????????????????!!??")
	//		}
	//	}
	//}*/


	if (FromItem == _Item) // 자기 자신 해제
	{
		unsigned int FromPos = MoveItemToInventory(-1, Inventory_CurrentData[_Item], InventoryBag::Inventory_Avata, InventoryBag::Inventory_Avata_Wear);
		All_WearAvata_Texture[All_WearAvata_Type[Avata->Enum_AvataClass]] = nullptr;
		Inventory_CurrentItem[FromPos] = _Item;
		_Item->SetUITextureTransform(Inventory_Blank[FromPos].Collision_Blank);

	}
	else // 타 아바타
	{
		All_WearAvata_Texture[All_WearAvata_Type[Avata->Enum_AvataClass]] = Avata;
		unsigned int FromPos = MoveItemToInventory(static_cast<int>(Avata->Enum_AvataClass), Inventory_CurrentData[_Item], InventoryBag::Inventory_Avata_Wear, InventoryBag::Inventory_Avata);

		Avata->SetUITextureTransform(All_WearAvata_Type[Avata->Enum_AvataClass]);
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
	AvataManager::GetInst()->ReadCharacterDataBase(nullptr);

}

void AvataInventory::OnEvent()
{
	
}


void AvataInventory::LevelStartEvent()
{
	GamePlayInventory::LevelStartEvent();
	SetLevelStartItem<Item_Avata>(GamePlayDataBase::GetCurrentCharacterData()->GetInventoryData(InventoryBag::Inventory_Avata));

	{
		std::vector<InventoryData*>& WearingAvata = GamePlayDataBase::GetCurrentCharacterData()->GetInventoryData(InventoryBag::Inventory_Avata_Wear);
		for (int i = 0; i < WearingAvata.size(); i++)
		{
			//
			if (WearingAvata[i] == nullptr)
			{
				continue;
			}

			Item_Avata* Item = CreateComponent<Item_Avata>("GamePlayItem");
			Item->SetDESC(WearingAvata[i]->Item_DESC);
			Item->SetUITextureTransform(All_WearAvata_Type[static_cast<AllAvataClass>(i)]);
			Inventory_CurrentData[Item] = WearingAvata[i];
			All_WearAvata_Texture[All_WearAvata_Type[static_cast<AllAvataClass>(i)]] = Item;
		}
	}




	Off();
	Inst = this;
}

void AvataInventory::LevelEndEvent()
{
	for (auto& GameItem : All_WearAvata_Texture)
	{
		if (GameItem.second != nullptr)
		{
			GameItem.second->Death();
			GameItem.second = nullptr;
		}
	}

	All_WearAvata_Texture.clear();


	GamePlayInventory::LevelEndEvent();
	Inst = nullptr;
}