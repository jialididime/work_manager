#include <iostream>
#include"workManger.h"
#include"employee.h"
#include"manger.h"
#include"work.h"
#include"boss.h"


using namespace std;
void test()
{
	Work *p[10];
	p[0] = new employee(1, "阿三", 001);
	//p[0]->showInfo();
	//cout<<p[0]->getDeptName()<<endl;
	p[1] = new manger(2, "张主任", 002);
	p[2] = new boss(0, "Mrs.王", 000);
	for (int i = 0; i < 3; i++)
	{
		p[i]->showInfo();
		cout << p[i]->getDeptName() << endl;
		cout << endl;
		delete p[i];
	}
	//delete []p;

}

int main()
{
	workManger wm;
	int a = 0;
	//test();
	while (true)
	{
		wm.showMenu();
		//	Work *w = new employee(10, "zs", 100);
		cout << "请输入你的选择:" << endl;
		cin >> a;
		switch (a)
		{
		case 0:wm.exitSystem();
			break;
		case 1:
			wm.addPerson();
			//w->showInfo();
			break;
		case 2:wm.showEmp();
			break;
		case 3:wm.delEmp();
			break;
		case 4:wm.modEmp();
			break;
		case 5:wm.findEmp();
			break;
		case 6:wm.sortEmp();
			break;
		case 7:wm.clearTable();
			break; 
		default:
			cout << "输入错误，请再次尝试" << endl;
			break;
		}


	}
	return 0;
}
