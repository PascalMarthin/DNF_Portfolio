#include "PreCompile.h"
#include "DNF.h"
#include "DebugLevel.h"

//#pragma comment(lib, "GameEngineBase.lib")

DNF::DNF()
	//: GameEngineCore()
{
}

DNF::~DNF()
{
}

void DNF::Start()
{
	// GameEngineDebug::ConsoleOpen();

	CreateLevel<DebugLevel>("Debug");
	//CreateLevel<PlayLevel>("Play");
	ChangeLevel("Debug");

	// 게임컨텐츠 정의
	// 이 게임에는 타이틀화면
	//            스테이지1
	//            스테이지2
}

void DNF::Update(float _DeltaTime)
{


}

void DNF::End()
{
	int a = 0;
}