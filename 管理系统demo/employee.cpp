#include"employee.h"


employee::employee(int id, string name, int deptid) //pid(id), pname(name), pdeptid(deptid) 
{

	this->pid = id;
	this->pname = name;
	this->pdeptid = deptid;


}
void employee::showInfo() {

	cout << "ְ�����: " << this->pid << endl;
	cout << "ְ��������" << this->pname << endl;
	cout << "��λ:     " << this->getDeptName() << endl;
	cout << endl;

}
string employee::getDeptName() {

	return string("Ա��");
}