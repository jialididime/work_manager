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
	void save();//�����ļ�
	int getNum();//ͳ������
	void init();//��ʼ��
	void showEmp();
	int isExit(int a);//ͨ��id�ж�Ա���Ƿ����
	void findEmp();//����
	void delEmp();//ɾ������
	void modEmp();//�޸ĺ���
	void sortEmp();//������
	void clearTable();
	int msize;//����
	bool isEmpty;//�ж��ļ��Ƿ�Ϊ��
	Work ** marr;//Ա������ָ��

};

