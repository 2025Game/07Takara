#include "CPlayerAttack.h"
#include "CXCharacter.h"
#include "CState.h"
void CPlayerAttack::Start(CXCharacter* parent)
{
	//親のポインタを保存
	mpParent = parent;

	//攻撃アニメーション
	mpParent->ChangeAnimation(3, false, 30);

	//攻撃状態
	mState = EState::EATTACK;
}

void CPlayerAttack::Update()
{
	//アニメーション終了判定
	if (mpParent->IsAnimationFinished())
	{
		//終了したら待機
		mState = EState::EIDLE;
	}
}
