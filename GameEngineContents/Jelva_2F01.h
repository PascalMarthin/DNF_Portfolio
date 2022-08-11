#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include "GamePlayCharacter.h"
#include "TownLevel.h"
#include "Jelva2F01_BackGround.h"
#include "Jelva2F01_WaveBackGround.h"

// Ό³Έν :
class Jelva_2F01 : public GameEngineLevel, public TownLevel
{
public:
	// constrcuter destructer
	Jelva_2F01();
	~Jelva_2F01();

	// delete Function
	Jelva_2F01(const Jelva_2F01& _Other) = delete;
	Jelva_2F01(Jelva_2F01&& _Other) noexcept = delete;
	Jelva_2F01& operator=(const Jelva_2F01& _Other) = delete;
	Jelva_2F01& operator=(Jelva_2F01&& _Other) noexcept = delete;


	inline GameEngineTexture* GetCollisionMapTexture() override
	{
		return Texture_Jelva2F01->GetCollisionTexture();
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override {}

	void OnEvent() override;
	// void OffEvent() {}
private:
	Jelva2F01_BackGround* Texture_Jelva2F01;
	Jelva2F01_WaveBackGround* Texture_Jelva2F01_Wave;

	GamePlayCharacter* Player_Fighter;
};
