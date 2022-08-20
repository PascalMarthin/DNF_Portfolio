#pragma once
#include <GameEngineCore/GameEngineTransformComponent.h>
#include <GameEngineCore/GameEngineCollision.h>

// 설명 :
enum class HitPostureType
{
	None,
	Standing,
	Hold,
	Air,
};
enum class HitType
{
	None,
	Hit,
	Slash,
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
	inline HitPostureType GetHitPostureType() const
	{
		return Enum_HitPostureType;
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


	void SettingFirst(unsigned int _Damage, unsigned int _MaxHitObject, HitPostureType _Type, HitType _HitType, const float4& _Power);

	virtual void CheckCollision() {};
	virtual bool TriggerSkill(GameEngineCollision* _This, GameEngineCollision* _Other);
	virtual bool TriggerSkill_ect(GameEngineCollision* _This, GameEngineCollision* _Other) { return false; };
	bool IsHitObject(GamePlayObject* _Object, int _HitOrder);

	void OnEvent() override;
	void OffEvent() override;

	std::vector<GameEngineCollision*> Collision_AllCollisionList;
	std::map<GamePlayObject*, int> Object_HitList;

	static int CheckDir(GameEngineCollision* _This, GameEngineCollision* _Other);
private:
	HitType Enum_HitType;
	HitPostureType Enum_HitPostureType;
	unsigned int int_SkillDamage;
	unsigned int int_MaxHit;

	float4 float4_HitPhysicsPower; // xyz = 날리는 파워, w = 경직시간

};

