#include "PreCompile.h"
#include <GameEngineBase/GameEngineInput.h>
#include "ChararcterSkillKeyManager.h"


ChararcterSkillKeyManager::ChararcterSkillKeyManager() 
{
}

ChararcterSkillKeyManager::~ChararcterSkillKeyManager() 
{
}

void ChararcterSkillKeyManager::Start()
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

void ChararcterSkillKeyManager::Update(float _DeltaTime)
{

}

void ChararcterSkillKeyManager::End()
{

}