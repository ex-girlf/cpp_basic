#include"workerManager.h"
#include<iostream>
#include <unistd.h>
using namespace std;

//构造函数初始化参数
WorkerManager::WorkerManager()
{
	//����FILENAME�Ƿ�����Լ������Ƿ�Ϊ�գ����������
	//���1���ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{

		m_Empnum = 0;
		m_EmpArray = NULL;
		m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//���2���ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
		//��ʼ������
		m_Empnum = 0;
		m_EmpArray = NULL;
		m_FileIsEmpty = true;
		//�ر�������
		ifs.close();
		return;
	}
	//���3���ļ����ڣ����ݲ�Ϊ��
	int num = this->getFileEmpNum();
	//cout << "�ļ������� " << num << " ��ְ��" << endl;
	this->m_Empnum = num;
	//��ʼ��ְ������
	this->m_EmpArray = new Worker*[this->m_Empnum];
	//����������ȥ
	initEmp();

	//for (int i = 0; i < this->m_Empnum; i++)
	//{
	//	cout << m_EmpArray[i]->m_Id << "\t"
	//		<< m_EmpArray[i]->m_Name << "\t"
	//		<< m_EmpArray[i]->m_Did << endl;
	//}

}

//显示菜单
void WorkerManager::showMenu()
{
	cout << "*************************" << endl
		<< "***欢迎使用职工管理系统***" << endl
		<< "******0.退出******" << endl
		<< "******1.新增******" << endl
		<< "******2.显示******" << endl
		<< "******3.删除******" << endl
		<< "******4.修改******" << endl
		<< "******5.查找******" << endl
		<< "******6.排序******" << endl
		<< "******7.晴空******" << endl
		<< "*************************" << endl;

}

//退出
void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	pause();
	exit(0);
}

//1.添加职工
void WorkerManager::addEmp()
{
	cout << "请输入添加职工数量" << endl;
	int addEmpNum = 0;
	cin >> addEmpNum;
	if (addEmpNum > 0)	
	{
		//
		int newsize = this->m_Empnum + addEmpNum;
		//数组指针
		Worker* * newSpace = new Worker*[newsize];
		//判断不为空，则进行数组拷贝
		if (this->m_Empnum != 0)
		{
			for (int i = 0; i < this->m_Empnum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//������ְ��
		for (int i = 0; i < addEmpNum; i++)
		{
			cout << "请输入第 " << i + 1 << " 个职工id" << endl;
			int id;
			cin >> id;
			cout << "请输入第  " << i + 1 << " 个职工姓名" << endl;
			string name;
			cin >> name;
			cout << "请输入第" << i + 1 << " 岗位角色" << endl
				<< "1 --- 普通职工" << endl
				<< "2 --- 经理" << endl
				<< "3 --- 老板" << endl;
			int did;
			while (true)
			{
				cin >> did;
				if (did == 1 || did == 2 || did == 3)
				{
					switch (did)
					{
					case 1:
						newSpace[this->m_Empnum + i] = new Employee(id, name, did);
						break;
					case 2:
						newSpace[this->m_Empnum + i] = new Manager(id, name, did);
						break;
					case 3:
						newSpace[this->m_Empnum + i] = new Boss(id, name, did);
						break;
					default:
						break;
					}
					break;
				}
				cout << "已成功添加职工信息" << endl;
			}
			
		}
		//�ͷ�ԭ�пռ�����
		delete[] this->m_EmpArray;
		//����ָ��ָ��
		this->m_EmpArray = newSpace;
		//����ְ������
		this->m_Empnum = newsize;

		//����ɹ�����
		cout << "�ɹ����� " << addEmpNum << " ����ְ����" << endl;
		this->m_FileIsEmpty = false; //��������
		this->save(); //���浽�ļ���
	}
	else
	{
		cout << "输入信息有误" << endl;
	}
}

//��������
void WorkerManager::save()
{
	//�����ļ������
	ofstream ofs;
	//������ķ�ʽ���ļ�����д�ļ�
	ofs.open(FILENAME, ios::out);
	//д�ļ�
	for (int i = 0; i < this->m_Empnum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << "\t"
			<< this->m_EmpArray[i]->m_Name << "\t"
			<< this->m_EmpArray[i]->m_Did << endl;
	}
	//�ر��ļ�
	ofs.close();
}

//��ȡ�ļ��е����ݸ���
int WorkerManager::getFileEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int num = 0; //�ļ��е�������
	int id;
	string name;
	int did;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	return num;
}

//���ļ���Ϊ��ʱ�ĳ�ʼ������
void WorkerManager::initEmp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		if (did == 1)
		{
			this->m_EmpArray[index] = new Employee(id, name, did);
		}
		else if (did == 2)
		{
			this->m_EmpArray[index] = new Manager(id, name, did);
		}
		else
		{
			this->m_EmpArray[index] = new Boss(id, name, did);
		}
		index++;
	}
	ifs.close();
}

//2.��ʾְ��
void WorkerManager::showEmp()
{
	if (m_FileIsEmpty == 1||m_Empnum == 0)
	{
		cout << "文件为空或无职工数据" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Empnum; i++)
		{
			//���ö�̬���ְ����Ϣ
			this->m_EmpArray[i]->showInfo();
		}
	}
}

int WorkerManager::empIsExist(int id){
	int index=-1;

	
	for (int i=0;i<this->m_Empnum;i++){
		if(this->m_EmpArray[i]->m_Id == id){
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::deleteEmp(){
	if (m_FileIsEmpty == 1||m_Empnum == 0)
	{
		cout << "文件为空或无职工数据" << endl;
	}
	else
	{
		int id =0;
		cout<<"请输入要删除的职工id:"<<endl;
		cin>>id;
		int index = this->empIsExist(id);
		if(index!=-1){
			
			for (int i = index; i < this->m_Empnum-1; i++)
			{
				if(this->m_EmpArray[i]->m_Id == id){
					this->m_EmpArray[i] = this->m_EmpArray[i+1];
				}
				
			}
			this->m_Empnum --;
			this->save();
			cout<<"删除成功"<<endl;
		}
		else{
			cout<<"未找到该员工"<<endl;
		}
	}
	pause();
	
}

//��������
WorkerManager::~WorkerManager()
{
	if (m_EmpArray != NULL)
	{
		
		delete[] m_EmpArray;
		m_EmpArray = NULL;
	}
}