#include "CApplication.h"
#include "CRectangle.h"
#include "CInput.h"
#include "glut.h"
#include "CVector.h"
#include"CTriangle.h"
#include"CMatrix.h"
#include"CTransform.h"
//背景モデル
#define MODEL_BACKGROUND "res\\sky.obj","res\\sky.mtl"

#define SOUND_BGM "res\\mario.wav" //BGM音声ファイル
#define SOUND_OVER "res\\mdai.wav" //ゲームオーバー音声ファイル
//モデルデータの指定
#define MODEL_OBJ "res\\f14.obj", "res\\f14.mtl"


CCharacterManager CApplication::mCharacterManager;
CTexture CApplication::mTexture;

CTexture* CApplication::Texture()
{
	return &mTexture;
}

CCharacterManager* CApplication::CharacterManager()
{
	return &mCharacterManager;
}

void CApplication::Start()
{
	mEye = CVector(1.0f, 2.0f, 3.0f);
	mModel.Load(MODEL_OBJ);
	mBackGround.Load(MODEL_BACKGROUND);
	CMatrix matrix;
	matrix.Print();


	// 追加キャラ
	mPlayer.Model(&mModel);
	mPlayer.Scale(CVector(0.1f, 0.1f, 0.1f)); // 拡大縮小
	mPlayer.Position(CVector(0.0f, 0.0f, -3.0f)); // 位置
	mPlayer.Rotation(CVector(0.0f, 180.0f, 0.0f)); // 回転

}

void CApplication::Update()
{
	mPlayer.Update();
	//カメラのパラメータを作成する
	CVector e, c, u;//視点、注視点、上方向
	//視点を求める
		e = mPlayer.Position() +CVector (0, 1, -3) * mPlayer.MatrixRotate();
		//注視点を求める
		c = mPlayer.Position();
	//上方向を求める
	u = CVector(0, 1, 0)*mPlayer.MatrixRotate();
		//カメラの設定
		gluLookAt(e.X(), e.Y(), e.Z(), c.X(), c.Y(), c.Z(), u.X(), u.Y(), u.Z());
		
		mPlayer.Render();
		mBackGround.Render();
		
	//頂点１、頂点２、頂点３、法線データの作成
	CVector v0, v1, v2, n;
	//法線を上向きで設定する
	n.Set(0.0f, 1.0f, 0.0f);
	//頂点１の座標を設定する
	v0.Set(0.0f, 0.0f, 0.5f);
	//頂点2の座標を設定する
	v1.Set(1.0f, 0.0f, 0.0f);
	//頂点３の座標を設定する
	v2.Set(0.0f, 0.0f, -0.5f);

	
	

	
	
	
	if (mInput.Key('J'))
	{
		mEye = mEye - CVector(0.1f, 0.0f, 0.0f);
	}
	if (mInput.Key('L'))
	{
		mEye = mEye + CVector(0.1f, 0.0f, 0.0f);
	}

	if (mInput.Key('I'))
	{
		mEye = mEye - CVector(0.0f, 0.0f, 0.1f);
	}
	if (mInput.Key('K'))
	{
		mEye = mEye + CVector(0.0f, 0.0f, 0.1f);
	}

	if (mInput.Key('O'))
	{
		mEye = mEye - CVector(0.0f, 0.1f, 0.0f);
	}
	if (mInput.Key('M'))
	{
		mEye = mEye + CVector(0.0f, 0.1f, 0.0f);
	}

	mPlayer.bullet.Update();
	mPlayer.bullet.Render();

}
