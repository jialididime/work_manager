#include"manger.h"


manger::manger(int id, string name, int deptid) //:pid(id), pname(name), pdeptid(deptid) 
{

	this->pid = id;
	this->pname = name;
	this->pdeptid = deptid;


}
void manger::showInfo() {

	cout << "ְ�����: " << this->pid << endl;
	cout << "ְ��������" << this->pname << endl;
	cout << "��λ: " << this->getDeptName() << endl;
	cout << endl;
}
string manger::getDeptName() {

	return string("����");
}