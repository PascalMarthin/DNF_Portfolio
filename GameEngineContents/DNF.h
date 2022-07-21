#pragma once
#include <GameEngineCore/GameEngineCore.h>

// 설명 :
class DNF : public GameEngineCore
{
public:
	DNF();
	~DNF();

	DNF(const DNF& _Other) = delete;
	DNF(DNF&& _Other) noexcept = delete;
	DNF& operator=(const DNF& _Other) = delete;
	DNF& operator=(DNF&& _Other) noexcept = delete;

	std::string GetWindowTitle() override
	{
		return "Dungeon And Fighter";
	}

protected:
	void Start() override;

	// 이 프로그램이 어느 상황에서건 계속 Update하면서 체크할일이 있다면 여기서 한다.
	// 서버가 붙지 않으면 그럴일은 없다. 게임이 무슨 레벨이건 뭐건 무슨키를 누르면 종료한다.
	// 타이틀을 넘기거나 이런
	void Update(float _DeltaTime) override;

	void End() override;

private:

	void AllResourceLoad();
	void BaseSoundLoad();
	void BaseTextureLoad();
	void BaseFolderTextureLoad();
	void BaseKeySetting();
	

};
