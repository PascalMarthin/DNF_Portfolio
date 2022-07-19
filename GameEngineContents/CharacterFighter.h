#pragma once
#include <map>
#include <string>

#include "GamePlayCharacter.h"

// 설명 : 캐릭터 모션에 관련된 클래스
class CharacterFighter : public GamePlayCharacter
{
public:
	// constrcuter destructer
	CharacterFighter();
	~CharacterFighter();

	// delete Function
	CharacterFighter(const CharacterFighter& _Other) = delete;
	CharacterFighter(CharacterFighter&& _Other) noexcept = delete;
	CharacterFighter& operator=(const CharacterFighter& _Other) = delete;
	CharacterFighter& operator=(CharacterFighter&& _Other) noexcept = delete;

protected:

	void Start() override;

	void Update(float _DeltaTime) override;

	// void End() override {}
	// void OnEvent() {}
	// void OffEvent() {}

private:
	void SetAnimationForFrameAnimationDESC();
	static std::map<std::string ,FrameAnimation_DESC> Fighter_F_Animation;

private:

};

enum class FighterMotionNumber
{
	Att_Dash,
	Att_BasePunch1,
	Att_OneinchPunch,
	Att_Upper,
	Att_BasePunch2,
	Att_BasePunch3,
	Att_BaseKick1,
	Move_QuickStand,
	Move_Dash,
	Move_Jump,
	Att_JumpKick,
	Att_Suplex1,
	Att_Spire,
	Att_LowKick1,
	Att_LowKick2,
	Hit_Stand1,
	Hit_FallUntilFloor,
	Hit_Down,
	Hit_Stand2,
	Att_Mount,
	Att_Casting,
	Att_Suplex2,
	Att_Suplex3,
	Att_JumpKick2,
	Move_Stand,
	Att_Changing,
	Att_Throwing,
	Att_Nen,
	Move_Stand_Battle,
	Move_Walk,
	Att_TakeDown,        // 내려찍기
	Att_MiddleKick,
	Att_RisingUpper,     // 라이징어퍼
	Att_Punch_Off,       // 붕권
	Att_Dash_Punch      

};
// 행위 > 행동