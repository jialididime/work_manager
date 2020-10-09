#include <iostream>
#include"workManger.h"
#include"windows.h"
using namespace std;


workManger::workManger()
{
	this->msize = 0;
	this->marr = NULL;
	ifstream ifs;
	ifs.open("db.txt", ios::in);
	if (!ifs.is_open())//文件不存在
	{
		cout << "文件不存在" << endl; //测试输出
		this->msize = 0;  //初始化人数
		this->isEmpty = true; //初始化文件为空标志
		this->marr = NULL; //初始化数组
		ifs.close(); //关闭文件
		return;
	}

	//文件存在，并且没有记录
	char ch;
	ifs >> ch;	
	if (ifs.eof())// 文件结尾标EOF
	{
		cout << "文件为空!" << endl;
		this->msize = 0;
		this->isEmpty = true;
		this->marr = NULL;
		ifs.close();
		return;
	}
	int num = this->getNum();
	//cout << "职工个数为：" << num << endl;  //测试代码
	this->msize = num;  //更新成员属性 
	//根据职工数创建数组
	this->marr = new Work *[this->msize];
	init();

	this->isEmpty = false;

	//测试代码
	/*for (int i = 0; i < this->msize; i++)
	{
		cout << "职工号： " << this->marr[i]->pid
			<< " 职工姓名： " << this->marr[i]->pname
			<< " 部门编号： " << this->marr[i]->pdeptid << endl;
	}*/

}
workManger::~workManger()
{
	if (this->marr != NULL)
	{
		delete[] this->marr;
	}
}

void workManger::showMenu()
{

	cout << "******欢迎使用职工管理系统*******" << endl;
	cout << "*********0.退出管理程序**********" << endl;
	cout << "*********1.增加职工信息**********" << endl;
	cout << "*********2.显示职工信息**********" << endl;
	cout << "*********3.删除职工信息**********" << endl;
	cout << "*********4.修改职工信息**********" << endl;
	cout << "*********5.查找职工信息**********" << endl;
	cout << "*********6.按照编号排序**********" << endl;
	cout << "*********7.清空所有文档**********" << endl;

}
void workManger::save()
{	
	ofstream ofs;
	ofs.open("db.txt", ios::out);
	for (int i = 0; i < this->msize; i++)
	{
		ofs << this->marr[i]->pid <<" "<< this->marr[i]->pname<<" " <<this->marr[i]->pdeptid << endl;

	}
	ofs.close();
	
}
void workManger::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
//增加职工函数
void workManger::addPerson() {
	cout << "请输入要添加职员的人数" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//新空间大小
		int newsize = this->msize + addNum;
		//开辟新空间
		Work** newspace = new Work*[newsize];
		if (this->marr != NULL)
		{//更新空间
			for(int i=0;i<this->msize;i++)
			{ 
				newspace[i] = this->marr[i];
			}

		}
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
			cin >> id;
			cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
			cin >> name;
			//cout << "请输入第 " << i + 1 << " 个新职工部门编号：" << endl;
			//cin >> did;
			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			Work * work = NULL;
			int b = 0;
			cin >> b;
			
			if (1 == b)
			{
				work = new employee(id, name,1);
			}
			else if (2==b)
			{
				work = new manger(id, name, 2);
			}
			else if (3==b)
			{
				work = new boss(id, name, 3);
			}
			else
			{
				cout << "输入错误" << endl;
			}
			newspace[this->msize + i] = work;
		}

		//释放原有空间
		delete[] this->marr;

		//更改新空间的指向
		this->marr = newspace;

		//更新新的个数
		this->msize = newsize;
		this->isEmpty = false;
		//提示信息
		cout << "成功添加" << addNum << "名新职工！" << endl;
		this->save();
	}
	else
	{
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
}
void workManger::init() {

	ifstream ifs;
	ifs.open("db.txt", ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Work * worker = NULL;
		//根据不同的部门Id创建不同对象
		if (dId == 1)  // 1普通员工
		{
			worker = new employee(id, name, dId);
		}
		else if (dId == 2) //2经理
		{
			worker = new manger(id, name, dId);
		}
		else //总裁
		{
			worker = new boss(id, name, dId);
		}
		//存放在数组中
		this->marr[index] = worker;
		index++;
	}
	
	//初始化职工


}


int workManger::getNum() {

	ifstream ifs;
	ifs.open("db.txt", ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//记录人数
		num++;
	}
	ifs.close();

	return num;

}
void workManger::showEmp() {

	if (this->isEmpty)
	{
		cout << "文件不存在" << endl;
		

	}
	else
	{
		for (int i = 0; i < this->msize; i++)
		{
			this->marr[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
int workManger::isExit(int a) {

	int b = -1;
	for (int i = 0; i < this->msize; i++)
	{
		if (this->marr[i]->pid == a)
		{
			b = i;
			break;
		}
	}
	return b;
}
void workManger::findEmp() 
{

	if (this->isEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else {

		cout << "请输入查找的方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按姓名查找" << endl;

		int select = 0;
		cin >> select;
		if (select==1) {
			cout << "请输入要查找的id" << endl;
			int fid;
			cin >> fid;
			int ret = this->isExit(fid);
			if (ret != -1)
			{
				cout << "查找成功，信息如下：" << endl;
				this->marr[ret]->showInfo();
			}
			else
			{
				cout << "此人不存在" << endl;
			}
		}
		else if (select == 2) //按姓名查找
		{
			string name;
			cout << "请输入查找的姓名：" << endl;
			cin >> name;

			bool flag = false;  //查找到的标志
			for (int i = 0; i < msize; i++)
			{
				if (marr[i]->pname == name)
				{
					cout << "查找成功，信息如下：" << endl;
					this->marr[i]->showInfo();

					flag = true;

				
				}
			}
			if (flag == false)
			{
				//查无此人
				cout << "查找失败，查无此人" << endl;
			}
		}
			else
			{
				cout << "输入错误" << endl;
			}
	}
	system("pause");
	system("cls");
}
void workManger::delEmp()
{
	if (this->isEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		int fid;
		cout << "请输入要删除的id：" << endl;
		cin >> fid;
		int ret = this->isExit(fid);
		if (ret != -1)//说明ret位置需要删除
		{
			for (int i = 0; i < this->msize-1; i++)
			{
				this->marr[i] = this->marr[i + 1];
			}
			this->msize--;
			this->save();
			cout << "删除成功" << endl;

		}
		else
		{
			cout << "此id不存在" << endl;
			
		}
	}
	system("pause");
	system("cls");
}
void workManger::modEmp()
{
	if (this->isEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		int fid;
		cout << "请输入要修改的id：" << endl;
		cin >> fid;
		int ret = this->isExit(fid);
		if (ret != -1)//说明ret位置需要修改
		{
			cout << "旧信息如下：" << endl;
			this->marr[ret]->showInfo();
			int mid,mdid;
			string mname;
			cout << "请输入要修改的id：" << endl;
			cin >> mid;
			cout << "请输入要修改的姓名：" << endl;
			cin >> mname;
			cout << "请输入要修改的岗位：" << endl;
			cout << "      1.员工" << endl;
			cout << "      2.经理" << endl;
			cout << "      3.老板" << endl;
			cin >> mdid;
			Work *worker = NULL;
			if (mdid == 1) {
				worker = new employee(mid, mname, mdid);
			}
			else if (mdid == 2) {
				worker = new manger(mid, mname, mdid);
			}
			else if (mdid == 3) {
				worker = new boss(mid, mname, mdid);
			}
			else
			{
				cout<<"输入错误"<<endl;
			}//更改数据 到数组中
			this->marr[ret] = worker;

			cout << "修改成功！" << endl;

			//保存到文件中
			this->save();
		}
		else
		{
			cout << "查无此人！" << endl;
		}
	}
	system("pause");
	system("cls");
}
void  workManger::sortEmp()
{
	if (this->isEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < msize - 1; i++)
		{
			for (int j = 0; j < msize - i-1; j++)
			{

				if (this->marr[j]->pid >this->marr[j + 1]->pid)
				{
					Work *worker = NULL;
					worker = this->marr[j];
					this->marr[j] = this->marr[j + 1];
					this->marr[j + 1] = worker;
				}
			}

		}
		cout << "按照升序排列结果如下：" << endl;
		this->showEmp();
	}

	system("pause");
	system("cls");
}
void workManger::clearTable() {
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1) {

		ofstream ofs("db.txt", ios::trunc);
		ofs.close();
		this->msize = 0;
		delete[] this->marr;
		this->marr = NULL;
		this->isEmpty = true;
		cout << "清理成功" << endl;
	}
	else
	{

	}
	system("pause");
	system("cls");
}