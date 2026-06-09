#include "CState.h"
#include "CPlayerJump.h"
#include "CXCharacter.h"
#include "CCollider.h"
#define GRAVITY CVector(0.0f, -0.0312f, 0.0f) // 重力加速度
#define JUMP_V CVector(0.0f, 0.6f, 0.0f) // ジャンプ初速

void CPlayerJump::Collision(CCollider* m, CCollider* o)
{
	//自身䛾コライダタイプ䛾判定
	switch (m->Type())
	{
	case CCollider::EType::ELINE://線分コライダ
		//相手のコライダが三角コライダの時
		if (o->Type() ==
			CCollider::EType::ETRIANGLE)
		{
			CVector adjust;//調整用ベクトル
			//三角形と線分の衝突判定
			if (CCollider::CollisionTriangleLine(
				o, m, &adjust))

			{
				//待機状態にする
				mState = EState::EIDLE;
			}
		}
		break;
	}
}

void CPlayerJump::Start(CXCharacter* parent)
{
	//親ポインタ
	mpParent = parent;
   //ジャンプアニメーション
	mpParent->ChangeAnimation(7, false,80 );
	//ジャンプ
	mState = EState::EJUMP;
	//ジャンプ初速度
	mJumpV = JUMP_V; 
}
void CPlayerJump::Update()
{
	//ジャンプの速度分だけ、上方向
	mpParent->Position(mpParent->Position() + mJumpV);
	//重力加速度分だけ、下方向への速度を増やす
	mJumpV = mJumpV + GRAVITY;
}
