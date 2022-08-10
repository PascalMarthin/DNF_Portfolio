#pragma once

// 설명 : Town에 해당되는 레벨의 템플릿
class TownLevel
{
public:
	// constrcuter destructer
	TownLevel();
	~TownLevel();

	// delete Function
	TownLevel(const TownLevel& _Other) = delete;
	TownLevel(TownLevel&& _Other) noexcept = delete;
	TownLevel& operator=(const TownLevel& _Other) = delete;
	TownLevel& operator=(TownLevel&& _Other) noexcept = delete;

	virtual GameEngineTexture* GetCollisionMapTexture() { return nullptr;  };
protected:


private:

};

