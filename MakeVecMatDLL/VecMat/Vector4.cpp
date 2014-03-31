#include "stdafx.h"

#include "Vector4.h"
#include <math.h>

//Constructor 4D
Vector4::Vector4(){
	w=0.0f;
	x=0.0f;
	y=0.0f;
	z=0.0f;
}
Vector4::Vector4(float a, float b, float c, float d){
	w = a;
	x = b;
	y = c;
	z = d;
}
Vector4::Vector4(char* hex){
	Hex(hex);
}
void Vector4::Hex(char* hex){
	//add char array check here
	//Temps
	r = g = b = a = 0;
	int tempint;
	//itterate through hex

	for( int i = 0; i < 8; i++){
		tempint = 0;
		if (hex[i] <= 'z' && hex[i] >= 'a'){
			if (hex[i] <= '0' && hex[i] >= '9'){	
			}else{
				hex[i]-=32;
			}
		}
		if (hex[i]>='A'){
			tempint = hex[i] - 'A';
			tempint += 10;
		}else{
			tempint += hex[i] - '0';
		}
		//Construct the values(this is to big)
		switch (i){
		case 7:
			a+=tempint*1;
			break;
		case 6:
			a+=tempint*16;
			break;
		case 5:
			b+=tempint*1;
			break;
		case 4:
			b+=tempint*16;
			break;
		case 3:
			g+=tempint*1;
			break;
		case 2:
			g+=tempint*16;
			break;
		case 1:
			r+=tempint*1;
			break;	
		case 0:
			r+=tempint*16;
			break;
		}
	}
}
//magnitude of 4D vector
float Vector4::Magnitude()const{ 
	return sqrt((w*w)+(x*x)+(y*y)+(z*z));
}
float Vector4::MagnitudeSquared()const{ 
	return ((w*w)+(x*x)+(y*y)+(z*z));
}
//Normalize of 4D vector (on self)
void Vector4::Normalize(){ 
	float len = Magnitude();
	w/=len;
	x/=len;
	y/=len;
	z/=len;
}
Vector4 Vector4::NormalizeReturn()const{ 
	Vector4 vect(w,x,y,z);
	float len = vect.Magnitude();
	vect.w/=len;
	vect.x/=len;
	vect.y/=len;
	vect.z/=len;
	return vect;
}
//multiple sets, sum and min max.
void Vector4::Zero(){
	w= x = y = z = 0.0f;
}
void Vector4::One(){
	w= x = y = z = 1.0f;
}
float Vector4::Sum()const{
	return (w+x+y+z);
}
float Vector4::Min()const{
	return Minf(Minf(w,x),Minf(y,z));
}
float Vector4::Max()const{
	return Maxf(Maxf(w,x),Maxf(y,z));
}
//Overloads
	//Comparitors
	bool    Vector4::operator   == (Vector4 vect)const {return(w == vect.w && x == vect.x && y == vect.y && z == vect.z);}
	bool    Vector4::operator   != (Vector4 vect)const {return(w != vect.w && x != vect.x && y != vect.y && z != vect.z);}
	void    Vector4::operator    = (float scalar)      {               w = scalar;x = scalar;y = scalar;z = scalar      ;}
	//negate		   					      										 
	Vector4 Vector4::operator   -  (            )      {return(Vector4(-w        ,-x        ,-y        ,-z)        )    ;}
	//Addition		   										
	Vector4 Vector4::operator   ++ (            )      {return Vector4(++w       ,++x       ,++y       , ++z       )    ;}
	Vector4 Vector4::operator   +  (Vector4 vect)const {return Vector4(w + vect.w,x + vect.x,y + vect.y, z + vect.z)    ;}
	Vector4 Vector4::operator   += (Vector4 vect)      {return ((*this) = (*this) + vect    ) ;}
	Vector4 Vector4::operator   +  (float scalar)const {return Vector4(w + scalar,x + scalar,y + scalar, z + scalar)    ;}
	Vector4 Vector4::operator   += (float scalar)      {return ((*this) = (*this) + scalar  ) ;}
	//Subtraction	   					      										    
	Vector4 Vector4::operator   -- (            )      {return Vector4(--w       ,--x       ,--y       , --z       )    ;}
	Vector4 Vector4::operator   -  (Vector4 vect)const {return Vector4(w - vect.w,x - vect.x,y - vect.y, z - vect.z)    ;}
	Vector4 Vector4::operator   -= (Vector4 vect)      {return ((*this) = (*this) + vect    ) ;}
	Vector4 Vector4::operator   -  (float scalar)const {return Vector4(w - scalar,x - scalar,y - scalar, z - scalar)    ;}
	Vector4 Vector4::operator   -= (float scalar)      {return ((*this) = (*this) - scalar  ) ;}
	//Division		   					      								    
	Vector4 Vector4::operator   /  (Vector4 vect)const {return Vector4(w / vect.w,x / vect.x,y / vect.y, z / vect.z)    ;}
	Vector4 Vector4::operator   /= (Vector4 vect)      {return ((*this) = (*this) + vect    ) ;}
	Vector4 Vector4::operator   /  (float scalar)const {return Vector4(w / scalar,x / scalar,y / scalar, z / scalar)    ;}
	Vector4 Vector4::operator   /= (float scalar)      {return ((*this) = (*this) / scalar  ) ;}
	//Multiplication   					      										    
	Vector4 Vector4::operator   *  (Vector4 vect)const {return Vector4(w * vect.w,x * vect.x,y * vect.y, z * vect.z)    ;}
	Vector4 Vector4::operator   *= (Vector4 vect)      {return ((*this) = (*this) * vect    ) ;}
	Vector4 Vector4::operator   *  (float scalar)const {return Vector4(w * scalar,x * scalar,y * scalar, z * scalar)    ;}
	Vector4 Vector4::operator   *= (float scalar)      {return ((*this) = (*this) * scalar  ) ;}