#pragma once
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
enum DamageFontEvent
{
	FirstTime = 0b0000000000000001,
	SecondTime = 0b0000000000000010,
	LastTime = 0b0000000000000100
};
class GameEngineDamageRenderer : public GameEngineActor
{
public:
	// constrcuter destructer
	GameEngineDamageRenderer();
	~GameEngineDamageRenderer();

	// delete Function
	GameEngineDamageRenderer(const GameEngineDamageRenderer& _Other) = delete;
	GameEngineDamageRenderer(GameEngineDamageRenderer&& _Other) noexcept = delete;
	GameEngineDamageRenderer& operator=(const GameEngineDamageRenderer& _Other) = delete;
	GameEngineDamageRenderer& operator=(GameEngineDamageRenderer&& _Other) noexcept = delete;

	inline void SetCritical()
	{
		Critical = true;
	}
	void SetDamage(unsigned int _Damage);


protected:
	void Start() override;

	void Update(float _Delta) override;

	void FontEnd();

private:
	static std::list<GameEngineDamageRenderer*> Static_AllDamageRenderer;
	static void SetPrintingFont(GameEngineDamageRenderer* _FontRenderer);

	std::vector<GameEngineUIRenderer*> All_Font;
	bool Critical;
	bool MaxDamage;

	int CheckTimeEvent;

	float FontSize;
	float CurrentCastingTime;
	//float Interval;

private:
	void FirstTime();
	void SecondTime();
	void LastTime();

	inline float4 GetTextureSize() const
	{
		return All_Font[0]->GetCurTexture()->GetScale();
	}

	static GameEngineFolderTexture* Folder_NumberTexture_Critical;
	static GameEngineFolderTexture* Folder_NumberTexture_Nomal;

};

