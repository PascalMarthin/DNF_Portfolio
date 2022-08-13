#include "PreCompile.h"
#include "DungeonLoding_BackGround.h"
#include "DNF.h"

DungeonLoding_BackGround::DungeonLoding_BackGround() 
{
}

DungeonLoding_BackGround::~DungeonLoding_BackGround() 
{
}

void DungeonLoding_BackGround::Start()
{
	Texture_BackGround = CreateComponent<GameEngineTextureRenderer>();
	Texture_BackGround->SetTexture("DungeonLoading_BackGround_Luke.png");
	Texture_BackGround->ScaleToTexture();


}

void DungeonLoding_BackGround::Update(float _DeltaTime)
{

}