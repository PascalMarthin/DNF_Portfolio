#include "PreCompile.h"
#include "Jelva_2F01.h"
#include "MoveManager.h"
#include "Jelva2F01_WaveBackGround.h"

Jelva_2F01::Jelva_2F01() 
	: Texture_Jelva2F01(nullptr)
	, Player_Fighter(nullptr)
	, Texture_Jelva2F01_Wave(nullptr)
{
}

Jelva_2F01::~Jelva_2F01() 
{
}


void Jelva_2F01::Start()
{
	Texture_Jelva2F01 = CreateActor<Jelva2F01_BackGround>();
	Texture_Jelva2F01_Wave = CreateActor<Jelva2F01_WaveBackGround>();

	float Hight = Texture_Jelva2F01->GetBackGroundTextureScale().y;
	float Width = Texture_Jelva2F01->GetBackGroundTextureScale().x;
	Texture_Jelva2F01->GetTransform().SetLocalPosition({ 0, 0, Hight + static_cast<float>(ZSortOrder::BackGround) });
	Texture_Jelva2F01_Wave->GetTransform().SetLocalPosition({ 0, 0, Hight + static_cast<float>(ZSortOrder::BackGround) });

	Player_Fighter = CreateActor<GamePlayCharacter>();
	Player_Fighter->GetTransform().SetLocalPosition({ GameEngineWindow::GetScale().hx(), -GameEngineWindow::GetScale().hy() - 200.f, Hight - GameEngineWindow::GetScale().hy() - 200.f + static_cast<float>(ZSortOrder::Character_Avata) - static_cast<float>(ZSortOrder::Character_Fighter_F) });
	GetMainCameraActor()->GetTransform().SetWorldMove(Player_Fighter->GetTransform().GetLocalPosition());

}

void Jelva_2F01::Update(float _DeltaTime)
{

	float4 Pos = Player_Fighter->GetMoveManager()->GetMoveCollision()->GetTransform().GetLocalPosition();
	if (!GetMainCameraActor()->IsFreeCameraMode())
	{
		if (Pos.x <= 642.f)
		{
			Pos.x = 642.f;
		}
		else if (Pos.x >= 1000.f)
		{
			Pos.x = 1000.f;
		}

		if ((Pos.y >= -609.f))
		{
			Pos.y = -609.f;
		}
		else if (Pos.y <= -747.f)
		{
			Pos.y = -747.f;
		}
		Pos.y += 100.f;

		GetMainCameraActor()->GetTransform().SetWorldPosition(Pos);

	}
	{
		Pos.x = (Pos.x - 800.f) * 0.5f;
		Pos.y = 0.f;
		Pos.z = Texture_Jelva2F01_Wave->GetTransform().GetLocalPosition().z;
		Texture_Jelva2F01_Wave->GetTransform().SetLocalPosition(Pos);
	}

}


void Jelva_2F01::OnEvent()
{
	float Hight = Texture_Jelva2F01->GetBackGroundTextureScale().y;
	if (GamePlayDataBase::GetCurrentCharacterData()->GetCurrentMap() == TownMap::Jelva2F)
	{
		Player_Fighter->GetTransform().SetLocalPosition({ 200.f , -650.f , Hight - 650.f + static_cast<float>(ZSortOrder::Character_Avata) - static_cast<float>(ZSortOrder::Character_Fighter_F) });
	}
	//else if (GamePlayDataBase::GetCurrentCharacterData()->GetCurrentMap() == TownMap::Jelva2F_01)
	//{
	//	Player_Fighter->GetTransform().SetLocalPosition({ 2216.f  , -600.f , Hight - 600.f + static_cast<float>(ZSortOrder::Character_Avata) - static_cast<float>(ZSortOrder::Character_Fighter_F) });
	//}
	else// Debug
	{
		Player_Fighter->GetTransform().SetLocalPosition({ 800.f  , -700.f , Hight - 700.f + static_cast<float>(ZSortOrder::Character_Avata) - static_cast<float>(ZSortOrder::Character_Fighter_F) });
	}

	GamePlayDataBase::GetCurrentCharacterData()->SetCurrentMap(TownMap::Jelva2F_01);
}