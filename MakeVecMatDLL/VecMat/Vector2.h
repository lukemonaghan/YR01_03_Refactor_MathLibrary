#ifndef _VECTOR2
#define _VECTOR2

#ifndef _VECTOR2_DLL_
#define VECTOR2DLL __declspec(dllexport)
#else
#define VECTOR2DLL __declspec(dllimport)
#endif

#include "Maths.h"

class VECTOR2DLL Vector2{
public:
	//Define data types (both x/y and u/v)
	union{
		struct{
			float x,y;
		};
		struct{
			float u,v;
		};
		struct{
			float i[2];
		};
	};
	//Constructors
	Vector2();
	Vector2(float a, float b);
	//Member functions
	float Magnitude()const;
	float MagnitudeSquared()const;

	float Dot(Vector2 vect);

	bool IsUnit()const;
	Vector2 GetUnit()const;

	Vector2 NormalizeReturn();
	void Normalize();

	Vector2 GetPerpendicular()const;

	void RotateRad(float angle);
	void RotateDegree(float angle);

	void RadianToVect(float angle);
	void degreeToVect(float angle);

	void Project(float angle, float distance);

	Vector2 Lerp(Vector2 vect1,Vector2 vect2,float t);

	void Zero();
	void One();
	float Sum()const;
	float Min()const;
	float Max()const;
//Overloads
	//Comparitors
	bool    operator   == (Vector2 vect)const;
	bool    operator   != (Vector2 vect)const;
	void    operator    = (float scalar);
	//negate		   					
	Vector2 operator   -  (            );
	//Addition		   					
	Vector2 operator   ++ (            );
	Vector2 operator   +  (Vector2 vect)const;
	Vector2 operator   += (Vector2 vect);
	Vector2 operator   +  (float scalar)const;
	Vector2 operator   += (float scalar);
	//Subtraction	   					
	Vector2 operator   -- (            );
	Vector2 operator   -  (Vector2 vect)const;
	Vector2 operator   -= (Vector2 vect);
	Vector2 operator   -  (float scalar)const;
	Vector2 operator   -= (float scalar);
	//Division							
	Vector2 operator   /  (Vector2 vect)const;
	Vector2 operator   /= (Vector2 vect);
	Vector2 operator   /  (float scalar)const;
	Vector2 operator   /= (float scalar);
	//Multiplication   					
	Vector2 operator   *  (Vector2 vect)const;
	Vector2 operator   *= (Vector2 vect);
	Vector2 operator   *  (float scalar)const;
	Vector2 operator   *= (float scalar);

};

#endif