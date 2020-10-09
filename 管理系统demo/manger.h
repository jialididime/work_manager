#pragma once
#include <iostream>
#include "work.h"
#include"string"
using namespace std;

class manger :public Work
{
public:
	manger(int id, string name, int deptid);
	virtual void showInfo();
	virtual string getDeptName();

};
#pragma once
