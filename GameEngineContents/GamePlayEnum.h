#pragma once

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
	None,
	Error = 99

};
//    0 ~   99 디버그
//  100 ~  999 장비
// 1000 ~ 1999 재료
// 2000 ~ 2999 소비
// 3000 ~ 3999 아바타
// 4000 ~ 4999 펫