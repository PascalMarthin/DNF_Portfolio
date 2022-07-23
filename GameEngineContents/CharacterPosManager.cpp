#include "PreCompile.h"
#include <GameEngineBase/GameEngineDebug.h>
#include "CharacterPosManager.h"

CharacterPosManager::CharacterPosManager(GamePlayObject* _Object)
	: Player(_Object)
	, ObjectInGamePos(_Object->GetPosToInGame())
	, PlayerTransform(_Object->GetTransform())
{
	if (nullptr == _Object)
	{
		MsgBoxAssert("�����Ŵ��� ������ ���� �Ͽ����ϴ�");
	}
}

CharacterPosManager::~CharacterPosManager() 
{
}

