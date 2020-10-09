#include"boss.h"


boss::boss(int id, string name, int deptid) //:pid(id), pname(name), pdeptid(deptid) 
{

	this->pid = id;
	this->pname = name;
	this->pdeptid = deptid;


}
void boss::showInfo() {

	cout << "职工编号: " << this->pid << endl;
	cout << "职工姓名: " << this->pname << endl;
	cout << "岗位: " << this->getDeptName() << endl;
	cout << endl;
}
string boss::getDeptName() {

	return string("老板");
}