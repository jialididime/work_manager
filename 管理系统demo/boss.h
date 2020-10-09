#pragma once
#include <iostream>
#include "work.h"
#include"string"
using namespace std;

class boss :public Work
{
public:
	boss(int id, string name, int deptid);
	virtual void showInfo();
	virtual string getDeptName();

};

