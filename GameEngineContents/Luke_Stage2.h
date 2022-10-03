#pragma once
#include "Dungeon_Luke.h"
#include "Luke_Stage2_BackGround.h"

class Bale;
class Luke_Stage2 : public Dungeon_Luke
{
public:
	// constrcuter destructer
	Luke_Stage2();
	~Luke_Stage2();

	// delete Function
	Luke_Stage2(const Luke_Stage2& _Other) = delete;
	Luke_Stage2(Luke_Stage2&& _Other) noexcept = delete;
	Luke_Stage2& operator=(const Luke_Stage2& _Other) = delete;
	Luke_Stage2& operator=(Luke_Stage2&& _Other) noexcept = delete;

	inline GameEngineTexture* GetCollisionMapTexture()
	{
		return 	Texture_Luke_Stage2->GetCollisionTexture();
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override {}

	void LevelStartEvent() override;
	//void OffEvent() override;
private:

	Luke_Stage2_BackGround* Texture_Luke_Stage2;
	Bale* Debug_Bale;

};
