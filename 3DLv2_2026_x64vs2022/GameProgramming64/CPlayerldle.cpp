#include "CPlayerIdle.h"
#include "CXCharacter.h"
//回転速度
#define ROTATIONSPEED 2.0f
void CPlayerIdle::Start(CXCharacter* parent)
{
	//親のポインタを保存
	mpParent = parent;
	//アニメーションの変更
	mpParent->ChangeAnimation(0, true, 60);
	mState = EState::EIDLE; //状態の種類を待機䛻する
}
void CPlayerIdle::Update()
{
	//Aキーを左回転、Dキーを右回転
	if (mInput.Key('D'))
	{
		CVector r = mpParent->Rotation() -
			CVector(0.0f, -ROTATIONSPEED, 0.0f);
		mpParent->Rotation(r);
	}
	
	if (mInput.Key('A'))
	{
		CVector r = mpParent->Rotation() -
			CVector(0.0f, +ROTATIONSPEED, 0.0f);
		mpParent->Rotation(r);
	}
	if (mInput.Key('W'))
	{
		mState = EState::EWALK;
	}

	//Iキーを押すと攻撃状態状態に切り替える
	if (mInput.Key('I'))
	{
		mState = EState::EATTACK;
	}

	//スペースキーを押すとジャンプ状態に切り替える
	if (mInput.Key(VK_SPACE))
	{
		mState = EState::EJUMP;
	}
}
