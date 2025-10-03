#include "CVector.h" 
//Set(Ｘ座標、Ｙ座標、Ｚ座標)
void CVector::Set(float x, float y, float z)
{
	mX = x;
	mY = y;
	mZ = z;
}

float CVector::X()const
{
	return mX;
}

float CVector::Y()const
{
	return mY;
}

float CVector::Z()const
{
	return mZ;
}