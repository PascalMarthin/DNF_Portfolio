#pragma once

// ���� : Town�� �ش�Ǵ� ������ ���ø�
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

