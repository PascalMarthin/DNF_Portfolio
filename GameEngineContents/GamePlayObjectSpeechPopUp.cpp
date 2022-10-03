#include "PreCompile.h"
#include "GamePlayObjectSpeechPopUp.h"
#include <GameEngineCore/GameEngineFontRenderer.h>


GameEngineFolderTexture* GamePlayObjectSpeechPopUp::TextureR_PopText = nullptr;
GamePlayObjectSpeechPopUp::GamePlayObjectSpeechPopUp() 
{
}

GamePlayObjectSpeechPopUp::~GamePlayObjectSpeechPopUp() 
{
}

void GamePlayObjectSpeechPopUp::Start()
{
	if (GamePlayObjectSpeechPopUp::TextureR_PopText == nullptr)
	{
		{
			GameEngineDirectory Dir;
			Dir.MoveParentToExitsChildDirectory("Resource");
			Dir.Move("Resource");
			Dir.Move("Texture");
			Dir.Move("UI");
			Dir.Move("PopUp");
			Dir.Move("TalkPopUp");

			GameEngineFolderTexture::Load(Dir.GetFullPath());

		}

		TextureR_PopText = GameEngineFolderTexture::Find("TalkPopUp");


	}
}

void GamePlayObjectSpeechPopUp::CreatePopup(const std::string& _Speech)
{
	int StringSize = static_cast<int>(_Speech.size());

	float Len = StringSize * 5.f;

	for (auto& Iter :vector_Texture_PopText)
	{
		Iter->Death();
	}
	vector_Texture_PopText.clear();
	// PIVOTMODE


	float StartPosx = 0;
	float StartPosy = 50;
	// ²¿¸®
	GameEngineUIRenderer* Effect = GetActor()->CreateComponent<GameEngineUIRenderer>();
	Effect->SetTexture(TextureR_PopText->GetTexture(9));
	Effect->SetPivot(PIVOTMODE::TOP);
	Effect->ScaleToTexture();
	Effect->GetTransform().SetLocalPosition({0 , StartPosy, 0}); // 
	vector_Texture_PopText.push_back(Effect);
	StartPosx -= 6.f;

	// ÁÂÇÏ´Ü
	Effect = GetActor()->CreateComponent<GameEngineUIRenderer>();
	Effect->SetTexture(TextureR_PopText->GetTexture(7));
	Effect->SetPivot(PIVOTMODE::RIGHTTOP);
	Effect->GetTransform().SetLocalScale({ (Len - 12.f) * 0.5f , 5 , 0 });
	Effect->GetTransform().SetLocalPosition({ StartPosx , StartPosy , 0 });
	vector_Texture_PopText.push_back(Effect);


	StartPosx -= (Len - 12.f) * 0.5f;
	// ÁÂÇÏ´Ü³¡
	Effect = GetActor()->CreateComponent<GameEngineUIRenderer>();
	Effect->SetTexture(TextureR_PopText->GetTexture(6));
	Effect->SetPivot(PIVOTMODE::RIGHTTOP);
	Effect->ScaleToTexture();
	Effect->GetTransform().SetLocalPosition({ StartPosx , StartPosy , 0 });
	vector_Texture_PopText.push_back(Effect);


	// ÁÂÁß´Ü
	Effect = GetActor()->CreateComponent<GameEngineUIRenderer>();
	Effect->SetTexture(TextureR_PopText->GetTexture(3));
	Effect->SetPivot(PIVOTMODE::RIGHTBOT);
	Effect->GetTransform().SetLocalScale({ 5 , 13 , 0 });
	Effect->GetTransform().SetLocalPosition({ StartPosx , StartPosy , 0 });
	vector_Texture_PopText.push_back(Effect);

	// ÁÂ»ó´Ü³¡
	StartPosy += 13.f;
	Effect = GetActor()->CreateComponent<GameEngineUIRenderer>();
	Effect->SetTexture(TextureR_PopText->GetTexture(0));
	Effect->SetPivot(PIVOTMODE::RIGHTBOT);
	Effect->ScaleToTexture();
	Effect->GetTransform().SetLocalPosition({ StartPosx , StartPosy , 0 });
	vector_Texture_PopText.push_back(Effect);



	// »ó´ÜÁß¾Ó
	Effect = GetActor()->CreateComponent<GameEngineUIRenderer>();
	Effect->SetTexture(TextureR_PopText->GetTexture(1));
	Effect->SetPivot(PIVOTMODE::LEFTBOT);
	Effect->GetTransform().SetLocalScale({ Len, 5 });
	Effect->GetTransform().SetLocalPosition({ StartPosx , StartPosy , 0 });
	vector_Texture_PopText.push_back(Effect);


	// Áß¾Ó
	Effect = GetActor()->CreateComponent<GameEngineUIRenderer>();
	Effect->SetTexture(TextureR_PopText->GetTexture(4));
	Effect->SetPivot(PIVOTMODE::LEFTTOP);
	Effect->GetTransform().SetLocalScale({ Len, 13 });
	Effect->GetTransform().SetLocalPosition({ StartPosx , StartPosy , 0 });
	vector_Texture_PopText.push_back(Effect);

	StartPosx += Len;
	// ¿ìÃø³¡
	Effect = GetActor()->CreateComponent<GameEngineUIRenderer>();
	Effect->SetTexture(TextureR_PopText->GetTexture(2));
	Effect->SetPivot(PIVOTMODE::LEFTBOT);
	Effect->ScaleToTexture();
	Effect->GetTransform().SetLocalPosition({ StartPosx , StartPosy , 0 });
	vector_Texture_PopText.push_back(Effect);


	// ¿ìÃøÁß¾Ó

	Effect = GetActor()->CreateComponent<GameEngineUIRenderer>();
	Effect->SetTexture(TextureR_PopText->GetTexture(5));
	Effect->SetPivot(PIVOTMODE::LEFTTOP);
	Effect->GetTransform().SetLocalScale({ 5, 13 });
	Effect->GetTransform().SetLocalPosition({ StartPosx , StartPosy , 0 });
	vector_Texture_PopText.push_back(Effect);

	// ¿ìÃøÇÏ´Ü³¡
	StartPosy -= 13.f;
	Effect = GetActor()->CreateComponent<GameEngineUIRenderer>();
	Effect->SetTexture(TextureR_PopText->GetTexture(8));
	Effect->SetPivot(PIVOTMODE::LEFTTOP);	
	Effect->ScaleToTexture();;
	Effect->GetTransform().SetLocalPosition({ StartPosx , StartPosy , 0 });
	vector_Texture_PopText.push_back(Effect);

	// ¿ìÃøÇÏ´ÜÁß¾Ó

	Effect = GetActor()->CreateComponent<GameEngineUIRenderer>();
	Effect->SetTexture(TextureR_PopText->GetTexture(7));
	Effect->SetPivot(PIVOTMODE::RIGHTTOP);
	Effect->GetTransform().SetLocalScale({ (Len - 12.f) * 0.5f, 5 });
	Effect->GetTransform().SetLocalPosition({ StartPosx , StartPosy , 0 });
	vector_Texture_PopText.push_back(Effect);





	GameEngineFontRenderer* Font = GetActor()->CreateComponent<GameEngineFontRenderer>();
	Font->SetPositionMode(FontPositionMode::WORLD);
	Font->GetTransform().SetLocalPosition({ 0, 57, -1.f});
	Font->SetText(_Speech, "±¼¸²");
	Font->SetColor({ 1.0f, 1.0f, 1.0f, 1.f });
	Font->SetRenderingOrder(10000);
	Font->SetSize(12);
	Font->SetTopAndBotSort(TopAndBotSort::VCENTER);
	Font->SetLeftAndRightSort(LeftAndRightSort::CENTER);
	Font->Death(5.f);
	Font->ChangeCamera(CAMERAORDER::UIFont);
	for ( auto& Iter : vector_Texture_PopText)
	{
		Iter->Death(5.f);
		Iter->ChangeCamera(CAMERAORDER::UIFont);
	}
	

	
}