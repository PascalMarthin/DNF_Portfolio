#include "PreCompile.h"
#include "GamePlayItem.h"

std::map<GamePlayItemCode, GamePlayItem_DESC*> GamePlayItem_DESC::AllItem_DESC;

void GamePlayItem_DESC::CreateALLItemData()
{
	if (GamePlayItem_DESC::AllItem_DESC.empty() == false)
	{
		return;
	}

	{
		AllItem_DESC[GamePlayItemCode::Fighter_F_Default_Belt] = new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Default_Belt, GamePlayItemRate::Common, "Fighter_F_Default_Belt");
		AllItem_DESC[GamePlayItemCode::Fighter_F_Default_Cap] =   new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Default_Cap,  GamePlayItemRate::Common, "Fighter_F_Default_Cap");
		AllItem_DESC[GamePlayItemCode::Fighter_F_Default_Coat] =  new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Default_Coat, GamePlayItemRate::Common, "Fighter_F_Default_Coat");
		AllItem_DESC[GamePlayItemCode::Fighter_F_Default_Face] =  new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Default_Face, GamePlayItemRate::Common, "Fighter_F_Default_Face");
		AllItem_DESC[GamePlayItemCode::Fighter_F_Default_Hair] =  new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Default_Hair, GamePlayItemRate::Common, "Fighter_F_Default_Hair");
		AllItem_DESC[GamePlayItemCode::Fighter_F_Default_Neck] =  new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Default_Neck, GamePlayItemRate::Common, "Fighter_F_Default_Neck");
		AllItem_DESC[GamePlayItemCode::Fighter_F_Default_Pants] = new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Default_Pants,GamePlayItemRate::Common, "Fighter_F_Default_Pants");
		AllItem_DESC[GamePlayItemCode::Fighter_F_Default_Shoes] = new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Default_Shoes,GamePlayItemRate::Common, "Fighter_F_Default_Shoes");
		AllItem_DESC[GamePlayItemCode::Fighter_F_Default_Skin] =  new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Default_Skin, GamePlayItemRate::Common, "Fighter_F_Default_Skin");
	}
														


	//AllItem_DESC[GamePlayItemCode::Fighter_F_Default_Belt] = new GamePlayItem_DESC();
}

void GamePlayItem_DESC::DestoryALLItemData()
{
	for (auto& DESC : AllItem_DESC)
	{
		if (DESC.second != nullptr)
		{
			delete DESC.second;
			DESC.second = nullptr;
		}
	}
	AllItem_DESC.clear();
}

inline GamePlayItem_DESC* GamePlayItem_DESC::Find(GamePlayItemCode _Code)
{
	return AllItem_DESC[_Code];
}

GamePlayItemType GamePlayItem_DESC::CheckItemType(GamePlayItemCode _Code)
{
	GamePlayItemType IndexType = GamePlayItemType::Unknown;

	{
		int IntType = static_cast<int>(_Code);
		if (0 <= IntType && IntType < 100)
		{
			IndexType = GamePlayItemType::Debug;
		}
		else if (100 <= IntType && IntType < 5000)
		{
			if (100 <= IntType && IntType < 1000)
			{
				IndexType = GamePlayItemType::Equipment;
			}
			if (1000 <= IntType && IntType < 2000)
			{
				IndexType = GamePlayItemType::Stuff;
			}
			if (2000 <= IntType && IntType < 3000)
			{
				IndexType = GamePlayItemType::Consumable;
			}
			if (3000 <= IntType && IntType < 4000)
			{
				IndexType = GamePlayItemType::Avatar;
			}
			if (4000 <= IntType && IntType < 5000)
			{
				IndexType = GamePlayItemType::Pet;
			}

		}
	}
	//    0 ~   99 디버그
	//  100 ~  999 장비
	// 1000 ~ 1999 재료
	// 2000 ~ 2999 소비
	// 3000 ~ 3999 아바타
	// 4000 ~ 4999 펫
	return IndexType;
}