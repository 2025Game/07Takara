#include "CApplication.h"
#include "CRectangle.h"
#include "CInput.h"
#include "glut.h"
#include "CVector.h"
#include"CTriangle.h"

#define SOUND_BGM "res\\mario.wav" //BGM音声ファイル
#define SOUND_OVER "res\\mdai.wav" //ゲームオーバー音声ファイル

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

}

void CApplication::Update()
{
	
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

	//視点の設定
	//gluLookAt(視点x,視点y,視点z,中心x,中心y,中心ｚ,上向ｘ,上向y,上向z)
	gluLookAt(1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	//描画開始
	//glBegin(形)
	//GL_TRIANGLES:三角形
	glBegin(GL_TRIANGLES);

	//法線（面の向き)の設定
	//glNormal3f(x座標、ｙ座標、ｚ座)
	//glNormal3f(0.0f, 1.0f, 0.0f);
	glNormal3f(n.X(), n.Y(), n.Z());
	//頂点座標の設定
	//glVertex3f(ｘ座標、Y座標、ｚ座標)
	glVertex3f(v0.X(),v0.Y(),v0.Z());
	glVertex3f(v1.X(),v1.Y(),v1.Z());
	glVertex3f(v2.X(),v2.Y(),v2.Z());
	
	//法線と頂点の設定
	n.Set(0.0f, 0.0f, 1.0f);
	v0.Set(0.5f, 0.0f, 0.0f);
	v1.Set(0.0f, 1.0f, 0.0f);
	v2.Set(-0.5f, 0.0f, 0.0f);

	//三角形2の描画
	glNormal3f(n.X(), n.Y(), n.Z());
	glVertex3f(v0.X(), v0.Y(), v0.Z());
	glVertex3f(v1.X(), v1.Y(), v1.Z());
	glVertex3f(v2.X(), v2.Y(), v2.Z());

	// 法線と頂点の設定
	n.Set(1.0f, 0.0f, 0.0f);
	v0.Set(0.0f, 0.5f, 0.0f);
	v1.Set(0.0f, 0.0f, 1.0f);
	v2.Set(0.0f, -0.5f, 0.0f);

	//課題三角形3の描画
	glNormal3f(n.X(), n.Y(), n.Z());
	glVertex3f(v0.X(), v0.Y(), v0.Z());
	glVertex3f(v1.X(), v1.Y(), v1.Z());
	glVertex3f(v2.X(), v2.Y(), v2.Z());
	


	//面の向きはｚ軸方向
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.5f, 0.0f, 0.0f);
	
	//課題 三角形を追加
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f,0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, -0.5f, 0.0f);

	


	//描画終了
	glEnd();

	//三角形クラスのインスタンス作成
	CTriangle t0;
	//法線と頂点の設定
	t0.Vertex(CVector(1.0f, 0.0f, 0.5f), CVector(2.0f, 0.0f, 0.0f), CVector(1.0f, 0.0f, -0.5f));
	t0.Normal(CVector(0.0f, 1.0f, 0.0f));
	//三角形の描画
	t0.Render();
	//三角形クラスのインスタンス作成
	CTriangle t1;
	//法線と頂点の設定
	t1.Vertex(CVector(0.5f, 1.0f, 0.0f), CVector(0.0f, 2.0f, 0.0f), CVector(-0.5f, 1.0f, 0.0f));
	t1.Normal(CVector(0.0f, 0.0f, 1.0f));
	//三角形の描画
	t1.Render();
	CTriangle t2;
	//法線と頂点の設定
	t2.Vertex(CVector(0.0f, -0.5f, 1.0f), CVector(0.0f, 0.5f, 1.0f), CVector(0.0f, 0.0f, 2.0f));
	t2.Normal(CVector(1.0f, 0.0f, 0.0f));
	t2.Render();
}
