#include "CPlayerWalk.h"
#include "CXCharacter.h"
#define VELOCITY 0.1f
void CPlayerWalk::Start(CXCharacter* parent)
{
	mpParent = parent;

	mState = EState::EWALK;
}

void CPlayerWalk::Update()
{
	if (mInput.Key('W'))
	{
		CVector p = mpParent->Position();
		mpParent->Position(p +
			mpParent->MatrixRotate().VectorZ() * VELOCITY);
	}
	else
	{
		//Wキー
		mState = EState::EIDLE;
	}

	if (mInput.Key('a'))
	{
		CVector p = mpParent->Position();
		mpParent->Position(p +
			mpParent->MatrixRotate().VectorZ() * VELOCITY);
	}
	else
	{
		//aキー
		mState = EState::EIDLE;
	}

	if (mInput.Key('d'))
	{
		CVector p = mpParent->Position();
		mpParent->Position(p -
			mpParent->MatrixRotate().VectorZ() * VELOCITY);
	}
	else
	{
		//dキー
		mState = EState::EIDLE;
	}
}



