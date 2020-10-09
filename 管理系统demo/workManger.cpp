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
	if (!ifs.is_open())//�ļ�������
	{
		cout << "�ļ�������" << endl; //�������
		this->msize = 0;  //��ʼ������
		this->isEmpty = true; //��ʼ���ļ�Ϊ�ձ�־
		this->marr = NULL; //��ʼ������
		ifs.close(); //�ر��ļ�
		return;
	}

	//�ļ����ڣ�����û�м�¼
	char ch;
	ifs >> ch;	
	if (ifs.eof())// �ļ���β��EOF
	{
		cout << "�ļ�Ϊ��!" << endl;
		this->msize = 0;
		this->isEmpty = true;
		this->marr = NULL;
		ifs.close();
		return;
	}
	int num = this->getNum();
	//cout << "ְ������Ϊ��" << num << endl;  //���Դ���
	this->msize = num;  //���³�Ա���� 
	//����ְ������������
	this->marr = new Work *[this->msize];
	init();

	this->isEmpty = false;

	//���Դ���
	/*for (int i = 0; i < this->msize; i++)
	{
		cout << "ְ���ţ� " << this->marr[i]->pid
			<< " ְ�������� " << this->marr[i]->pname
			<< " ���ű�ţ� " << this->marr[i]->pdeptid << endl;
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

	cout << "******��ӭʹ��ְ������ϵͳ*******" << endl;
	cout << "*********0.�˳��������**********" << endl;
	cout << "*********1.����ְ����Ϣ**********" << endl;
	cout << "*********2.��ʾְ����Ϣ**********" << endl;
	cout << "*********3.ɾ��ְ����Ϣ**********" << endl;
	cout << "*********4.�޸�ְ����Ϣ**********" << endl;
	cout << "*********5.����ְ����Ϣ**********" << endl;
	cout << "*********6.���ձ������**********" << endl;
	cout << "*********7.��������ĵ�**********" << endl;

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
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
//����ְ������
void workManger::addPerson() {
	cout << "������Ҫ���ְԱ������" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//�¿ռ��С
		int newsize = this->msize + addNum;
		//�����¿ռ�
		Work** newspace = new Work*[newsize];
		if (this->marr != NULL)
		{//���¿ռ�
			for(int i=0;i<this->msize;i++)
			{ 
				newspace[i] = this->marr[i];
			}

		}
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			cout << "������� " << i + 1 << " ����ְ����ţ�" << endl;
			cin >> id;
			cout << "������� " << i + 1 << " ����ְ��������" << endl;
			cin >> name;
			//cout << "������� " << i + 1 << " ����ְ�����ű�ţ�" << endl;
			//cin >> did;
			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
				cout << "�������" << endl;
			}
			newspace[this->msize + i] = work;
		}

		//�ͷ�ԭ�пռ�
		delete[] this->marr;

		//�����¿ռ��ָ��
		this->marr = newspace;

		//�����µĸ���
		this->msize = newsize;
		this->isEmpty = false;
		//��ʾ��Ϣ
		cout << "�ɹ����" << addNum << "����ְ����" << endl;
		this->save();
	}
	else
	{
		cout << "������������������" << endl;
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
		//���ݲ�ͬ�Ĳ���Id������ͬ����
		if (dId == 1)  // 1��ͨԱ��
		{
			worker = new employee(id, name, dId);
		}
		else if (dId == 2) //2����
		{
			worker = new manger(id, name, dId);
		}
		else //�ܲ�
		{
			worker = new boss(id, name, dId);
		}
		//�����������
		this->marr[index] = worker;
		index++;
	}
	
	//��ʼ��ְ��


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
		//��¼����
		num++;
	}
	ifs.close();

	return num;

}
void workManger::showEmp() {

	if (this->isEmpty)
	{
		cout << "�ļ�������" << endl;
		

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
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else {

		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2������������" << endl;

		int select = 0;
		cin >> select;
		if (select==1) {
			cout << "������Ҫ���ҵ�id" << endl;
			int fid;
			cin >> fid;
			int ret = this->isExit(fid);
			if (ret != -1)
			{
				cout << "���ҳɹ�����Ϣ���£�" << endl;
				this->marr[ret]->showInfo();
			}
			else
			{
				cout << "���˲�����" << endl;
			}
		}
		else if (select == 2) //����������
		{
			string name;
			cout << "��������ҵ�������" << endl;
			cin >> name;

			bool flag = false;  //���ҵ��ı�־
			for (int i = 0; i < msize; i++)
			{
				if (marr[i]->pname == name)
				{
					cout << "���ҳɹ�����Ϣ���£�" << endl;
					this->marr[i]->showInfo();

					flag = true;

				
				}
			}
			if (flag == false)
			{
				//���޴���
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
			else
			{
				cout << "�������" << endl;
			}
	}
	system("pause");
	system("cls");
}
void workManger::delEmp()
{
	if (this->isEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		int fid;
		cout << "������Ҫɾ����id��" << endl;
		cin >> fid;
		int ret = this->isExit(fid);
		if (ret != -1)//˵��retλ����Ҫɾ��
		{
			for (int i = 0; i < this->msize-1; i++)
			{
				this->marr[i] = this->marr[i + 1];
			}
			this->msize--;
			this->save();
			cout << "ɾ���ɹ�" << endl;

		}
		else
		{
			cout << "��id������" << endl;
			
		}
	}
	system("pause");
	system("cls");
}
void workManger::modEmp()
{
	if (this->isEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		int fid;
		cout << "������Ҫ�޸ĵ�id��" << endl;
		cin >> fid;
		int ret = this->isExit(fid);
		if (ret != -1)//˵��retλ����Ҫ�޸�
		{
			cout << "����Ϣ���£�" << endl;
			this->marr[ret]->showInfo();
			int mid,mdid;
			string mname;
			cout << "������Ҫ�޸ĵ�id��" << endl;
			cin >> mid;
			cout << "������Ҫ�޸ĵ�������" << endl;
			cin >> mname;
			cout << "������Ҫ�޸ĵĸ�λ��" << endl;
			cout << "      1.Ա��" << endl;
			cout << "      2.����" << endl;
			cout << "      3.�ϰ�" << endl;
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
				cout<<"�������"<<endl;
			}//�������� ��������
			this->marr[ret] = worker;

			cout << "�޸ĳɹ���" << endl;

			//���浽�ļ���
			this->save();
		}
		else
		{
			cout << "���޴��ˣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}
void  workManger::sortEmp()
{
	if (this->isEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
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
		cout << "�����������н�����£�" << endl;
		this->showEmp();
	}

	system("pause");
	system("cls");
}
void workManger::clearTable() {
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;

	if (select == 1) {

		ofstream ofs("db.txt", ios::trunc);
		ofs.close();
		this->msize = 0;
		delete[] this->marr;
		this->marr = NULL;
		this->isEmpty = true;
		cout << "����ɹ�" << endl;
	}
	else
	{

	}
	system("pause");
	system("cls");
}