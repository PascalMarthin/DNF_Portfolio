#pragma once
#define DefaultMove 100
#define WindowX 1280
#define WindowY 720 

#define MonitorX 1260.f / 1067.f
#define MonitorY 720.f / 600.f




enum class GamePlayItemType
{
	Equipment, // ���
	Stuff,     // ���
	Consumable,// �Һ�
	Avatar,    // �ƹ�Ÿ
	Pet,    // ��
	Debug,
	Unknown
};

enum class GamePlayItemRate
{
	Error,
	None,
	Nomal,
	Common,
	UnCommon,
	Rare,
	Unique,
	Legendary,
	Epic
};
enum class AllAvataClass
{
	Belt,
	Cap,
	Coat,
	Face,
	Hair,
	Neck,
	Pants,
	Shoes,
	Skin,
	Weapon,
	None,
};

enum class GamePlayItemCode
{
	Error,
	Empty,

	Fighter_F_Default_Belt = 20,
	Fighter_F_Default_Cap = 21,
	Fighter_F_Default_Coat = 22,
	Fighter_F_Default_Face = 23,
	Fighter_F_Default_Hair = 24,
	Fighter_F_Default_Neck = 25,
	Fighter_F_Default_Pants = 26,
	Fighter_F_Default_Shoes = 27,
	Fighter_F_Default_Skin = 28,

	Debug_Weapon = 100,


	Level1Up = 2000,
	Equipment_Upgrade12,



	Fighter_F_Belt_7st_Red = 3000,
	Fighter_F_Belt_7st_Blue,
	Fighter_F_Belt_7st_Gold,

	Fighter_F_Belt_4st_White,
	Fighter_F_Belt_4st_Gold,
	Fighter_F_Belt_4st_Blue,
	//Fighter_F_Belt_4st_Purple,

	Fighter_F_Belt_9st_Gold,
	Fighter_F_Belt_9st_Purple,

	Fighter_F_Belt_Former_Striker,


	Fighter_F_Cap_7st_Red = 3200,
	Fighter_F_Cap_7st_Blue,
	Fighter_F_Cap_7st_Gold,

	Fighter_F_Cap_4st_White,
	Fighter_F_Cap_4st_Gold,
	Fighter_F_Cap_4st_Blue,

	Fighter_F_Cap_9st_Gold,
	Fighter_F_Cap_9st_Purple,

	Fighter_F_Cap_Former_Striker,


	Fighter_F_Coat_7st_Red = 3400,
	Fighter_F_Coat_7st_Blue,
	Fighter_F_Coat_7st_Gold,

	Fighter_F_Coat_4st_White,
	Fighter_F_Coat_4st_Gold,
	Fighter_F_Coat_4st_Blue,

	Fighter_F_Coat_9st_Gold,
	Fighter_F_Coat_9st_Purple,

	Fighter_F_Coat_Former_Striker,


	Fighter_F_Face_7st_Red = 3600,
	Fighter_F_Face_7st_Blue,
	Fighter_F_Face_7st_Gold,

	Fighter_F_Face_4st_White,
	Fighter_F_Face_4st_Gold,
	Fighter_F_Face_4st_Blue,

	Fighter_F_Face_9st_Gold,
	Fighter_F_Face_9st_Purple,

	Fighter_F_Face_Former_Striker,


	Fighter_F_Hair_7st_Red = 3800,
	Fighter_F_Hair_7st_Blue,
	Fighter_F_Hair_7st_Gold,

	Fighter_F_Hair_4st_White,
	Fighter_F_Hair_4st_Gold,
	Fighter_F_Hair_4st_Blue,

	Fighter_F_Hair_9st_Gold,
	Fighter_F_Hair_9st_Purple,

	Fighter_F_Hair_Former_Striker,


	Fighter_F_Neck_7st_Red = 4000,
	Fighter_F_Neck_7st_Blue,
	Fighter_F_Neck_7st_Gold,

	Fighter_F_Neck_4st_White,
	Fighter_F_Neck_4st_Gold,
	Fighter_F_Neck_4st_Blue,

	Fighter_F_Neck_9st_Gold,
	Fighter_F_Neck_9st_Purple,

	Fighter_F_Neck_Former_Striker,


	Fighter_F_Pants_7st_Red = 4200,
	Fighter_F_Pants_7st_Blue,
	Fighter_F_Pants_7st_Gold,

	Fighter_F_Pants_4st_White,
	Fighter_F_Pants_4st_Gold,
	Fighter_F_Pants_4st_Blue,

	Fighter_F_Pants_9st_Gold,
	Fighter_F_Pants_9st_Purple,

	Fighter_F_Pants_Former_Striker,


	Fighter_F_Shoes_7st_Red = 4400,
	Fighter_F_Shoes_7st_Blue,
	Fighter_F_Shoes_7st_Gold,

	Fighter_F_Shoes_4st_White,
	Fighter_F_Shoes_4st_Gold,
	Fighter_F_Shoes_4st_Blue,

	Fighter_F_Shoes_9st_Gold,
	Fighter_F_Shoes_9st_Purple,

	Fighter_F_Shoes_Former_Striker,


};
//    0 ~   99 �����
//  100 ~  999 ���
// 1000 ~ 1999 ���
// 2000 ~ 2999 �Һ�
// 3000 ~ 4999 �ƹ�Ÿ
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



enum CharacterStat
{
	Player_Character_ALive			=	0b0000000000000001 ,// ������							
	Player_Character_Action			=	0b0000000000000010 ,// �ൿ��						
	Player_Character_Move			=	0b0000000000000100 ,// �̵���						
	Player_Character_Dash			=   0b0000000000001000 ,// �뽬��
	Player_Character_Jump			=	0b0000000000010000 ,// ����	
	Player_Character_BaseAtt		=	0b0000000000100000 ,// �⺻������							
	Player_Character_DoSkill		=	0b0000000001000000 ,// ��ų�����						
	Player_Character_Casting		=	0b0000000010000000 ,// ĳ������						
	Player_Character_Charging		=	0b0000000100000000 ,// ��¡��							
	Player_Character_Invincibility	=	0b0000001000000000 ,// ��������							
	Player_Character_Evasion		=	0b0000010000000000 ,// ����ȸ��(�ǰ�����X)					
	Player_Character_Superarmor		=	0b0000100000000000 ,// ���۾Ƹӻ���							
	Player_Character_BeHit			=	0b0001000000000000 ,// ������						
	Player_Character_Aerial	        =   0b0010000000000000 ,// Ÿ�Ƿ� ���߿� �ߴ���							
	Player_Character_BeDown	        =   0b0100000000000000 ,// �ٿ���		
	Player_Character_BeHold			=	0b1000000000000000  // �����ִ���															
};


enum ZSortOrder
{


	HUD_SkillBlank = 67,
	HUD_ExpBar = 68,
	HUD_Bar = 69,
	HUD_Base = 70,
	Inventory_Item = 78,
	Inventory_Blank = 79,
	Inventory = 80,

	Monster_Bale = 60,
	NPC_Object = 50, // -Y
	Character_Avata = 74,
	Character_Fighter_F = 130, // -Y,


	BackGround = 200,
};
// ~100 UI
// ~500 ĳ����
// 

enum class EngineInput
{
	None,
	A,
	S,
	D,
	F,
	G,
	H,
	Q,
	W,
	E,
	R,
	X,
	C,
	Z,
	SPACE,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	ESCAPE,
	LBUTTON,
	RBUTTON
};

enum class CharacterFormerClass
{
	None,
	Striker,
	Lucher,
	CharacterClass_Max
};

enum class AllCharacterClass
{
	 None
	, Swordman_M
	, Swordman_F
	, Fighter_M
	, Fighter_F
	, Gunner_M
	, Gunner_F
	, Mage_M
	, Mage_F
	, Priest_M
	, Priest_F
	, Thief
	, Knight
	, Demoniclancer
	, Gunblader
	, Darknight
	, Creator
	, AllCharacterClass_Max
};

enum class CollisionOrder
{
	None = 0,
	InGame_Object = 1,
	Player = 2,
	Player_Floor = 3,
	Player_Att = 4,
	Monster = 10,
	Monster_Att = 11,
	UI_MainMouse = 20,
	UI_UIMouse = 21,
	ChangeMap = 22,
	UI_InventoryItem,
	UI_InventoryBlank,
};

enum class ObjectType
{
	None,
	Character,
	NPC,
	Monster,
	Custom
};

enum class TownMap
{
	None,
	Seria_Room,
	Jelva1F,
	Jelva2F,
	Jelva2F_01,
	DungeonSelect,
};

enum class WorldDungeon
{
	None,
	Luke
};

enum class ActorOrder
{
	None,
	Mouse = 1,
};