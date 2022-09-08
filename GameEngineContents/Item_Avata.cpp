#include "PreCompile.h"
#include "Item_Avata.h"
#include "GamePlayItem_DESC.h"

Item_Avata::Item_Avata() 
	: Enum_AvataClass(AllAvataClass::None)
{
}

Item_Avata::~Item_Avata() 
{
}


void Item_Avata::Start()
{
	GamePlayItem::Start();

}

void Item_Avata::AfterSetDesc()
{
	Enum_AvataClass = FindAvataClass(Desc_ItemDesc->GetItemCode());
}

AllAvataClass Item_Avata::FindAvataClass(GamePlayItemCode _Code)
{
	int Code = static_cast<int>(_Code);
	AllAvataClass Class = AllAvataClass::None;

	// ~ 3199 ��Ʈ
// ~ 3399 ����
// ~ 3599 ����
// ~ 3799 ��
// ~ 3999 �Ӹ�
// ~ 4199 ��� - ���� - ��
// ~ 4399 ����
// ~ 4599 �Ź�
// ~ 4799 �Ǻ�
// ~ 4999 ����
	if (Code >= 3000 && Code < 5000)
	{
		if (Code < 3199)
		{
			Class = AllAvataClass::Belt;
		}
		else if(Code < 3399)
		{
			Class = AllAvataClass::Cap;
		}
		else if (Code < 3599)
		{
			Class = AllAvataClass::Coat;
			
		}
		else if (Code < 3799)
		{
			Class = AllAvataClass::Face;

		}
		else if (Code < 3999)
		{
			Class = AllAvataClass::Hair;

		}
		else if (Code < 4199)
		{
			Class = AllAvataClass::Neck;

		}
		else if (Code < 4399)
		{
			Class = AllAvataClass::Pants;

		}
		else if (Code < 4599)
		{
			Class = AllAvataClass::Shoes;
		}
		else if (Code < 4799)
		{
			Class = AllAvataClass::Skin;
		}
		else if (Code < 4999)
		{
			Class = AllAvataClass::Weapon;
		}
	}
	return Class;

}