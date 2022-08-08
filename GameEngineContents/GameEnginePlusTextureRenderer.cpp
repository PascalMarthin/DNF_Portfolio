#pragma once
#include "PreCompile.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include <GameEngineCore/GameEngineFolderTexture.h>

#include "GameEnginePlusTextureRenderer.h"

GameEnginePlusTextureRenderer::GameEnginePlusTextureRenderer()
	: CurrentAvata(nullptr)
	, CurrentAniPlus(nullptr)
	, DefaultCharacterAvata(nullptr)
	, ManualControl(false)
	, MC_CurFrame(0)
	, EndFrame(false)
{

}

GameEnginePlusTextureRenderer::~GameEnginePlusTextureRenderer()
{

}



void GameEnginePlusTextureRenderer::Start()
{
	GameEngineTextureRenderer::Start();
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
			if (false == bOnceEnd && nullptr != End)
			{
				End(Info);
				bOnceEnd = true;
				bOnceStart = false;
			}

			if (true == Info.Loop)
			{
				Info.CurFrame = 0;
			}
			else
			{
				Info.CurFrame = static_cast<unsigned int>(Info.Frames.size()) - 1;
			}
		}

		if (nullptr == (*FolderTextureDouble))
		{
			if ((*DefaultCharacterAvataDouble) != nullptr)
			{
				ParentRenderer->SetTexture((*DefaultCharacterAvataDouble)->GetTexture(Info.Frames[Info.CurFrame]));
			}
			else
			{
				ParentRenderer->SetTexture(Texture);
			}
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
}

void GameEnginePlusTextureRenderer::ChangeFolderTexturePlus(const std::string& _TextureName)
{
	CurrentAvata = GameEngineFolderTexture::Find(_TextureName);
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
		MsgBoxAssert("�̹� �����ϴ� �ִϸ��̼��� �� ������� �߽��ϴ�.");
		return;
	}

	CurrentAvata = GameEngineFolderTexture::Find(_Desc.TextureName);

	FrameAnimationForAvata& NewAni = FrameAniPlus[Name];
	NewAni.Info = _Desc;
	NewAni.ParentRenderer = this;
	NewAni.Texture = GameEngineTexture::Find("Null.png");
	NewAni.FolderTextureDouble = &CurrentAvata;
	NewAni.DefaultCharacterAvataDouble = &DefaultCharacterAvata;
}


void GameEnginePlusTextureRenderer::ChangeFrameAnimationPlus(const std::string& _AnimationName)
{
	//if (CurrentAvata == nullptr)
	//{
	//	MsgBoxAssert("���� ���� �ؽ��İ� ���õ��� �ʾҽ��ϴ�.");
	//	return;
	//}

	std::string Name = GameEngineString::ToUpperReturn(_AnimationName);

	if (FrameAniPlus.end() == FrameAniPlus.find(Name))
	{
		MsgBoxAssert("�������� �ʴ� �ִϸ��̼����� ü���� �Ϸ��� �߽��ϴ�.");
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
		else if (DefaultCharacterAvata != nullptr)
		{
			SetTexture(DefaultCharacterAvata->GetTexture(CurrentAniPlus->Info.Frames[0]));
		}
		else
		{
			SetTexture(CurrentAniPlus->Texture);
		}
	}
}
void GameEnginePlusTextureRenderer::SetDefaultCharacterAvata(const std::string& _TextureName)
{
	SetDefaultCharacterAvata(GameEngineFolderTexture::Find(_TextureName));
}


void GameEnginePlusTextureRenderer::SetDefaultCharacterAvata(GameEngineFolderTexture* _FolderTexture)
{
	if (DefaultCharacterAvata != nullptr)
	{
		MsgBoxAssert("�̹� ����Ʈ �ƹ�Ÿ�� �����Ǿ� �ֽ��ϴ�")
	}
	DefaultCharacterAvata = _FolderTexture;
}

void GameEnginePlusTextureRenderer::SetManualControl()
{
	ManualControl = true;
	MC_CurFrame = CurrentAniPlus->Info.CurFrame;

}

void GameEnginePlusTextureRenderer::SetAutoControl()
{
	CurrentAniPlus->Reset();
	if (CurrentAvata != nullptr)
	{
		SetTexture(CurrentAvata->GetTexture(CurrentAniPlus->Info.CurFrame));
	}
	else if (DefaultCharacterAvata != nullptr)
	{
		SetTexture(DefaultCharacterAvata->GetTexture(CurrentAniPlus->Info.CurFrame));
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
	SetTexture(CurrentAvata->GetTexture(MC_CurFrame));
}