#ifndef _UNITTESTGENERIC_H_
#define _UNITTESTGENERIC_H_

class cUnitTest{
public:
	cUnitTest(){};
	~cUnitTest(){};

	virtual bool DoTest() = 0;
	virtual void Show() = 0;
};

#endif