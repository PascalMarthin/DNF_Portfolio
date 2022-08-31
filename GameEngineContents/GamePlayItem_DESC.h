#pragma once
#include "GamePlayEnum.h"

// ���� :
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

	~GamePlayItem_DESC();

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

	inline GameEngineTexture* GetItemIcon() const
	{
		return ItemIcon;
	}

	static GamePlayItem_DESC* Find(GamePlayItemCode _Code);
	static GamePlayItemType CheckItemType(GamePlayItemCode _Code);

	//get
private:
	const GamePlayItemCode  ItemCode;
	const GamePlayItemType  ItemType;
	const GamePlayItemRate  ItemRate;

	const std::string ItemName;

	GameEngineTexture* const ItemIcon;


	//std::string Explanation;

private:
	static std::map<GamePlayItemCode, GamePlayItem_DESC*> AllItem_DESC;
	static void CreateALLItemData();

	// GamePlayItemCode�� ������� ItemType�� �Է�

	static void DestoryALLItemData();
};

