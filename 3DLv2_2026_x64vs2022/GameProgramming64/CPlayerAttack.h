#pragma once
#include "CState.h"

class CPlayerAttack : public CState
{
public:
	//状態開始
	void Start(CXCharacter* parent) override;

	//更新
	void Update() override;
private:
	
};