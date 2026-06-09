#pragma once
class CCollider;
class CXCharacter;
//状態䛾種類
enum class EState
{
	EJUMP,//ジャンプ
	ENONE, //状態䛺し
	EIDLE, //待機
	EWALK, //歩き
	EATTACK,//攻撃
};
class CState
{
public:
	virtual ~CState() {};
	//状態䛾開始
	virtual void Start(CXCharacter* parent) {};
	//状態䛾更新
	virtual void Update() {};
	//衝突処理
	//Collision(コライダ1, コライダ2)
	virtual void Collision(CCollider* m, CCollider* o) {};
	//状態䛾取得
	EState State() { return mState; }
protected:
	EState mState; //状態䛾種類
	CXCharacter* mpParent; //親のポインタ
};