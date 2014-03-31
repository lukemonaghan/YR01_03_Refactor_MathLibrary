#ifndef _VECTOR4
#define _VECTOR4

#ifndef _VECTOR4_DLL_
#define VECTOR4DLL __declspec(dllexport)
#else
#define VECTOR4DLL __declspec(dllimport)
#endif

#include "Maths.h"

class VECTOR4DLL Vector4{
public:
	union{
		struct{
			float w,x,y,z;
		};
		struct{
			float r,g,b,a;
		};
	};

	Vector4();
	Vector4(float a, float b, float c, float d);
	Vector4(char* hex);
	void Hex(char* hex);

	float Magnitude()const;
	float MagnitudeSquared()const;

	void Normalize();
	Vector4 NormalizeReturn()const;
	//multiple sets, sum and min max.
	void Zero();
	void  One();
	float Sum()const;
	float Min()const;
	float Max()const;
//Overloads
	//Comparitors
	bool    operator   == (Vector4 vect)const;
	bool    operator   != (Vector4 vect)const;
	void    operator    = (float scalar);
	//negate		   					
	Vector4 operator   -  (            );
	//Addition		   					
	Vector4 operator   ++ (            );
	Vector4 operator   +  (Vector4 vect)const;
	Vector4 operator   += (Vector4 vect);
	Vector4 operator   +  (float scalar)const;
	Vector4 operator   += (float scalar);
	//Subtraction	   					
	Vector4 operator   -- (            );
	Vector4 operator   -  (Vector4 vect)const;
	Vector4 operator   -= (Vector4 vect);
	Vector4 operator   -  (float scalar)const;
	Vector4 operator   -= (float scalar);
	//Division		   					
	Vector4 operator   /  (Vector4 vect)const;
	Vector4 operator   /= (Vector4 vect);
	Vector4 operator   /  (float scalar)const;
	Vector4 operator   /= (float scalar);
	//Multiplication   					
	Vector4 operator   *  (Vector4 vect)const;
	Vector4 operator   *= (Vector4 vect);
	Vector4 operator   *  (float scalar)const;
	Vector4 operator   *= (float scalar);

};

#endif