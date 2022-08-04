#include "PreCompile.h"
#include "GamePlayDataBase.h"

GamePlayDataBase::GamePlayDataBase(CharacterFormerClass _Class, const std::string& _Name)
	: Enum_FormerClass(_Class)
	, NickName(_Name)
{
}

GamePlayDataBase::~GamePlayDataBase() 
{
	if (!DataBase_InventoryData.empty())
	{
		for (auto& ItemData : DataBase_InventoryData)
		{
			for (auto& InventoryDataIter : ItemData.second)
			{
				delete InventoryDataIter;
			}
		}
		DataBase_InventoryData.clear();
	}
}

