#pragma once

enum class GamePlayItemType
{
	Equipment, // ���
	Stuff,     // ���
	Consumable,// �Һ�
	Avatar,    // �ƹ�Ÿ
	Pet   ,    // ��
	Debug ,
	Unknown
};


enum class GamePlayItemCode
{
	None,
	Error = 99

};
//    0 ~   99 �����
//  100 ~  999 ���
// 1000 ~ 1999 ���
// 2000 ~ 2999 �Һ�
// 3000 ~ 3999 �ƹ�Ÿ
// 4000 ~ 4999 ��