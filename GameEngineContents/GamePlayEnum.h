#pragma once

#define Player_Character_ALive				0x00 // 생존
#define Player_Character_Action				0x01 // 행동가능
#define Player_Character_Move				0x02 // 이동가능
#define Player_Character_InAir				0x03 // 공중

#define Player_Character_BaseAtt			0x04 // 기본공격
#define Player_Character_DoSkill			0x05 // 스킬사용
#define Player_Character_Casting			0x06 // 캐스팅
#define Player_Character_Charging			0x07 // 차징

#define Player_Character_Invincibility		0x08 // 무적
#define Player_Character_Evasion			0x09 // 절대회피(피격판정X)
#define Player_Character_Superarmor			0x0a // 슈퍼아머

#define Player_Character_BeHit				0x0b // 경직
#define Player_Character_BeAir	            0x0c // 공중에 뜸
#define Player_Character_BeDown	            0x0d // 다운
#define Player_Character_BeHold				0x0e // 잡힘


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


enum class GamePlayItemCode
{
	Error,
	Empty
	 

};
//    0 ~   99 디버그
//  100 ~  999 장비
// 1000 ~ 1999 재료
// 2000 ~ 2999 소비
// 3000 ~ 3999 아바타
// 4000 ~ 4999 펫