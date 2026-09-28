#ifndef CGAMESCENE_H
#define CGAMESCENE_H
#include "CPaladin.h"
#include "CSceneBase.h"
#include "CModel.h"
#include "CColliderMesh.h"
//ゲームシーン
class CGameScene :public CSceneBase
{
public:
	CGameScene();
	//シーン読み込み
	void Load();
	CPaladin* paladin = new CPaladin(
		CVector(0.0f, 1.0f, -4.0f)
	);

	//シーンの更新処理
	void Update();
private:
	CColliderMesh mColliderMesh; //メッシュコライダ
	CModel mBackGround; //背景モデル
	CModelX mPlayer;
};

#endif

