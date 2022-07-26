#include "PreCompile.h"
#include "GamePlayObject.h"

GamePlayObject::GamePlayObject() 
	: ObjectPos(float4::ZERO)
{
}

GamePlayObject::~GamePlayObject() 
{
}

void GamePlayObject::Start()
{
	ObjectPos = GetTransform().GetLocalPosition();
}

