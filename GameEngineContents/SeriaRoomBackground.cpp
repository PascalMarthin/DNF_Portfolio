#include "PreCompile.h"
#include <GameEngineBase/GameEngineWindow.h>
#include "GamePlayEnum.h"
#include "SeriaRoomBackground.h"


SeriaRoomBackground::SeriaRoomBackground() 
	: Collision_SeriaRoom_OutDoor(nullptr)
{
}

SeriaRoomBackground::~SeriaRoomBackground() 
{
}

void SeriaRoomBackground::Start()
{
	Texture_BackGround = CreateComponent<GameEngineTextureRenderer>();
	//Texture_BackGround->GetTransform().SetLocalPosition({ 0, 0 });
	Texture_BackGround->CreateFrameAnimationFolder("Seria_BackGround", FrameAnimation_DESC("Seria_Room", 0.15f));
	Texture_BackGround->ChangeFrameAnimation("Seria_BackGround");
	Texture_BackGround->GetTransform().SetLocalScale({ 1280, 720 });
	//Texture_BackGround->ScaleToTexture();
	Texture_BackGround->SetPivot(PIVOTMODE::LEFTTOP);



	Texture_MapCollision = GameEngineTexture::Find("Seria_Room_Pixel.png");


	Collision_SeriaRoom_OutDoor = CreateComponent<GameEngineCollision>();
	Collision_SeriaRoom_OutDoor->GetTransform().SetLocalScale({ 700, 200 });
	Collision_SeriaRoom_OutDoor->GetTransform().SetLocalPosition({ 640, -720 });
	Collision_SeriaRoom_OutDoor->ChangeOrder(CollisionOrder::ChangeMap);
	Collision_SeriaRoom_OutDoor->SetDebugSetting(CollisionType::CT_AABB, float4::GREEN);

}

void SeriaRoomBackground::Update(float _DeltaTime)
{
	if (Collision_SeriaRoom_OutDoor->IsCollision(CollisionType::CT_AABB, CollisionOrder::ChangeMap, CollisionType::CT_AABB,
		[](GameEngineCollision* _This, GameEngineCollision* _Other)
		{
			if (_Other->GetNameConstRef() == "Character_Map_Collision")
			{
				return true;
			}
			else
			{
				return false;
			}
		}))
	{
		// ChangeMap
	}
}
