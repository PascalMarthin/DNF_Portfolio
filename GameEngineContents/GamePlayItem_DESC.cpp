#include "PreCompile.h"
#include "GamePlayItem.h"
#include "AvataManager.h"
#include "GamePlayItem_DESC.h"

GamePlayItem_DESC::~GamePlayItem_DESC() 
{
}


std::map<GamePlayItemCode, GamePlayItem_DESC*> GamePlayItem_DESC::AllItem_DESC;

void GamePlayItem_DESC::CreateALLItemData()
{
	if (GamePlayItem_DESC::AllItem_DESC.empty() == false)
	{
		return;
	}


	AllItem_DESC[GamePlayItemCode::Level1Up] = new GamePlayItem_DESC(GamePlayItemCode::Level1Up, GamePlayItemRate::Rare, "Level1Up", "Item_Level1Up.png");

	AllItem_DESC[GamePlayItemCode::Equipment_Upgrade12] = new GamePlayItem_DESC(GamePlayItemCode::Equipment_Upgrade12, GamePlayItemRate::Unique, "Equipment_Upgrade12", "Equipment_Upgrade12.png");
	
	AllItem_DESC[GamePlayItemCode::Fighter_F_Belt_7st_Red		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Belt_7st_Red, GamePlayItemRate::Rare, "Fighter_F_Belt_7st_Red", "Fighter_F_Belt_7st_Red.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Belt_7st_Blue		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Belt_7st_Blue, GamePlayItemRate::Rare, "Fighter_F_Belt_7st_Blue", "Fighter_F_Belt_7st_Blue.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Belt_7st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Belt_7st_Gold, GamePlayItemRate::Rare, "Fighter_F_Belt_7st_Gold", "Fighter_F_Belt_7st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Belt_4st_White		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Belt_4st_White, GamePlayItemRate::Rare, "Fighter_F_Belt_4st_White", "Fighter_F_Belt_4st_White.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Belt_4st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Belt_4st_Gold, GamePlayItemRate::Rare, "Fighter_F_Belt_4st_Gold", "Fighter_F_Belt_4st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Belt_4st_Blue		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Belt_4st_Blue, GamePlayItemRate::Rare, "Fighter_F_Belt_4st_Blue", "Fighter_F_Belt_4st_Blue.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Belt_9st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Belt_9st_Gold, GamePlayItemRate::Rare, "Fighter_F_Belt_9st_Gold", "Fighter_F_Belt_9st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Belt_9st_Purple	 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Belt_9st_Purple, GamePlayItemRate::Rare, "Fighter_F_Belt_9st_Purple", "Fighter_F_Belt_9st_Purple.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Belt_Former_Striker ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Belt_Former_Striker, GamePlayItemRate::Rare, "Fighter_F_Belt_Former_Striker", "Fighter_F_Belt_Former_Striker.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Cap_7st_Red		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Cap_7st_Red, GamePlayItemRate::Rare, "Fighter_F_Cap_7st_Red", "Fighter_F_Cap_7st_Red.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Cap_7st_Blue		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Cap_7st_Blue, GamePlayItemRate::Rare, "Fighter_F_Cap_7st_Blue", "Fighter_F_Cap_7st_Blue.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Cap_7st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Cap_7st_Gold, GamePlayItemRate::Rare, "Fighter_F_Cap_7st_Gold", "Fighter_F_Cap_7st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Cap_4st_White		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Cap_4st_White, GamePlayItemRate::Rare, "Fighter_F_Cap_4st_White", "Fighter_F_Cap_4st_White.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Cap_4st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Cap_4st_Gold, GamePlayItemRate::Rare, "Fighter_F_Cap_4st_Gold", "Fighter_F_Cap_4st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Cap_4st_Blue		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Cap_4st_Blue, GamePlayItemRate::Rare, "Fighter_F_Cap_4st_Blue", "Fighter_F_Cap_4st_Blue.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Cap_9st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Cap_9st_Gold, GamePlayItemRate::Rare, "Fighter_F_Cap_9st_Gold", "Fighter_F_Cap_9st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Cap_9st_Purple		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Cap_9st_Purple, GamePlayItemRate::Rare, "Fighter_F_Cap_9st_Purple", "Fighter_F_Cap_9st_Purple.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Cap_Former_Striker	 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Cap_Former_Striker, GamePlayItemRate::Rare, "Fighter_F_Cap_Former_Striker", "Fighter_F_Cap_Former_Striker.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Coat_7st_Red		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Coat_7st_Red, GamePlayItemRate::Rare, "Fighter_F_Coat_7st_Red", "Fighter_F_Coat_7st_Red.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Coat_7st_Blue		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Coat_7st_Blue, GamePlayItemRate::Rare, "Fighter_F_Coat_7st_Blue", "Fighter_F_Coat_7st_Blue.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Coat_7st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Coat_7st_Gold, GamePlayItemRate::Rare, "Fighter_F_Coat_7st_Gold", "Fighter_F_Coat_7st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Coat_4st_White		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Coat_4st_White, GamePlayItemRate::Rare, "Fighter_F_Coat_4st_White", "Fighter_F_Coat_4st_White.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Coat_4st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Coat_4st_Gold, GamePlayItemRate::Rare, "Fighter_F_Coat_4st_Gold", "Fighter_F_Coat_4st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Coat_4st_Blue		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Coat_4st_Blue, GamePlayItemRate::Rare, "Fighter_F_Coat_4st_Blue", "Fighter_F_Coat_4st_Blue.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Coat_9st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Coat_9st_Gold, GamePlayItemRate::Rare, "Fighter_F_Coat_9st_Gold", "Fighter_F_Coat_9st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Coat_9st_Purple	 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Coat_9st_Purple, GamePlayItemRate::Rare, "Fighter_F_Coat_9st_Purple", "Fighter_F_Coat_9st_Purple.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Coat_Former_Striker ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Coat_Former_Striker, GamePlayItemRate::Rare, "Fighter_F_Coat_Former_Striker", "Fighter_F_Coat_Former_Striker.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Face_7st_Red		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Face_7st_Red, GamePlayItemRate::Rare, "Fighter_F_Face_7st_Red", "Fighter_F_Face_7st_Red.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Face_7st_Blue		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Face_7st_Blue, GamePlayItemRate::Rare, "Fighter_F_Face_7st_Blue", "Fighter_F_Face_7st_Blue.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Face_7st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Face_7st_Gold, GamePlayItemRate::Rare, "Fighter_F_Face_7st_Gold", "Fighter_F_Face_7st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Face_4st_White		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Face_4st_White, GamePlayItemRate::Rare, "Fighter_F_Face_4st_White", "Fighter_F_Face_4st_White.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Face_4st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Face_4st_Gold, GamePlayItemRate::Rare, "Fighter_F_Face_4st_Gold", "Fighter_F_Face_4st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Face_4st_Blue		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Face_4st_Blue, GamePlayItemRate::Rare, "Fighter_F_Face_4st_Blue", "Fighter_F_Face_4st_Blue.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Face_9st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Face_9st_Gold, GamePlayItemRate::Rare, "Fighter_F_Face_9st_Gold", "Fighter_F_Face_9st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Face_9st_Purple	 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Face_9st_Purple, GamePlayItemRate::Rare, "Fighter_F_Face_9st_Purple", "Fighter_F_Face_9st_Purple.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Face_Former_Striker ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Face_Former_Striker, GamePlayItemRate::Rare, "Fighter_F_Face_Former_Striker", "Fighter_F_Face_Former_Striker.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Hair_7st_Red		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Hair_7st_Red, GamePlayItemRate::Rare, "Fighter_F_Hair_7st_Red", "Fighter_F_Hair_7st_Red.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Hair_7st_Blue		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Hair_7st_Blue, GamePlayItemRate::Rare, "Fighter_F_Hair_7st_Blue", "Fighter_F_Hair_7st_Blue.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Hair_7st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Hair_7st_Gold, GamePlayItemRate::Rare, "Fighter_F_Hair_7st_Gold", "Fighter_F_Hair_7st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Hair_4st_White		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Hair_4st_White, GamePlayItemRate::Rare, "Fighter_F_Hair_4st_White", "Fighter_F_Hair_4st_White.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Hair_4st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Hair_4st_Gold, GamePlayItemRate::Rare, "Fighter_F_Hair_4st_Gold", "Fighter_F_Hair_4st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Hair_4st_Blue		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Hair_4st_Blue, GamePlayItemRate::Rare, "Fighter_F_Hair_4st_Blue", "Fighter_F_Hair_4st_Blue.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Hair_9st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Hair_9st_Gold, GamePlayItemRate::Rare, "Fighter_F_Hair_9st_Gold", "Fighter_F_Hair_9st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Hair_9st_Purple	 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Hair_9st_Purple, GamePlayItemRate::Rare, "Fighter_F_Hair_9st_Purple", "Fighter_F_Hair_9st_Purple.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Hair_Former_Striker ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Hair_Former_Striker, GamePlayItemRate::Rare, "Fighter_F_Hair_Former_Striker", "Fighter_F_Hair_Former_Striker.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Neck_7st_Red		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Neck_7st_Red, GamePlayItemRate::Rare, "Fighter_F_Neck_7st_Red", "Fighter_F_Neck_7st_Red.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Neck_7st_Blue		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Neck_7st_Blue, GamePlayItemRate::Rare, "Fighter_F_Neck_7st_Blue", "Fighter_F_Neck_7st_Blue.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Neck_7st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Neck_7st_Gold, GamePlayItemRate::Rare, "Fighter_F_Neck_7st_Gold", "Fighter_F_Neck_7st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Neck_4st_White		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Neck_4st_White, GamePlayItemRate::Rare, "Fighter_F_Neck_4st_White", "Fighter_F_Neck_4st_White.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Neck_4st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Neck_4st_Gold, GamePlayItemRate::Rare, "Fighter_F_Neck_4st_Gold", "Fighter_F_Neck_4st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Neck_4st_Blue		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Neck_4st_Blue, GamePlayItemRate::Rare, "Fighter_F_Neck_4st_Blue", "Fighter_F_Neck_4st_Blue.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Neck_9st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Neck_9st_Gold, GamePlayItemRate::Rare, "Fighter_F_Neck_9st_Gold", "Fighter_F_Neck_9st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Neck_9st_Purple	 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Neck_9st_Purple, GamePlayItemRate::Rare, "Fighter_F_Neck_9st_Purple", "Fighter_F_Neck_9st_Purple.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Neck_Former_Striker ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Neck_Former_Striker, GamePlayItemRate::Rare, "Fighter_F_Neck_Former_Striker", "Fighter_F_Neck_Former_Striker.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Pants_7st_Red		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Pants_7st_Red, GamePlayItemRate::Rare, "Fighter_F_Pants_7st_Red", "Fighter_F_Pants_7st_Red.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Pants_7st_Blue		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Pants_7st_Blue, GamePlayItemRate::Rare, "Fighter_F_Pants_7st_Blue", "Fighter_F_Pants_7st_Blue.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Pants_7st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Pants_7st_Gold, GamePlayItemRate::Rare, "Fighter_F_Pants_7st_Gold", "Fighter_F_Pants_7st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Pants_4st_White	 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Pants_4st_White, GamePlayItemRate::Rare, "Fighter_F_Pants_4st_White", "Fighter_F_Pants_4st_White.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Pants_4st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Pants_4st_Gold, GamePlayItemRate::Rare, "Fighter_F_Pants_4st_Gold", "Fighter_F_Pants_4st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Pants_4st_Blue		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Pants_4st_Blue, GamePlayItemRate::Rare, "Fighter_F_Pants_4st_Blue", "Fighter_F_Pants_4st_Blue.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Pants_9st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Pants_9st_Gold, GamePlayItemRate::Rare, "Fighter_F_Pants_9st_Gold", "Fighter_F_Pants_9st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Pants_9st_Purple	 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Pants_9st_Purple, GamePlayItemRate::Rare, "Fighter_F_Pants_9st_Purple", "Fighter_F_Pants_9st_Purple.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Pants_Former_Striker]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Pants_Former_Striker, GamePlayItemRate::Rare, "Fighter_F_Pants_Former_Striker", "Fighter_F_Pants_Former_Striker.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Shoes_7st_Red 		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Shoes_7st_Red, GamePlayItemRate::Rare, "Fighter_F_Shoes_7st_Red", "Fighter_F_Shoes_7st_Red.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Shoes_7st_Blue		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Shoes_7st_Blue, GamePlayItemRate::Rare, "Fighter_F_Shoes_7st_Blue", "Fighter_F_Shoes_7st_Blue.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Shoes_7st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Shoes_7st_Gold, GamePlayItemRate::Rare, "Fighter_F_Shoes_7st_Gold", "Fighter_F_Shoes_7st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Shoes_4st_White	 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Shoes_4st_White, GamePlayItemRate::Rare, "Fighter_F_Shoes_4st_White", "Fighter_F_Shoes_4st_White.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Shoes_4st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Shoes_4st_Gold, GamePlayItemRate::Rare, "Fighter_F_Shoes_4st_Gold", "Fighter_F_Shoes_4st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Shoes_4st_Blue		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Shoes_4st_Blue, GamePlayItemRate::Rare, "Fighter_F_Shoes_4st_Blue", "Fighter_F_Shoes_4st_Blue.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Shoes_9st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Shoes_9st_Gold, GamePlayItemRate::Rare, "Fighter_F_Shoes_9st_Gold", "Fighter_F_Shoes_9st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Shoes_9st_Purple	 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Shoes_9st_Purple, GamePlayItemRate::Rare, "Fighter_F_Shoes_9st_Purple", "Fighter_F_Shoes_9st_Purple.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Shoes_Former_Striker]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Shoes_Former_Striker, GamePlayItemRate::Rare, "Fighter_F_Shoes_Former_Striker", "Fighter_F_Shoes_Former_Striker.png");
//	AllItem_DESC[GamePlayItemCode::Equipment_Upgrade12] = new GamePlayItem_DESC(GamePlayItemCode::Equipment_Upgrade12, GamePlayItemRate::Unique, "Equipment_Upgrade12", "Equipment_Upgrade12.png");


	{
		//AllItem_DESC[GamePlayItemCode::Fighter_F_Default_Belt] = new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Default_Belt, GamePlayItemRate::Common, "Fighter_F_Default_Belt");
		//AllItem_DESC[GamePlayItemCode::Fighter_F_Default_Cap] =   new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Default_Cap,  GamePlayItemRate::Common, "Fighter_F_Default_Cap");
		//AllItem_DESC[GamePlayItemCode::Fighter_F_Default_Coat] =  new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Default_Coat, GamePlayItemRate::Common, "Fighter_F_Default_Coat");
		//AllItem_DESC[GamePlayItemCode::Fighter_F_Default_Face] =  new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Default_Face, GamePlayItemRate::Common, "Fighter_F_Default_Face");
		//AllItem_DESC[GamePlayItemCode::Fighter_F_Default_Hair] =  new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Default_Hair, GamePlayItemRate::Common, "Fighter_F_Default_Hair");
		//AllItem_DESC[GamePlayItemCode::Fighter_F_Default_Neck] =  new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Default_Neck, GamePlayItemRate::Common, "Fighter_F_Default_Neck");
		//AllItem_DESC[GamePlayItemCode::Fighter_F_Default_Pants] = new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Default_Pants,GamePlayItemRate::Common, "Fighter_F_Default_Pants");
		//AllItem_DESC[GamePlayItemCode::Fighter_F_Default_Shoes] = new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Default_Shoes,GamePlayItemRate::Common, "Fighter_F_Default_Shoes");
		//AllItem_DESC[GamePlayItemCode::Fighter_F_Default_Skin] =  new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Default_Skin, GamePlayItemRate::Common, "Fighter_F_Default_Skin");
	}


	//AllItem_DESC[GamePlayItemCode::Fighter_F_Default_Belt] = new GamePlayItem_DESC();
	AvataManager::CreateAvataData();
	//장비매니저::Create장비Data();
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

GamePlayItem_DESC* GamePlayItem_DESC::Find(GamePlayItemCode _Code)
{
	if (AllItem_DESC.find(_Code) == AllItem_DESC.end())
	{
		MsgBoxAssert("아이템이 구현이 안되어있습니다")
	}
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
			if (3000 <= IntType && IntType < 5000)
			{
				IndexType = GamePlayItemType::Avatar;
			}
			//if (4000 <= IntType && IntType < 5000)
			//{
			//	IndexType = GamePlayItemType::Pet;
			//}

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