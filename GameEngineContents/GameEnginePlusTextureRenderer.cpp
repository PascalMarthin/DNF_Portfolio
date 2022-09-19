#pragma once
#include "PreCompile.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include <GameEngineCore/GameEngineFolderTexture.h>

#include "GameEnginePlusTextureRenderer.h"

GameEnginePlusTextureRenderer::GameEnginePlusTextureRenderer()
	: CurrentAvata(nullptr)
	, CurrentAniPlus(nullptr)
	, ManualControl(false)
	, MC_CurFrame(0)
	, EndFrame(false)
	, Texture_OutLine(nullptr)
{

}

GameEnginePlusTextureRenderer::~GameEnginePlusTextureRenderer()
{

}



void GameEnginePlusTextureRenderer::Start()
{
	GameEngineTextureRenderer::Start();

	SetPipeLine("Texture_Avata");

	ChangeCamera(CAMERAORDER::Object);
	ShaderResources.SetConstantBufferLink("PixelData", GetPixelData());

	Texture_OutLine = GetActor()->CreateComponent<GameEngineTextureRenderer>();
	Texture_OutLine->GetTransform().SetLocalScale({ 500, 500 });
	Texture_OutLine->SetPipeLine("OutLine");
	Texture_OutLine->ShaderResources.SetConstantBufferLink("PixelData", Texture_OutLine->GetPixelData());
	Texture_OutLine->GetTransform().SetLocalMove({ 0, 0, 0.01f });
	Texture_OutLine->GetPixelData().MulColor = float4::ZERO;
	Texture_OutLine->GetPixelData().PlusColor = float4::YELLOW;
	Texture_OutLine->ChangeCamera(CAMERAORDER::Object);
	//Renderer->SetPipeLine("Outline");
	//Renderer->ShaderResources.SetConstantBufferLink("PixelData", Renderer->GetPixelData());

	//Renderer->ShaderResources.SetConstantBufferLink("AtlasData", Renderer->Geta);
}

void FrameAnimationForAvata::Reset()
{
	Info.FrameTime = 0.0f;
	Info.CurFrame = 0;
}

void FrameAnimationForAvata::Update(float _Delta)
{
	Info.FrameTime += _Delta;

	if (nullptr != Time)
	{
		Time(Info, _Delta);
	}


	if (false == bOnceStart
		&& Info.CurFrame == 0)
	{
		if (nullptr != Start)
		{
			Start(Info);
		}
		bOnceStart = true;
		bOnceEnd = false;
	}

	if (Info.Inter <= Info.FrameTime)
	{
		++Info.CurFrame;
		if (nullptr != Frame)
		{
			Frame(Info);
		}

		if (Info.CurFrame >= Info.Frames.size())
		{
			ParentRenderer->EndFrame = true;
			if (false == bOnceEnd && nullptr != End)
			{
				End(Info);
				bOnceEnd = true;
				bOnceStart = false;
			}

			if (true == Info.Loop)
			{
				Info.CurFrame = 0;
				ParentRenderer->EndFrame = false;
			}
			else
			{
				Info.CurFrame = static_cast<unsigned int>(Info.Frames.size()) - 1;
			}
		}

		if (nullptr == (*FolderTextureDouble))
		{
			ParentRenderer->SetTexture(Texture);
		}
		else
		{
			ParentRenderer->SetTexture((*FolderTextureDouble)->GetTexture(Info.Frames[Info.CurFrame]));
		}

		Info.FrameTime -= Info.Inter;
	}
}

void GameEnginePlusTextureRenderer::Update(float _Delta)
{
	if (nullptr != CurrentAniPlus && ManualControl == false)
	{
		CurrentAniPlus->Update(_Delta);
	}
	
	//if (Texture_OutLine != nullptr)
	//{
	//	Texture_OutLine->SetTexture(GetCurTexture());
	//}
	//
}



void GameEnginePlusTextureRenderer::SetTexture(GameEngineTexture* _Texture)
{
	if (nullptr == _Texture)
	{
		MsgBoxAssert("존재하지 않는 텍스처를 사용하려고 했습니다.");
		return;
	}

	GameEngineTextureRenderer::SetTexture(_Texture);
	Texture_OutLine->SetTexture(_Texture);
}

void GameEnginePlusTextureRenderer::SetTexture(const std::string& _Name)
{
	GameEngineTextureRenderer::SetTexture(_Name);
	Texture_OutLine->SetTexture(_Name);
}



void GameEnginePlusTextureRenderer::ChangeFolderTexturePlus(const std::string& _TextureName)
{
	GameEngineFolderTexture* Texure = GameEngineFolderTexture::Find(_TextureName);
	if (Texure == nullptr)
	{
		MsgBoxAssert("이름이 잘못된 아바타를 불러오려고 하였습니다")
	}
	CurrentAvata = Texure;
}

void GameEnginePlusTextureRenderer::ChangeFolderTexturePlus(GameEngineFolderTexture* _Texture)
{
	CurrentAvata = _Texture;
}


void GameEnginePlusTextureRenderer::CreateFrameAnimationFolderPlus(const std::string& _AnimationName, const FrameAnimation_DESC& _Desc)
{
	std::string Name = GameEngineString::ToUpperReturn(_AnimationName);

	if (FrameAniPlus.end() != FrameAniPlus.find(Name))
	{
		MsgBoxAssert("이미 존재하는 애니메이션을 또 만들려고 했습니다.");
		return;
	}

	//CurrentAvata = GameEngineFolderTexture::Find(_Desc.TextureName);

	FrameAnimationForAvata& NewAni = FrameAniPlus[Name];
	NewAni.Info = _Desc;
	NewAni.ParentRenderer = this;
	NewAni.Texture = GameEngineTexture::Find("Null.png");
	NewAni.FolderTextureDouble = &CurrentAvata;
}


void GameEnginePlusTextureRenderer::ChangeFrameAnimationPlus(const std::string& _AnimationName)
{
	//if (CurrentAvata == nullptr)
	//{
	//	MsgBoxAssert("아직 폴더 텍스쳐가 세팅되지 않았습니다.");
	//	return;
	//}

	std::string Name = GameEngineString::ToUpperReturn(_AnimationName);

	if (FrameAniPlus.end() == FrameAniPlus.find(Name))
	{
		MsgBoxAssert("존재하지 않는 애니메이션으로 체인지 하려고 했습니다.");
		return;
	}

	EndFrame = false;

	if (CurrentAniPlus != &FrameAniPlus[Name])
	{
		CurrentAniPlus = &FrameAniPlus[Name];
		CurrentAniPlus->Reset();
		if (CurrentAvata != nullptr)
		{
			SetTexture(CurrentAvata->GetTexture(CurrentAniPlus->Info.Frames[0]));
		}
		else
		{
			SetTexture(CurrentAniPlus->Texture);
		}
	}
}


void GameEnginePlusTextureRenderer::SetManualControl()
{
	ManualControl = true;
	MC_CurFrame = CurrentAniPlus->Info.CurFrame;

}

void GameEnginePlusTextureRenderer::SetAutoControl(bool _Reset)
{
	if (_Reset)
	{
		CurrentAniPlus->Reset();
	}

	if (CurrentAvata != nullptr)
	{
		SetTexture(CurrentAvata->GetTexture(CurrentAniPlus->Info.Frames[MC_CurFrame]));
	}
	else
	{
		SetTexture(CurrentAniPlus->Texture);
	}
	ManualControl = false;


}

void GameEnginePlusTextureRenderer::SetFrame_Manual(int _Frame)
{
	if (_Frame == -1)
	{
		++MC_CurFrame;
	}
	else
	{
		MC_CurFrame = _Frame;
	}

	if (CurrentAvata != nullptr)
	{
		SetTexture(CurrentAvata->GetTexture(CurrentAniPlus->Info.Frames[MC_CurFrame]));
	}
	else
	{
		SetTexture(CurrentAniPlus->Texture);
	}
	
}