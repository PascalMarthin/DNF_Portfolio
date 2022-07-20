#pragma once
#include <GameEngineCore/GameEngineTextureRenderer.h>

// ���� : ���� �ƹ�Ÿ �ý��ۿ� ���� �ؽ��ķ�����Ŭ����
// ���� �ؽ��� �ϳ��θ� �̷���� ������ ���� �ּҰ��� �����Ѵ�
enum class AvataClass;
enum class CharactorClass;
class FrameAnimationForAvata;
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

	void SetDefaultCharactorAvata(const std::string& _TextureName);
	void SetDefaultCharactorAvata(GameEngineFolderTexture* _FolderTexture);

	void ChangeFolderTexturePlus(const std::string& _TextureName);
	void ChangeFolderTexturePlus(GameEngineFolderTexture* _Texture);

	void CreateFrameAnimationFolderPlus(const std::string& _AnimationName, const FrameAnimation_DESC& _Desc);
	//void CreateFrameAnimation(const std::string& _AnimationName, const FrameAnimation_DESC& _Desc);

	void ChangeFrameAnimationPlus(const std::string& _AnimationName);


protected:
	void Start() override;
	void Update(float _Delta) override;


private:
	GameEngineFolderTexture* CurrentAvata;

	GameEngineFolderTexture* DefaultCharactorAvata;

	std::map<std::string, FrameAnimationForAvata> FrameAniPlus;
	FrameAnimationForAvata* CurrentAniPlus;

};

class FrameAnimationForAvata : public GameEngineNameObject
{
	friend GameEnginePlusTextureRenderer;

	FrameAnimation_DESC Info;

	GameEnginePlusTextureRenderer* ParentRenderer;
	GameEngineFolderTexture** FolderTextureDouble;
	GameEngineFolderTexture** DefaultCharactorAvataDouble;
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
	// ���۷����� ��ȯ��

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
