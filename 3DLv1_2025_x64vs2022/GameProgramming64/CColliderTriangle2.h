#pragma once
#pragma once
#ifndef CCOLLIDERTRIANGLE2_H
#define CCOLLIDERTRIANGLE2_H

#include "CCollider.h"

/*
三角形コライダ2の定義
*/
class CColliderTriangle2 : public CCollider
{
public:
    CColliderTriangle2() {}

    // コンストラクタ
    CColliderTriangle2(CCharacter3* parent, CMatrix* matrix,
        const CVector& v0, const CVector& v1, const CVector& v2);

    // 設定
    void Set(CCharacter3* parent, CMatrix* matrix,
        const CVector& v0, const CVector& v1, const CVector& v2);

    // 描画
    void Render();
};

#endif
