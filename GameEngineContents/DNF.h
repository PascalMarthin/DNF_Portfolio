#pragma once
#include <GameEngineCore/GameEngineCore.h>

// ���� :
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

	// �� ���α׷��� ��� ��Ȳ������ ��� Update�ϸ鼭 üũ������ �ִٸ� ���⼭ �Ѵ�.
	// ������ ���� ������ �׷����� ����. ������ ���� �����̰� ���� ����Ű�� ������ �����Ѵ�.
	// Ÿ��Ʋ�� �ѱ�ų� �̷�
	void Update(float _DeltaTime) override;

	void End() override;

private:

	void AllResourceLoad();
	void BaseSoundLoad();
	void BaseTextureLoad();
	void BaseFolderTextureLoad();
	void BaseKeySetting();
	

};
