#pragma once
#define DefaultMove 100
#define WindowX 1280
#define WindowY 720 

#define MonitorX 1260.f / 1067.f
#define MonitorY 720.f / 600.f




enum class GamePlayItemType
{
	Equipment, // 장비
	Stuff,     // 재료
	Consumable,// 소비
	Avatar,    // 아바타
	Pet,    // 펫
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
//    0 ~   99 디버그
//  100 ~  999 장비
// 1000 ~ 1999 재료
// 2000 ~ 2999 소비
// 3000 ~ 4999 아바타
// ~ 3199 벨트
// ~ 3399 모자
// ~ 3599 상의
// ~ 3799 얼굴
// ~ 3999 머리
// ~ 4199 어깨 - 가슴 - 목
// ~ 4399 하의
// ~ 4599 신발
// ~ 4799 피부
// ~ 4999 무기



enum CharacterStat
{
	Player_Character_ALive			=	0b0000000000000001 ,// 생존중							
	Player_Character_Action			=	0b0000000000000010 ,// 행동중						
	Player_Character_Move			=	0b0000000000000100 ,// 이동중						
	Player_Character_Dash			=   0b0000000000001000 ,// 대쉬중
	Player_Character_Jump			=	0b0000000000010000 ,// 공중	
	Player_Character_BaseAtt		=	0b0000000000100000 ,// 기본공격중							
	Player_Character_DoSkill		=	0b0000000001000000 ,// 스킬사용중						
	Player_Character_Casting		=	0b0000000010000000 ,// 캐스팅중						
	Player_Character_Charging		=	0b0000000100000000 ,// 차징중							
	Player_Character_Invincibility	=	0b0000001000000000 ,// 무적상태							
	Player_Character_Evasion		=	0b0000010000000000 ,// 절대회피(피격판정X)					
	Player_Character_Superarmor		=	0b0000100000000000 ,// 슈퍼아머상태							
	Player_Character_BeHit			=	0b0001000000000000 ,// 경직중						
	Player_Character_Aerial	        =   0b0010000000000000 ,// 타의로 공중에 뜨는중							
	Player_Character_BeDown	        =   0b0100000000000000 ,// 다운중		
	Player_Character_BeHold			=	0b1000000000000000  // 잡혀있는중															
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
// ~500 캐릭터
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