#pragma once
#include <vector>
#include <list>
#include <GameEngineBase/GameEngineMath.h>

// Ό³Έν :
class GamePlayCharacter;
class GamePlayItem;
class GamePlayItemBag
{
protected:
	GamePlayItemBag(GamePlayCharacter* _Owner);
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

	virtual bool PushItembyDrag(GamePlayItem* _Item, GamePlayItemBag* _From) = 0;

protected:
	std::vector<GamePlayItem*> ItemList;

private:
	GamePlayCharacter* const Owner;

};

