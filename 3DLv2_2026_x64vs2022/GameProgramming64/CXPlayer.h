#pragma once
#ifndef CXPLAYER_H
#define CXPLAYER_H
#include "CXCharacter.h"
#include "CColliderLine.h"
#include "CCollisionManager.h"
#include <memory>
#include "CState.h"
#include "CPlayerIdle.h"
class CXPlayer : public CXCharacter
{
public:
    void Update() override;
    //衝突処理
//Collision(コライダ1, コライダ2)
    void Collision(CCollider* m, CCollider* o);
    //衝突処理
    void Collision();
    CColliderLine mColliderLine;
    CXPlayer();
private:
    EState mState; //状態䛾保持
    CState* mpState; //状態処理
    std::unique_ptr<CPlayerIdle> mpIdle; //待機状態
};

#endif