//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////																		Author : Luke Monaghan																	//////
//////																		Date   : 29/03/2013																		//////
//////																		Brief  : Vector Formulas																//////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _VECTORLIB
#define _VECTORLIB

#ifndef _MATHS_DLL_
#define MATHSDLL __declspec(dllexport)
#else
#define MATHSDLL __declspec(dllimport)
#endif

//constants
#define PI      3.14159265358979323846f
#define RAD2DEG 57.2957795130823208768f
#define DEG2RAD 0.01745329251994329577f
//convert between rad and degree
MATHSDLL float radToDegree(float rad);
MATHSDLL float degreeToRad(float degree);
//reciprocal
MATHSDLL float Recipf(float x);
//min max
MATHSDLL float Minf(float x, float y);
MATHSDLL float Maxf(float x, float y);
//power
MATHSDLL int PowerUp(int value);
MATHSDLL int PowerDown(int value);
MATHSDLL int PowerClosest(int value);

MATHSDLL float Lerp(float f_1, float f_2, float t);
#endif