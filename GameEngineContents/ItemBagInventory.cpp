#include "PreCompile.h"
#include <GameEngineBase/GameEngineInput.h>
#include "ItemBagInventory.h"

ItemBagInventory::ItemBagInventory()
	: Inventory_Window(nullptr)

{
}

ItemBagInventory::~ItemBagInventory() 
{
}

void ItemBagInventory::Start()
{

}

void ItemBagInventory::Update(float _DeltaTime)
{
	if (GameEngineInput::GetInst()->IsPress("LMouseCLK") == true)
	{
		float4 MousePos = GetLevel()->GetMainCamera()->GetMouseWorldDir();
		GetTransform().SetLocalMove(MousePos);
	}
}