#include "PreCompile.h"
#include "GameEnginePlusCharacterStatWindow.h"
#include <GameEngineCore/GEngine.h>

GameEnginePlusCharacterStatWindow::GameEnginePlusCharacterStatWindow() 
{
}

GameEnginePlusCharacterStatWindow::~GameEnginePlusCharacterStatWindow() 
{
}

void GameEnginePlusCharacterStatWindow::Initialize(class GameEngineLevel* _Level)
{

}

void GameEnginePlusCharacterStatWindow::OnGUI(GameEngineLevel* _Level, float _DeltaTime)
{
	int FPS = static_cast<int>(1.0f / _DeltaTime);
	// printf 형식인데 안씀.

	std::string Name = "FPS : " + std::to_string(FPS);
	ImGui::Text(Name.c_str());

	if (true == ImGui::Button("CollisionDebugSwtich"))
	{
		GEngine::CollisionDebugSwitch();
	}

	if (true == ImGui::Button("FreeCameaOnOff"))
	{
		GEngine::GetCurrentLevel()->GetMainCameraActor()->FreeCameraModeOnOff();
	}


	std::string AllRenderTarget = "AllRenderTarget";
	ImGui::Text(AllRenderTarget.c_str());

	//for (std::pair<std::string, GameEngineRenderTarget*> RenderTargetPair : GameEngineRenderTarget::NamedRes)
	//{
	//	// ImGui::Text(RenderTarget.first.c_str());

	//	if (true == ImGui::TreeNodeEx(RenderTargetPair.first.c_str(), 0))
	//	{
	//		GameEngineRenderTarget* RenderTarget = RenderTargetPair.second;

	//		for (ID3D11ShaderResourceView* _View : RenderTarget->ShaderResourceViews)
	//		{
	//			float4 Scale = GameEngineWindow::GetScale() * 0.2f;

	//			if (true == ImGui::ImageButton(static_cast<ImTextureID>(_View), { Scale.x, Scale.y }))
	//			{
	//				GameEngineImageShotWindow* NewWindow = GameEngineGUI::CreateGUIWindow<GameEngineImageShotWindow>("ImageShot", nullptr);
	//				NewWindow->RenderTextureSetting(static_cast<ImTextureID>(_View), { GameEngineWindow::GetScale().x ,GameEngineWindow::GetScale().y });
	//			}
	//		}

	//		ImGui::TreePop();
	//	}
	//}

}