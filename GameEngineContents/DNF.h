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
	float4 StartWindowSize() override
	{ 
		return { 1280.0f, 720.0f }; 
	};

	float4 StartWindowPosition() override
	{ 
		return { 0,0 }; 
	};

	
	template<typename LevelType>
	inline void CreateLoadLevel(const std::string& _Name)
	{
		CreateLevel<LevelType>(_Name);
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
	void BaseShaderLoad();
	

	// ------------Static----------
public:
	inline static DNF* GetInst()
	{
		return DNF::MainCoreEngine;
	}


private:
	static DNF* MainCoreEngine;
};
