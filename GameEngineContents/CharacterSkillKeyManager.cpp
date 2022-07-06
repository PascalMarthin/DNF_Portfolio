#include "PreCompile.h"
#include <GameEngineBase/GameEngineInput.h>
#include "CharacterSkillKeyManager.h"


CharacterSkillKeyManager::CharacterSkillKeyManager() 
{
}

CharacterSkillKeyManager::~CharacterSkillKeyManager() 
{
}

void CharacterSkillKeyManager::Start()
{
	{
		GameEngineInput::GetInst()->CreateKey("Key_A", 'A');
		GameEngineInput::GetInst()->CreateKey("Key_S", 'S');
		GameEngineInput::GetInst()->CreateKey("Key_D", 'D');
		GameEngineInput::GetInst()->CreateKey("Key_F", 'F');
		GameEngineInput::GetInst()->CreateKey("Key_G", 'G');
		GameEngineInput::GetInst()->CreateKey("Key_H", 'H');
		GameEngineInput::GetInst()->CreateKey("Key_Q", 'Q');
		GameEngineInput::GetInst()->CreateKey("Key_W", 'W');
		GameEngineInput::GetInst()->CreateKey("Key_E", 'E');
		GameEngineInput::GetInst()->CreateKey("Key_R", 'R');

	}
	Off();

}

void CharacterSkillKeyManager::Update(float _DeltaTime)
{

}

void CharacterSkillKeyManager::End()
{

}