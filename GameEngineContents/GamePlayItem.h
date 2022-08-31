#pragma once
#include <list>
#include <map>
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineBase/GameEngineMath.h>
#include <GameEngineCore/GameEngineComponent.h>

#include "GamePlayEnum.h"

// ���� : ��� ������ ������ ���⼭
// ���� �� ������ ���⼭
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
	// 99�� �ʰ��� �ʰ��� ������ŭ ����

public:

	// ������ ���� �����ϴ� ���� �ƴ� Create��
	// ���� : ���� ü������ ������ ����

	//static GamePlayItem* CreateItemByDrop(const GamePlayItemCode _ItemCode, float4& _Pos, int _Stack = 1);
	//// �������� ��� ����

	//static GamePlayItem* CreateItemByBag(const GamePlayItemCode _ItemCode, float4& _Pos, GamePlayItemBag* _ItemBag, int _Stack = 1);
	// ItemBag���� ���̷�Ʈ ����

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

