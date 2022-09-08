#pragma once
#include <list>
#include <map>
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineBase/GameEngineMath.h>
#include <GameEngineCore/GameEngineTransformComponent.h>

#include "GamePlayEnum.h"

// 설명 : 모든 아이템 관리는 여기서
// 생성 및 삭제도 여기서
class GamePlayItem_DESC;
class GamePlayItem : public GameEngineTransformComponent
{

	friend class GamePlayInventory;
public:
	GamePlayItem();
	~GamePlayItem();

	GamePlayItem(const GamePlayItem& _Other) = delete;
	GamePlayItem(GamePlayItem&& _Other) noexcept = delete;
	GamePlayItem& operator=(const GamePlayItem& _Other) = delete;
	GamePlayItem& operator=(GamePlayItem&& _Other) noexcept = delete;



	inline GameEngineUIRenderer* GetUIRenderer() const
	{
		return Texture_Item;
	}
	inline GameEngineCollision* GetCollision() const
	{
		return Collision_Item;
	}
	inline GamePlayItem_DESC* GetItemDesc() const
	{
		return Desc_ItemDesc;
	}


public:


	void SetDESC(GamePlayItem_DESC* _DESC);
	void SetTransform(GameEngineTransformBase* _Parent);


	//void DestroyItem();


	//void PickupFieldItem(class GamePlayCharacter* _Character);

protected:

	void Update(float _DeltaTime) override;

	//void LevelStartEvent() override {}

	//void OffEvent() override {}

	void Start() override;

	void End() override;

	GamePlayItem_DESC* Desc_ItemDesc;

	GameEngineUIRenderer* Texture_Item;
	GameEngineCollision* Collision_Item;

private:
	void SetThumbnail();


};

