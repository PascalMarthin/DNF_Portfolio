#pragma once
#include <GameEngineCore/GameEngineComponent.h>

// Ό³Έν :
class GamePlayObject;
class GamePlayCharacter;
class CharacterStatManager;
class MoveManager : public GameEngineComponent
{
	friend class GamePlayCharacter;
public:
	// constrcuter destructer
	MoveManager();
	~MoveManager();

	// delete Function
	MoveManager(const MoveManager& _Other) = delete;
	MoveManager(MoveManager&& _Other) noexcept = delete;
	MoveManager& operator=(const MoveManager& _Other) = delete;
	MoveManager& operator=(MoveManager&& _Other) noexcept = delete;


	void SetCharacterMove(const float4& _Move);
	void SetCharacterLocation(const float4& _Pos);
	void SetJump(const float4& _StartJumpPos);


protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	// void End() override {}
	void OnEvent() override;
	// void OffEvent() override {}

private:
	GamePlayObject* ParentCharacter;

	// Jump
	float JumpTime;
	float JumpPower;
	float JumpHigh;
	float CurrentGravitIndex;
	float4 LandingPostion;
	// Jump

	CharacterStatManager* ManagerStat;
};

