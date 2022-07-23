#include "PreCompile.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineCore/GameEngineComponent.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include "InterfaceHUD.h"

InterfaceHUD::InterfaceHUD() 
	: HUDBase(nullptr)
	, HPBar(nullptr)
	, MPBar(nullptr)
	, HPBar_Hit(nullptr)
	, HUDBasePivot({0, 0, 10})
	, HPBarPivot({ -146, -6, 8 })
	, MPBarPivot({  146, -6, 8 })

{
}

InterfaceHUD::~InterfaceHUD() 
{
}

void InterfaceHUD::Start()
{
	GetTransform().SetLocalPosition({ 0, -258 });
	HUDBase = CreateComponent<GameEngineTextureRenderer>();
	HPBar   = CreateComponent<GameEngineTextureRenderer>();
	MPBar   = CreateComponent<GameEngineTextureRenderer>();
	HPBar_Hit = CreateComponent<GameEngineTextureRenderer>();

	HUDBase->SetTexture("HUDBase.png");
	HUDBase->ScaleToTexture();
	HUDBase->GetTransform().SetLocalPosition(HUDBasePivot);
	HPBar->SetTexture("HPBar.png");
	HPBar->ScaleToTexture();
	HPBar->GetTransform().SetLocalPosition(HPBarPivot);
	HPBar_Hit->SetTexture("HPBarHit.png");
	HPBar_Hit->ScaleToTexture();
	HPBar_Hit->GetTransform().SetLocalPosition(HPBarPivot);
	HPBar_Hit->Off();
	MPBar->SetTexture("MPBar.png");
	MPBar->ScaleToTexture();
	MPBar->GetTransform().SetLocalPosition(MPBarPivot);



}

void InterfaceHUD::Update(float _DeltaTime)
{

}