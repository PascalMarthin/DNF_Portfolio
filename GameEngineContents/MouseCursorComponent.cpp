#include "PreCompile.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "MouseCursorComponent.h"
#include "GamePlayEnum.h"

MouseCursorComponent::MouseCursorComponent() 
	: Texture_Cursor(nullptr)
	, Collision_MainCam_MouseCursor(nullptr)
	, Collision_UICam_MouseCursor(nullptr)
{
}

MouseCursorComponent::~MouseCursorComponent() 
{
}

void MouseCursorComponent::Start()
{
	Texture_Cursor = CreateComponent<GameEngineUIRenderer>();
	Texture_Cursor->SetTexture("Cursor_Basic.png");
	Texture_Cursor->ScaleToTexture();


	Collision_MainCam_MouseCursor = CreateComponent<GameEngineCollision>("Collision_MainCam_MouseCursor");
	Collision_MainCam_MouseCursor->GetTransform().SetLocalScale({8, 8});
	Collision_MainCam_MouseCursor->ChangeOrder(CollisionOrder::UI_MainMouse);

	Collision_UICam_MouseCursor = CreateComponent<GameEngineCollision>("Collision_UICam_MouseCursor");
	Collision_UICam_MouseCursor->GetTransform().SetLocalScale({ 8, 8 });
	Collision_UICam_MouseCursor->ChangeOrder(CollisionOrder::UI_UIMouse);
}

void MouseCursorComponent::Update(float _DeltaTime)
{
	const float4& MainMousePos = GetLevel()->GetMainCamera()->GetMouseWorldPosition();
	Texture_Cursor->GetTransform().SetLocalPosition({ MainMousePos.x + 8.f , MainMousePos.y - 8.f, -100.f });
	Collision_MainCam_MouseCursor->GetTransform().SetLocalPosition({ MainMousePos.x - 8 , MainMousePos.y + 8 , 0 });

	const float4& UIMousePos = GetLevel()->GetUICamera()->GetMouseWorldPositionToActor();
	Collision_UICam_MouseCursor->GetTransform().SetLocalPosition({ UIMousePos.x - 8 , UIMousePos.y + 8 , 0 });

	//GameEngineDebug::OutPutString(std::to_string(Texture_Cursor->GetTransform().GetLocalPosition().x) + " / " + std::to_string(Texture_Cursor->GetTransform().GetLocalPosition().y) + " / " + std::to_string(Texture_Cursor->GetTransform().GetLocalPosition().z));
}

void MouseCursorComponent::LevelStartEvent()
{

}