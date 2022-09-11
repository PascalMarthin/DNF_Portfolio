#pragma once
#include <GameEngineCore/GameEngineTransformComponent.h>

// Ό³Έν :
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
	inline float4 GetLandPos() const
	{
		return LandingPostion;
	}

	float4 SetCharacterMove(const float4& _Move);
	//void SetCharacterMove_Inertia(const float4& _Move);
	void SetCharacterLocation(const float4& _Pos);
	void SetAerial();
	void SetJump(float _Power);

	//void SetBeAir();

	void SetObjectPos(const float4& _Pos);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	// void End() override {}
	void LevelStartEvent() override;
	void LevelEndEvent() override;

private:
	GamePlayObject* ParentCharacter;

	// -------------Hit-----------------
public:
	inline void HitDir(float _Dir);
	void SetHit(const float4& _HitPower);
	void SetHold(float _HoldTime);
	float HitTime;
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

