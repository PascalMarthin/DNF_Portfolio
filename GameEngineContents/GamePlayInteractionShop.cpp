#include "PreCompile.h"
#include "GamePlayInteractionShop.h"
#include "GamePlayObjectNPC.h"
#include "GamePlayItem_DESC.h"

GamePlayInteractionShop::GamePlayInteractionShop() 
	: Texture_Window(nullptr)
	, map_SellList(nullptr)
{
}

GamePlayInteractionShop::~GamePlayInteractionShop() 
{
}

void GamePlayInteractionShop::Start()
{
	Texture_Window = CreateComponent<GameEngineUIRenderer>();
	Texture_Window->SetFolderTextureToIndex("Shop_Interface", 0);
	Texture_Window->GetTransform().SetLocalPosition({-200, 0, 1});
	Texture_Window->ScaleToTexture();
	Texture_Window->Off();


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
		Renderer->SetTexture(DESC->GetItemIcon());
		Renderer->ScaleToTexture();
		vector_ItemIcon.push_back(Renderer);

		Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->SetFolderTextureToIndex("shop_slot", 0);
		Renderer->SetPivot(PIVOTMODE::LEFTTOP);
		Renderer->GetTransform().SetLocalPosition({ -170.f * (x * 180.f), 200.f * (y * -57.f + 10.f )});
		Renderer->ScaleToTexture();
		vector_ItemSlot.push_back(Renderer);


		++x;
		if (x > 1)
		{
			++y; 
			x = 0;
		}
	}

	
}



void GamePlayInteractionShop::Update(float _DeltaTime)
{
	
}

void GamePlayInteractionShop::LevelStartEvent()
{
}
void GamePlayInteractionShop::LevelEndEvent()
{
}