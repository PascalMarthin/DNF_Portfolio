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
		MsgBoxAssert("포스매니저 생성에 실패 하였습니다");
	}
}

CharacterPosManager::~CharacterPosManager() 
{
}

