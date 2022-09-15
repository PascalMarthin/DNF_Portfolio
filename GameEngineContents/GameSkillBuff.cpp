#include "PreCompile.h"
#include "GameSkillBuff.h"

GameSkillBuff::GameSkillBuff() 
	:	BuffTime(0)
{
}

GameSkillBuff::~GameSkillBuff() 
{
}

bool GameSkillBuff::BuffCurrentTime(float _Time)
{
	BuffTime -= _Time;
	if (BuffTime <= 0)
	{
		BuffEnd();
		return true;
	}
	else
	{
		return false;
	}
}