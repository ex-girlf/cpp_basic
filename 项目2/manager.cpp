#include"manager.h"
#include<iostream>
using namespace std;
//���캯��
Manager::Manager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Did = did;
}

//��ȡԱ���ĸ�λ
string Manager::getDid()
{
	return string("经理");
}

//��ʾԱ������Ϣ
void Manager::showInfo()
{
	cout << "ְ职工编号:" << this->m_Id
		<< "\t职工姓名:" << this->m_Name
		<< "\t职工岗位:" << this->getDid()
		<< "\t负责接收老板任务，下发给普通员工" << endl;
}