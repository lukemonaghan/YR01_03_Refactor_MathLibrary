#include "stdafx.h"

#include "Vector3.h"
#include <math.h>

//Constructor 2D
Vector3::Vector3(){
	x=0;
	y=0;
	z=0;
}
Vector3::Vector3(float a,float b,float c){
	x = a;
	y = b;
	z = c;
}
//magnitude
float Vector3::Magnitude()const{
	return sqrt((x*x)+(y*y)+(z*z)); 
}
float Vector3::MagnitudeSquared()const{
	return (x*x)+(y*y)+(z*z); 
}
//Dot Product
float Vector3::Dot(Vector3 vect){
	return (x * vect.x + y * vect.y + z * vect.z);
}
//unit
bool Vector3::IsUnit()const{
	return (Magnitude() <= 1.0f);
}
Vector3 Vector3::GetUnit()const{
	float fMag = Magnitude();
	const float fInvNorm = (fMag != 0.0f) ? Recipf( fMag ) : 1.00e+12f;
	return Vector3( x * fInvNorm, y * fInvNorm , z * fInvNorm);
}
//Normalize
Vector3 Vector3::NormalizeReturn(){ 
	Vector3 vect;
	vect.x = x;
	vect.y = y;
	vect.z = z;
	float len = vect.Magnitude();
	vect.x/=len;
	vect.y/=len;
	vect.z/=len;
	return vect;
}
void Vector3::Normalize(){ 
	float len = Magnitude();
	x/=len;
	y/=len;
	z/=len;
}
//Cross Products
Vector3 Vector3::Cross(Vector3 vect){
	return Vector3( y * vect.z - z * vect.y, 
					z * vect.x - x * vect.z,
					x * vect.y - y * vect.x);
}
Vector3 Vector3::Cross(Vector3 vect,Vector3 vect2){
	return Vector3( vect.y * vect.z - vect.z * vect.y, 
					vect.z * vect.x - vect.x * vect.z,
					vect.x * vect.y - vect.y * vect.x );
}
Vector3 Vector3::Cross2(Vector3 vect,Vector3 vect2){
	return Vector3( (vect.x * vect2.z) - (vect.z * vect2.x), 
					vect.y,
					(vect.z * vect2.x) - (vect.x * vect2.z) );
}
//Rotate
void Vector3::RotateXRad(float angle){
	const float f_Y = y;
	y = (f_Y * cosf(angle)) - (z * sinf(angle));
	z = (f_Y * sinf(angle)) + (z * cosf(angle));
}
void Vector3::RotateXDeg(float angle){
	angle = degreeToRad(angle);
	RotateXRad(angle);
}
void Vector3::RotateYRad(float angle){
	const float f_X = x;
	x = (f_X * cosf(angle)) + (  z * sinf(angle));
	z = (  z * cosf(angle)) - (f_X * sinf(angle));
}
void Vector3::RotateYDeg(float angle){
	angle = degreeToRad(angle);
	RotateYRad(angle);
}
void Vector3::RotateZRad(float angle){
	const float f_X = x;
	x = (f_X * cosf(angle)) - ( y * sinf(angle));
	y = (f_X * sinf(angle)) + ( y * cosf(angle));
}
void Vector3::RotateZDeg(float angle){
	angle = degreeToRad(angle);
	RotateZRad(angle);
}
//Projection
void Vector3::Project(Vector3 angles, float distance){
	const float f_Z_Dist = distance * cosf(angles.x);
	y -= distance * sinf(angles.x);
	x += f_Z_Dist * sinf(angles.y);
	z += f_Z_Dist * cosf(angles.y);
}
void Vector3::ProjectOrtho(Vector3 angles,float distance){
	const float fRotCor = angles.y - PI*0.5f;
	const float f_Z_Dist = distance * cosf(angles.x);
	y -= distance * sinf(angles.x);
	x += f_Z_Dist * sinf(fRotCor);
	z += f_Z_Dist * cosf(fRotCor);
}
//Interpolation
Vector3 Vector3::Lerp(Vector3 vect1,Vector3 vect2,float t){
	return (vect2 - vect1)*t + vect1;
}
//multiple sets, sum and min max.
void Vector3::Zero(){
	x = y = 0.0f;
}
void Vector3::One(){
	x = y = 1.0f;
}
float Vector3::Sum()const{
	return (x+y);
}
float Vector3::Min()const{
	return Minf(x,y);
}
float Vector3::Max()const{
	return Maxf(x,y);
}
//Overloads
//Comparitors
bool    Vector3::operator   == (Vector3 vect)const {return   (x == vect.x && y == vect.y && z == vect.z) ;}
bool    Vector3::operator   != (Vector3 vect)const {return   (x != vect.x && y != vect.y && z != vect.z) ;}
void    Vector3::operator    = (float scalar)      {          x = scalar;    y = scalar;    z = scalar   ;}
//negate		   					      										 
Vector3 Vector3::operator   -  (            )      {return(Vector3(-x,-y,-z))                            ;}
//Addition		   		
Vector3 Vector3::operator   ++ (            )      {return Vector3(++x       ,++y       , ++z       )    ;}
Vector3 Vector3::operator   +  (Vector3 vect)const {return Vector3(x + vect.x,y + vect.y, z + vect.z)    ;}
Vector3 Vector3::operator   += (Vector3 vect)      {return ((*this) = (*this) + vect    ) ;}
Vector3 Vector3::operator   +  (float scalar)const {return Vector3(x + scalar,y + scalar, z + scalar)    ;}
Vector3 Vector3::operator   += (float scalar)      {return ((*this) = (*this) + scalar  ) ;}
//Subtraction	   					      													    
Vector3 Vector3::operator   -- (            )      {return Vector3(--x       ,--y       , --z       )    ;}
Vector3 Vector3::operator   -  (Vector3 vect)const {return Vector3(x - vect.x,y - vect.y, z - vect.z)    ;}
Vector3 Vector3::operator   -= (Vector3 vect)      {return ((*this) = (*this) - vect    ) ;}
Vector3 Vector3::operator   -  (float scalar)const {return Vector3(x - scalar,y - scalar, z - scalar)    ;}
Vector3 Vector3::operator   -= (float scalar)      {return ((*this) = (*this) - scalar  ) ;}
//Division		   					      													    
Vector3 Vector3::operator   /  (Vector3 vect)const {return Vector3(x / vect.x,y / vect.y, z / vect.z)    ;}
Vector3 Vector3::operator   /= (Vector3 vect)      {return ((*this) = (*this) / vect    ) ;}
Vector3 Vector3::operator   /  (float scalar)const {return Vector3(x / scalar,y / scalar, z / scalar)    ;}
Vector3 Vector3::operator   /= (float scalar)      {return ((*this) = (*this) / scalar  ) ;}
//Multiplication   					      													    
Vector3 Vector3::operator   *  (Vector3 vect)const {return Vector3(x * vect.x,y * vect.y, z * vect.z)    ;}
Vector3 Vector3::operator   *= (Vector3 vect)      {return ((*this) = (*this) * vect    ) ;}
Vector3 Vector3::operator   *  (float scalar)const {return Vector3(x * scalar,y * scalar, z * scalar)    ;}
Vector3 Vector3::operator   *= (float scalar)      {return ((*this) = (*this) * scalar  ) ;}