#pragma once
#include <GameEngineCore/GameEngineComponent.h>
#include "GameEnginePlusTextureRenderer.h"

// 설명 : GamePlayCharacter의 상태의 따른 렌더러 사용
class GamePlayCharacterRenderer : public GameEngineComponent
{
	friend class GamePlayCharacter;
	friend class CharacterFighter;
public:
	// constrcuter destructer
	GamePlayCharacterRenderer();
	~GamePlayCharacterRenderer();

	// delete Function
	GamePlayCharacterRenderer(const GamePlayCharacterRenderer& _Other) = delete;
	GamePlayCharacterRenderer(GamePlayCharacterRenderer&& _Other) noexcept = delete;
	GamePlayCharacterRenderer& operator=(const GamePlayCharacterRenderer& _Other) = delete;
	GamePlayCharacterRenderer& operator=(GamePlayCharacterRenderer&& _Other) noexcept = delete;

protected:
	void Start() override;

	//void Update(float _DeltaTime) override;

	// void End() override {}
	// void OnEvent() {}
	// void OffEvent() {}
private:

	GameEnginePlusTextureRenderer* Avata_Belt;
	GameEnginePlusTextureRenderer* Avata_Cap;
	GameEnginePlusTextureRenderer* Avata_Coat;
	GameEnginePlusTextureRenderer* Avata_Face;
	GameEnginePlusTextureRenderer* Avata_Hair_a;
	GameEnginePlusTextureRenderer* Avata_Hair_b;
	GameEnginePlusTextureRenderer* Avata_Neck;
	GameEnginePlusTextureRenderer* Avata_Pants;
	GameEnginePlusTextureRenderer* Avata_Shoes_a;
	GameEnginePlusTextureRenderer* Avata_Skin;

	std::vector<GameEnginePlusTextureRenderer*> AllAvatas;

};

