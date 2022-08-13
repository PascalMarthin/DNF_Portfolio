#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include "Dungeon_Luke.h"
#include "Luke_Stage1_BackGround.h"

// Ό³Έν :
class Luke_Stage1_BackGround;
class Luke_Stage1 : public GameEngineLevel, public Dungeon_Luke
{
public:
	// constrcuter destructer
	Luke_Stage1();
	~Luke_Stage1();

	// delete Function
	Luke_Stage1(const Luke_Stage1& _Other) = delete;
	Luke_Stage1(Luke_Stage1&& _Other) noexcept = delete;
	Luke_Stage1& operator=(const Luke_Stage1& _Other) = delete;
	Luke_Stage1& operator=(Luke_Stage1&& _Other) noexcept = delete;


	inline GameEngineTexture* GetCollisionMapTexture()
	{
		return 	Texture_Luke_Stage1->GetCollisionTexture();
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override {}

	void OnEvent() override;
	//void OffEvent() override;
private:

	Luke_Stage1_BackGround* Texture_Luke_Stage1;
};

