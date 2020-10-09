#include"manger.h"


manger::manger(int id, string name, int deptid) //:pid(id), pname(name), pdeptid(deptid) 
{

	this->pid = id;
	this->pname = name;
	this->pdeptid = deptid;


}
void manger::showInfo() {

	cout << "职工编号: " << this->pid << endl;
	cout << "职工姓名：" << this->pname << endl;
	cout << "岗位: " << this->getDeptName() << endl;
	cout << endl;
}
string manger::getDeptName() {

	return string("经理");
}