#pragma once
#define DefaultMove 100.f

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

enum class CharacterStat
{
	Player_Character_ALive			=	0x00 ,// 생존								
	Player_Character_Action			=	0x01 ,// 행동가능							
	Player_Character_Move			=	0x02 ,// 이동가능							
	Player_Character_InAir			=	0x03 ,// 공중								
	Player_Character_BaseAtt		=	0x04 ,// 기본공격							
	Player_Character_DoSkill		=	0x05 ,// 스킬사용							
	Player_Character_Casting		=	0x06 ,// 캐스팅								
	Player_Character_Charging		=	0x07 ,// 차징								
	Player_Character_Invincibility	=	0x08 ,// 무적								
	Player_Character_Evasion		=	0x09 ,// 절대회피(피격판정X)					
	Player_Character_Superarmor		=	0x0a ,// 슈퍼아머							
	Player_Character_BeHit			=	0x0b ,// 경직								
	Player_Character_BeAir	        =   0x0c ,// 공중에 뜸							
	Player_Character_BeDown	        =   0x0d ,// 다운								
	Player_Character_BeHold			=	0x0e // 잡힘								
									
};