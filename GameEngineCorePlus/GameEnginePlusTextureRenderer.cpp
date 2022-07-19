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
//			MsgBoxAssert("�ؽ�ó�� ���õ��� ���� �ִϸ��̼� �Դϴ�.");
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
//		MsgBoxAssert("�̹� �����ϴ� �ִϸ��̼��� �� ������� �߽��ϴ�.");
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
//		MsgBoxAssert("���� ���� �ؽ��İ� ���õ��� �ʾҽ��ϴ�.");
//		return;
//	}
//
//	std::string Name = GameEngineString::ToUpperReturn(_AnimationName);
//
//	if (FrameAniPlus.end() == FrameAniPlus.find(Name))
//	{
//		MsgBoxAssert("�������� �ʴ� �ִϸ��̼����� ü���� �Ϸ��� �߽��ϴ�.");
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

//// ���� �����ӿ� ���´�.
//void GameEngineTextureRenderer::AnimationBindStart(const std::string& _AnimationName, std::function<void(const FrameAnimation_DESC&)> Function)
//{
//	std::string Name = GameEngineString::ToUpperReturn(_AnimationName);
//
//	if (FrameAni.end() == FrameAni.find(Name))
//	{
//		MsgBoxAssert("�������� �ʴ� �ִϸ��̼����� ü���� �Ϸ��� �߽��ϴ�.");
//		return;
//	}
//
//	FrameAni[Name].Start = Function;
//}
//// ������ �����ӿ� ���´�
//void GameEngineTextureRenderer::AnimationBindEnd(const std::string& _AnimationName, std::function<void(const FrameAnimation_DESC&)> Function)
//{
//	std::string Name = GameEngineString::ToUpperReturn(_AnimationName);
//
//	if (FrameAni.end() == FrameAni.find(Name))
//	{
//		MsgBoxAssert("�������� �ʴ� �ִϸ��̼����� ü���� �Ϸ��� �߽��ϴ�.");
//		return;
//	}
//
//	FrameAni[Name].End = Function;
//}
//// �������� �ٲ𶧸��� ���´�
//void GameEngineTextureRenderer::AnimationBindFrame(const std::string& _AnimationName, std::function<void(const FrameAnimation_DESC&)> Function)
//{
//	std::string Name = GameEngineString::ToUpperReturn(_AnimationName);
//
//	if (FrameAni.end() == FrameAni.find(Name))
//	{
//		MsgBoxAssert("�������� �ʴ� �ִϸ��̼����� ü���� �Ϸ��� �߽��ϴ�.");
//		return;
//	}
//
//	FrameAni[Name].Frame = Function;
//}