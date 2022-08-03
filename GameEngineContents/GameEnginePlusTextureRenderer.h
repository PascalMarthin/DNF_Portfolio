#pragma once
#include <GameEngineCore/GameEngineTextureRenderer.h>

// 설명 : 던파 아바타 시스템에 맞춘 텍스쳐렌더링클래스
// 폴더 텍스쳐 하나로만 이루어져 있으며 같은 주소값을 공유한다
enum class AvataClass;
enum class AllCharacterClass;
class GameEnginePlusTextureRenderer;
class FrameAnimationForAvata : public GameEngineNameObject
{
	friend GameEnginePlusTextureRenderer;

	FrameAnimation_DESC Info;

	GameEnginePlusTextureRenderer* ParentRenderer;
	GameEngineFolderTexture** FolderTextureDouble;
	GameEngineFolderTexture** DefaultCharacterAvataDouble;
	GameEngineTexture* Texture;

	bool bOnceStart;
	bool bOnceEnd;
	std::function<void(const FrameAnimation_DESC&)> Frame;
	std::function<void(const FrameAnimation_DESC&)> End;
	std::function<void(const FrameAnimation_DESC&)> Start;
	std::function<void(const FrameAnimation_DESC&, float)> Time;

	inline FrameAnimation_DESC& GetInfo()
	{
		return Info;
	}
	// 레퍼런스로 반환함

	void Reset();

	void Update(float _DeltaTime);

};
class GameEnginePlusTextureRenderer : public GameEngineTextureRenderer
{
	friend FrameAnimationForAvata;
public:
	// constrcuter destructer
	GameEnginePlusTextureRenderer();
	~GameEnginePlusTextureRenderer();

	// delete Function
	GameEnginePlusTextureRenderer(const GameEnginePlusTextureRenderer& _Other) = delete;
	GameEnginePlusTextureRenderer(GameEnginePlusTextureRenderer&& _Other) noexcept = delete;
	GameEnginePlusTextureRenderer& operator=(const GameEnginePlusTextureRenderer& _Other) = delete;
	GameEnginePlusTextureRenderer& operator=(GameEnginePlusTextureRenderer&& _Other) noexcept = delete;


	inline bool IsEndFrame() const
	{
		return EndFrame;
	}
	void SetDefaultCharacterAvata(const std::string& _TextureName);
	void SetDefaultCharacterAvata(GameEngineFolderTexture* _FolderTexture);

	void ChangeFolderTexturePlus(const std::string& _TextureName);
	void ChangeFolderTexturePlus(GameEngineFolderTexture* _Texture);

	void CreateFrameAnimationFolderPlus(const std::string& _AnimationName, const FrameAnimation_DESC& _Desc);
	//void CreateFrameAnimation(const std::string& _AnimationName, const FrameAnimation_DESC& _Desc);

	void ChangeFrameAnimationPlus(const std::string& _AnimationName);

	bool EndFrame;


	// 수동 조작관련
	void SetManualControl();
	void SetAutoControl();
	void SetFrame_Manual(int _Frame);
private:
	bool ManualControl;
	//

	int MC_CurFrame;

public:
	// 시작 프레임에 들어온다.
	template<typename ObjectType>
	void AnimationBindStart(const std::string& _AnimationName, void(ObjectType::* _Ptr)(const FrameAnimation_DESC&), ObjectType* _This)
	{
		std::string Name = GameEngineString::ToUpperReturn(_AnimationName);

		if (FrameAniPlus.end() == FrameAniPlus.find(Name))
		{
			MsgBoxAssert("존재하지 않는 애니메이션으로 할당 하려고 했습니다.");
			return;
		}

		FrameAniPlus[Name].Start = std::bind(_Ptr, _This, FrameAniPlus[Name].Info);
	}
	// 끝나는 프레임에 들어온다
	template<typename ObjectType>
	void AnimationBindEnd(const std::string& _AnimationName, void(ObjectType::* _Ptr)(const FrameAnimation_DESC&), ObjectType* _This)
	{
		std::string Name = GameEngineString::ToUpperReturn(_AnimationName);

		if (FrameAniPlus.end() == FrameAniPlus.find(Name))
		{
			MsgBoxAssert("존재하지 않는 애니메이션으로 할당 하려고 했습니다.");
			return;
		}

		FrameAniPlus[Name].End = std::bind(_Ptr, _This, FrameAniPlus[Name].Info);
	}
	// 프레임이 바뀔때마다 들어온다
	template<typename ObjectType>
	void AnimationBindFrame(const std::string& _AnimationName, void(ObjectType::* _Ptr)(const FrameAnimation_DESC&), ObjectType* _This)
	{
		std::string Name = GameEngineString::ToUpperReturn(_AnimationName);

		if (FrameAniPlus.end() == FrameAniPlus.find(Name))
		{
			MsgBoxAssert("존재하지 않는 애니메이션으로 할당 하려고 했습니다.");
			return;
		}

		FrameAniPlus[Name].Frame = std::bind(_Ptr, _This, FrameAniPlus[Name].Info);
	}
	// Update
	template<typename ObjectType>
	void AnimationBindTime(const std::string& _AnimationName, void(ObjectType::* _Ptr)(const FrameAnimation_DESC&), ObjectType* _This)
	{
		std::string Name = GameEngineString::ToUpperReturn(_AnimationName);

		if (FrameAniPlus.end() == FrameAniPlus.find(Name))
		{
			MsgBoxAssert("존재하지 않는 애니메이션으로 할당 하려고 했습니다.");
			return;
		}

		FrameAniPlus[Name].Time = std::bind(_Ptr, _This, FrameAniPlus[Name].Info);
	}

	//// 전역
	//void AnimationBindStart(const std::string& _AnimationName, void(*_Ptr)(const FrameAnimation_DESC&))
	//{
	//	std::string Name = GameEngineString::ToUpperReturn(_AnimationName);

	//	if (FrameAniPlus.end() == FrameAniPlus.find(Name))
	//	{
	//		MsgBoxAssert("존재하지 않는 애니메이션으로 할당 하려고 했습니다.");
	//		return;
	//	}

	//	FrameAniPlus[Name].Start = std::bind(_Ptr, FrameAniPlus[Name].Info);
	//}

	//// 끝나는 프레임에 들어온다
	//void AnimationBindEnd(const std::string& _AnimationName, void(*_Ptr)(const FrameAnimation_DESC&))
	//{
	//	std::string Name = GameEngineString::ToUpperReturn(_AnimationName);

	//	if (FrameAniPlus.end() == FrameAniPlus.find(Name))
	//	{
	//		MsgBoxAssert("존재하지 않는 애니메이션으로 할당 하려고 했습니다.");
	//		return;
	//	}

	//	FrameAniPlus[Name].End = std::bind(_Ptr, FrameAniPlus[Name].Info);
	//}
	//// 프레임이 바뀔때마다 들어온다
	//void AnimationBindFrame(const std::string& _AnimationName, void(*_Ptr)(const FrameAnimation_DESC&))
	//{
	//	std::string Name = GameEngineString::ToUpperReturn(_AnimationName);

	//	if (FrameAniPlus.end() == FrameAniPlus.find(Name))
	//	{
	//		MsgBoxAssert("존재하지 않는 애니메이션으로 할당 하려고 했습니다.");
	//		return;
	//	}

	//	FrameAniPlus[Name].Frame = std::bind(_Ptr, FrameAniPlus[Name].Info);
	//}
	//// Update
	//void AnimationBindTime(const std::string& _AnimationName, void(*_Ptr)(const FrameAnimation_DESC&))
	//{
	//	std::string Name = GameEngineString::ToUpperReturn(_AnimationName);

	//	if (FrameAniPlus.end() == FrameAniPlus.find(Name))
	//	{
	//		MsgBoxAssert("존재하지 않는 애니메이션으로 할당 하려고 했습니다.");
	//		return;
	//	}

	//	FrameAniPlus[Name].Time = std::bind(_Ptr, FrameAniPlus[Name].Info);
	//}

protected:
	void Start() override;
	void Update(float _Delta) override;


private:
	GameEngineFolderTexture* CurrentAvata;

	GameEngineFolderTexture* DefaultCharacterAvata;

	std::map<std::string, FrameAnimationForAvata> FrameAniPlus;
	FrameAnimationForAvata* CurrentAniPlus;

};

enum class AvataClass
{
	Belt,
	Cap,
	Coat,
	Face,
	Hair,
	Neck,
	Pants,
	Shoes,
	Skin
};
