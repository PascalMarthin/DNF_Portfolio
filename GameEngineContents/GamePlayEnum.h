#pragma once

#define Player_Character_ALive				0x00 // ����
#define Player_Character_Action				0x01 // �ൿ����
#define Player_Character_Move				0x02 // �̵�����
#define Player_Character_InAir				0x03 // ����

#define Player_Character_BaseAtt			0x04 // �⺻����
#define Player_Character_DoSkill			0x05 // ��ų���
#define Player_Character_Casting			0x06 // ĳ����
#define Player_Character_Charging			0x07 // ��¡

#define Player_Character_Invincibility		0x08 // ����
#define Player_Character_Evasion			0x09 // ����ȸ��(�ǰ�����X)
#define Player_Character_Superarmor			0x0a // ���۾Ƹ�

#define Player_Character_BeHit				0x0b // ����
#define Player_Character_BeAir	            0x0c // ���߿� ��
#define Player_Character_BeDown	            0x0d // �ٿ�
#define Player_Character_BeHold				0x0e // ����


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
	Error,
	Empty
	 

};
//    0 ~   99 �����
//  100 ~  999 ���
// 1000 ~ 1999 ���
// 2000 ~ 2999 �Һ�
// 3000 ~ 3999 �ƹ�Ÿ
// 4000 ~ 4999 ��