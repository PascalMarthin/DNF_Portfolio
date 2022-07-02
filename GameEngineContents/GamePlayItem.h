#pragma once
#include <list>
#include <map>
#include <GameEngineBase/GameEngineMath.h>

#include "GamePlayEnum.h"

// ���� : ��� ������ ������ ���⼭
// ���� �� ������ ���⼭
class GamePlayItemBag;
class GamePlayItem
{
private:
	~GamePlayItem();
	// �Ҹ��� private


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
	// 99�� �ʰ��� �ʰ��� ������ŭ ����

public:

	// ������ ���� �����ϴ� ���� �ƴ� Create��
	// ���� : ���� ü������ ������ ����

	static GamePlayItem* CreateItemByDrop(const GamePlayItemCode _ItemCode, float4& _Pos, int _Stack = 1);
	// �������� ��� ����

	static GamePlayItem* CreateItemByBag(const GamePlayItemCode _ItemCode, float4& _Pos, GamePlayItemBag* _ItemBag, int _Stack = 1);
	// ItemBag���� ���̷�Ʈ ����

	static void DestroyAllFieldItem();

	static void DestroyAll();
	
	void DestroyItem();


	void PickupFieldItem(class GamePlayCharacter* _Character);

protected:


private:
	GamePlayItemType CheckItemType();
	// GamePlayItemCode�� ������� ItemType�� �Է�


private:
	GamePlayItemBag* ItemBag;
	GamePlayItemType ItemType;
	
	GamePlayItemCode const ItemCode;
	const float4* Pos; // ���ϰ� ����ȭ ��Ű����, �ϴ� ����
	// ��������� �� ���ΰ� ���������� �� ���ΰ�. �ʵ嵵 ���� �� ���ΰ� �ƴѰ�

	int Stack;
	bool Field;


	static std::list<GamePlayItem*> AllFieldItemList;
	// �ʵ忡 ������ �ִ� ������
	static std::list<GamePlayItem*> AllItemList;
	// �ʵ忡 ������ �ִ� �������� ������ ��� ������
};

