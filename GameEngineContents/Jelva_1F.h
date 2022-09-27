#pragma once
#include "GamePlayLevelTemplate.h"
#include "GamePlayCharacter.h"
#include "TownLevel.h"
#include "Jelva1F_BackGround.h"
// ���� :
class Hartz_von_kruger_NPC;
class Guard_Zelva_NPC;
class Isabella_NPC;
class Jelva_1F : public GamePlayLevelTemplate, public TownLevel
{
public:
	// constrcuter destructer
	Jelva_1F();
	~Jelva_1F();

	// delete Function
	Jelva_1F(const Jelva_1F& _Other) = delete;
	Jelva_1F(Jelva_1F&& _Other) noexcept = delete;
	Jelva_1F& operator=(const Jelva_1F& _Other) = delete;
	Jelva_1F& operator=(Jelva_1F&& _Other) noexcept = delete;

	inline GameEngineTexture* GetCollisionMapTexture() override
	{
		return Texture_Jelva1F->GetCollisionTexture();
	}
protected:

	void Start() override;
	void Update(float _DeltaTime) override;

	void End() override {}
	void LevelStartEvent() override;
	void LevelEndEvent() override;
	// void OffEvent() override

private:
	Jelva1F_BackGround* Texture_Jelva1F;

	Isabella_NPC* NPC_Isabella;
	Guard_Zelva_NPC* NPC_Guard_Zelva;
	Hartz_von_kruger_NPC* NPC_Hartz;
	GamePlayCharacter* Player_Character;
};

