#pragma once
#ifndef CVECTOR_H
#define CVECTOR_H
/*
ベクトルクラス
ベクトルデータを扱います
*/
class CVector {
public:
	//各軸での値の設定
	//Set(x座標,y座標,z座標,)
	void Set(float x,float y,float z);
	//Xの値を得る
	float X()const;
	//Yの値を得る
	float Y()const;
	//Zの値を得る
	float Z()const;
private:
	//3D各軸での値を設定
	float mX, mY, mZ;
};
#endif