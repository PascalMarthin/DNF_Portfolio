#include "PreCompile.h"
#include "Item_Equipment.h"
#include "GamePlayItem_DESC.h"
#include "GamePlayDataBase.h"

Item_Equipment::Item_Equipment() 
	: Enum_EquipmentClass(AllEquipmentClass::None)
	, AddDamage(0)
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
	SetStatClass(Desc_ItemDesc->GetItemCode());
}

void Item_Equipment::SetStatClass(GamePlayItemCode _Code)
{
	switch (_Code)
	{
	case GamePlayItemCode::Debug_Weapon:
		map_Stat[StatClass::Physical_Damage] = 99999999;
		break;
	case GamePlayItemCode::Tropica_Coat:
		map_Stat[StatClass::MAXHP] = 800000;
		break;
	case GamePlayItemCode::Tropica_Belt:
		map_Stat[StatClass::Physical_Armor] = 100000;
		break;
	case GamePlayItemCode::Tropica_Pants:
		map_Stat[StatClass::MAXHP] = 50000;
		AddDamage = 0.03f;
		break;
	case GamePlayItemCode::Tropica_Neck:
		map_Stat[StatClass::Physical_Armor] = 5000;
		AddDamage = 0.04f;
		break;
	case GamePlayItemCode::Tropica_Shoes:
		AddDamage = 0.05f;
		break;
	default:
		break;
	}
}

float Item_Equipment::FindAddDamage(GamePlayItemCode _Code)
{
	float a = 0;
	switch (_Code)
	{
	case GamePlayItemCode::Debug_Weapon:
		break;
	case GamePlayItemCode::Tropica_Coat:

		break;
	case GamePlayItemCode::Tropica_Belt:
	
		break;
	case GamePlayItemCode::Tropica_Pants:

		a = 0.03f;
		break;
	case GamePlayItemCode::Tropica_Neck:

		a = 0.04f;
		break;
	case GamePlayItemCode::Tropica_Shoes:
		a = 0.05f;
		break;
	default:
		break;
	}
	return a;
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