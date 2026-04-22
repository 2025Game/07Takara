#include "CSceneBase.h"

// コンストラクタ
CSceneBase::CSceneBase(EScene scene)
{
    mSceneType = scene;
}

// シーンタイプ取得
EScene CSceneBase::GetSceneType() const
{
    return mSceneType;
}