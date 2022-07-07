#include "PreCompile.h"
#include "CharacterUIKeyManager.h"

#include <GameEngineBase/GameEngineInput.h>

CharacterUIKeyManager::CharacterUIKeyManager()
{
}

CharacterUIKeyManager::~CharacterUIKeyManager()
{
}

void CharacterUIKeyManager::Start()
{
	{
		GameEngineInput::GetInst()->CreateKey("BaseAtt", 'X');
		GameEngineInput::GetInst()->CreateKey("Jump", 'C');
		GameEngineInput::GetInst()->CreateKey("Key_Upper", 'Z');
		GameEngineInput::GetInst()->CreateKey("SpaceBar", VK_SPACE);
		GameEngineInput::GetInst()->CreateKey("UP_Arrow", VK_UP);
		GameEngineInput::GetInst()->CreateKey("Down_Arrow", VK_DOWN);
		GameEngineInput::GetInst()->CreateKey("Left_Arrow", VK_LEFT);
		GameEngineInput::GetInst()->CreateKey("Right_Arrow", VK_RIGHT);
	}

	{
		GameEngineInput::GetInst()->CreateKey("Quick_1", 0x31);
		GameEngineInput::GetInst()->CreateKey("Quick_2", 0x32);
		GameEngineInput::GetInst()->CreateKey("Quick_3", 0x33);
		GameEngineInput::GetInst()->CreateKey("Quick_4", 0x34);
		GameEngineInput::GetInst()->CreateKey("Quick_5", 0x35);

	}

	{
		GameEngineInput::GetInst()->CreateKey("ESC", VK_ESCAPE);
		GameEngineInput::GetInst()->CreateKey("Inventory", 'I');
		GameEngineInput::GetInst()->CreateKey("Skill", 'K');
		GameEngineInput::GetInst()->CreateKey("MyStat", 'P');
	}

	Off();

}

void CharacterUIKeyManager::Update(float _DeltaTime)
{

}

void CharacterUIKeyManager::End()
{

}