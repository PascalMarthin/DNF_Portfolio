#include "PreCompile.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "MouseCursorComponent.h"
#include "GamePlayEnum.h"

MouseCursorComponent::MouseCursorComponent() 
	: Texture_Cursor(nullptr)
	, Collision_MouseCursor(nullptr)
{
}

MouseCursorComponent::~MouseCursorComponent() 
{
}

void MouseCursorComponent::Start()
{
	Texture_Cursor = CreateComponent<GameEngineTextureRenderer>();
	Texture_Cursor->SetTexture("Cursor_Basic.png");
	Texture_Cursor->ScaleToTexture();


	Collision_MouseCursor = CreateComponent<GameEngineCollision>("Collision_MouseCursor");
	Collision_MouseCursor->GetTransform().SetLocalScale({8, 8});
	Collision_MouseCursor->ChangeOrder(CollisionOrder::UI_ect);
}

void MouseCursorComponent::Update(float _DeltaTime)
{
	const float4& MousePos = GetLevel()->GetMainCamera()->GetMouseWorldPosition();
	Texture_Cursor->GetTransform().SetLocalPosition({ MousePos.x + 8.f , MousePos.y - 8.f, 0 });
	Collision_MouseCursor->GetTransform().SetLocalPosition({ MousePos.x - 8 , MousePos.y + 8 , 0 });
	//GameEngineDebug::OutPutString(std::to_string(Texture_Cursor->GetTransform().GetLocalPosition().x) + " / " + std::to_string(Texture_Cursor->GetTransform().GetLocalPosition().y) + " / " + std::to_string(Texture_Cursor->GetTransform().GetLocalPosition().z));
}