#pragma once
#include<iostream>
#include"string"
using namespace std;
class Work {
public:
	int pid;
	string pname;
	int pdeptid;
	virtual void showInfo()=0;
	virtual string getDeptName()=0;


};