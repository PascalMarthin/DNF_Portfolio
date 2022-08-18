#pragma once
#include <GameEngineCore/GameEngineTransformComponent.h>

// ���� :
class GamePlayObject;
class GameEngineCollision;
class GamePlayCharacter;
class CharacterStatManager;
class MoveManager : public GameEngineTransformComponent
{
	friend class GamePlayCharacter;
	friend class CharacterStatManager;
public:
	// constrcuter destructer
	MoveManager();
	~MoveManager();

	// delete Function
	MoveManager(const MoveManager& _Other) = delete;
	MoveManager(MoveManager&& _Other) noexcept = delete;
	MoveManager& operator=(const MoveManager& _Other) = delete;
	MoveManager& operator=(MoveManager&& _Other) noexcept = delete;

	inline GameEngineCollision* GetMoveCollision() const
	{
		return Collision_Move;
	}

	float4 SetCharacterMove(const float4& _Move);
	//void SetCharacterMove_Inertia(const float4& _Move);
	void SetCharacterLocation(const float4& _Pos);
	void SetJump();
	void SetJump(float _Power);

	//void SetBeAir();


protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	// void End() override {}
	void OnEvent() override;
	void OffEvent() override;

private:
	GamePlayObject* ParentCharacter;

	// -------------Hit-----------------
public:
	void SetHit(const float4& _HitPower);

private:
	float4 BlowPower;
	// -------------Jump----------------
	float JumpTime;
	float JumpHigh;
	float4 LandingPostion;
	//float4 Move_Inertia;
	// -------------Jump----------------

	CharacterStatManager* ManagerStat;

private:
	// ----------Collision---------------
	GameEngineCollision* Collision_Move;
	GameEngineTexture* Texture_CollisionMap;
};

