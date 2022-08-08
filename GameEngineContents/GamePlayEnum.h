#pragma once
#define DefaultMove 100
#define WindowX 1280
#define WindowY 720 

#define CameraZoom 1.0f
#define CameraZoomInvers 1.f - ((CameraZoom - 1.0f) / 2.0f)


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
	None,
	Belt,
	Cap,
	Coat,
	Face,
	Hair,
	Neck,
	Pants,
	Shoes,
	Skin,
};

enum class GamePlayItemCode
{
	Error,
	Empty,

	Fighter_F_Default_Belt	 = 20,
	Fighter_F_Default_Cap	 = 21,
	Fighter_F_Default_Coat	 = 22,
	Fighter_F_Default_Face	 = 23,
	Fighter_F_Default_Hair	 = 24,
	Fighter_F_Default_Neck	 = 25,
	Fighter_F_Default_Pants	 = 26,
	Fighter_F_Default_Shoes	 = 27,
	Fighter_F_Default_Skin	 = 28,

};
//    0 ~   99 디버그
//  100 ~  999 장비
// 1000 ~ 1999 재료
// 2000 ~ 2999 소비
// 3000 ~ 3999 아바타
// 4000 ~ 4999 펫

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
	Player_Character_BeAir	        =   0b0010000000000000 ,// 타의로 공중에 뜨는중							
	Player_Character_BeDown	        =   0b0100000000000000 ,// 다운중		
	Player_Character_BeHold			=	0b1000000000000000  // 잡혀있는중															
};


enum ZSortOrder
{


	HUD_SkillBlank = 67,
	HUD_ExpBar     = 68,
	HUD_Bar        = 69,
	HUD_Base       = 70,
	Inventory_Item = 78,
	Inventory_Blank = 79,
	Inventory = 80,



	BackGround = 1200,
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
	Monster = 3,
	UI_ect = 4,
};

enum class ObjectType
{
	None,
	Character,
	NPC,
	Monster,
	Custom
};