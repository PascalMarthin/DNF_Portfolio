#pragma once
#include <GameEngineCore/GameEngineDefaultRenderer.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>

// 설명 : 던파 아바타 시스템에 맞춘 텍스쳐렌더링클래스
enum class AvataClass;
enum class CharactorClass;
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


	void SetTextureForAvata(GameEngineTexture* _Texture);

	void SetTextureForAvata(const std::string& _Name);

	void SetFrameForAvata(UINT _Index);

	void SetTextureForAvata(const std::string& _Name, UINT _Index);

	void SetTextureForAvata(GameEngineTexture* _Texture, UINT _Index);

	void CreateFrameAnimationFolderForAvata(CharactorClass _CharactorClass,AvataClass _AvataClass, const FrameAnimation_DESC& _Desc);
	//void CreateFrameAnimation(const std::string& _AnimationName, const FrameAnimation_DESC& _Desc);

	void ChangeFrameAnimationForAvata(CharactorClass _CharactorClass, AvataClass _AvataClass);
	void ChangeTextureInFrameAnimationForAvata(CharactorClass _CharactorClass, AvataClass _AvataClass, const std::string& _FolderTexture);


protected:
	void Start() override;
	void Update(float _Delta) override;


private:
	GameEngineTexture* CurTex;
	float4 FrameData;

	std::map<CharactorClass, std::map<AvataClass, FrameAnimationForAvata>> FrameAni;
	FrameAnimationForAvata* CurAni;

	void FrameDataResetForAvata();
};

class FrameAnimationForAvata : public GameEngineNameObject
{
	friend GameEnginePlusTextureRenderer;

	FrameAnimation_DESC Info;

	GameEnginePlusTextureRenderer* ParentRenderer;
	GameEngineTexture* Texture;
	GameEngineFolderTexture* FolderTexture;

	bool bOnceStart;
	bool bOnceEnd;
	std::function<void(const FrameAnimation_DESC&)> Frame;
	std::function<void(const FrameAnimation_DESC&)> End;
	std::function<void(const FrameAnimation_DESC&)> Start;
	std::function<void(const FrameAnimation_DESC&, float)> Time;

	void Reset();

	void Update(float _DeltaTime);
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

enum class CharactorClass
{
	Fighter_F
};