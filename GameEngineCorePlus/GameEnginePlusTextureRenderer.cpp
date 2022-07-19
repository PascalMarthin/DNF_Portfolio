//#pragma once
//#include <GameEngineBase/GameEngineDebug.h>
//#include <GameEngineCore/GameEngineTextureRenderer.h>
////#include <GameEngineCore/GameEngineFolderTexture.h>
//
//#include "GameEnginePlusTextureRenderer.h"
//
//GameEnginePlusTextureRenderer::GameEnginePlusTextureRenderer()
//	: CurrentAvata(nullptr)
//	, CurrentAniPlus(nullptr)
//{
//
//}
//
//GameEnginePlusTextureRenderer::~GameEnginePlusTextureRenderer()
//{
//
//}
//
//
//
//void GameEnginePlusTextureRenderer::Start()
//{
//	GameEngineTextureRenderer::Start();
//}
//
//void FrameAnimationForAvata::Reset()
//{
//	Info.FrameTime = 0.0f;
//	Info.CurFrame = Info.Start;
//}
//
//void FrameAnimationForAvata::Update(float _Delta)
//{
//	Info.FrameTime += _Delta;
//
//	if (nullptr != Time)
//	{
//		Time(Info, _Delta);
//	}
//
//	if (false == bOnceStart
//		&& Info.CurFrame == Info.Start
//		&& nullptr != Start)
//	{
//		Start(Info);
//		bOnceStart = true;
//		bOnceEnd = false;
//	}
//
//	if (Info.Inter <= Info.FrameTime)
//	{
//		++Info.CurFrame;
//		if (nullptr != Frame)
//		{
//			Frame(Info);
//		}
//
//		if (nullptr != FolderTextureDouble)
//		{
//			ParentRenderer->SetTexture((*FolderTextureDouble)->GetTexture(Info.CurFrame));
//		}
//		else
//		{
//			MsgBoxAssert("텍스처가 세팅되지 않은 애니메이션 입니다.");
//		}
//
//		if (Info.CurFrame >= Info.End)
//		{
//			if (false == bOnceEnd && nullptr != End)
//			{
//				End(Info);
//				bOnceEnd = true;
//				bOnceStart = false;
//			}
//
//			if (true == Info.Loop)
//			{
//				Info.CurFrame = Info.Start;
//			}
//			else 
//			{
//				Info.CurFrame = Info.End;
//			}
//		}
//
//		Info.FrameTime -= Info.Inter;
//	}
//}
//
//void GameEnginePlusTextureRenderer::Update(float _Delta)
//{
//	if (nullptr != CurrentAniPlus)
//	{
//		CurrentAniPlus->Update(_Delta);
//	}
//}
//
//void GameEnginePlusTextureRenderer::ChangeFolderTexturePlus(const std::string& _TextureName)
//{
//	CurrentAvata = GameEngineFolderTexture::Find(_TextureName);
//}
//
//void GameEnginePlusTextureRenderer::ChangeFolderTexturePlus(GameEngineFolderTexture* _Texture)
//{
//	CurrentAvata = _Texture;
//}
//
//
//void GameEnginePlusTextureRenderer::CreateFrameAnimationFolderPlus(const std::string& _AnimationName, const FrameAnimation_DESC& _Desc)
//{
//	std::string Name = GameEngineString::ToUpperReturn(_AnimationName);
//
//	if (FrameAniPlus.end() != FrameAniPlus.find(Name))
//	{
//		MsgBoxAssert("이미 존재하는 애니메이션을 또 만들려고 했습니다.");
//		return;
//	}
//
//	CurrentAvata = GameEngineFolderTexture::Find(_Desc.TextureName);
//
//	FrameAnimationForAvata& NewAni = FrameAniPlus[Name];
//	NewAni.Info = _Desc;
//	NewAni.ParentRenderer = this;
//	NewAni.FolderTextureDouble = &CurrentAvata;
//}
//
//
//void GameEnginePlusTextureRenderer::ChangeFrameAnimationPlus(const std::string& _AnimationName)
//{
//	if (CurrentAvata == nullptr)
//	{
//		MsgBoxAssert("아직 폴더 텍스쳐가 세팅되지 않았습니다.");
//		return;
//	}
//
//	std::string Name = GameEngineString::ToUpperReturn(_AnimationName);
//
//	if (FrameAniPlus.end() == FrameAniPlus.find(Name))
//	{
//		MsgBoxAssert("존재하지 않는 애니메이션으로 체인지 하려고 했습니다.");
//		return;
//	}
//
//	if (CurrentAniPlus != &FrameAniPlus[Name])
//	{
//		CurrentAniPlus = &FrameAniPlus[Name];
//		CurrentAniPlus->Reset();
//		SetTexture(CurrentAvata->GetTexture(CurrentAniPlus->Info.CurFrame));
//	}
//}

//// 시작 프레임에 들어온다.
//void GameEngineTextureRenderer::AnimationBindStart(const std::string& _AnimationName, std::function<void(const FrameAnimation_DESC&)> Function)
//{
//	std::string Name = GameEngineString::ToUpperReturn(_AnimationName);
//
//	if (FrameAni.end() == FrameAni.find(Name))
//	{
//		MsgBoxAssert("존재하지 않는 애니메이션으로 체인지 하려고 했습니다.");
//		return;
//	}
//
//	FrameAni[Name].Start = Function;
//}
//// 끝나는 프레임에 들어온다
//void GameEngineTextureRenderer::AnimationBindEnd(const std::string& _AnimationName, std::function<void(const FrameAnimation_DESC&)> Function)
//{
//	std::string Name = GameEngineString::ToUpperReturn(_AnimationName);
//
//	if (FrameAni.end() == FrameAni.find(Name))
//	{
//		MsgBoxAssert("존재하지 않는 애니메이션으로 체인지 하려고 했습니다.");
//		return;
//	}
//
//	FrameAni[Name].End = Function;
//}
//// 프레임이 바뀔때마다 들어온다
//void GameEngineTextureRenderer::AnimationBindFrame(const std::string& _AnimationName, std::function<void(const FrameAnimation_DESC&)> Function)
//{
//	std::string Name = GameEngineString::ToUpperReturn(_AnimationName);
//
//	if (FrameAni.end() == FrameAni.find(Name))
//	{
//		MsgBoxAssert("존재하지 않는 애니메이션으로 체인지 하려고 했습니다.");
//		return;
//	}
//
//	FrameAni[Name].Frame = Function;
//}