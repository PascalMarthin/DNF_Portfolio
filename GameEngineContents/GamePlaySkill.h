#pragma once
#include <GameEngineCore/GameEngineTransformComponent.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include "CharacterStatManager.h"
#include "MoveManager.h"
#include "AvataManager.h"

// 설명 :
enum class HitPostureType
{
	None,
	Standing,
	Hold,
	Aerial,
};
enum class HitType
{
	None,
	Hit,
	Slash,
};
struct SkillComboPower
{
	//SkillComboPower() {}

	unsigned int int_SkillDamage;
	unsigned int int_MaxHit;

	float4 float4_HitPhysicsPower;

	HitType Enum_HitType;
	HitPostureType Enum_HitPostureType;
	SkillComboPower(unsigned int _Damage, unsigned int _MaxHit, const float4& _Power, HitPostureType _Type, HitType _HitType)
		: int_SkillDamage(_Damage), int_MaxHit(_MaxHit), float4_HitPhysicsPower(_Power), Enum_HitType(_HitType), Enum_HitPostureType(_Type)
	{

	}
	~SkillComboPower() {}
};

class GamePlayObject;
class GamePlaySkill : public GameEngineTransformComponent
{
public:
	friend GamePlayObject;
	friend class CharacterSkillManager;
	// constrcuter destructer
	GamePlaySkill();
	~GamePlaySkill();

	// delete Function
	GamePlaySkill(const GamePlaySkill& _Other) = delete;
	GamePlaySkill(GamePlaySkill&& _Other) noexcept = delete;
	GamePlaySkill& operator=(const GamePlaySkill& _Other) = delete;
	GamePlaySkill& operator=(GamePlaySkill&& _Other) noexcept = delete;


	inline unsigned int GetSkillLevel()
	{
		return int_SkillLevel;
	}

	inline int GetCollisionIndex() const
	{
		return int_ComboStuck;
	}
	inline void SetCollisionIndex(int _Index)
	{
		int_ComboStuck = _Index;
	}

	inline std::function<bool(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime)> Get_SkillAction()
	{
		return std::bind(&GamePlaySkill::ActiveSkill, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);
	}


	virtual void StartSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata) {}
	virtual void EndSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata) { int a = 0; }
private:
protected:
	int int_ComboStuck;
	float TimePass;
	bool SomeOneHit;
	GameEngineActor* Actor_DummyActor;

	//
	virtual bool ActiveSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime)  = 0;
	 
	virtual void CheckCollision();
	virtual void CheckCollision(int _Combo);
	virtual CollisionReturn CollsionHitFunction(GameEngineCollision* _This, GameEngineCollision* _Other);
	virtual bool TriggerSkill_ect(GameEngineCollision* _This, GameEngineCollision* _Other) { return false; };
	bool IsHitObject(GamePlayObject* _Object, int _HitOrder);

	bool Is_CollisionCheck;


	// Casting---------
	void CreateCastingTexture(float _CastingTime);;
	void Casting(CharacterStatManager* _Stat, AvataManager* _Avata);
	void CastingBuff();
	void CastingBuffEnd();
	GameEngineEffectRenderer* Texture_CastingBuff;
	void CastingEnd(CharacterStatManager* _Stat, AvataManager* _Avata);
	float CastingTime;
	float CurrentCastingTime;
	void Start() override;
	void Update(float _DeltaTime) override;

	void LevelStartEvent() override;
	void LevelEndEvent() override;
	//


	void OnEvent() override;
	void OffEvent() override;

	std::vector<GameEngineCollision*> Collision_AllCollisionList;
	std::map<GamePlayObject*, int> Object_HitList;
	bool bool_MultiHit;

	static int CheckDir(GameEngineCollision* _This, GameEngineCollision* _Other);
	float FSM_Move_Helper();

	// -------Power--------------
	std::vector<SkillComboPower> Class_Power; // xyz = 날리는 파워, w = 경직시간

	// ------CoolTime-------------
	inline void SetCoolTime(float _Time)
	{
		CoolTime = _Time;
	}
	//------Casting-------------
	std::vector<GameEngineEffectRenderer*> Vector_CastingTexture;
private:
	float CoolTime;
	float CurrentCoolTime;

	GameEngineTexture* Texture_Thumbnail;

	
	//------SkillLevel----
	unsigned int int_SkillLevel;
};

