#pragma once
#include <list>
#include <map>
#include <GameEngineBase/GameEngineMath.h>

#include "GamePlayEnum.h"

// 설명 : 모든 아이템 관리는 여기서
// 생성 및 삭제도 여기서
class GamePlayItemBag;
class GamePlayItem
{
private:
	~GamePlayItem();
	// 소멸자 private


public:
	GamePlayItem(const GamePlayItemCode _ItemCode, float4& _Pos);

	GamePlayItem(const GamePlayItem& _Other) = delete;
	GamePlayItem(GamePlayItem&& _Other) noexcept = delete;
	GamePlayItem& operator=(const GamePlayItem& _Other) = delete;
	GamePlayItem& operator=(GamePlayItem&& _Other) noexcept = delete;


	inline GamePlayItemCode GetItemCode() const
	{
		return ItemCode;
	}

	inline GamePlayItemType GetItemType() const
	{
		return ItemType;
	}

	int CombineStackItem(GamePlayItem* _Item);
	// 99개 초과시 초과된 갯수만큼 리턴

public:

	// 생성은 직접 생성하는 것이 아닌 Create로
	// 이유 : 좀더 체계적인 생성을 위해

	static GamePlayItem* CreateItemByDrop(const GamePlayItemCode _ItemCode, float4& _Pos, int _Stack = 1);
	// 던전에서 드롭 생성

	static GamePlayItem* CreateItemByBag(const GamePlayItemCode _ItemCode, float4& _Pos, GamePlayItemBag* _ItemBag, int _Stack = 1);
	// ItemBag으로 다이렉트 생성

	static void DestroyAllFieldItem();

	static void DestroyAll();
	
	void DestroyItem();


	void PickupFieldItem(class GamePlayCharacter* _Character);

protected:


private:
	GamePlayItemType CheckItemType();
	// GamePlayItemCode를 기반으로 ItemType을 입력


private:
	GamePlayItemBag* ItemBag;
	GamePlayItemType ItemType;
	
	GamePlayItemCode const ItemCode;
	const float4* Pos; // 편리하게 동기화 시키려고, 일단 만듬
	// 상대적으로 할 것인가 절대적으로 할 것인가. 필드도 포함 할 것인가 아닌가

	int Stack;
	bool Field;


	static std::list<GamePlayItem*> AllFieldItemList;
	// 필드에 떨어져 있는 아이템
	static std::list<GamePlayItem*> AllItemList;
	// 필드에 떨어져 있는 아이템을 제외한 모든 아이템
};

