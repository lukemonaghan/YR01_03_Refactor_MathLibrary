//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////																		Author : Luke Monaghan																	//////
//////																		Date   : 21/4/2013																		//////
//////																		Brief  : Vector Lib Testing																//////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Maths.h"   // Maths header
#include "Vector2.h" //Vector header
#include "Vector3.h" //Vector header
#include "Vector4.h" //Vector header

#include "Matrix3.h" //Matrix header
#include "Matrix4.h" //Matrix header

#include <iostream>
using namespace std; //I know.. Im lazy.Plus this is small, speed isnt a big issue here.

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// program loop
bool bRun = true;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// buffers
char cBuffer[64];
float fBuffer;

int vect = 0;
int matx = 0;
int hexordec = 0;

float angle = 0.0f;
float fdistance = 0.0f;
float scalar = 0.0f;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Setup Vectors
Vector2 vect2_1(2,2);
Vector2 vect2_2(2,2);
Vector2 vect2_R(0,0);

Vector3 vect3_1(3,3,3);
Vector3 vect3_2(3,3,3);
Vector3 vect3_R(0,0,0);

Vector4 vect4_1(4,4,4,4);
Vector4 vect4_2("04040404");
Vector4 vect4_R("00000000");
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Setup Matrix's
Matrix3 Matx3_1(0,0,0,0,0,0,0,0,0);
Matrix3 Matx3_2(0,0,0,0,0,0,0,0,0);
Matrix3 Matx3_R(0,0,0,0,0,0,0,0,0);

Matrix4 Matx4_1(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
Matrix4 Matx4_2(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
Matrix4 Matx4_R(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Value Getters
float GetValue(){
	cin >> fBuffer;
	return fBuffer;
}
void GetValue(char* command,float &fReturn){
	cout << command; cin >> fReturn;
}
void GetValue(char* command,int &iReturn){
	cout << command; cin >> iReturn;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Axis functions
int CheckAxis(){
	cin >>cBuffer;
	if (cBuffer[0] != 'w' && cBuffer[0] != 'x' && cBuffer[0] != 'y' || cBuffer[0] != 'z'){
		cout << "no axis of : " << cBuffer[0] << endl;
		return 0;
	}
	return cBuffer[0];
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Message Functions
void ShowCurrent(){
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Vector2
	if (_strcmpi(cBuffer, "v2") == 0){
	cout << endl;
	cout << " -    Vect2_1 : " << vect2_1.x << " : " << vect2_1.y << endl;
	cout << " -    Vect2_2 : " << vect2_2.x << " : " << vect2_2.y << endl;
	cout << " -    Vect2_R : " << vect2_R.x << " : " << vect2_R.y << endl;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Vector 3
	}if (_strcmpi(cBuffer, "v3") == 0){
	cout << endl;		 
	cout << " -    Vect3_1 : " << vect3_1.x << " : " << vect3_1.y << " : " << vect3_1.z << endl;
	cout << " -    Vect3_2 : " << vect3_2.x << " : " << vect3_2.y << " : " << vect3_2.z << endl;
	cout << " -    Vect3_R : " << vect3_R.x << " : " << vect3_R.y << " : " << vect3_R.z << endl;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Vector 4
	}if (_strcmpi(cBuffer, "v4") == 0){
	cout << endl;		 		 
	cout << " -    Vect4_1 : " << vect4_1.w << " : " << vect4_1.x << " : " << vect4_1.y << " : " << vect4_1.z << endl;
	cout << " -    Vect4_2 : " << vect4_2.w << " : " << vect4_2.x << " : " << vect4_2.y << " : " << vect4_2.z << endl;
	cout << " -    Vect4_R : " << vect4_R.w << " : " << vect4_R.x << " : " << vect4_R.y << " : " << vect4_R.z << endl;	 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Matrix 3
	}if (_strcmpi(cBuffer, "M3") == 0){
	cout << endl;
	cout << " -    Matx3_1 : " << endl
		 << "                " << Matx3_1.m00 << " : " << Matx3_1.m01 << " : " << Matx3_1.m02 << endl
		 << "                " << Matx3_1.m10 << " : " << Matx3_1.m11 << " : " << Matx3_1.m12 << endl
		 <<	"                " << Matx3_1.m20 << " : " << Matx3_1.m21 << " : " << Matx3_1.m22 << endl;
	cout << " -    Matx3_2 : " << endl
		 << "                " << Matx3_2.m00 << " : " << Matx3_2.m01 << " : " << Matx3_2.m02 << endl
		 << "                " << Matx3_2.m10 << " : " << Matx3_2.m11 << " : " << Matx3_2.m12 << endl
		 <<	"                " <<	Matx3_2.m20 << " : " << Matx3_2.m21 << " : " << Matx3_2.m22 << endl;
	cout << " -    Matx3_R : " << endl
		 << "                " << Matx3_R.m00 << " : " << Matx3_R.m01 << " : " << Matx3_R.m02 << endl
		 << "                " << Matx3_R.m10 << " : " << Matx3_R.m11 << " : " << Matx3_R.m12 << endl
		 <<	"                " <<	Matx3_R.m20 << " : " << Matx3_R.m21 << " : " << Matx3_R.m22 << endl;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Matrix 4
	}if (_strcmpi(cBuffer, "M4") == 0){
	cout << endl;
	cout << " -    Matx4_1 : " << endl
		 << "                " << Matx4_1.m00 << " : " << Matx4_1.m01 << " : " << Matx4_1.m02 << " : " << Matx4_1.m03 << endl
		 << "                " << Matx4_1.m10 << " : " << Matx4_1.m11 << " : " << Matx4_1.m12 << " : " << Matx4_1.m13 << endl
		 <<	"                " << Matx4_1.m20 << " : " << Matx4_1.m21 << " : " << Matx4_1.m22 << " : " << Matx4_1.m23 << endl
		 <<	"                " << Matx4_1.m30 << " : " << Matx4_1.m31 << " : " << Matx4_1.m32 << " : " << Matx4_1.m33 << endl;
	cout << " -    Matx4_2 : " << endl
		 << "                " << Matx4_2.m00 << " : " << Matx4_2.m01 << " : " << Matx4_2.m02 << " : " << Matx4_2.m03 << endl
		 << "                " << Matx4_2.m10 << " : " << Matx4_2.m11 << " : " << Matx4_2.m12 << " : " << Matx4_2.m13 << endl
		 <<	"                " << Matx4_2.m20 << " : " << Matx4_2.m21 << " : " << Matx4_2.m22 << " : " << Matx4_2.m23 << endl
		 <<	"                " << Matx4_2.m30 << " : " << Matx4_2.m31 << " : " << Matx4_2.m32 << " : " << Matx4_2.m33 << endl;
	cout << " -    Matx4_R : " << endl
		 << "                " << Matx4_R.m00 << " : " << Matx4_R.m01 << " : " << Matx4_R.m02 << " : " << Matx4_R.m03 << endl
		 << "                " << Matx4_R.m10 << " : " << Matx4_R.m11 << " : " << Matx4_R.m12 << " : " << Matx4_R.m13 << endl
		 <<	"                " << Matx4_R.m20 << " : " << Matx4_R.m21 << " : " << Matx4_R.m22 << " : " << Matx4_R.m23 << endl
		 <<	"                " << Matx4_R.m30 << " : " << Matx4_R.m31 << " : " << Matx4_R.m32 << " : " << Matx4_R.m33 << endl;
	}
}
void Show(){
	cout << "                            : v2 v3 v4 m3 m4" << endl;
	cout << "What do you want to display : ";cin >> cBuffer;
	ShowCurrent();
}
void Help(){
	cout << "                            : v2 v3 v4 m3 m4" << endl;
	cout << "What do you want help with  : ";cin >> cBuffer;
	ShowCurrent();
	cout  << endl;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Vector2 Help
	if (_strcmpi(cBuffer, "v2") == 0){
	cout << "v2                   - set a vector with inputs" << endl
		 << "v2Rotate             - Rotate vector2 using degree" << endl
		 << endl
		 << "v2magnitude          - magnitude of vector2" << endl
		 << "v2magnitudesquared   - magnitudeSquared of vector" << endl
		 << endl
		 << "v2Dot                - Dot product of both vectors" << endl
		 << "v2IsUnit             - bool checking if it is a unit vector" << endl
		 << "v2GetUnit            - Get the unit vector" << endl
		 << endl
		 << "v2Normalize          - Normalize vector" << endl
		 << "v2Perpendicular      - set return vector to perpendicular" << endl
		 << "v2DegToVect          - Convert Degree to Vector" << endl
		 << "v2Project            - Create projection vector" << endl
		 << endl
		 << "v2Lerp               - set return vector to linear Interpolation" << endl
		 << endl
		 << "v2Zero               - set vector to 0.0f" << endl
		 << "v2One                - set vector to 1.0f" << endl
		 << "v2Sum                - Return the sum of both vectors" << endl
		 << "v2Min                - Return the smaller value in vector" << endl
		 << "v2Max                - Return the larger value in vector" << endl
		 << endl
		 << "v2Equ                - check if two vectors are equal" << endl
		 << "v2NotEqu             - check if two vectors are not equal" << endl
		 << "v2Set                - set one vector to the other" << endl
		 << "v2SetScalar          - set all units in vector to a value" << endl
		 << "v2Negate             - negate a vector" << endl 
		 << endl
		 << "v2++                 - add one to all values in a vector" << endl
		 << "v2Add                - add both vectors" << endl
		 << "v2AddEqu             - add one vector ot the other" << endl
		 << "v2AddScalar          - add scalar to vector, returns to return vector" << endl
		 << "v2AddScalarEqu       - add scalar to vector, returns to self" << endl 
		 << endl
		 << "v2--                 - Subtract one to all values in a vector" << endl 
		 << "v2Sub                - Subtract both vectors" << endl
		 << "v2SubEqu             - Subtract one vector ot the other" << endl
		 << "v2SubScalar          - Subtract scalar to vector, returns to return vector" << endl
		 << "v2SubScalarEqu       - Subtract scalar to vector, returns to self" << endl
		 << endl
		 << "v2Div                - Divide both vectors" << endl
		 << "v2DivEqu             - Divide one vector ot the other" << endl
		 << "v2DivScalar          - Divide scalar to vector, returns to return vector" << endl
		 << "v2DivScalarEqu       - Divide scalar to vector, returns to self" << endl
		 << endl
		 << "v2Mpl                - Multiply both vectors" << endl
		 << "v2MplEqu             - Multiply one vector ot the other" << endl
		 << "v2MplScalar          - Multiply scalar to vector, returns to return vector" << endl
		 << "v2MplScalarEqu       - Multiply scalar to vector, returns to self" << endl;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Vector3 Help
	if (_strcmpi(cBuffer, "v3") == 0){
	cout << "v3                   - set a vector with inputs" << endl
		 << "v3RotateX             - Rotate vector2 using degree on X axis" << endl
		 << "v3RotateY             - Rotate vector2 using degree on Y axis" << endl
		 << "v3RotateZ             - Rotate vector2 using degree on Z axis" << endl
		 << endl
		 << "v3magnitude          - magnitude of vector2" << endl
		 << "v3magnitudesquared   - magnitudeSquared of vector" << endl
		 << endl
		 << "v3Dot                - Dot product of both vectors" << endl
		 << "v3IsUnit             - bool checking if it is a unit vector" << endl
		 << "v3GetUnit            - Get the unit vector" << endl
		 << endl
		 << "v3Cross              - Cross Product " << endl
		 << "v3Cross2             - Cross Product return 2D" << endl
		 << endl
		 << "v3Normalize          - Normalize vector" << endl
		 << "v3Project            - Create projection vector" << endl
		 << "v3ProjectOrtho       - Create Ortho projection vector" << endl
		 << endl
		 << "v3Lerp               - set return vector to linear Interpolation" << endl
		 << endl
		 << "v3Zero               - set vector to 0.0f" << endl
		 << "v3One                - set vector to 1.0f" << endl
		 << "v3Sum                - Return the sum of both vectors" << endl
		 << "v3Min                - Return the smaller value in vector" << endl
		 << "v3Max                - Return the larger value in vector" << endl
		 << endl
		 << "v3Equ                - check if two vectors are equal" << endl
		 << "v3NotEqu             - check if two vectors are not equal" << endl
		 << "v3Set                - set one vector to the other" << endl
		 << "v3SetScalar          - set all units in vector to a value" << endl
		 << "v3Negate             - negate a vector" << endl 
		 << endl
		 << "v3++                 - add one to all values in a vector" << endl
		 << "v3Add                - add both vectors" << endl
		 << "v3AddEqu             - add one vector ot the other" << endl
		 << "v3AddScalar          - add scalar to vector, returns to return vector" << endl
		 << "v3AddScalarEqu       - add scalar to vector, returns to self" << endl 
		 << endl
		 << "v3--                 - Subtract one to all values in a vector" << endl 
		 << "v3Sub                - Subtract both vectors" << endl
		 << "v3SubEqu             - Subtract one vector ot the other" << endl
		 << "v3SubScalar          - Subtract scalar to vector, returns to return vector" << endl
		 << "v3SubScalarEqu       - Subtract scalar to vector, returns to self" << endl
		 << endl
		 << "v3Div                - Divide both vectors" << endl
		 << "v3DivEqu             - Divide one vector ot the other" << endl
		 << "v3DivScalar          - Divide scalar to vector, returns to return vector" << endl
		 << "v3DivScalarEqu       - Divide scalar to vector, returns to self" << endl
		 << endl
		 << "v3Mpl                - Multiply both vectors" << endl
		 << "v3MplEqu             - Multiply one vector ot the other" << endl
		 << "v3MplScalar          - Multiply scalar to vector, returns to return vector" << endl
		 << "v3MplScalarEqu       - Multiply scalar to vector, returns to self" << endl;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Vector4 Help
	if (_strcmpi(cBuffer, "v4") == 0){
	cout << "v4                   - set a vector with inputs" << endl
		 << endl
		 << "v4magnitude          - magnitude of vector" << endl
		 << "v4Normalize          - Normalize vector" << endl
		 << endl
		 << "v4Zero               - set vector to 0.0f" << endl
		 << "v4One                - set vector to 1.0f" << endl
		 << "v4Sum                - Return the sum of both vectors" << endl
		 << "v4Min                - Return the smaller value in vector" << endl
		 << "v4Max                - Return the larger value in vector" << endl
		 << endl
		 << "v4Equ                - check if two vectors are equal" << endl
		 << "v4NotEqu             - check if two vectors are not equal" << endl
		 << "v4Set                - set one vector to the other" << endl
		 << "v4SetScalar          - set all units in vector to a value" << endl
		 << "v4Negate             - negate a vector" << endl 
		 << endl
		 << "v4++                 - add one to all values in a vector" << endl
		 << "v4Add                - add both vectors" << endl
		 << "v4AddEqu             - add one vector ot the other" << endl
		 << "v4AddScalar          - add scalar to vector, returns to return vector" << endl
		 << "v4AddScalarEqu       - add scalar to vector, returns to self" << endl 
		 << endl
		 << "v4--                 - Subtract one to all values in a vector" << endl 
		 << "v4Sub                - Subtract both vectors" << endl
		 << "v4SubEqu             - Subtract one vector ot the other" << endl
		 << "v4SubScalar          - Subtract scalar to vector, returns to return vector" << endl
		 << "v4SubScalarEqu       - Subtract scalar to vector, returns to self" << endl
		 << endl
		 << "v4Div                - Divide both vectors" << endl
		 << "v4DivEqu             - Divide one vector ot the other" << endl
		 << "v4DivScalar          - Divide scalar to vector, returns to return vector" << endl
		 << "v4DivScalarEqu       - Divide scalar to vector, returns to self" << endl
		 << endl
		 << "v4Mpl                - Multiply both vectors" << endl
		 << "v4MplEqu             - Multiply one vector ot the other" << endl
		 << "v4MplScalar          - Multiply scalar to vector, returns to return vector" << endl
		 << "v4MplScalarEqu       - Multiply scalar to vector, returns to self" << endl;
	}
	if (_strcmpi(cBuffer, "m3") == 0){
	cout << "m3                   - set a matrix with inputs" << endl
		 << endl
		 << "m3Determinant        - Get Determinant of Matrix" << endl
		 << "m3Inverse            - Inverse Matrix" << endl
		 << "m3GetInverse         - Get Inverse of Matrix" << endl
		 << endl
		 << "m3RotateX            - Rotate Matrix on X" << endl
		 << "m3RotateY            - Rotate Matrix on Y" << endl
		 << "m3RotateZ            - Rotate Matrix on Z" << endl
		 << endl
		 << "m3RotateXYZ          - Rotate Matrix on XYZ" << endl
		 << "m3RotateYXZ          - Rotate Matrix on YXZ" << endl
		 << "m3RotateZXY          - Rotate Matrix on ZXY" << endl
		 << "m3RotateZYX          - Rotate Matrix on ZYX" << endl
		 << endl
		 << "m3Ortho              - Setup matrix in ortho" << endl
		 << "m3OrthoNormalize     - normalize and Ortho a matrix" << endl
		 << endl
		 << "m3Scale              - Scale a matrix with vector 3" << endl
		 << "m3ScaleScalar        - Scale a matrix with a scalar" << endl
		 << endl
		 << "m3Identity           - Setup matrix as an identity matrix" << endl
		 << "m3Zero               - Set matrix to zero" << endl
		 << endl
		 << "m3Equ                - check if two matrix's are equal" << endl
		 << "m3NotEqu             - check if two matrix's are not equal" << endl
		 << "m3Set                - set one vector to the other" << endl
		 << "m3SetScalar          - set all units in vector to a value" << endl
		 << "m3Negate             - negate a vector" << endl 
		 << endl
		 << "m3++                 - add one to all values in a matrix" << endl
		 << "m3Add                - add both matrix's" << endl
		 << "m3AddEqu             - add one matrix to the other" << endl
		 << endl
		 << "m3--                 - Subtract one to all values in a matrix" << endl 
		 << "m3Sub                - Subtract both matrix's" << endl
		 << "m3SubEqu             - Subtract one matrix to the other" << endl
		 << endl
		 << "m3Mplm3              - Multiply both matrix's" << endl
		 << "m3MplEqum3           - Multiply one matrix ot the other" << endl
		 << "m3MplV3              - Multiply matrix by vector return to matrix" << endl
		 << "m3MplEquV3           - Multiply one matrix by a vector return to self" << endl
		 << "m3MplScalarScalar    - Multiply scalar to matrix, returns to return matrix" << endl
		 << "m3MplScalarEquScalar - Multiply scalar to matrix, returns to self" << endl
		 << endl;
}
	if (_strcmpi(cBuffer, "m4") == 0){
    cout << "m4                   - set a matrix with inputs" << endl
		 << endl
		 << "m4RotateX            - Rotate Matrix on X" << endl
		 << "m4RotateY            - Rotate Matrix on Y" << endl
		 << "m4RotateZ            - Rotate Matrix on Z" << endl
		 << endl
		 << "m4RotateXYZ          - Rotate Matrix on XYZ" << endl
		 << "m4RotateYXZ          - Rotate Matrix on YXZ" << endl
		 << "m4RotateZXY          - Rotate Matrix on ZXY" << endl
		 << "m4RotateZYX          - Rotate Matrix on ZYX" << endl
		 << endl
		 << "m4Ortho              - Setup matrix in ortho" << endl
		 << "m4OrthoNormalize     - normalize and Ortho a matrix" << endl
		 << endl
		 << "m4Scale              - Scale a matrix with vector 3" << endl
		 << "m4ScaleScalar        - Scale a matrix with a scalar" << endl
		 << endl
		 << "m4Identity           - Setup matrix as an identity matrix" << endl
		 << "m4Zero               - Set matrix to zero" << endl
		 << endl
		 << "m4Equ                - check if two matrix's are equal" << endl
		 << "m4NotEqu             - check if two matrix's are not equal" << endl
		 << "m4Set                - set one vector to the other" << endl
		 << "m4SetScalar          - set all units in vector to a value" << endl
		 << "m4Negate             - negate a vector" << endl 
		 << endl
		 << "m4++                 - add one to all values in a matrix" << endl
		 << "m4Add                - add both matrix's" << endl
		 << "m4AddEqu             - add one matrix to the other" << endl
		 << endl
		 << "m4--                 - Subtract one to all values in a matrix" << endl 
		 << "m4Sub                - Subtract both matrix's" << endl
		 << "m4SubEqu             - Subtract one matrix to the other" << endl
		 << endl
		 << "m4Mplm3              - Multiply both matrix's" << endl
		 << "m4MplEqum3           - Multiply one matrix ot the other" << endl
		 << "m4MplV3              - Multiply matrix by vector return to matrix" << endl
		 << "m4MplEquV3           - Multiply one matrix by a vector return to self" << endl
		 << "m4MplScalarScalar    - Multiply scalar to matrix, returns to return matrix" << endl
		 << "m4MplScalarEquScalar - Multiply scalar to matrix, returns to self" << endl
		 << endl;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Default Help
	cout << endl
		 << "power2u              - Power of two scaled up" << endl
		 << "power2d              - Power of two scaled down" << endl
		 << "power2c              - Power of two closest" << endl
		 << "LerpScalar           - Linear Interpretation on scalar value" << endl
		 << endl
		 << "cls                  - Clear Screen" << endl
		 << "show                 - Show the vectors" << endl
		 << "help                 - Show this help screen" << endl
		 << "exit                 - Exit this program" << endl;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// END OF HELP
	}
void Header(){
	cout << "-------------------------------------------------------------------------------" << endl
		 << "------------------------------- Vector Matrix Tests ---------------------------" << endl
		 << "---------------------------------- Luke Monaghan ------------------------------" << endl
		 << "-------------------------------------------------------------------------------" << endl;
}
void warning(){
	cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl
		 << "!!!!!!!!!!!!!!!!!!!!!!!! DONT ENTER ANYTHING BUT NUMBERS !!!!!!!!!!!!!!!!!!!!!!" << endl
	     << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl 
		 << endl;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Vector Checks
bool CheckV2(){
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Reset
	if (_strcmpi(cBuffer, "v2") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){
			GetValue("vect2_1.x = ",vect2_1.x);
			GetValue("vect2_1.y = ",vect2_1.y);
		}
		if (vect == 2){
			GetValue("vect2_2.x = ",vect2_2.x );
			GetValue("vect2_2.y = ",vect2_2.y );
		}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Rotate
	if (_strcmpi(cBuffer, "v2Rotate") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		GetValue("angle in degrees = ",angle);
		if (vect == 1){vect2_1.RotateDegree(angle);}
		if (vect == 2){vect2_2.RotateDegree(angle);}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Magnitude
	if (_strcmpi(cBuffer, "v2magnitude") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){cout << "v2magnitude is " << vect2_1.Magnitude();}
		if (vect == 2){cout << "v2magnitude is " <<  vect2_2.Magnitude();}
	return true;
	}
	if (_strcmpi(cBuffer, "v2magnitudesquared") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){cout << "v2magnitudesquared is " <<  vect2_1.MagnitudeSquared();}
		if (vect == 2){cout << "v2magnitudesquared is " <<  vect2_2.MagnitudeSquared();}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Dot
	if (_strcmpi(cBuffer, "v2Dot") == 0){
		cout << "Dot Product is " << vect2_1.Dot(vect2_2) << endl << endl;
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Unit
	if (_strcmpi(cBuffer, "v2IsUnit") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){cout << "v2IsUnit " << vect2_1.IsUnit();}
		if (vect == 2){cout << "v2IsUnit " << vect2_2.IsUnit();}
	return true;
	}
	if (_strcmpi(cBuffer, "v2GetUnit") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){vect2_R =  vect2_1.GetUnit();}
		if (vect == 2){vect2_R = vect2_2.GetUnit();}
	return true;
	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Normalize
	if (_strcmpi(cBuffer, "v2Normalize") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){vect2_R = vect2_1.NormalizeReturn();}
		if (vect == 2){vect2_R = vect2_2.NormalizeReturn();}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Perpendicular
	if (_strcmpi(cBuffer, "v2Perpendicular") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){vect2_R = vect2_1.GetPerpendicular();}
		if (vect == 2){vect2_R = vect2_2.GetPerpendicular();}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Degreetovect
	if (_strcmpi(cBuffer, "v2DegToVect") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		GetValue("Angle In Degrees : ",angle);
		if (vect == 1){vect2_1.degreeToVect(angle);}
		if (vect == 2){vect2_2.degreeToVect(angle);}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Project
	if (_strcmpi(cBuffer, "v2Project") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		GetValue("Angle = ",angle);
		GetValue("Distance = ",fdistance);
		if (vect == 1){vect2_1.Project(angle,fdistance);}
		if (vect == 2){vect2_2.Project(angle,fdistance);}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Lerp
	if (_strcmpi(cBuffer, "v2Lerp") == 0){
		GetValue("Scalar = ",scalar);
		vect2_R = vect2_1.Lerp(vect2_1,vect2_2,scalar);
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Setters
	if (_strcmpi(cBuffer, "v2Zero") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){vect2_1.Zero();}
		if (vect == 2){vect2_2.Zero();}
		if (vect == 3){vect2_R.Zero();}
	return true;
	}
	if (_strcmpi(cBuffer, "v2One") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){vect2_1.One();}
		if (vect == 2){vect2_2.One();}
		if (vect == 3){vect2_R.One();}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Sum Min Max
	if (_strcmpi(cBuffer, "v2Sum") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){cout << "Sum is : " << vect2_1.Sum();}
		if (vect == 2){cout << "Sum is : " << vect2_2.Sum();}
	return true;
	}
	if (_strcmpi(cBuffer, "v2Min") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){cout << "Min is : " << vect2_1.Min();}
		if (vect == 2){cout << "Min is : " << vect2_2.Min();}
	return true;
	}
	if (_strcmpi(cBuffer, "v2Max") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){cout << "Max is : " << vect2_1.Max();}
		if (vect == 2){cout << "Max is : " << vect2_2.Max();}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// General Overloads
	if (_strcmpi(cBuffer, "v2Equ") == 0){
		cout << (vect2_1 == vect2_2) << endl;
	return true;
	}
	if (_strcmpi(cBuffer, "v2NotEqu") == 0){
		cout << (vect2_1 != vect2_2) << endl;
	return true;
	}
	if (_strcmpi(cBuffer, "v2Set") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){vect2_1 = vect2_2;}
		if (vect == 2){vect2_2 = vect2_1;}
	return true;
	}
	if (_strcmpi(cBuffer, "v2Negate") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){vect2_1 = -vect2_1;}
		if (vect == 2){vect2_2 = -vect2_2;}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Overload Addition
	if (_strcmpi(cBuffer, "v2++") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){vect2_1++;}
		if (vect == 2){vect2_2++;}
	return true;
	}
	if (_strcmpi(cBuffer, "v2Add") == 0){
		vect2_R = vect2_1 + vect2_2;
	return true;
	}
	if (_strcmpi(cBuffer, "v2AddEqu") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){vect2_1 += vect2_2;}
		if (vect == 2){vect2_2 += vect2_1;}
	return true;
	}
	if (_strcmpi(cBuffer, "v2AddScalar") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		GetValue("Scalar = ",scalar);
		if (vect == 1){vect2_R = vect2_1 + scalar;}
		if (vect == 2){vect2_R = vect2_2 + scalar;}
	return true;
	}
	if (_strcmpi(cBuffer, "v2AddScalarEqu") == 0){
		GetValue("Vector 1 or 2 : ",vect);		
		GetValue("Scalar = ",scalar);
		if (vect == 1){vect2_1 += scalar;}
		if (vect == 2){vect2_2 += scalar;}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Overload Subtraction
	if (_strcmpi(cBuffer, "v2--") == 0){
		GetValue("Vector 1 or 2 : ",vect);		
		if (vect == 1){vect2_1--;}
		if (vect == 2){vect2_2--;}
	return true;
	}
	if (_strcmpi(cBuffer, "v2Sub") == 0){
		vect2_R = vect2_1 - vect2_2;
	return true;
	}
	if (_strcmpi(cBuffer, "v2SubEqu") == 0){
		GetValue("Vector 1 or 2 : ",vect);	
		if (vect == 1){vect2_1 -= vect2_2;}
		if (vect == 2){vect2_2 -= vect2_1;}
	return true;
	}
	if (_strcmpi(cBuffer, "v2SubScalar") == 0){
		GetValue("Vector 1 or 2 : ",vect);	
		GetValue("Scalar = ",scalar);
		if (vect == 1){vect2_R = vect2_1 - scalar;}
		if (vect == 2){vect2_R = vect2_2 - scalar;}
	return true;
	}
	if (_strcmpi(cBuffer, "v2SubScalarEqu") == 0){
		GetValue("Vector 1 or 2 : ",vect);	
		GetValue("Scalar = ",scalar);
		if (vect == 1){vect2_1 -= scalar;}
		if (vect == 2){vect2_2 -= scalar;}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Overload Division
	if (_strcmpi(cBuffer, "v2Div") == 0){
		vect2_R = vect2_1 / vect2_2;
	return true;
	}
	if (_strcmpi(cBuffer, "v2DivEqu") == 0){
		GetValue("Vector 1 or 2 : ",vect);	
		if (vect == 1){vect2_1 /= vect2_2;}
		if (vect == 2){vect2_2 /= vect2_1;}
	return true;
	}
	if (_strcmpi(cBuffer, "v2DivScalar") == 0){
		GetValue("Vector 1 or 2 : ",vect);	
		GetValue("Scalar = ",scalar);
		if (vect == 1){vect2_R = vect2_1 / scalar;}
		if (vect == 2){vect2_R = vect2_2 / scalar;}
	return true;
	}
	if (_strcmpi(cBuffer, "v2DivScalarEqu") == 0){
		GetValue("Vector 1 or 2 : ",vect);	
		GetValue("Scalar = ",scalar);
		if (vect == 1){vect2_1 /= scalar;}
		if (vect == 2){vect2_2 /= scalar;}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Overload Multiplication
	if (_strcmpi(cBuffer, "v2Mpl") == 0){
		vect2_R = vect2_1 * vect2_2;
	return true;
	}
	if (_strcmpi(cBuffer, "v2MplEqu") == 0){
		GetValue("Vector 1 or 2 : ",vect);	
		if (vect == 1){vect2_1 *= vect2_2;}
		if (vect == 2){vect2_2 *= vect2_1;}
	return true;
	}
	if (_strcmpi(cBuffer, "v2MplScalar") == 0){
		GetValue("Vector 1 or 2 : ",vect);	
		GetValue("Scalar = ",scalar);
		if (vect == 1){vect2_R = vect2_1 * scalar;}
		if (vect == 2){vect2_R = vect2_2 * scalar;}
	return true;
	}
	if (_strcmpi(cBuffer, "v2MplScalarEqu") == 0){
		GetValue("Vector 1 or 2 : ",vect);	
		GetValue("Scalar = ",scalar);
		if (vect == 1){vect2_1 *= scalar;}
		if (vect == 2){vect2_2 *= scalar;}
	return true;
	}
return false;
}
bool CheckV3(){
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Reset
	if (_strcmpi(cBuffer, "v3") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){
			GetValue("vect3_1.x = ",vect3_1.x);
			GetValue("vect3_1.y = ",vect3_1.y);
			GetValue("vect3_1.z = ",vect3_1.z);
		}
		if (vect == 2){
			GetValue("vect3_2.x = ",vect3_2.x);
			GetValue("vect3_2.y = ",vect3_2.y);
			GetValue("vect3_2.z = ",vect3_2.z);
		}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Rotations
	if (_strcmpi(cBuffer, "v3RotateX") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		GetValue("Angle = ",angle);
		if (vect == 1){vect3_1.RotateXDeg(angle);}
		if (vect == 2){vect3_2.RotateXDeg(angle);}
	return true;
	}
	if (_strcmpi(cBuffer, "v3RotateY") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		GetValue("Angle = ",angle);
		if (vect == 1){vect3_1.RotateYDeg(angle);}
		if (vect == 2){vect3_2.RotateYDeg(angle);}
	return true;
	}
	if (_strcmpi(cBuffer, "v3RotateZ") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		GetValue("Angle = ",angle);
		if (vect == 1){vect3_1.RotateZDeg(angle);}
		if (vect == 2){vect3_2.RotateZDeg(angle);}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Magnitude
if (_strcmpi(cBuffer, "v3magnitude") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){cout << "v3magnitude is " << vect3_1.Magnitude();}
		if (vect == 2){cout << "v3magnitude is " << vect3_2.Magnitude();}
	return true;
	}
	if (_strcmpi(cBuffer, "v3magnitudesquared") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){cout << "v3magnitudesquared is " <<  vect3_1.MagnitudeSquared();}
		if (vect == 2){cout << "v3magnitudesquared is " <<  vect3_2.MagnitudeSquared();}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Dot
	if (_strcmpi(cBuffer, "v3Dot") == 0){
		cout << "Dot Product is " << vect3_1.Dot(vect3_2) << endl  << endl;
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Unit
	if (_strcmpi(cBuffer, "v3IsUnit") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){cout << "v2IsUnit " << vect3_1.IsUnit();}
		if (vect == 2){cout << "v2IsUnit " << vect3_2.IsUnit();}
	return true;
	}
	if (_strcmpi(cBuffer, "v3GetUnit") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){vect3_R = vect3_1.GetUnit();}
		if (vect == 2){vect3_R = vect3_2.GetUnit();}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Normalize
	if (_strcmpi(cBuffer, "v3Normalize") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){vect3_R = vect3_1.NormalizeReturn();}
		if (vect == 2){vect3_R = vect3_2.NormalizeReturn();}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Cross
	if (_strcmpi(cBuffer, "v3Cross") == 0){
		vect3_R = vect3_1.Cross(vect3_2);
	return true;
	}
	if (_strcmpi(cBuffer, "v3Cross2") == 0){
		vect3_R = vect3_1.Cross2(vect3_1,vect3_2);
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Project
	if (_strcmpi(cBuffer, "v3Project") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		GetValue("Distance = ",fdistance);
		if (vect == 1){vect3_1.Project(vect3_1,fdistance);}
		if (vect == 2){vect3_2.Project(vect3_2,fdistance);}
	return true;
	}
	if (_strcmpi(cBuffer, "v3ProjectOrtho") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		GetValue("Distance = ",fdistance);
		if (vect == 1){vect3_1.ProjectOrtho(vect3_1,fdistance);}
		if (vect == 2){vect3_2.ProjectOrtho(vect3_2,fdistance);}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Linear Interpolation
	if (_strcmpi(cBuffer, "v3Lerp") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		GetValue("Distance = ",fdistance);
		if (vect == 1){vect3_R = vect3_1.Lerp(vect3_1,vect3_2,fdistance);}
		if (vect == 2){vect3_R = vect3_2.Lerp(vect3_2,vect3_2,fdistance);}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Setters
	if (_strcmpi(cBuffer, "v3Zero") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){vect3_1.Zero();}
		if (vect == 2){vect3_2.Zero();}
		if (vect == 3){vect3_R.Zero();}
	return true;
	}
	if (_strcmpi(cBuffer, "v3One") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){vect3_1.One();}
		if (vect == 2){vect3_2.One();}
		if (vect == 3){vect3_R.One();}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Sum Min Max
	if (_strcmpi(cBuffer, "v3Sum") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){cout << "Sum is : " << vect3_1.Sum();}
		if (vect == 2){cout << "Sum is : " << vect3_2.Sum();}
	return true;
	}
	if (_strcmpi(cBuffer, "v3Min") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){cout << "Min is : " << vect3_1.Min();}
		if (vect == 2){cout << "Min is : " << vect3_2.Min();}
	return true;
	}
	if (_strcmpi(cBuffer, "v3Max") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){cout << "Max is : " << vect3_1.Max();}
		if (vect == 2){cout << "Max is : " << vect3_2.Max();}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// General Overloads
	if (_strcmpi(cBuffer, "v3Equ") == 0){
		cout << (vect3_1 == vect3_2) << endl;
	return true;
	}
	if (_strcmpi(cBuffer, "v3NotEqu") == 0){
		cout << (vect3_1 != vect3_2) << endl;
	return true;
	}
	if (_strcmpi(cBuffer, "v3Set") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){vect3_1 = vect3_2;}
		if (vect == 2){vect3_2 = vect3_1;}
	return true;
	}
	if (_strcmpi(cBuffer, "v3SetScalar") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		GetValue("Scalar = ",scalar);
		if (vect == 1){vect3_1 = scalar;}
		if (vect == 2){vect3_2 = scalar;}
	return true;
	}
	if (_strcmpi(cBuffer, "v3Negate") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){vect3_1 = -vect3_1;}
		if (vect == 2){vect3_2 = -vect3_2;}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Overload Addition
	if (_strcmpi(cBuffer, "v3++") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){vect3_1++;}
		if (vect == 2){vect3_2++;}
	return true;
	}
	if (_strcmpi(cBuffer, "v3Add") == 0){
		vect3_R = vect3_1 + vect3_2;
	return true;
	}
	if (_strcmpi(cBuffer, "v3AddEqu") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){vect3_1 += vect3_2;}
		if (vect == 2){vect3_2 += vect3_1;}
	return true;
	}
	if (_strcmpi(cBuffer, "v3AddScalar") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		GetValue("Scalar = ",scalar);
		if (vect == 1){vect3_R = vect3_1 + scalar;}
		if (vect == 2){vect3_R = vect3_2 + scalar;}
	return true;
	}
	if (_strcmpi(cBuffer, "v3AddScalarEqu") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		GetValue("Scalar = ",scalar);
		if (vect == 1){vect3_1 += scalar;}
		if (vect == 2){vect3_2 += scalar;}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Overload Subtraction
	if (_strcmpi(cBuffer, "v3--") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){vect3_1--;}
		if (vect == 2){vect3_2--;}
	return true;
	}
	if (_strcmpi(cBuffer, "v3Sub") == 0){
		vect3_R = vect3_1 - vect3_2;
	return true;
	}
	if (_strcmpi(cBuffer, "v3SubEqu") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){vect3_1 -= vect3_2;}
		if (vect == 2){vect3_2 -= vect3_1;}
	return true;
	}
	if (_strcmpi(cBuffer, "v3SubScalar") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		GetValue("Scalar = ",scalar);
		if (vect == 1){vect3_R = vect3_1 - scalar;}
		if (vect == 2){vect3_R = vect3_2 - scalar;}
	return true;
	}
	if (_strcmpi(cBuffer, "v3SubScalarEqu") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		GetValue("Scalar = ",scalar);
		if (vect == 1){vect3_1 -= scalar;}
		if (vect == 2){vect3_2 -= scalar;}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Overload Division
	if (_strcmpi(cBuffer, "v3Div") == 0){
		vect3_R = vect3_1 / vect3_2;
	return true;
	}
	if (_strcmpi(cBuffer, "v3DivEqu") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){vect3_1 /= vect3_2;}
		if (vect == 2){vect3_2 /= vect3_1;}
	return true;
	}
	if (_strcmpi(cBuffer, "v3DivScalar") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		GetValue("Scalar = ",scalar);
		if (vect == 1){vect3_R = vect3_1 / scalar;}
		if (vect == 2){vect3_R = vect3_2 / scalar;}
	return true;
	}
	if (_strcmpi(cBuffer, "v3DivScalarEqu") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		GetValue("Scalar = ",scalar);
		if (vect == 1){vect3_1 /= scalar;}
		if (vect == 2){vect3_2 /= scalar;}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Overload Multiplication
	if (_strcmpi(cBuffer, "v3Mpl") == 0){
		vect3_R = vect3_1 * vect3_2;
	return true;
	}
	if (_strcmpi(cBuffer, "v3MplEqu") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){vect3_1 *= vect3_2;}
		if (vect == 2){vect3_2 *= vect3_1;}
	return true;
	}
	if (_strcmpi(cBuffer, "v3MplScalar") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		GetValue("Scalar = ",scalar);
		if (vect == 1){vect3_R = vect3_1 * scalar;}
		if (vect == 2){vect3_R = vect3_2 * scalar;}
	return true;
	}
	if (_strcmpi(cBuffer, "v3MplScalarEqu") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		GetValue("Scalar = ",scalar);
		if (vect == 1){vect3_1 *= scalar;}
		if (vect == 2){vect3_2 *= scalar;}
	return true;
	}
return false;
}
bool CheckV4(){
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Reset (With HEX)
	if (_strcmpi(cBuffer, "v4") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		GetValue("Hex = 0, Decimal  = 1 : ",hexordec);
		if (vect == 1){
			if (hexordec==0){
				cout << "Vector4_1.Hex - Enter an eight char HEX code ";cin >> cBuffer;
				vect4_1.Hex(cBuffer);
			}else{
				GetValue("vect4_1.w = ",vect4_1.w);
				GetValue("vect4_1.x = ",vect4_1.x);
				GetValue("vect4_1.y = ",vect4_1.y);
				GetValue("vect4_1.z = ",vect4_1.z);
			}
		}
		if (vect == 2){
			if (hexordec==0){
				cout << "Vector4_1.Hex - Enter an eight char HEX code ";cin >> cBuffer;
				vect4_2.Hex(cBuffer);
			}else{
				GetValue("vect4_2.w = ",vect4_2.w);
				GetValue("vect4_2.x = ",vect4_2.x);
				GetValue("vect4_2.y = ",vect4_2.y);
				GetValue("vect4_2.z = ",vect4_2.z);
			}
		}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Magnitude
	if (_strcmpi(cBuffer, "v4magnitude") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){cout << "v4magnitude is " << vect4_1.Magnitude();}
		if (vect == 2){cout << "v4magnitude is " <<  vect4_2.Magnitude();}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Normalize
	if (_strcmpi(cBuffer, "v4normalize") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){vect4_R = vect4_1.NormalizeReturn();}
		if (vect == 2){vect4_R = vect4_2.NormalizeReturn();}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Setters
	if (_strcmpi(cBuffer, "v4Zero") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){vect4_1.Zero();}
		if (vect == 2){vect4_2.Zero();}
		if (vect == 3){vect4_R.Zero();}
	return true;
	}
	if (_strcmpi(cBuffer, "v4One") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){vect4_1.One();}
		if (vect == 2){vect4_2.One();}
		if (vect == 3){vect4_R.One();}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Sum Min Max
	if (_strcmpi(cBuffer, "v4Sum") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){cout << "Sum is : " << vect4_1.Sum();}
		if (vect == 2){cout << "Sum is : " << vect4_2.Sum();}
	return true;
	}
	if (_strcmpi(cBuffer, "v4Min") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){cout << "Min is : " << vect4_1.Min();}
		if (vect == 2){cout << "Min is : " << vect4_2.Min();}
	return true;
	}
	if (_strcmpi(cBuffer, "v4Max") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){cout << "Max is : " << vect4_1.Max();}
		if (vect == 2){cout << "Max is : " << vect4_2.Max();}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// General Overloads
	if (_strcmpi(cBuffer, "v4Equ") == 0){
		cout << (vect4_1 == vect4_2) << endl;
	return true;
	}
	if (_strcmpi(cBuffer, "v4NotEqu") == 0){
		cout << (vect4_1 != vect4_2) << endl;
	return true;
	}
	if (_strcmpi(cBuffer, "v4Set") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){vect4_1 = vect4_2;}
		if (vect == 2){vect4_2 = vect4_1;}
	return true;
	}
	if (_strcmpi(cBuffer, "v4SetScalar") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		GetValue("Scalar = ",scalar);
		if (vect == 1){vect4_1 = scalar;}
		if (vect == 2){vect4_2 = scalar;}
	return true;
	}
	if (_strcmpi(cBuffer, "v4Negate") == 0){		
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){vect4_1 = -vect4_1;}
		if (vect == 2){vect4_2 = -vect4_2;}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Overload Addition
	if (_strcmpi(cBuffer, "v4++") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){vect4_1++;}
		if (vect == 2){vect4_2++;}
	return true;
	}
	if (_strcmpi(cBuffer, "v4Add") == 0){
		vect4_R = vect4_1 + vect4_2;
	return true;
	}
	if (_strcmpi(cBuffer, "v4AddEqu") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){vect4_1 += vect4_2;}
		if (vect == 2){vect4_2 += vect4_1;}
	return true;
	}
	if (_strcmpi(cBuffer, "v4AddScalar") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		GetValue("Scalar = ",scalar);
		if (vect == 1){vect4_R = vect4_1 + scalar;}
		if (vect == 2){vect4_R = vect4_2 + scalar;}
	return true;
	}
	if (_strcmpi(cBuffer, "v4AddScalarEqu") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		GetValue("Scalar = ",scalar);
		if (vect == 1){vect4_1 += scalar;}
		if (vect == 2){vect4_2 += scalar;}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Overload Subtraction
	if (_strcmpi(cBuffer, "v4--") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){vect4_1--;}
		if (vect == 2){vect4_2--;}
	return true;
	}
	if (_strcmpi(cBuffer, "v4Sub") == 0){
		vect4_R = vect4_1 - vect4_2;
	return true;
	}
	if (_strcmpi(cBuffer, "v4SubEqu") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){vect4_1 -= vect4_2;}
		if (vect == 2){vect4_2 -= vect4_1;}
	return true;
	}
	if (_strcmpi(cBuffer, "v4SubScalar") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		GetValue("Scalar = ",scalar);
		if (vect == 1){vect4_R = vect4_1 - scalar;}
		if (vect == 2){vect4_R = vect4_2 - scalar;}
	return true;
	}
	if (_strcmpi(cBuffer, "v4SubScalarEqu") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		GetValue("Scalar = ",scalar);
		if (vect == 1){vect4_1 -= scalar;}
		if (vect == 2){vect4_2 -= scalar;}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Overload Division
	if (_strcmpi(cBuffer, "v4Div") == 0){
		vect4_R = vect4_1 / vect4_2;
	return true;
	}
	if (_strcmpi(cBuffer, "v2DivEqu") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){vect4_1 /= vect4_2;}
		if (vect == 2){vect4_2 /= vect4_1;}
	return true;
	}
	if (_strcmpi(cBuffer, "v4DivScalar") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		GetValue("Scalar = ",scalar);
		if (vect == 1){vect4_R = vect4_1 / scalar;}
		if (vect == 2){vect4_R = vect4_2 / scalar;}
	return true;
	}
	if (_strcmpi(cBuffer, "v4DivScalarEqu") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		GetValue("Scalar = ",scalar);
		if (vect == 1){vect4_1 /= scalar;}
		if (vect == 2){vect4_2 /= scalar;}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Overload Multiplication
	if (_strcmpi(cBuffer, "v4Mpl") == 0){
		vect4_R = vect4_1 * vect4_2;
	return true;
	}
	if (_strcmpi(cBuffer, "v4MplEqu") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		if (vect == 1){vect4_1 *= vect4_2;}
		if (vect == 2){vect4_2 *= vect4_1;}
	return true;
	}
	if (_strcmpi(cBuffer, "v4MplScalar") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		GetValue("Scalar = ",scalar);
		if (vect == 1){vect4_R = vect4_1 * scalar;}
		if (vect == 2){vect4_R = vect4_2 * scalar;}
	return true;
	}
	if (_strcmpi(cBuffer, "v4MplScalarEqu") == 0){
		GetValue("Vector 1 or 2 : ",vect);
		GetValue("Scalar = ",scalar);
		if (vect == 1){vect4_1 *= scalar;}
		if (vect == 2){vect4_2 *= scalar;}
	return true;
	}
return false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Matrix Checks
bool CheckM3(){
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Reset
	if (_strcmpi(cBuffer, "m3") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		if (matx == 1){
			GetValue("Matx3_1.m00 = ",Matx3_1.m00);	GetValue("Matx3_1.m01 = ",Matx3_1.m01);	GetValue("Matx3_1.m02 = ",Matx3_1.m02);	   
			GetValue("Matx3_1.m10 = ",Matx3_1.m10); GetValue("Matx3_1.m11 = ",Matx3_1.m11);	GetValue("Matx3_1.m12 = ",Matx3_1.m12);	
			GetValue("Matx3_1.m20 = ",Matx3_1.m20);	GetValue("Matx3_1.m21 = ",Matx3_1.m21);	GetValue("Matx3_1.m22 = ",Matx3_1.m22);
		}
		if (matx == 2){
			GetValue("Matx3_2.m00 = ",Matx3_2.m00);	GetValue("Matx3_2.m01 = ",Matx3_2.m01);	GetValue("Matx3_2.m02 = ",Matx3_2.m02);	   
			GetValue("Matx3_2.m10 = ",Matx3_2.m10); GetValue("Matx3_2.m11 = ",Matx3_2.m11);	GetValue("Matx3_2.m12 = ",Matx3_2.m12);	
			GetValue("Matx3_2.m20 = ",Matx3_2.m20);	GetValue("Matx3_2.m21 = ",Matx3_2.m21);	GetValue("Matx3_2.m22 = ",Matx3_2.m22);
		}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Determinate
	if (_strcmpi(cBuffer, "m3Determinant") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		if (matx == 1){cout << "Determinant is " << Matx3_1.Determinant();}
		if (matx == 2){cout << "Determinant is " << Matx3_2.Determinant();}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Inverse
	if (_strcmpi(cBuffer, "m3Inverse") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		if (matx == 1){cout << Matx3_1.Inverse();}
		if (matx == 2){cout << Matx3_2.Inverse();}
	return true;
	}
	if (_strcmpi(cBuffer, "m3InverseGet") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		if (matx == 1){cout << Matx3_1.InverseGet(Matx3_R);}
		if (matx == 2){cout << Matx3_2.InverseGet(Matx3_R);}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Rotate 1 axis
	if (_strcmpi(cBuffer, "m3RotateX") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Angle =  ",angle);
		if (matx == 1){Matx3_1.RotateX(angle);}
		if (matx == 2){Matx3_2.RotateX(angle);}
	return true;
	}
	if (_strcmpi(cBuffer, "m3RotateY") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Angle =  ",angle);
		if (matx == 1){Matx3_1.RotateY(angle);}
		if (matx == 2){Matx3_2.RotateY(angle);}
	return true;
	}
	if (_strcmpi(cBuffer, "m3RotateZ") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Angle =  ",angle);
		if (matx == 1){Matx3_1.RotateZ(angle);}
		if (matx == 2){Matx3_2.RotateZ(angle);}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Rotate 3axis
	if (_strcmpi(cBuffer, "m3RotateXYZ") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Vector 1 or 2 : ",vect);
		if (matx == 1){
			switch (vect){
			case 1:
				Matx3_1.RotateXYZ(vect3_1);
				break;
			case 2:
				Matx3_1.RotateXYZ(vect3_2);
				break;
			}
		}
		if (matx == 2){
			switch (vect){
			case 1:
				Matx3_2.RotateXYZ(vect3_1);
				break;
			case 2:
				Matx3_2.RotateXYZ(vect3_2);
				break;
			}
		}
	return true;
	}
	if (_strcmpi(cBuffer, "m3RotateYXZ") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Vector 1 or 2 : ",vect);
		if (matx == 1){
			switch (vect){
			case 1:
				Matx3_1.RotateYXZ(vect3_1);
				break;
			case 2:
				Matx3_1.RotateYXZ(vect3_2);
				break;
			}
		}
		if (matx == 2){
			switch (vect){
			case 1:
				Matx3_2.RotateYXZ(vect3_1);
				break;
			case 2:
				Matx3_2.RotateYXZ(vect3_2);
				break;
			}
		}
	return true;
	}
	if (_strcmpi(cBuffer, "m3RotateZXY") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Vector 1 or 2 : ",vect);
		if (matx == 1){
			switch (vect){
			case 1:
				Matx3_1.RotateZXY(vect3_1);
				break;
			case 2:
				Matx3_1.RotateZXY(vect3_2);
				break;
			}
		}
		if (matx == 2){
			switch (vect){
			case 1:
				Matx3_2.RotateZXY(vect3_1);
				break;
			case 2:
				Matx3_2.RotateZXY(vect3_2);
				break;
			}
		}
	return true;
	}
	if (_strcmpi(cBuffer, "m3RotateZYX") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Vector 1 or 2 : ",vect);
		if (matx == 1){
			switch (vect){
			case 1:
				Matx3_1.RotateZYX(vect3_1);
				break;
			case 2:
				Matx3_1.RotateZYX(vect3_2);
				break;
			}
		}
		if (matx == 2){
			switch (vect){
			case 1:
				Matx3_2.RotateZYX(vect3_1);
				break;
			case 2:
				Matx3_2.RotateZYX(vect3_2);
				break;
			}
		}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Translate
	if (_strcmpi(cBuffer, "m3TranslateX") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Scalar ",scalar);
		if (matx == 1){
			Matx3_1.TranslateX(scalar);
		}
		if (matx == 2){
			Matx3_2.TranslateX(scalar);
		}
	return true;
	}
	if (_strcmpi(cBuffer, "m3TranslateY") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Scalar ",scalar);
		if (matx == 1){
			Matx3_1.TranslateY(scalar);
		}
		if (matx == 2){
			Matx3_2.TranslateY(scalar);
		}
	return true;
	}
	if (_strcmpi(cBuffer, "m3TranslateV2") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Vector 1 or 2 : ",vect);
		if (matx == 1){
			switch (vect){
			case 1:
				Matx3_1.TranslateXY(vect2_1);
				break;
			case 2:
				Matx3_1.TranslateXY(vect2_2);
				break;
			}
		}
		if (matx == 2){
			switch (vect){
			case 1:
				Matx3_2.TranslateXY(vect2_1);
				break;
			case 2:
				Matx3_2.TranslateXY(vect2_2);
				break;
			}
		}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Ortho
	if (_strcmpi(cBuffer, "m3Ortho") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		if (matx == 1){Matx3_1.Ortho();}
		if (matx == 2){Matx3_2.Ortho();}
	return true;
	}
	if (_strcmpi(cBuffer, "m3OrthoNormalize") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		if (matx == 1){Matx3_1.OrthoNormalize();}
		if (matx == 2){Matx3_2.OrthoNormalize();}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Scale
	if (_strcmpi(cBuffer, "m3Scale") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Vector 1 or 2 : ",vect);
		if (matx == 1){
			switch (vect){
			case 1:
				Matx3_1.Scale(vect3_1);
				break;
			case 2:
				Matx3_1.Scale(vect3_2);
				break;
			}
		}
		if (matx == 2){
			switch (vect){
			case 1:
				Matx3_2.Scale(vect3_1);
				break;
			case 2:
				Matx3_2.Scale(vect3_2);
				break;
			}
		}
	return true;
	}
	if (_strcmpi(cBuffer, "m3ScaleScalar") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Vector 1 or 2 : ",vect);
		if (matx == 1){Matx3_1.Scale(scalar);}
		if (matx == 2){Matx3_2.Scale(scalar);}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Setters
	if (_strcmpi(cBuffer, "m3Identity") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		if (matx == 1){Matx3_1.Identity();}
		if (matx == 2){Matx3_2.Identity();}
	return true;
	}
	if (_strcmpi(cBuffer, "m3Zero") == 0){
		GetValue("Matrix 1 or 2 : ",matx);	
		if (matx == 1){Matx3_1.Zero();}
		if (matx == 2){Matx3_2.Zero();}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// General Overloads
	if (_strcmpi(cBuffer, "m3Equ") == 0){
		cout << (Matx3_1 == Matx3_2) << endl;
	return true;
	}
	if (_strcmpi(cBuffer, "m3NotEqu") == 0){
		cout << (Matx3_1 != Matx3_2) << endl;
	return true;
	}
	if (_strcmpi(cBuffer, "m3Set") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		if (matx == 1){Matx3_1 = Matx3_1;}
		if (matx == 2){Matx3_2 = Matx3_2;}
	return true;
	}
	if (_strcmpi(cBuffer, "m3SetScalar") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Scalar =  ",scalar);
		if (matx == 1){Matx3_1 = scalar;}
		if (matx == 2){Matx3_2 = scalar;}
	return true;
	}
	if (_strcmpi(cBuffer, "m3Negate") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		if (matx == 1){Matx3_1 = -Matx3_1;}
		if (matx == 2){Matx3_2 = -Matx3_2;}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Addition
	if (_strcmpi(cBuffer, "m3++") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		if (matx == 1){Matx3_1++;}
		if (matx == 2){Matx3_2++;}
	return true;
	}
	if (_strcmpi(cBuffer, "m3Add") == 0){
		Matx3_R = Matx3_1 + Matx3_2;
	return true;
	}
	if (_strcmpi(cBuffer, "m3AddEqu") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		if (matx == 1){Matx3_1 += Matx3_2;}
		if (matx == 2){Matx3_1 += Matx3_2;}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// SUbtraction
	if (_strcmpi(cBuffer, "m3--") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		if (matx == 1){Matx3_1--;}
		if (matx == 2){Matx3_2--;}
	return true;
	}
	if (_strcmpi(cBuffer, "m3Sub") == 0){
		Matx3_R = Matx3_1 - Matx3_2;
	return true;
	}
	if (_strcmpi(cBuffer, "m3SubEqu") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		if (matx == 1){Matx3_1 -= Matx3_2;}
		if (matx == 2){Matx3_1 -= Matx3_2;}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Multiplication
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Matrix By Matrix
	if (_strcmpi(cBuffer, "M3MplM3") == 0){
		Matx3_R = Matx3_1 * Matx3_2;
	return true;
	}
	if (_strcmpi(cBuffer, "M3MplEquM3") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		if (matx == 1){Matx3_1 *= Matx3_2;}
		if (matx == 2){Matx3_1 *= Matx3_2;}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Matrix By Vector
	if (_strcmpi(cBuffer, "M3MplV3") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Matrix 1 or 2 : ",vect);
		if (matx == 1){
			switch (vect){
			case 1:
				vect3_R = Matx3_1 * vect3_1;
				break;
			case 2:
				vect3_R = Matx3_1 * vect3_2;
				break;
			}
		}
		if (matx == 2){
			switch (vect){
			case 1:
				vect3_R = Matx3_2 * vect3_1;
				break;
			case 2:
				vect3_R = Matx3_2 * vect3_2;
				break;
			}
		}
	return true;
	}
	if (_strcmpi(cBuffer, "M3MplEquV3") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Matrix 1 or 2 : ",vect);
		if (matx == 1){
			switch (vect){
			case 1:
				Matx3_1 *= vect3_1;
				break;
			case 2:
				Matx3_1 *= vect3_2;
				break;
			}
		}
		if (matx == 2){
			switch (vect){
			case 1:
				Matx3_2 *= vect3_1;
				break;
			case 2:
				Matx3_2 *= vect3_2;
				break;
			}
		}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Matrix By 
	if (_strcmpi(cBuffer, "M3MplScalar") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Scalar = ",scalar);
		if (matx == 1){Matx3_R = Matx3_1 * scalar;}
		if (matx == 2){Matx3_R = Matx3_1 * scalar;}
	return true;
	}
	if (_strcmpi(cBuffer, "M3MplEquScalar") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Scalar = ",scalar);
		if (matx == 1){Matx3_1 *= scalar;}
		if (matx == 2){Matx3_1 *= scalar;}
	return true;
	}
return false;
}
bool CheckM4(){
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Reset
	if (_strcmpi(cBuffer, "m4") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		if (matx == 1){
			GetValue("Matx4_1.m00 = ",Matx4_1.m00);	GetValue("Matx4_1.m01 = ",Matx4_1.m01);	GetValue("Matx4_1.m02 = ",Matx4_1.m02); GetValue("Matx4_1.m03 = ",Matx4_1.m02);
			GetValue("Matx4_1.m10 = ",Matx4_1.m10); GetValue("Matx4_1.m11 = ",Matx4_1.m11);	GetValue("Matx4_1.m12 = ",Matx4_1.m12);	GetValue("Matx4_1.m13 = ",Matx4_1.m12);
			GetValue("Matx4_1.m20 = ",Matx4_1.m20);	GetValue("Matx4_1.m21 = ",Matx4_1.m21);	GetValue("Matx4_1.m22 = ",Matx4_1.m22);	GetValue("Matx4_1.m23 = ",Matx4_1.m22);
			GetValue("Matx4_1.m30 = ",Matx4_1.m30);	GetValue("Matx4_1.m31 = ",Matx4_1.m31);	GetValue("Matx4_1.m32 = ",Matx4_1.m32);	GetValue("Matx4_1.m33 = ",Matx4_1.m32);
		}
		if (matx == 2){
			GetValue("Matx4_2.m00 = ",Matx4_2.m00);	GetValue("Matx4_2.m01 = ",Matx4_2.m01);	GetValue("Matx4_2.m02 = ",Matx4_2.m02); GetValue("Matx4_2.m03 = ",Matx4_1.m02);
			GetValue("Matx4_2.m10 = ",Matx4_2.m10); GetValue("Matx4_2.m11 = ",Matx4_2.m11);	GetValue("Matx4_2.m12 = ",Matx4_2.m12);	GetValue("Matx4_2.m13 = ",Matx4_1.m12);
			GetValue("Matx4_2.m20 = ",Matx4_2.m20);	GetValue("Matx4_2.m21 = ",Matx4_2.m21);	GetValue("Matx4_2.m22 = ",Matx4_2.m22);	GetValue("Matx4_2.m23 = ",Matx4_1.m22);
			GetValue("Matx4_2.m30 = ",Matx4_2.m30);	GetValue("Matx4_2.m31 = ",Matx4_2.m31);	GetValue("Matx4_2.m32 = ",Matx4_2.m32);	GetValue("Matx4_2.m33 = ",Matx4_1.m32);
		}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Rotate 1 axis
	if (_strcmpi(cBuffer, "m4RotateX") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Angle = ",angle);
		if (matx == 1){Matx4_1.RotateX(angle);}
		if (matx == 2){Matx4_2.RotateX(angle);}
	return true;
	}
	if (_strcmpi(cBuffer, "m4RotateY") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Angle = ",angle);
		if (matx == 1){Matx4_1.RotateY(angle);}
		if (matx == 2){Matx4_2.RotateY(angle);}
	return true;
	}
	if (_strcmpi(cBuffer, "m4RotateZ") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Angle = ",angle);
		if (matx == 1){Matx4_1.RotateZ(angle);}
		if (matx == 2){Matx4_2.RotateZ(angle);}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Rotate 3axis
	if (_strcmpi(cBuffer, "m4RotateXYZ") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Vector 1 or 2 : ",vect);
		if (matx == 1){
			switch (vect){
			case 1:
				Matx4_1.RotateXYZ(vect3_1);
				break;
			case 2:
				Matx4_1.RotateXYZ(vect3_2);
				break;
			}
		}
		if (matx == 2){
			switch (vect){
			case 1:
				Matx4_2.RotateXYZ(vect3_1);
				break;
			case 2:
				Matx4_2.RotateXYZ(vect3_2);
				break;
			}
		}
	return true;
	}
	if (_strcmpi(cBuffer, "m4RotateYXZ") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Vector 1 or 2 : ",vect);
		if (matx == 1){
			switch (vect){
			case 1:
				Matx4_1.RotateYXZ(vect3_1);
				break;
			case 2:
				Matx4_1.RotateYXZ(vect3_2);
				break;
			}
		}
		if (matx == 2){
			switch (vect){
			case 1:
				Matx4_2.RotateYXZ(vect3_1);
				break;
			case 2:
				Matx4_2.RotateYXZ(vect3_2);
				break;
			}
		}
	return true;
	}
	if (_strcmpi(cBuffer, "m4RotateZXY") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Vector 1 or 2 : ",vect);
		if (matx == 1){
			switch (vect){
			case 1:
				Matx4_1.RotateZXY(vect3_1);
				break;
			case 2:
				Matx4_1.RotateZXY(vect3_2);
				break;
			}
		}
		if (matx == 2){
			switch (vect){
			case 1:
				Matx4_2.RotateZXY(vect3_1);
				break;
			case 2:
				Matx4_2.RotateZXY(vect3_2);
				break;
			}
		}
	return true;
	}
	if (_strcmpi(cBuffer, "m4RotateZYX") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Vector 1 or 2 : ",vect);
		if (matx == 1){
			switch (vect){
			case 1:
				Matx4_1.RotateZYX(vect3_1);
				break;
			case 2:
				Matx4_1.RotateZYX(vect3_2);
				break;
			}
		}
		if (matx == 2){
			switch (vect){
			case 1:
				Matx4_2.RotateZYX(vect3_1);
				break;
			case 2:
				Matx4_2.RotateZYX(vect3_2);
				break;
			}
		}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Translate
	if (_strcmpi(cBuffer, "m4TranslateX") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Scalar ",scalar);
		if (matx == 1){
			Matx4_1.TranslateX(scalar);
		}
		if (matx == 2){
			Matx4_2.TranslateX(scalar);
		}
	return true;
	}
	if (_strcmpi(cBuffer, "m4TranslateY") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Scalar ",scalar);
		if (matx == 1){
			Matx4_1.TranslateY(scalar);
		}
		if (matx == 2){
			Matx4_2.TranslateY(scalar);
		}
	return true;
	}
	if (_strcmpi(cBuffer, "m4TranslateZ") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Scalar ",scalar);
		if (matx == 1){
			Matx4_1.TranslateZ(scalar);
		}
		if (matx == 2){
			Matx4_2.TranslateZ(scalar);
		}
	return true;
	}
	if (_strcmpi(cBuffer, "m4TranslateV3") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Vector 1 or 2 : ",vect);
		if (matx == 1){
			switch (vect){
			case 1:
				Matx4_1.TranslateXYZ(vect3_1);
				break;
			case 2:
				Matx4_1.TranslateXYZ(vect3_2);
				break;
			}
		}
		if (matx == 2){
			switch (vect){
			case 1:
				Matx4_2.TranslateXYZ(vect3_1);
				break;
			case 2:
				Matx4_2.TranslateXYZ(vect3_2);
				break;
			}
		}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Ortho
	if (_strcmpi(cBuffer, "m4Ortho") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		//yeahhhh bit messy/////////
		cout << "Left : ";        //
		float Left = GetValue();  //
		cout << "Right : ";       //
		float Right = GetValue(); //
		cout << "Top : ";         //
		float Top = GetValue();	  //
		cout << "Bottom : ";      //
		float Bottom = GetValue();//
		cout << "Near : ";        //
		float Near = GetValue();  //
		 cout << "Far : ";        //
		float Far = GetValue();	  //
		if (matx == 1){Matx4_1.Ortho(Left,Right,Top,Bottom,Near,Far);}
		if (matx == 2){Matx4_2.Ortho(Left,Right,Top,Bottom,Near,Far);}
	return true;
	}
	if (_strcmpi(cBuffer, "m4OrthoNormalize") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		if (matx == 1){Matx4_1.OrthoNormalize();}
		if (matx == 2){Matx4_2.OrthoNormalize();}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Scale
	if (_strcmpi(cBuffer, "m4Scale") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Vector 1 or 2 : ",vect);
		if (matx == 1){
			switch (vect){
			case 1:
				Matx4_1.Scale(vect3_1);
				break;
			case 2:
				Matx4_1.Scale(vect3_2);
				break;
			}
		}
		if (matx == 2.0f){
			switch (vect){
			case 1:
				Matx4_2.Scale(vect3_1);
				break;
			case 2:
				Matx4_2.Scale(vect3_2);
				break;
			}
		}
	return true;
	}
	if (_strcmpi(cBuffer, "m4ScaleScalar") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Scalar = ",scalar);
		if (matx == 1){Matx4_1.Scale(scalar);}
		if (matx == 2){Matx4_2.Scale(scalar);}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Setters
	if (_strcmpi(cBuffer, "m4Identity") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		if (matx == 1){Matx4_1.Identity();}
		if (matx == 2){Matx4_2.Identity();}
	return true;
	}
	if (_strcmpi(cBuffer, "m4Zero") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		if (matx == 1){Matx4_1.Zero();}
		if (matx == 2){Matx4_2.Zero();}
		if (matx == 3){Matx4_R.Zero();}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// General Overloads
	if (_strcmpi(cBuffer, "m4Equ") == 0){
		cout << (Matx4_1 == Matx4_2) << endl;
	return true;
	}
	if (_strcmpi(cBuffer, "m4NotEqu") == 0){
		cout << (Matx4_1 != Matx4_2) << endl;
	return true;
	}
	if (_strcmpi(cBuffer, "m4Set") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		if (matx == 1){Matx4_1 = Matx4_1;}
		if (matx == 2){Matx4_2 = Matx4_2;}
	return true;
	}
	if (_strcmpi(cBuffer, "m4SetScalar") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Scalar = ",scalar);
		if (matx == 1){Matx4_1 = scalar;}
		if (matx == 2){Matx4_2 = scalar;}
	return true;
	}
	if (_strcmpi(cBuffer, "m4Negate") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		if (matx == 1){Matx4_1 = -Matx4_1;}
		if (matx == 2){Matx4_2 = -Matx4_2;}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Addition
	if (_strcmpi(cBuffer, "m4++") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		if (matx == 1){Matx4_1++;}
		if (matx == 2){Matx4_2++;}
	return true;
	}
	if (_strcmpi(cBuffer, "m4Add") == 0){
		Matx4_R = Matx4_1 + Matx4_2;
	return true;
	}
	if (_strcmpi(cBuffer, "m4AddEqu") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		if (matx == 1){Matx4_1 += Matx4_2;}
		if (matx == 2){Matx4_1 += Matx4_2;}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// SUbtraction
	if (_strcmpi(cBuffer, "m4--") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		if (matx == 1){Matx4_1--;}
		if (matx == 2){Matx4_2--;}
	return true;
	}
	if (_strcmpi(cBuffer, "m4Sub") == 0){
		Matx4_R = Matx4_1 - Matx4_2;
	return true;
	}
	if (_strcmpi(cBuffer, "m4SubEqu") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		if (matx == 1){Matx4_1 -= Matx4_2;}
		if (matx == 2){Matx4_1 -= Matx4_2;}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Multiplication
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Matrix By Matrix
	if (_strcmpi(cBuffer, "M4MlyM4") == 0){
		Matx4_R = Matx4_1 * Matx4_2;
	return true;
	}
	if (_strcmpi(cBuffer, "M4MlyEquM4") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		if (matx == 1){Matx4_1 *= Matx4_2;}
		if (matx == 2){Matx4_1 *= Matx4_2;}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Matrix By Vector
	if (_strcmpi(cBuffer, "M4MlyV4") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Vector 1 or 2 : ",vect);
		if (matx == 1){
			switch (vect){
			case 1:
				vect4_R = Matx4_1 * vect4_1;
				break;
			case 2:
				vect4_R = Matx4_1 * vect4_2;
				break;
			}
		}
		if (matx == 2){
			switch (vect){
			case 1:
				vect4_R = Matx4_2 * vect4_1;
				break;
			case 2:
				vect4_R = Matx4_2 * vect4_2;
				break;
			}
		}
	return true;
	}
	if (_strcmpi(cBuffer, "M4MlyEquV4") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Vector 1 or 2 : ",vect);
		if (matx == 1){
			switch (vect){
			case 1:
				Matx4_1 *= vect4_1;
				break;
			case 2:
				Matx4_1 *= vect4_2;
				break;
			}
		}
		if (matx == 2){
			switch (vect){
			case 1:
				Matx4_2 *= vect4_1;
				break;
			case 2:
				Matx4_2 *= vect4_2;
				break;
			}
		}
	return true;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Matrix By 
	if (_strcmpi(cBuffer, "M4MlyScalar") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Scalar = ",scalar);
		if (matx == 1.0f){Matx4_R = Matx4_1 * scalar;}
		if (matx == 2.0f){Matx4_R = Matx4_1 * scalar;}
	return true;
	}
	if (_strcmpi(cBuffer, "M4MlyEquScalar") == 0){
		GetValue("Matrix 1 or 2 : ",matx);
		GetValue("Scalar = ",scalar);
		if (matx == 1.0f){Matx4_1 *= scalar;}
		if (matx == 2.0f){Matx4_1 *= scalar;}
	return true;
	}
return false;
}
bool Maths(){
	if (_strcmpi(cBuffer, "power2u") == 0){
		GetValue("Scalar : ",scalar);
		cout << "Closest Greater power of " << scalar << "is : " <<  PowerUp(scalar) << endl;
		return true;
		}
		if (_strcmpi(cBuffer, "power2d") == 0){
		GetValue("Scalar : ",scalar);
		cout << "Closest Lesser power of " << scalar << "is : " <<  PowerDown(scalar) << endl;
		return true;
		}
		if (_strcmpi(cBuffer, "power2c") == 0){
		GetValue("Scalar : ",scalar);
		cout << "Closest power of " << scalar << "is : " << PowerClosest(scalar) << endl;
		return true;
		}
		if (_strcmpi(cBuffer, "LerpScalar") == 0){
		GetValue("Scalar : ",scalar);
		float scalar2;
		GetValue("Scalar2 : ",scalar2);
		GetValue("distance (between 0-1) : ",fdistance);
		cout << "Lerp of " << scalar << " and " << scalar2 << " with distance of " << fdistance << " is : " << Lerp(scalar,scalar2,fdistance) << endl;
		return true;
		}
return false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// End Of Functions

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// MAIN
int main(){
	Header();
	while(bRun){
		cout << endl << "Command : "; cin >> cBuffer;
		if (_strcmpi(cBuffer, "cls")  == 0) {
			system("cls");
			Header();
		}else if (_strcmpi(cBuffer, "show") == 0) {
			Show();
		}else if (_strcmpi(cBuffer, "help") == 0) {
			Help();
		}else if (_strcmpi(cBuffer, "exit") == 0) { 
			bRun = false; 
			cout << "Open me again soon!" << endl;
		}else if (Maths()){
		}else if (CheckV2()){
			cBuffer[0] = 'v';cBuffer[1] = '2'	;cBuffer[2] = NULL;
			ShowCurrent();
		}else if (CheckV3()){
			cBuffer[0] = 'v';cBuffer[1] = '3';cBuffer[2] = NULL;
			ShowCurrent();
		}else if (CheckV4()){
			cBuffer[0] = 'v';cBuffer[1] = '4';cBuffer[2] = NULL;
			ShowCurrent();
		}else if (CheckM3()){
			cBuffer[0] = 'm';cBuffer[1] = '3';cBuffer[2] = NULL;
			ShowCurrent();
		}else if (CheckM4()){
			cBuffer[0] = 'm';cBuffer[1] = '4';cBuffer[2] = NULL;
			ShowCurrent();
		}else{
			cout << "------------------------------- No Found Command ------------------------------" << endl;
		}
	}
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// MAIN