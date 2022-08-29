#include "PreCompile.h"
#include "ItemInventory.h"
#include "GamePlayDataBase.h"

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
			for (int x = (-3); x < 4; x++)
			{
				GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>("Inventory_Blank");
				Renderer->SetTexture("Inventory_Blank.png");
				Renderer->ScaleToTexture();
				Renderer->GetTransform().SetLocalPosition({static_cast<float>(31 * x) - 10,static_cast<float>(31 * y) -12.f , 1});
				GameEngineCollision* Collision = CreateComponent<GameEngineCollision>();
				Collision->GetTransform().SetLocalScale(Renderer->GetTransform().GetLocalPosition().Half());
				Collision->GetTransform().SetLocalPosition(Renderer->GetTransform().GetLocalPosition());
				Collision->SetDebugSetting(CollisionType::CT_AABB2D, {0.5f, 0.5f, 0, 0.5f});


				Inventory_Blank[{x + 4, y}].Collision_Blank = Collision;
				Inventory_Blank[{x + 4, y}].Texture_Blank = Renderer;
			}
		}
	}
	
}

void ItemInventory::Update(float _DeltaTime)
{
	//GameEngineDebug::OutPutString(std::to_string(Texture_Inventory->GetTransform().GetLocalPosition().x) + " / " + std::to_string(Texture_Inventory->GetTransform().GetLocalPosition().y) + " / " + std::to_string(Texture_Inventory->GetTransform().GetLocalPosition().z));
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
}
void ItemInventory::LevelStartEvent()
{
	SetLevelStartItem(GamePlayDataBase::GetCurrentCharacterData()->GetInventoryData(InventoryBag::Inventory_ItemInventory_Equipment));
	

}

void ItemInventory::LevelEndEvent()
{
	for (auto& Blank : Inventory_CurrentItem)
	{
		Blank.second.Texture_Blank->Death();
		Blank.second.Collision_Blank->Death();
	}
}