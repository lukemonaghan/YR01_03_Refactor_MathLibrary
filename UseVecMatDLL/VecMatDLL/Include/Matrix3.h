#ifndef _MATRIX3
#define _MATRIX3

#ifndef _MATRIX3_DLL_
#define MATRIX3DLL __declspec(dllexport)
#else
#define MATRIX3DLL __declspec(dllimport)
#endif

#include "Maths.h"
#include "Vector3.h"
#include "Vector2.h"

class MATRIX3DLL Matrix3{
public:
	union{ //so we can use individual or array;
		struct{
			float m[3][3];
		};
		struct{
			float m00,m01,m02,
				  m10,m11,m12,
				  m20,m21,m22;
		};
	};
	Matrix3();
	Matrix3(float fm00,float fm01,float fm02,
			float fm10,float fm11,float fm12,
			float fm20,float fm21,float fm22);
	
	float Determinant()const;
	bool  Inverse();
	bool  InverseGet(Matrix3 &mat3)const;
		  
	void  RotateX (float angle);
	void  RotateY (float angle);
	void  RotateZ (float angle);
		  
	void  RotateXYZ (Vector3 v3Angles);
	void  RotateYXZ (Vector3 v3Angles);
	void  RotateZXY (Vector3 v3Angles);
	void  RotateZYX (Vector3 v3Angles);

	void TranslateX ( float scalar);
	void TranslateY ( float scalar);
	void TranslateXY ( Vector2 vect );	

	void  Ortho();
	void  OrthoNormalize();
		  
	void  Scale(Vector3 vect);
	void  Scale(float scalar);
		  
	void  Identity();
	void  Zero();

//overloads
	//Comparitors
	bool    operator   == (Matrix3 mat3)const;
	bool    operator   != (Matrix3 mat3)const;
	void    operator    = (Matrix3 mat3);
	void    operator    = (float scalar);
	//negate		   					
	Matrix3 operator   -  (            );
	//Addition		   					
	Matrix3 operator   ++ (            );
	Matrix3 operator   +  (Matrix3 mat3)const;
	Matrix3 operator   += (Matrix3 mat3);
	//Subtraction	   					
	Matrix3 operator   -- (            );
	Matrix3 operator   -  (Matrix3 mat3)const;
	Matrix3 operator   -= (Matrix3 mat3);
	//Multiplication  
	Matrix3 operator   *  (Matrix3 mat3)const;
	Matrix3 operator   *= (Matrix3 mat3);

	Vector3 operator   *  (Vector3 vect)const;
	Vector3 operator   *= (Vector3 vect);

	Matrix3 operator   *  (float scalar)const;
	Matrix3 operator   *= (float scalar);
};
#endif