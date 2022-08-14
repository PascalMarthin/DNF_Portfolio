#pragma once
#include "GamePlayObject.h"
#include <GameEngineCore/GameEngineCollision.h> 

// Ό³Έν :
class GameEngineStateManager;
class GamePlayMonster : public GamePlayObject
{
public:
	// constrcuter destructer
	GamePlayMonster();
	~GamePlayMonster();

	// delete Function
	GamePlayMonster(const GamePlayMonster& _Other) = delete;
	GamePlayMonster(GamePlayMonster&& _Other) noexcept = delete;
	GamePlayMonster& operator=(const GamePlayMonster& _Other) = delete;
	GamePlayMonster& operator=(GamePlayMonster&& _Other) noexcept = delete;

	inline GameEngineCollision* GetBodyCollision() const
	{
		return Collision_HitBody;
	}

protected:
	// -------------------FSM---------------------
	GameEngineStateManager FSMManager;

	void OnEvent() override;
	//--------------------Collision---------------
	GameEngineCollision* Collision_HitBody;


	//---------------------Texture-----------------
	GameEngineTextureRenderer* Texture_Monster;

private:
	

};

