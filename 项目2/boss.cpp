#include"boss.h"
#include<iostream>
using namespace std;
//���캯��
Boss::Boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Did = did;
}

//��ȡԱ���ĸ�λ
string Boss::getDid()
{
	return string("资本家");
}

//��ʾԱ������Ϣ
void Boss::showInfo()
{
	cout << "ְ职工编号:" << this->m_Id
		<< "\t职工姓名:" << this->m_Name
		<< "\t职工岗位:" << this->getDid()
		<< "\t我是老板" << endl;
}