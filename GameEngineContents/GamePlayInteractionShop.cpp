#include "PreCompile.h"
#include "GamePlayInteractionShop.h"
#include "GamePlayObjectNPC.h"
#include "GamePlayItem_DESC.h"
#include "GameEngineUIFontRenderer.h"
#include "GamePlayDataBase.h"
#include "GamePlayCharacter.h"

GamePlayInteractionShop::GamePlayInteractionShop() 
	: Texture_Window(nullptr)
	, map_SellList(nullptr)
	, Current_Collision(nullptr)
	, Current_DESC(nullptr)
	, Texture_OutLine(nullptr)
{
}

GamePlayInteractionShop::~GamePlayInteractionShop() 
{
}

void GamePlayInteractionShop::Start()
{
	Texture_Window = CreateComponent<GameEngineUIRenderer>();
	Texture_Window->SetFolderTextureToIndex("Shop_Interface", 0);
	Texture_Window->GetTransform().SetLocalPosition({0, 0, 1});
	Texture_Window->ScaleToTexture();
	Texture_Window->Off();
	GetTransform().SetLocalPosition({ -380, 0, 1 });

	Texture_OutLine = CreateComponent<GameEngineUIRenderer>();
	Texture_OutLine->SetFolderTextureToIndex("shop_slot", 1);
	Texture_OutLine->GetTransform().SetLocalPosition({ 0, 0, 1.0001f });
	Texture_OutLine->ScaleToTexture();
	Texture_OutLine->SetPivot(PIVOTMODE::LEFTTOP);
	Texture_OutLine->Off();

	Off();

}
void GamePlayInteractionShop::SetShopData(GamePlayObjectNPC* _NPC)
{
	map_SellList = nullptr;
	if (_NPC->map_SellItemList.size() == 0)
	{
		return;
	}

	Texture_Window->On();
	map_SellList = &_NPC->map_SellItemList;

	float x = 0;
	float y = 0;
	for (auto& Item : (*map_SellList))
	{
		GamePlayItem_DESC* DESC = GamePlayItem_DESC::Find(Item.first);


		GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->SetFolderTextureToIndex("shop_slot", 4);
		Renderer->ScaleToTexture();
		Renderer->SetPivot(PIVOTMODE::LEFTTOP);
		Renderer->GetTransform().SetLocalPosition({ -110.f + (x * 180.f) + 25.f, 190.f + (y * -77.f - 15.f) - 6.f, -0.0001f });
		vector_ItemSlot.push_back(Renderer);


		Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->SetTexture(DESC->GetItemIcon());
		Renderer->ScaleToTexture();
		Renderer->SetPivot(PIVOTMODE::LEFTTOP);
		Renderer->GetTransform().SetLocalPosition({ -200.f + (x * 180.f) + 25.f, 220.f + (y * -77.f - 15.f) - 6.f, -0.0001f });
		vector_ItemIcon.push_back(Renderer);

		Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->SetFolderTextureToIndex("shop_slot", 0);
		Renderer->SetPivot(PIVOTMODE::LEFTTOP);
		Renderer->GetTransform().SetLocalPosition({ -200.f + (x * 180.f) + 20.f, 220.f + (y * -77.f - 15.f),  });// 
		Renderer->ScaleToTexture();
		vector_ItemSlot.push_back(Renderer);

		map_RendererCode[Renderer] = DESC;


		GameEngineCollision* Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({ 165, 57 });
		Collision->GetTransform().SetLocalPosition({ -200.f + (x * 180.f) + 20.f + 82.5f, 220.f + (y * -77.f - 15.f) - 28.5f });
		Collision->ChangeOrder(CollisionOrder::UI_InventoryBlank);
		vector_Collision.push_back(Collision);
		map_CollisionRenderer[Collision] = Renderer;



		GameEngineUIFontRenderer* Font = CreateComponent<GameEngineUIFontRenderer>();
		Font->SetPositionMode(FontPositionMode::WORLD);
		Font->GetTransform().SetLocalPosition({ -50.f + (x * 180.f) + 25.f, 190.f + (y * -77.f - 15.f) -6.f });
		Font->SetColor({ 1.0f, 1.0f, 1.0f, 1.0 });
		Font->SetRenderingOrder(10000);
		Font->SetSize(12);
		Font->SetTopAndBotSort(TopAndBotSort::TOP);
		Font->SetLeftAndRightSort(LeftAndRightSort::RIGHT);
		Font->SetText(std::to_string(Item.second), "±¼¸²");



		////Renderer = CreateComponent<GameEngineUIRenderer>();
		////Renderer->SetFolderTextureToIndex("Money", 1);
		////Renderer->ScaleToTexture();
		////Renderer->SetPivot(PIVOTMODE::LEFTTOP);
		////Renderer->GetTransform().SetLocalPosition({ -120.f + (x * 180.f) + 25.f, 190.f + (y * -77.f - 15.f) - 6.f });
		////vector_ItemIcon.push_back(Renderer);
		
		
		++x;
		if (x > 1)
		{
			++y; 
			x = 0;
		}
	}

	Texture_OutLine->Off();

}



void GamePlayInteractionShop::Update(float _DeltaTime)
{

	if (GameEngineInput::GetInst()->IsDown("LMouseCLK"))
	{
		Texture_OutLine->Off();
		Current_Collision = nullptr;
		Current_DESC = nullptr;
		for (GameEngineCollision* Coliision : vector_Collision)
		{
			if (Coliision->IsCollision(CollisionType::CT_AABB2D, CollisionOrder::UI_UIMouse, CollisionType::CT_AABB2D,
				std::bind(&GamePlayInteractionShop::CheckCollision, this, std::placeholders::_1, std::placeholders::_2)))
			{
				Current_DESC = map_RendererCode[map_CollisionRenderer[Current_Collision]];
				Texture_OutLine->GetTransform().SetLocalPosition(map_CollisionRenderer[Current_Collision]->GetTransform().GetLocalPosition());
				Texture_OutLine->On();
				break;
			}
		}
	}
	else if (GameEngineInput::GetInst()->IsDown("Enter"))
	{
		GamePlayCharacter::GetCurrentCharacterData()->SetGold((*map_SellList)[Current_DESC->GetItemCode()]);
		GamePlayCharacter::GetCurrentCharacterData()->CreateItem(Current_DESC->GetItemCode(), 1);
		//GamePlayCharacter::GetInst()->inven
	}

}

CollisionReturn GamePlayInteractionShop::CheckCollision(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	Current_Collision = _This;


	return CollisionReturn::Break;
}

void GamePlayInteractionShop::LevelStartEvent()
{
}
void GamePlayInteractionShop::LevelEndEvent()
{
}