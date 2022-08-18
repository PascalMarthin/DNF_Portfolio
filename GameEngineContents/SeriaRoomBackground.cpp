#include "PreCompile.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineCore/GEngine.h>
#include "GamePlayEnum.h"
#include "DummyActor.h"
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
	Texture_BackGround->SetPivot(PIVOTMODE::LEFTTOP);
	//Texture_BackGround->ScaleToTexture();



	Texture_MapCollision = GameEngineTexture::Find("Seria_Room_Pixel.png");


	Collision_SeriaRoom_OutDoor = GetLevel()->CreateActor<DummyActor>()->CreateComponent<GameEngineCollision>();
	Collision_SeriaRoom_OutDoor->GetTransform().SetLocalScale({ 700.f, 100.f , 50.f });
	Collision_SeriaRoom_OutDoor->GetTransform().SetWorldPosition({ 640, -720 + 80, 80 });
	Collision_SeriaRoom_OutDoor->ChangeOrder(CollisionOrder::ChangeMap);
	Collision_SeriaRoom_OutDoor->SetDebugSetting(CollisionType::CT_AABB, float4::GREEN);

	SetBackGroundZOrder();

}

void SeriaRoomBackground::Update(float _DeltaTime)
{
	if (Collision_SeriaRoom_OutDoor->IsCollision(CollisionType::CT_AABB, CollisionOrder::Player_Floor, CollisionType::CT_AABB,
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
		GEngine::ChangeLevel("Jelva_1F");
	}
}
