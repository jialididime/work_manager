#pragma once
#include <iostream>
#include"boss.h"
#include"manger.h"
#include"employee.h"
#include"string"
#include<fstream>


class workManger {
public:
	workManger();
	~workManger();
	void showMenu();
	void exitSystem();
	void addPerson();
	void save();//保存文件
	int getNum();//统计人数
	void init();//初始化
	void showEmp();
	int isExit(int a);//通过id判断员工是否存在
	void findEmp();//查找
	void delEmp();//删除函数
	void modEmp();//修改函数
	void sortEmp();//排序函数
	void clearTable();
	int msize;//人数
	bool isEmpty;//判断文件是否为空
	Work ** marr;//员工数组指针

};

