#pragma once
#include <vector>
#include <list>
#include <GameEngineBase/GameEngineMath.h>
#include <GameEngineCore/GameEngineActor.h>

// ���� :
class GamePlayCharacter;
class GamePlayItem;
class GamePlayItemBag : public GameEngineActor
{
protected:
	GamePlayItemBag();
public:
	virtual ~GamePlayItemBag();

	GamePlayItemBag(const GamePlayItemBag& _Other) = delete;
	GamePlayItemBag(GamePlayItemBag&& _Other) noexcept = delete;
	GamePlayItemBag& operator=(const GamePlayItemBag& _Other) = delete;
	GamePlayItemBag& operator=(GamePlayItemBag&& _Other) noexcept = delete;

	inline GamePlayCharacter* GetOwner() const
	{
		return Owner;
	}
	inline void SetOwner(GamePlayCharacter* _Owner)
	{
		if (nullptr == Owner)
		{
			Owner = _Owner;
		}
		else
		{
			MsgBoxAssert("�̹� ���� ������ Ŭ�����Դϴ�");
		}
		// Constó�� �ѹ� ������ �ٲܼ� ������ ��
	}

	virtual bool PushItembyDrag(GamePlayItem* _Item, GamePlayItemBag* _From) = 0;

protected:
	std::vector<GamePlayItem*> ItemList;
	GamePlayCharacter* Owner;

	//void Start() override;

private:

};

