#pragma once
#define DefaultMove 100
#define WindowX 1280
#define WindowY 720 

#define CameraZoom 1.0f
#define CameraZoomInvers 1.f - ((CameraZoom - 1.0f) / 2.0f)

enum class GamePlayItemType
{
	Equipment, // 장비
	Stuff,     // 재료
	Consumable,// 소비
	Avatar,    // 아바타
	Pet   ,    // 펫
	Debug ,
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
	Player_Character_ALive			=	0x00 ,// 생존중							
	Player_Character_Action			=	0x01 ,// 행동중						
	Player_Character_Move			=	0x02 ,// 이동중						
	Player_Character_Dash			=   0x03 ,// 대쉬중
	Player_Character_Jump			=	0x04 ,// 공중	
	Player_Character_BaseAtt		=	0x05 ,// 기본공격중							
	Player_Character_DoSkill		=	0x06 ,// 스킬사용중						
	Player_Character_Casting		=	0x07 ,// 캐스팅중						
	Player_Character_Charging		=	0x08 ,// 차징중							
	Player_Character_Invincibility	=	0x09 ,// 무적상태							
	Player_Character_Evasion		=	0x0a ,// 절대회피(피격판정X)					
	Player_Character_Superarmor		=	0x0b ,// 슈퍼아머상태							
	Player_Character_BeHit			=	0x0c ,// 경직중						
	Player_Character_BeAir	        =   0x0d ,// 타의로 공중에 뜨는중							
	Player_Character_BeDown	        =   0x0e ,// 다운중		
	Player_Character_BeHold			=	0x0f  // 잡혀있는중															
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
};
// ~100 UI
// ~500 캐릭터

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