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

	AllItem_DESC[GamePlayItemCode::s_HPPotion] = new GamePlayItem_DESC(GamePlayItemCode::s_HPPotion, GamePlayItemRate::UnCommon, "s_HPPotion", "s_HPPotion.png");
	AllItem_DESC[GamePlayItemCode::m_HPPotion] = new GamePlayItem_DESC(GamePlayItemCode::m_HPPotion, GamePlayItemRate::Rare, "m_HPPotion", "m_HPPotion.png");
	AllItem_DESC[GamePlayItemCode::L_HPPotion] = new GamePlayItem_DESC(GamePlayItemCode::L_HPPotion, GamePlayItemRate::Unique, "L_HPPotion", "L_HPPotion.png");
	AllItem_DESC[GamePlayItemCode::s_MPPotion] = new GamePlayItem_DESC(GamePlayItemCode::s_MPPotion, GamePlayItemRate::UnCommon, "s_MPPotion", "s_MPPotion.png");
	AllItem_DESC[GamePlayItemCode::m_MPPotion] = new GamePlayItem_DESC(GamePlayItemCode::m_MPPotion, GamePlayItemRate::Rare, "m_MPPotion", "m_MPPotion.png");
	AllItem_DESC[GamePlayItemCode::L_MPPotion] = new GamePlayItem_DESC(GamePlayItemCode::L_MPPotion, GamePlayItemRate::Unique, "L_MPPotion", "L_MPPotion.png");





	AllItem_DESC[GamePlayItemCode::Tropica_Coat] = new GamePlayItem_DESC(GamePlayItemCode::Tropica_Coat, GamePlayItemRate::Epic, "Tropica_Coat", "Tropica_Coat.png");
	AllItem_DESC[GamePlayItemCode::Tropica_Belt] = new GamePlayItem_DESC(GamePlayItemCode::Tropica_Belt, GamePlayItemRate::Epic, "Tropica_Belt", "Tropica_Belt.png");
	AllItem_DESC[GamePlayItemCode::Tropica_Pants] = new GamePlayItem_DESC(GamePlayItemCode::Tropica_Pants, GamePlayItemRate::Epic, "Tropica_Pants", "Tropica_Pants.png");
	AllItem_DESC[GamePlayItemCode::Tropica_Neck] = new GamePlayItem_DESC(GamePlayItemCode::Tropica_Neck, GamePlayItemRate::Epic, "Tropica_Neck", "Tropica_Neck.png");
	AllItem_DESC[GamePlayItemCode::Tropica_Shoes] = new GamePlayItem_DESC(GamePlayItemCode::Tropica_Shoes, GamePlayItemRate::Epic, "Tropica_Shoes", "Tropica_Shoes.png");


	AllItem_DESC[GamePlayItemCode::Equipment_Upgrade12] = new GamePlayItem_DESC(GamePlayItemCode::Equipment_Upgrade12, GamePlayItemRate::Unique, "Equipment_Upgrade12", "Equipment_Upgrade12.png");
	
	AllItem_DESC[GamePlayItemCode::Fighter_F_Belt_7st_Red		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Belt_7st_Red, GamePlayItemRate::Rare, "Fighter_F_Belt_7st_Red", "Fighter_F_Belt_7st_Red.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Belt_7st_Blue		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Belt_7st_Blue, GamePlayItemRate::Rare, "Fighter_F_Belt_7st_Blue", "Fighter_F_Belt_7st_Blue.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Belt_7st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Belt_7st_Gold, GamePlayItemRate::Rare, "Fighter_F_Belt_7st_Gold", "Fighter_F_Belt_7st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Belt_4st_White		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Belt_4st_White, GamePlayItemRate::Rare, "Fighter_F_Belt_4st_White", "Fighter_F_Belt_4st_White.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Belt_4st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Belt_4st_Gold, GamePlayItemRate::Rare, "Fighter_F_Belt_4st_Gold", "Fighter_F_Belt_4st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Belt_4st_Black		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Belt_4st_Black, GamePlayItemRate::Rare, "Fighter_F_Belt_4st_Black", "Fighter_F_Belt_4st_Black.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Belt_9st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Belt_9st_Gold, GamePlayItemRate::Rare, "Fighter_F_Belt_9st_Gold", "Fighter_F_Belt_9st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Belt_9st_Purple	 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Belt_9st_Purple, GamePlayItemRate::Rare, "Fighter_F_Belt_9st_Purple", "Fighter_F_Belt_9st_Purple.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Belt_Former_Striker ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Belt_Former_Striker, GamePlayItemRate::Rare, "Fighter_F_Belt_Former_Striker", "Fighter_F_Belt_Former_Striker.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Cap_7st_Red		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Cap_7st_Red, GamePlayItemRate::Rare, "Fighter_F_Cap_7st_Red", "Fighter_F_Cap_7st_Red.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Cap_7st_Blue		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Cap_7st_Blue, GamePlayItemRate::Rare, "Fighter_F_Cap_7st_Blue", "Fighter_F_Cap_7st_Blue.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Cap_7st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Cap_7st_Gold, GamePlayItemRate::Rare, "Fighter_F_Cap_7st_Gold", "Fighter_F_Cap_7st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Cap_4st_White		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Cap_4st_White, GamePlayItemRate::Rare, "Fighter_F_Cap_4st_White", "Fighter_F_Cap_4st_White.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Cap_4st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Cap_4st_Gold, GamePlayItemRate::Rare, "Fighter_F_Cap_4st_Gold", "Fighter_F_Cap_4st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Cap_4st_Black		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Cap_4st_Black, GamePlayItemRate::Rare, "Fighter_F_Cap_4st_Black", "Fighter_F_Cap_4st_Black.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Cap_9st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Cap_9st_Gold, GamePlayItemRate::Rare, "Fighter_F_Cap_9st_Gold", "Fighter_F_Cap_9st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Cap_9st_Purple		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Cap_9st_Purple, GamePlayItemRate::Rare, "Fighter_F_Cap_9st_Purple", "Fighter_F_Cap_9st_Purple.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Cap_Former_Striker	 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Cap_Former_Striker, GamePlayItemRate::Rare, "Fighter_F_Cap_Former_Striker", "Fighter_F_Cap_Former_Striker.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Coat_7st_Red		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Coat_7st_Red, GamePlayItemRate::Rare, "Fighter_F_Coat_7st_Red", "Fighter_F_Coat_7st_Red.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Coat_7st_Blue		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Coat_7st_Blue, GamePlayItemRate::Rare, "Fighter_F_Coat_7st_Blue", "Fighter_F_Coat_7st_Blue.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Coat_7st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Coat_7st_Gold, GamePlayItemRate::Rare, "Fighter_F_Coat_7st_Gold", "Fighter_F_Coat_7st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Coat_4st_White		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Coat_4st_White, GamePlayItemRate::Rare, "Fighter_F_Coat_4st_White", "Fighter_F_Coat_4st_White.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Coat_4st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Coat_4st_Gold, GamePlayItemRate::Rare, "Fighter_F_Coat_4st_Gold", "Fighter_F_Coat_4st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Coat_4st_Black		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Coat_4st_Black, GamePlayItemRate::Rare, "Fighter_F_Coat_4st_Black", "Fighter_F_Coat_4st_Black.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Coat_9st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Coat_9st_Gold, GamePlayItemRate::Rare, "Fighter_F_Coat_9st_Gold", "Fighter_F_Coat_9st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Coat_9st_Purple	 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Coat_9st_Purple, GamePlayItemRate::Rare, "Fighter_F_Coat_9st_Purple", "Fighter_F_Coat_9st_Purple.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Coat_Former_Striker ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Coat_Former_Striker, GamePlayItemRate::Rare, "Fighter_F_Coat_Former_Striker", "Fighter_F_Coat_Former_Striker.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Face_7st_Red		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Face_7st_Red, GamePlayItemRate::Rare, "Fighter_F_Face_7st_Red", "Fighter_F_Face_7st_Red.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Face_7st_Blue		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Face_7st_Blue, GamePlayItemRate::Rare, "Fighter_F_Face_7st_Blue", "Fighter_F_Face_7st_Blue.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Face_7st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Face_7st_Gold, GamePlayItemRate::Rare, "Fighter_F_Face_7st_Gold", "Fighter_F_Face_7st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Face_4st_White		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Face_4st_White, GamePlayItemRate::Rare, "Fighter_F_Face_4st_White", "Fighter_F_Face_4st_White.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Face_4st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Face_4st_Gold, GamePlayItemRate::Rare, "Fighter_F_Face_4st_Gold", "Fighter_F_Face_4st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Face_4st_Black		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Face_4st_Black, GamePlayItemRate::Rare, "Fighter_F_Face_4st_Black", "Fighter_F_Face_4st_Black.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Face_9st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Face_9st_Gold, GamePlayItemRate::Rare, "Fighter_F_Face_9st_Gold", "Fighter_F_Face_9st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Face_9st_Purple	 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Face_9st_Purple, GamePlayItemRate::Rare, "Fighter_F_Face_9st_Purple", "Fighter_F_Face_9st_Purple.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Face_Former_Striker ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Face_Former_Striker, GamePlayItemRate::Rare, "Fighter_F_Face_Former_Striker", "Fighter_F_Face_Former_Striker.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Hair_7st_Red		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Hair_7st_Red, GamePlayItemRate::Rare, "Fighter_F_Hair_7st_Red", "Fighter_F_Hair_7st_Red.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Hair_7st_Blue		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Hair_7st_Blue, GamePlayItemRate::Rare, "Fighter_F_Hair_7st_Blue", "Fighter_F_Hair_7st_Blue.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Hair_7st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Hair_7st_Gold, GamePlayItemRate::Rare, "Fighter_F_Hair_7st_Gold", "Fighter_F_Hair_7st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Hair_4st_White		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Hair_4st_White, GamePlayItemRate::Rare, "Fighter_F_Hair_4st_White", "Fighter_F_Hair_4st_White.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Hair_4st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Hair_4st_Gold, GamePlayItemRate::Rare, "Fighter_F_Hair_4st_Gold", "Fighter_F_Hair_4st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Hair_4st_Black		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Hair_4st_Black, GamePlayItemRate::Rare, "Fighter_F_Hair_4st_Black", "Fighter_F_Hair_4st_Black.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Hair_9st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Hair_9st_Gold, GamePlayItemRate::Rare, "Fighter_F_Hair_9st_Gold", "Fighter_F_Hair_9st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Hair_9st_Purple	 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Hair_9st_Purple, GamePlayItemRate::Rare, "Fighter_F_Hair_9st_Purple", "Fighter_F_Hair_9st_Purple.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Hair_Former_Striker ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Hair_Former_Striker, GamePlayItemRate::Rare, "Fighter_F_Hair_Former_Striker", "Fighter_F_Hair_Former_Striker.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Neck_7st_Red		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Neck_7st_Red, GamePlayItemRate::Rare, "Fighter_F_Neck_7st_Red", "Fighter_F_Neck_7st_Red.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Neck_7st_Blue		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Neck_7st_Blue, GamePlayItemRate::Rare, "Fighter_F_Neck_7st_Blue", "Fighter_F_Neck_7st_Blue.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Neck_7st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Neck_7st_Gold, GamePlayItemRate::Rare, "Fighter_F_Neck_7st_Gold", "Fighter_F_Neck_7st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Neck_4st_White		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Neck_4st_White, GamePlayItemRate::Rare, "Fighter_F_Neck_4st_White", "Fighter_F_Neck_4st_White.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Neck_4st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Neck_4st_Gold, GamePlayItemRate::Rare, "Fighter_F_Neck_4st_Gold", "Fighter_F_Neck_4st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Neck_4st_Black		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Neck_4st_Black, GamePlayItemRate::Rare, "Fighter_F_Neck_4st_Black", "Fighter_F_Neck_4st_Black.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Neck_9st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Neck_9st_Gold, GamePlayItemRate::Rare, "Fighter_F_Neck_9st_Gold", "Fighter_F_Neck_9st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Neck_9st_Purple	 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Neck_9st_Purple, GamePlayItemRate::Rare, "Fighter_F_Neck_9st_Purple", "Fighter_F_Neck_9st_Purple.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Neck_Former_Striker ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Neck_Former_Striker, GamePlayItemRate::Rare, "Fighter_F_Neck_Former_Striker", "Fighter_F_Neck_Former_Striker.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Pants_7st_Red		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Pants_7st_Red, GamePlayItemRate::Rare, "Fighter_F_Pants_7st_Red", "Fighter_F_Pants_7st_Red.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Pants_7st_Blue		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Pants_7st_Blue, GamePlayItemRate::Rare, "Fighter_F_Pants_7st_Blue", "Fighter_F_Pants_7st_Blue.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Pants_7st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Pants_7st_Gold, GamePlayItemRate::Rare, "Fighter_F_Pants_7st_Gold", "Fighter_F_Pants_7st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Pants_4st_White	 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Pants_4st_White, GamePlayItemRate::Rare, "Fighter_F_Pants_4st_White", "Fighter_F_Pants_4st_White.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Pants_4st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Pants_4st_Gold, GamePlayItemRate::Rare, "Fighter_F_Pants_4st_Gold", "Fighter_F_Pants_4st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Pants_4st_Black		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Pants_4st_Black, GamePlayItemRate::Rare, "Fighter_F_Pants_4st_Black", "Fighter_F_Pants_4st_Black.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Pants_9st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Pants_9st_Gold, GamePlayItemRate::Rare, "Fighter_F_Pants_9st_Gold", "Fighter_F_Pants_9st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Pants_9st_Purple	 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Pants_9st_Purple, GamePlayItemRate::Rare, "Fighter_F_Pants_9st_Purple", "Fighter_F_Pants_9st_Purple.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Pants_Former_Striker]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Pants_Former_Striker, GamePlayItemRate::Rare, "Fighter_F_Pants_Former_Striker", "Fighter_F_Pants_Former_Striker.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Shoes_7st_Red 		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Shoes_7st_Red, GamePlayItemRate::Rare, "Fighter_F_Shoes_7st_Red", "Fighter_F_Shoes_7st_Red.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Shoes_7st_Blue		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Shoes_7st_Blue, GamePlayItemRate::Rare, "Fighter_F_Shoes_7st_Blue", "Fighter_F_Shoes_7st_Blue.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Shoes_7st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Shoes_7st_Gold, GamePlayItemRate::Rare, "Fighter_F_Shoes_7st_Gold", "Fighter_F_Shoes_7st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Shoes_4st_White	 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Shoes_4st_White, GamePlayItemRate::Rare, "Fighter_F_Shoes_4st_White", "Fighter_F_Shoes_4st_White.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Shoes_4st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Shoes_4st_Gold, GamePlayItemRate::Rare, "Fighter_F_Shoes_4st_Gold", "Fighter_F_Shoes_4st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Shoes_4st_Black		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Shoes_4st_Black, GamePlayItemRate::Rare, "Fighter_F_Shoes_4st_Black", "Fighter_F_Shoes_4st_Black.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Shoes_9st_Gold		 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Shoes_9st_Gold, GamePlayItemRate::Rare, "Fighter_F_Shoes_9st_Gold", "Fighter_F_Shoes_9st_Gold.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Shoes_9st_Purple	 ]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Shoes_9st_Purple, GamePlayItemRate::Rare, "Fighter_F_Shoes_9st_Purple", "Fighter_F_Shoes_9st_Purple.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Shoes_Former_Striker]= new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Shoes_Former_Striker, GamePlayItemRate::Rare, "Fighter_F_Shoes_Former_Striker", "Fighter_F_Shoes_Former_Striker.png");

	AllItem_DESC[GamePlayItemCode::Fighter_F_Belt_14st_White] = new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Belt_14st_White, GamePlayItemRate::Rare, "Fighter_F_Belt_14st_White", "Fighter_F_Belt_14st_White.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Cap_14st_White] = new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Cap_14st_White, GamePlayItemRate::Rare, "Fighter_F_Cap_14st_White", "Fighter_F_Cap_14st_White.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Shoes_14st_White] = new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Shoes_14st_White, GamePlayItemRate::Rare, "Fighter_F_Shoes_14st_White", "Fighter_F_Shoes_14st_White.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Coat_14st_White] = new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Coat_14st_White, GamePlayItemRate::Rare, "Fighter_F_Coat_14st_White", "Fighter_F_Coat_14st_White.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Pants_14st_White] = new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Pants_14st_White, GamePlayItemRate::Rare, "Fighter_F_Pants_14st_White", "Fighter_F_Pants_14st_White.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Face_14st_White] = new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Face_14st_White, GamePlayItemRate::Rare, "Fighter_F_Face_14st_White", "Fighter_F_Face_14st_White.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Neck_14st_White] = new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Neck_14st_White, GamePlayItemRate::Rare, "Fighter_F_Neck_14st_White", "Fighter_F_Neck_14st_White.png");
	AllItem_DESC[GamePlayItemCode::Fighter_F_Hair_14st_White] = new GamePlayItem_DESC(GamePlayItemCode::Fighter_F_Hair_14st_White, GamePlayItemRate::Rare, "Fighter_F_Hair_14st_White", "Fighter_F_Hair_14st_White.png");

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
	//���Ŵ���::Create���Data();
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
		MsgBoxAssert("�������� ������ �ȵǾ��ֽ��ϴ�")
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
	//    0 ~   99 �����
	//  100 ~  999 ���
	// 1000 ~ 1999 ���
	// 2000 ~ 2999 �Һ�
	// 3000 ~ 3999 �ƹ�Ÿ
	// 4000 ~ 4999 ��
	return IndexType;
}