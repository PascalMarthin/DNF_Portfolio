#pragma once
#define DefaultMove 100.f

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
//    0 ~   99 �����
//  100 ~  999 ���
// 1000 ~ 1999 ���
// 2000 ~ 2999 �Һ�
// 3000 ~ 3999 �ƹ�Ÿ
// 4000 ~ 4999 ��

enum class CharacterStat
{
	Player_Character_ALive			=	0x00 ,// ����								
	Player_Character_Action			=	0x01 ,// �ൿ����							
	Player_Character_Move			=	0x02 ,// �̵�����							
	Player_Character_InAir			=	0x03 ,// ����								
	Player_Character_BaseAtt		=	0x04 ,// �⺻����							
	Player_Character_DoSkill		=	0x05 ,// ��ų���							
	Player_Character_Casting		=	0x06 ,// ĳ����								
	Player_Character_Charging		=	0x07 ,// ��¡								
	Player_Character_Invincibility	=	0x08 ,// ����								
	Player_Character_Evasion		=	0x09 ,// ����ȸ��(�ǰ�����X)					
	Player_Character_Superarmor		=	0x0a ,// ���۾Ƹ�							
	Player_Character_BeHit			=	0x0b ,// ����								
	Player_Character_BeAir	        =   0x0c ,// ���߿� ��							
	Player_Character_BeDown	        =   0x0d ,// �ٿ�								
	Player_Character_BeHold			=	0x0e // ����								
									
};