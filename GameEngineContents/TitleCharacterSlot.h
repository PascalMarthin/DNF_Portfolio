#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>

// ���� :
class GamePlayDataBase;
class AvataManager;
class TitleCharacterSlot : public GameEngineActor
{
	friend class SelectCharacterLevel;
public:
	// constrcuter destructer
	TitleCharacterSlot();
	~TitleCharacterSlot();

	// delete Function
	TitleCharacterSlot(const TitleCharacterSlot& _Other) = delete;
	TitleCharacterSlot(TitleCharacterSlot&& _Other) noexcept = delete;
	TitleCharacterSlot& operator=(const TitleCharacterSlot& _Other) = delete;
	TitleCharacterSlot& operator=(TitleCharacterSlot&& _Other) noexcept = delete;

	void CreateAvataData(GamePlayDataBase* _Data);
	void SetCharacterAvataData();

protected:
	void Start() override;

	void Update(float _DeltaTime) override;

	// void End() override {}
	// void OnEvent() {}
	// void OffEvent() {}
private:
	GameEngineTextureRenderer* Texture_SlotBorder;
	GameEngineTextureRenderer* Texture_MagicCircle;

	// �ƹ�Ÿ �Ŵ���
	AvataManager* Manager_Avata;
	GamePlayDataBase* Data_Character;

	GameEngineCollision* Collision_SlotBorder;

};

