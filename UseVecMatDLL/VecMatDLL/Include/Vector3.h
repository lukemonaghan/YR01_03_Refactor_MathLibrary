#ifndef _VECTOR3
#define _VECTOR3

#ifndef _VECTOR3_DLL_
#define VECTOR3DLL __declspec(dllexport)
#else
#define VECTOR3DLL __declspec(dllimport)
#endif

#include "Maths.h"

class VECTOR3DLL Vector3{
public:
    union{
        struct {
            float x,y,z;
        };
        struct{
            float i[3];
        };
    };	
	Vector3();
	Vector3(float a,float b,float c);
//Member functions
	float Magnitude()const;
	float MagnitudeSquared()const;

	float Dot(Vector3 vect);

	bool IsUnit()const;
	Vector3 GetUnit()const;

	Vector3 NormalizeReturn();
	void Normalize();

	Vector3 Cross(Vector3 vect);
	Vector3 Cross(Vector3 vect,Vector3 vect2);
	Vector3 Cross2(Vector3 vect,Vector3 vect2);

	void RotateXRad(float angle);
	void RotateXDeg(float angle);
	void RotateYRad(float angle);
	void RotateYDeg(float angle);	
	void RotateZRad(float angle);
	void RotateZDeg(float angle);

	void Project(Vector3 angles, float distance);
	void ProjectOrtho(Vector3 angles,float distance);

	Vector3 Lerp(Vector3 vect1,Vector3 vect2,float t);

	void Zero();
	void One();
	float Sum()const;
	float Min()const;
	float Max()const;
//Overloads
	//Comparitors
	bool    operator   == (Vector3 vect)const;
	bool    operator   != (Vector3 vect)const;
	void    operator    = (float scalar);
	//negate		   					
	Vector3 operator   -  (            );
	//Addition		   					
	Vector3 operator   ++ (            );
	Vector3 operator   +  (Vector3 vect)const;
	Vector3 operator   += (Vector3 vect);
	Vector3 operator   +  (float scalar)const;
	Vector3 operator   += (float scalar);
	//Subtraction	   					
	Vector3 operator   -- (            );
	Vector3 operator   -  (Vector3 vect)const;
	Vector3 operator   -= (Vector3 vect);
	Vector3 operator   -  (float scalar)const;
	Vector3 operator   -= (float scalar);
	//Division		   					
	Vector3 operator   /  (Vector3 vect)const;
	Vector3 operator   /= (Vector3 vect);
	Vector3 operator   /  (float scalar)const;
	Vector3 operator   /= (float scalar);
	//Multiplication   					
	Vector3 operator   *  (Vector3 vect)const;
	Vector3 operator   *= (Vector3 vect);
	Vector3 operator   *  (float scalar)const;
	Vector3 operator   *= (float scalar);

};

#endif