#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include "GamePlayCharacter.h"
#include "TownLevel.h"
#include "Jelva2F_BackGround.h"
// Ό³Έν :
class Jelva_2F : public GameEngineLevel, public TownLevel
{
public:
	// constrcuter destructer
	Jelva_2F();
	~Jelva_2F();

	// delete Function
	Jelva_2F(const Jelva_2F& _Other) = delete;
	Jelva_2F(Jelva_2F&& _Other) noexcept = delete;
	Jelva_2F& operator=(const Jelva_2F& _Other) = delete;
	Jelva_2F& operator=(Jelva_2F&& _Other) noexcept = delete;

	inline GameEngineTexture* GetCollisionMapTexture() override
	{
		return Texture_Jelva2F->GetCollisionTexture();
	}
protected:

	void Start() override;

	void Update(float _DeltaTime) override;

	void End() override {}

	void LevelStartEvent() override;
	// void OffEvent() {}
private:
	Jelva2F_BackGround* Texture_Jelva2F;

	GamePlayCharacter* Player_Character;
};

