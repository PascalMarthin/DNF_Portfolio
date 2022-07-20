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
			MsgBoxAssert("무슨 이유로 아이템을 바꾸는지?")
		}
		
	}

	int CombineStackItem(GamePlayItem* _Item);
	// 99개 초과시 초과된 갯수만큼 리턴

public:

	// 생성은 직접 생성하는 것이 아닌 Create로
	// 이유 : 좀더 체계적인 생성을 위해

	//static GamePlayItem* CreateItemByDrop(const GamePlayItemCode _ItemCode, float4& _Pos, int _Stack = 1);
	//// 던전에서 드롭 생성

	//static GamePlayItem* CreateItemByBag(const GamePlayItemCode _ItemCode, float4& _Pos, GamePlayItemBag* _ItemBag, int _Stack = 1);
	// ItemBag으로 다이렉트 생성

	
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
			MsgBox("아이콘이 설정 되지 않았습니다");
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
	// GamePlayItemCode를 기반으로 ItemType을 입력

	static void DestoryALLItemData();
};
