#pragma once
#include <iostream>
#include "work.h"
#include"string"
using namespace std;

class employee :public Work
{
public:
	employee(int id,string name,int deptid);
	virtual void showInfo();
	virtual string getDeptName();

};

