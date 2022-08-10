#pragma once
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>

// Ό³Έν :
class BackGroundParent
{
public:
	// constrcuter destructer
	BackGroundParent();
	~BackGroundParent();

	// delete Function
	BackGroundParent(const BackGroundParent& _Other) = delete;
	BackGroundParent(BackGroundParent&& _Other) noexcept = delete;
	BackGroundParent& operator=(const BackGroundParent& _Other) = delete;
	BackGroundParent& operator=(BackGroundParent&& _Other) noexcept = delete;

	inline GameEngineTexture* GetCollisionTexture() const
	{
		return Texture_MapCollision;
	}
	inline float4 GetBackGroundTextureScale()
	{
		return Texture_BackGround->GetTransform().GetWorldScale();
	}

protected:
	GameEngineTextureRenderer* Texture_BackGround;

	GameEngineTexture* Texture_MapCollision;
private:

};

