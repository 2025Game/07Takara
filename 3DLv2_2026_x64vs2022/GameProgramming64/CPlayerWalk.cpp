#include "CPlayerWalk.h"
#include "CXCharacter.h"
#define VELOCITY 0.1f
#define ROTATIONSPEED 1.5f
void CPlayerWalk::Start(CXCharacter* parent)
{
	//親のポインタを保存
	mpParent = parent;
	//アニメーション
	mpParent->ChangeAnimation(1, true, 60);
	mState = EState::EWALK;
}

void CPlayerWalk::Update()
{
	if (mInput.Key('W'))
	{
		//Wキー 前進
		CVector p = mpParent->Position();

		mpParent->Position(
			p +
			mpParent->MatrixRotate().VectorZ() * VELOCITY);


		//Aキー 左回転
		if (mInput.Key('A'))
		{
			CVector r =
				mpParent->Rotation() -
				CVector(0.0f, ROTATIONSPEED, 0.0f);

			mpParent->Rotation(r);
		}

		//Dキー 右回転
		if (mInput.Key('D'))
		{
			CVector r =
				mpParent->Rotation() +
				CVector(0.0f, ROTATIONSPEED, 0.0f);

			mpParent->Rotation(r);
		}

		//Iキー　攻撃状態を攻撃
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
	else
	{
		//W離したら待機
		mState = EState::EIDLE;
	}
}



