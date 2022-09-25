#include "PreCompile.h"
#include "Item_Equipment.h"
#include "GamePlayItem_DESC.h"

Item_Equipment::Item_Equipment() 
	: Enum_EquipmentClass(AllEquipmentClass::None)
{
}

Item_Equipment::~Item_Equipment() 
{
}

void Item_Equipment::Start()
{
	GamePlayItem::Start();

}

void Item_Equipment::AfterSetDesc()
{
	Enum_EquipmentClass = FindAvataClass(Desc_ItemDesc->GetItemCode());
}

AllEquipmentClass Item_Equipment::FindAvataClass(GamePlayItemCode _Code)
{
	int Code = static_cast<int>(_Code);
	AllEquipmentClass Class = AllEquipmentClass::None;

	//  100 ~  999 Àåºñ
	if (Code >= 100 && Code < 999)
	{
		if (Code < 110)
		{
			Class = AllEquipmentClass::Neck;
		}
		else if (Code < 120)
		{
			Class = AllEquipmentClass::Coat;
		}
		else if (Code < 130)
		{
			Class = AllEquipmentClass::Belt;

		}
		else if (Code < 140)
		{
			Class = AllEquipmentClass::Pants;
		}
		else if (Code < 150)
		{
			Class = AllEquipmentClass::Shoes;
		}
		else if (Code < 160)
		{
			Class = AllEquipmentClass::Weapon;
		}
	}
	return Class;

}