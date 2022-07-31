#include "PreCompile.h"
#include "CharacterStryker.h"

CharacterStryker::CharacterStryker() 
{
}

CharacterStryker::~CharacterStryker() 
{
}

void CharacterStryker::Start()
{
	GamePlayCharacter::SetPlayerClass(CharacterClass::Fighter_F_Stryker);
	CharacterFighter::Start();
	Set_Default_FSMManager();
}



void CharacterStryker::Update(float _DeltaTime)
{

}

void CharacterStryker::End()
{

}

void CharacterStryker::Set_Default_FSMManager()
{
	CharacterFighter::Set_Default_FSMManager();
}