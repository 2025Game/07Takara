#pragma once
#include "CState.h"
#include "CVector.h"
class CPlayerJump : public CState
{
public:
	//状態開始
	void Start(CXCharacter* parent) override;
	//衝突処理
//Collision(コライダ1, コライダ2)
	void Collision(CCollider* m, CCollider* o) override;
	//更新
	void Update() override;
private:
	CVector mJumpV; //ジャンプの速度
};