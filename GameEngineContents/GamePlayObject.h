#pragma once

// Ό³Έν :
class GamePlayObject
{
public:
	// constrcuter destructer
	GamePlayObject();
	~GamePlayObject();

	// delete Function
	GamePlayObject(const GamePlayObject& _Other) = delete;
	GamePlayObject(GamePlayObject&& _Other) noexcept = delete;
	GamePlayObject& operator=(const GamePlayObject& _Other) = delete;
	GamePlayObject& operator=(GamePlayObject&& _Other) noexcept = delete;

protected:

private:

};

