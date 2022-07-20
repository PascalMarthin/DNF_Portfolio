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

	
	inline GamePlayItemCode GetItemCode()
	{
		return ItemCode;
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

	//static GamePlayItem* CreateItemByDrop(const GamePlayItemCode _ItemCode, float4& _Pos, int _Stack = 1);
	//// �������� ��� ����

	//static GamePlayItem* CreateItemByBag(const GamePlayItemCode _ItemCode, float4& _Pos, GamePlayItemBag* _ItemBag, int _Stack = 1);
	// ItemBag���� ���̷�Ʈ ����

	
	void DestroyItem();


	void PickupFieldItem(class GamePlayCharacter* _Character);

protected:

	void Update(float _DeltaTime) override;

	void OnEvent() override {}

	void OffEvent() override {}

	void Start() override;

	void End() override;

private:



private:
	GamePlayItemBag* CurrentItemBag;
	
	GamePlayItemCode ItemCode;
	GamePlayItem_DESC* ItemDesc;

	int Stack;
	bool Field;

};

class GamePlayItem_DESC
{
	friend class DNF;
public:
	GamePlayItem_DESC(GamePlayItemCode _Code, GamePlayItemRate _Rate, const std::string& _Name, const std::string& _IconName)
		: ItemCode(_Code)
		, ItemType(CheckItemType(_Code))
		, ItemRate(_Rate)
		, ItemName(_Name)
		, ItemIcon(GameEngineTexture::Find(_IconName))
	{
		if (ItemIcon == nullptr)
		{
			MsgBox("�������� ���� ���� �ʾҽ��ϴ�");
		}
	}

	GamePlayItem_DESC(GamePlayItemCode _Code, GamePlayItemRate _Rate, const std::string& _Name)
		: ItemCode(_Code)
		, ItemType(CheckItemType(_Code))
		, ItemRate(_Rate)
		, ItemName(_Name)
		, ItemIcon(nullptr)
	{

	}

	inline GamePlayItemType GetItemType() const
	{
		return ItemType;
	}

	inline GamePlayItemCode GetItemCode() const
	{
		return ItemCode;
	}

	inline GamePlayItemRate GetItemRate() const
	{
		return ItemRate;
	}

	inline std::string GetItemName() const
	{
		return ItemName;
	}

	inline const GameEngineTexture* GetItemIcon() const
	{
		return ItemIcon;
	}

	static GamePlayItem_DESC* Find(GamePlayItemCode _Code);

	//get
private:
	const GamePlayItemCode  ItemCode;
	const GamePlayItemType  ItemType;
	const GamePlayItemRate  ItemRate;
	
	const std::string const ItemName;

	const GameEngineTexture* const ItemIcon;


	//std::string Explanation;

private:
	static std::map<GamePlayItemCode, GamePlayItem_DESC*> AllItem_DESC;
	static void CreateALLItemData();

	static GamePlayItemType CheckItemType(GamePlayItemCode _Code);
	// GamePlayItemCode�� ������� ItemType�� �Է�

	static void DestoryALLItemData();
};
