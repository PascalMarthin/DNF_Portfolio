#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "BackGroundParent.h"

// Ό³Έν :
class Jelva2F01_WaveBackGround : public GameEngineActor, public BackGroundParent
{
public:
	// constrcuter destructer
	Jelva2F01_WaveBackGround();
	~Jelva2F01_WaveBackGround();

	// delete Function
	Jelva2F01_WaveBackGround(const Jelva2F01_WaveBackGround& _Other) = delete;
	Jelva2F01_WaveBackGround(Jelva2F01_WaveBackGround&& _Other) noexcept = delete;
	Jelva2F01_WaveBackGround& operator=(const Jelva2F01_WaveBackGround& _Other) = delete;
	Jelva2F01_WaveBackGround& operator=(Jelva2F01_WaveBackGround&& _Other) noexcept = delete;

	inline std::vector<GameEngineTextureRenderer*>& GetSeaWave()
	{
		return Texture_SeaWave;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	//void End() override {}
	// void OnEvent() override
	// void OffEvent() override
private:
	std::vector<GameEngineTextureRenderer*> Texture_SeaWave;
};

