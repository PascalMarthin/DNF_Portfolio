#pragma once
#include <vector>
#include <list>
#include <GameEngineBase/GameEngineMath.h>
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
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

	virtual bool PushItembyDrag(GamePlayItem* _Item, GamePlayItemBag* _From) = 0;

protected:
	std::vector<GamePlayItem*> ItemList;

	//void Start() override;

private:

};

