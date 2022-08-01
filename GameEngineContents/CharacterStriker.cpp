#include "PreCompile.h"
#include "CharacterStriker.h"

CharacterStriker::CharacterStriker() 
{
}

CharacterStriker::~CharacterStriker() 
{
}

void CharacterStriker::Start()
{
	CharacterFighter::Start();
	Set_Default_FSMManager();
}



void CharacterStriker::Update(float _DeltaTime)
{

}

void CharacterStriker::End()
{

}

void CharacterStriker::Set_Default_FSMManager()
{
	CharacterFighter::Set_Default_FSMManager();
}