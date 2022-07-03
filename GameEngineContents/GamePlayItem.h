#pragma once
#include <list>
#include <map>
#include <GameEngineBase/GameEngineMath.h>
#include <GameEngineCore/GameEngineComponent.h>

#include "GamePlayEnum.h"

// ���� : ��� ������ ������ ���⼭
// ���� �� ������ ���⼭
class GamePlayItemBag;
class GamePlayItem : public GameEngineTransformComponent
{
public:
	GamePlayItem();
	~GamePlayItem();

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

	inline void SetItemCode(GamePlayItemCode _Code)
	{
		if (ItemCode == GamePlayItemCode::Error)
		{
			ItemCode = _Code;
		}
		else
		{
			MsgBoxAssert("���� ������ �������� �ٲٴ���?")
		}
		
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
	
	void DestroyItem();


	void PickupFieldItem(class GamePlayCharacter* _Character);

protected:

	void Update(float _DeltaTime) override;

	void OnEvent() override {}

	void OffEvent() override {}

	void Start() override;

	void End() override;

private:
	GamePlayItemType CheckItemType();
	// GamePlayItemCode�� ������� ItemType�� �Է�


private:
	GamePlayItemBag* ItemBag;
	GamePlayItemType ItemType;
	
	GamePlayItemCode ItemCode;
	// ��������� �� ���ΰ� ���������� �� ���ΰ�. �ʵ嵵 ���� �� ���ΰ� �ƴѰ�

	int Stack;
	bool Field;


	static std::list<GamePlayItem*> AllFieldItemList;
	// �ʵ忡 ������ �ִ� ������
	static std::list<GamePlayItem*> AllItemList;
	// �ʵ忡 ������ �ִ� �������� ������ ��� ������
};

