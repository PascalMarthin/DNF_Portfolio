#include <Windows.h>
#include <GameEngineContents/DNF.h>

#pragma comment(lib, "GameEngineBase.lib")
#pragma comment(lib, "GameEngineCore.lib")
#pragma comment(lib, "GameEngineContents.lib")

//#include <GameEngineContents/ContentsCore.h>
#include <GameEngineBase/GameEngineMath.h>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	new int();
	//_CrtSetBreakAlloc(61076);
	GameEngineCore::Start<DNF>();

	return 0;
}

