#include"boss.h"


boss::boss(int id, string name, int deptid) //:pid(id), pname(name), pdeptid(deptid) 
{

	this->pid = id;
	this->pname = name;
	this->pdeptid = deptid;


}
void boss::showInfo() {

	cout << "ְ�����: " << this->pid << endl;
	cout << "ְ������: " << this->pname << endl;
	cout << "��λ: " << this->getDeptName() << endl;
	cout << endl;
}
string boss::getDeptName() {

	return string("�ϰ�");
}