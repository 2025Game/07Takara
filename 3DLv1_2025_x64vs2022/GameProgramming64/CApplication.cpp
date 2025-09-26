#include "CApplication.h"
#include "CRectangle.h"
#include "CInput.h"
#include "glut.h"

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

	//視点の設定
	//gluLookAt(視点x,視点y,視点z,中心x,中心y,中心ｚ,上向ｘ,上向y,上向z)
	gluLookAt(1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	//描画開始
	//glBegin(形)
	//GL_TRIANGLES:三角形
	glBegin(GL_TRIANGLES);

	//法線（面の向き)の設定
	//glNormal3f(x座標、ｙ座標、ｚ座)
	glNormal3f(0.0f, 1.0f, 0.0f);

	//頂点座標の設定
	//glVertex3f(ｘ座標、Y座標、ｚ座標)
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -0.5f);

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

}
