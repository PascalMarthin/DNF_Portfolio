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

	// ���������� ����
	// �� ���ӿ��� Ÿ��Ʋȭ��
	//            ��������1
	//            ��������2
}

void DNF::Update(float _DeltaTime)
{


}

void DNF::End()
{
	int a = 0;
}