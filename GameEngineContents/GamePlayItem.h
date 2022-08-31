#pragma once
#include <list>
#include <map>
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineBase/GameEngineMath.h>
#include <GameEngineCore/GameEngineComponent.h>

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



	int CombineStackItem(GamePlayItem* _Item);
	// 99개 초과시 초과된 갯수만큼 리턴

public:

	// 생성은 직접 생성하는 것이 아닌 Create로
	// 이유 : 좀더 체계적인 생성을 위해

	//static GamePlayItem* CreateItemByDrop(const GamePlayItemCode _ItemCode, float4& _Pos, int _Stack = 1);
	//// 던전에서 드롭 생성

	//static GamePlayItem* CreateItemByBag(const GamePlayItemCode _ItemCode, float4& _Pos, GamePlayItemBag* _ItemBag, int _Stack = 1);
	// ItemBag으로 다이렉트 생성

	void SetDESC(GamePlayItem_DESC* _DESC);
	void SetTransform(GameEngineTransformBase* _Parent);


	void DestroyItem();


	void PickupFieldItem(class GamePlayCharacter* _Character);

protected:

	void Update(float _DeltaTime) override;

	//void LevelStartEvent() override {}

	//void OffEvent() override {}

	void Start() override;

	void End() override;

private:
	void SetThumbnail();


private:
	GamePlayItem_DESC* Desc_ItemDesc;

	GameEngineUIRenderer* Texture_Item;
	GameEngineCollision* Collision_Item;

	int Stack;
	bool Field;

};

