#include "stdafx.h"
#include "UnitTests.h"

#include <time.h>
#include <iostream>
using namespace std;//yeah I know..

int main(){
	srand(time(NULL));
	cUnitTestTranslate3 Translate3;
	Matrix3 TestMatx3,AnsMatx3;
	Vector2 TestVect2;
	int iTests;
	int iTx,iTy,iTz;
	int iPass = 0;
	cout << "Amount of tests to do on Translate3 = ";cin >> iTests;
	for (int i = 0; i < iTests; i++){
		TestMatx3.Identity();
		AnsMatx3.Identity();

		iTx = rand()%100-50;
		iTy = rand()%100-50;

		TestVect2.x = iTx;
		TestVect2.y = iTy;

		AnsMatx3.m02 = iTx;
		AnsMatx3.m12 = iTy;

		cout << "Now Testing with values of : iTx = " << iTx << " : iTy = " << iTy << endl; 
		Translate3.SetData(TestMatx3,TestVect2,AnsMatx3);
		if (Translate3.DoTest()){
			cout << "Test on Translate3 Passed! :)" << endl << endl;
			Translate3.Show();
			iPass++;
		}else{
			cout << "Test on Translate3 Falied! :(" << endl << endl;
			Translate3.Show();
			system("pause");
		}
	}
	if (iPass == iTests){
		cout << "-------------------- (: !All Tests on Translate3 Passed! :) ------------------" << endl << endl;
	}else{
		cout << "------------------- ): !Some Tests on Translate3 FAILED! :( ------------------" << endl << endl;
	}

	iPass = 0;//Reset out Passtester
	cUnitTestTranslate4 Translate4;
	Matrix4 TestMatx4,AnsMatx4;
	Vector3 TestVect3;

	cout << "Amount of tests to do = ";cin >> iTests;
	for (int i = 0; i < iTests; i++){
		TestMatx4.Identity();
		AnsMatx4.Identity();

		iTx = rand()%100-50;
		iTy = rand()%100-50;
		iTz = rand()%100-50;

		TestVect3.x = iTx;
		TestVect3.y = iTy;
		TestVect3.z = iTz;

		AnsMatx4.m03 = iTx;
		AnsMatx4.m13 = iTy;
		AnsMatx4.m23 = iTz;

		cout << "Now Testing with values of : iTx = " << iTx << " : iTy = " << iTy << " : iTz = " << iTz << endl; 
		Translate4.SetData(TestMatx4,TestVect3,AnsMatx4);
		if (Translate4.DoTest()){
			cout << "Test on Translate4 Passed! :)" << endl << endl;
			Translate4.Show();
			iPass++;
		}else{
			cout << "Test on Translate4 Falied! :(" << endl << endl;
			Translate4.Show();
			system("pause");
		}
	}
	if (iPass == iTests){
		cout << "-------------------- (: !All Tests on Translate4 Passed! :) ------------------" << endl << endl;
	}else{
		cout << "------------------- ): !Some Tests on Translate4 FAILED! :( ------------------" << endl << endl;
	}

	system("pause");
	return 1+1-1-1;
}