#include "CGameScene.h"
#include "CCharacter3.h"
#include "CTaskManager.h"
#include "CXCharacter.h"
#include "CXPlayer.h"
//背景モデルデータの指定
#define MODEL_BACKGROUND "res\\sky.obj","res\\sky.mtl"

CGameScene::CGameScene()
	:CSceneBase(EScene::eGame)
{

}

void CGameScene::Load()

{
   
    //課題　背景モデルデータの読み込み
    mBackGround.Load(MODEL_BACKGROUND);
    //キャラクタのインスタンス作成
    CCharacter3* character = new CCharacter3();
    //キャラクタのモデルの設定
    character->Model(&mBackGround);
    mPlayer.Load(MODEL_FILE);
    // Xキャラクタ生成
    CXCharacter* xchar = new CXPlayer();
    // mPlayerを設定
    xchar->Init(&mPlayer);
    // プレイヤー位置設定
    xchar->Position(CVector(1.0f, 0.0f, 0.0f));
    mColliderMesh.Set(nullptr, nullptr, &mBackGround);
   
}

void CGameScene::Update()
{
    // カメラ設定
    gluLookAt(
        1.0f, 2.0f, 10.0f,
        0.0f, 2.0f, 0.0f,
        0.0f, 1.0f, 0.0f
    );
    mBackGround.Render();
    // 全キャラクタ更新
    CTaskManager::Instance()->Update();
    //衝突処理の呼び出し
    CTaskManager::Instance()->Collision();
    // 全キャラクタ描画
    CTaskManager::Instance()->Render();
    //コライダの描画
    CCollisionManager::Instance()->Render();

    
}

