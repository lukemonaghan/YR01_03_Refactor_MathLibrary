#include "Vector2.h"
#include <math.h>

//Constructor 2D
Vector2::Vector2(){
	x=0;
	y=0;
}
Vector2::Vector2(float a, float b){
	x = a;
	y = b;
}
//magnitude
float Vector2::Magnitude()const{
	return sqrt((x*x)+(y*y)); 
}
float Vector2::MagnitudeSquared()const{
	return (x*x)+(y*y); 
}
//Dot Product
float Vector2::Dot(Vector2 vect){
	return (x * vect.x + y * vect.y);
}
//unit
bool Vector2::IsUnit()const{
	return (Magnitude() <= 1.0f);
}
Vector2 Vector2::GetUnit()const{
	float fMag = Magnitude();
	const float fInvNorm = (fMag != 0.0f) ? Recipf( fMag ) : 1.00e+12f;
	return Vector2( x * fInvNorm, y * fInvNorm );
}
//Normalize
Vector2 Vector2::NormalizeReturn(){ 
	Vector2 vect;
	vect.x = x;
	vect.y = y;
	float len = vect.Magnitude();
	vect.x/=len;
	vect.y/=len;
	return vect;
}
void Vector2::Normalize(){ 
	float len = Magnitude();
	x/=len;
	y/=len;
}
//perpendicular
Vector2 Vector2::GetPerpendicular()const{
	return(Vector2(y, -x));
}
//Rotate
void Vector2::RotateRad(float angle){
	float xt = (x * cosf(angle)) - (y * sinf(angle));
	float yt = (x * sinf(angle)) + (y * cosf(angle));
	x = xt;
	y = yt;
}
void Vector2::RotateDegree(float angle){
	angle = degreeToRad(angle);
	RotateRad(angle);
}
//angle to vector
void Vector2::RadianToVect(float angle){
	x = cos((float)angle);
	y = sin((float)angle);
	Normalize();
}
void Vector2::degreeToVect(float angle){
	angle = degreeToRad(angle);
	x = cos((float)angle);
	y = sin((float)angle);
	Normalize();
}
//Projection
void Vector2::Project(float angle, float distance){
	x+= distance * cos(angle);
	y+= distance * sin(angle);
}
//Interpolation
Vector2 Vector2::Lerp(Vector2 vect1,Vector2 vect2,float t){
	return (vect2 - vect1)*t + vect1;
}
//multiple sets, sum and min max.
void Vector2::Zero(){
	x = y = 0.0f;
}
void Vector2::One(){
	x = y = 1.0f;
}
float Vector2::Sum()const{
	return (x+y);
}
float Vector2::Min()const{
	return Minf(x,y);
}
float Vector2::Max()const{
	return Maxf(x,y);
}
//Overloads
	//Comparitors
	bool    Vector2::operator   == (Vector2 vect)const {return   (x == vect.x && y == vect.y) ;}
	bool    Vector2::operator   != (Vector2 vect)const {return   (x != vect.x && y != vect.y) ;}
	void    Vector2::operator    = (float scalar)	   {               x = scalar;y = scalar  ;}
	//negate		   					      	 							 
	Vector2 Vector2::operator   -  (            )	   {return(Vector2(-x,-y));                }
	//Addition		   							  
	Vector2 Vector2::operator   ++ (            )	   {return Vector2(++x       ,++y       ) ;}
	Vector2 Vector2::operator   +  (Vector2 vect)const {return Vector2(x + vect.x,y + vect.y) ;}
	Vector2 Vector2::operator   += (Vector2 vect)	   {return ((*this) = (*this) + vect    ) ;}
	Vector2 Vector2::operator   +  (float scalar)const {return Vector2(x + scalar,y + scalar) ;}
	Vector2 Vector2::operator   += (float scalar)	   {return ((*this) = (*this) + scalar  ) ;}
	//Subtraction	   							  
	Vector2 Vector2::operator   -- (            )	   {return Vector2(--x       ,--y       ) ;}
	Vector2 Vector2::operator   -  (Vector2 vect)const {return Vector2(x - vect.x,y - vect.y) ;}
	Vector2 Vector2::operator   -= (Vector2 vect)	   {return ((*this) = (*this) - vect    ) ;}
	Vector2 Vector2::operator   -  (float scalar)const {return Vector2(x - scalar,y - scalar) ;}
	Vector2 Vector2::operator   -= (float scalar)	   {return ((*this) = (*this) - scalar  ) ;}
	//Division									  
	Vector2 Vector2::operator   /  (Vector2 vect)const {return Vector2(x / vect.x,y / vect.y) ;}
	Vector2 Vector2::operator   /= (Vector2 vect)	   {return ((*this) = (*this) / vect    ) ;}
	Vector2 Vector2::operator   /  (float scalar)const {return Vector2(x / scalar,y / scalar) ;}
	Vector2 Vector2::operator   /= (float scalar)	   {return ((*this) = (*this) / scalar  ) ;}
	//Multiplication   					      	 							 
	Vector2 Vector2::operator   *  (Vector2 vect)const {return Vector2(x * vect.x,y * vect.y) ;}
	Vector2 Vector2::operator   *= (Vector2 vect)	   {return ((*this) = (*this) * vect    ) ;}
	Vector2 Vector2::operator   *  (float scalar)const {return Vector2(x * scalar,y * scalar) ;}
	Vector2 Vector2::operator   *= (float scalar)	   {return ((*this) = (*this) * scalar  ) ;}