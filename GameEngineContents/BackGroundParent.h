#pragma once
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "GamePlayEnum.h"

// Ό³Έν :
class BackGroundParent : public GameEngineActor
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
	void Start() override;

	inline void SetBackGroundZOrder()
	{
		GetTransform().SetLocalPosition({ 0, 0, GetBackGroundTextureScale().y + static_cast<float>(ZSortOrder::BackGround) });
	}


	GameEngineTextureRenderer* Texture_BackGround;

	GameEngineTexture* Texture_MapCollision;
private:

};

