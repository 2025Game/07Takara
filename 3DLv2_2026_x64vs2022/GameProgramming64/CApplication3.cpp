#include "CApplication3.h"


CApplication3::CApplication3()
{
}

CApplication3::~CApplication3()
{
}

void CApplication3::Start()
{

    //タイトルシーン
    mpScene = std::make_unique<CTitleScene>();
    mpScene->Load();
    // ゲームシーン生成
    mpScene = std::make_unique<CGameScene>();

    // ゲームシーン読み込み
    mpScene->Load();


}

void CApplication3::Update()
{
    // ゲームシーン更新
    mpScene->Update();
}