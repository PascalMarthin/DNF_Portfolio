#pragma once
#include <GameEngineCore/GameEngineTransformComponent.h>
#include <GameEngineCore/GameEngineCollision.h>

// 설명 :
enum class HitType
{
	None,
	Standing,
	Hold,
	Air,
};
class GamePlayObject;
class GamePlaySkill : public GameEngineTransformComponent
{
public:
	// constrcuter destructer
	GamePlaySkill();
	~GamePlaySkill();

	// delete Function
	GamePlaySkill(const GamePlaySkill& _Other) = delete;
	GamePlaySkill(GamePlaySkill&& _Other) noexcept = delete;
	GamePlaySkill& operator=(const GamePlaySkill& _Other) = delete;
	GamePlaySkill& operator=(GamePlaySkill&& _Other) noexcept = delete;




	inline unsigned int GetSkillDamage() const
	{
		return int_SkillDamage;
	}
	inline HitType GetHitType() const
	{
		return Enum_HitType;
	}
	inline float4 GetBlowPower() const
	{
		return float4_HitPhysicsPower;
	}

	inline int GetCollisionIndex() const
	{
		return int_CurrentCollision;
	}
	inline void SetCollisionIndex(int _Index)
	{
		int_CurrentCollision = _Index;
	}

protected:
	int int_CurrentCollision;
	unsigned int int_SkillDamage;
	HitType Enum_HitType;

	float4 float4_HitPhysicsPower; // xyz = 날리는 파워, w = 경직시간

	virtual bool TriggerSkill(GameEngineCollision* _This, GameEngineCollision* _Other) = 0;
	bool IsHitObject(GamePlayObject* _Object, int _HitOrder);
	static int CheckDir(GameEngineCollision* _This, GameEngineCollision* _Other);

	std::vector<GameEngineCollision*> Collision_AllCollisionList;
	std::map<GamePlayObject*, int> Object_HitList;

private:
};

