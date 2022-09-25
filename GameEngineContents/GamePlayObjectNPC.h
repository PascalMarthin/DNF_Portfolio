#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "GameEnginePlusTextureRenderer.h"

// Ό³Έν :
enum class NPCEnum
{
	Ajelia,
	Erika,
	Hartz_von_kruger,
	Hunter_pon,
	Isabella,
	Merill_pioneer,
	Seria,
	Roi_hartwig,
};
enum class InteractOption
{
	None,
	Quest,
	Deal,
	Talking,
	Exit,
};

class GameEnginePlusTextureRenderer;
class GamePlayObjectNPC : public GameEngineActor
{
	friend class GamePlayInteractionWindow;
public:
	// constrcuter destructer
	GamePlayObjectNPC();
	~GamePlayObjectNPC();

	// delete Function
	GamePlayObjectNPC(const GamePlayObjectNPC& _Other) = delete;
	GamePlayObjectNPC(GamePlayObjectNPC&& _Other) noexcept = delete;
	GamePlayObjectNPC& operator=(const GamePlayObjectNPC& _Other) = delete;
	GamePlayObjectNPC& operator=(GamePlayObjectNPC&& _Other) noexcept = delete;

	inline void SetOutLine()
	{
		Texture_NPCStanding->GetOutLine()->On();
	}
	inline void SetOutLineOff()
	{
		Texture_NPCStanding->GetOutLine()->Off();
	}

	inline const std::vector<InteractOption>& GetInteractOption() const
	{
		return vector_Option;
	}
	inline const std::vector<std::string>& GetStringRef(InteractOption _Option)
	{
		return map_InteractionTalk[_Option];
	}
	inline std::vector<std::string>* GetStringPtr(InteractOption _Option)
	{
		return &map_InteractionTalk[_Option];
	}
	
	inline const std::string& GetName() const
	{
		return Name;
	}
	inline GameEngineTexture* GetFaceImage() const
	{
		return TexureR_Face;
	}


protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	// void End() override {}
	// void OnEvent() override {}
	// void OffEvent() override {}


	NPCEnum EnumNPC;
	std::map<InteractOption, std::vector<std::string>> map_InteractionTalk;
	std::vector<InteractOption> vector_Option;
	std::string Name;

	GameEnginePlusTextureRenderer* Texture_NPCStanding;
	//GameEngineTextureRenderer* Texture_NPCOutLine;
	GameEngineTexture* TexureR_Face;

	std::map<GamePlayItemCode, int> map_SellItemList;

private:
	GameEngineCollision* Collision_CharacterSpot;




};

