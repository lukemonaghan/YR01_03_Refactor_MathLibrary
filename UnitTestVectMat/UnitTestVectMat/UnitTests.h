#ifndef _UNITTEST_H_
#define _UNITTEST_H_

#include "UnitTestGeneric.h"

#include "Include\Matrix3.h"
#include "Include\Matrix4.h"

#include "Include\Vector2.h"
#include "Include\Vector3.h"

#include <iostream>

using namespace std;//yeah I know..

class cUnitTestTranslate3 : public cUnitTest{
public :
	void SetData(Matrix3 mat,Vector2 vect, Matrix3 matans){
		Matx3 = mat;
		Vect2 = vect;
		MatAns = matans;
	}
	virtual bool DoTest(){
		Matx3.TranslateXY(Vect2);
		return (Matx3 == MatAns);
	}
	virtual void Show(){
	cout << " -      Matx3 : " << endl
		 << "                " << Matx3.m00 << " : " << Matx3.m01 << " : " << Matx3.m02 << endl
		 << "                " << Matx3.m10 << " : " << Matx3.m11 << " : " << Matx3.m12 << endl
		 <<	"                " << Matx3.m20 << " : " << Matx3.m21 << " : " << Matx3.m22 << endl;
	cout << " -     MatAns : " << endl
		 << "                " << MatAns.m00 << " : " << MatAns.m01 << " : " << MatAns.m02 << endl
		 << "                " << MatAns.m10 << " : " << MatAns.m11 << " : " << MatAns.m12 << endl
		 <<	"                " << MatAns.m20 << " : " << MatAns.m21 << " : " << MatAns.m22 << endl;
	}
private:
	Matrix3 Matx3;
	Matrix3 MatAns;
	Vector2 Vect2;
};

class cUnitTestTranslate4 : public cUnitTest{
public :
	void SetData(Matrix4 mat,Vector3 vect, Matrix4 matans){
		Matx4 = mat;
		Vect3 = vect;
		MatAns = matans;
	}
	virtual bool DoTest(){
		Matx4.TranslateXYZ(Vect3);
		return (Matx4 == MatAns);
	}
	virtual void Show(){
	cout << " -      Matx4 : " << endl
		 << "                " << Matx4.m00 << " : " << Matx4.m01 << " : " << Matx4.m02 << " : " << Matx4.m03 << endl
		 << "                " << Matx4.m10 << " : " << Matx4.m11 << " : " << Matx4.m12 << " : " << Matx4.m13 << endl
		 <<	"                " << Matx4.m20 << " : " << Matx4.m21 << " : " << Matx4.m22 << " : " << Matx4.m23 << endl
		 <<	"                " << Matx4.m30 << " : " << Matx4.m31 << " : " << Matx4.m32 << " : " << Matx4.m33 << endl;
	cout << " -     MatAns : " << endl
		 << "                " << MatAns.m00 << " : " << MatAns.m01 << " : " << MatAns.m02 << " : " << MatAns.m03 << endl
		 << "                " << MatAns.m10 << " : " << MatAns.m11 << " : " << MatAns.m12 << " : " << MatAns.m13 << endl
		 <<	"                " << MatAns.m20 << " : " << MatAns.m21 << " : " << MatAns.m22 << " : " << MatAns.m23 << endl
		 <<	"                " << MatAns.m30 << " : " << MatAns.m31 << " : " << MatAns.m32 << " : " << MatAns.m33 << endl;
	}
private:
	Matrix4 Matx4;
	Matrix4 MatAns;
	Vector3 Vect3;
};

#endif