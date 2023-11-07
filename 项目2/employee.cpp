#include"employee.h"
#include <iostream>

Employee::Employee(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Did = did;
}

//��ȡ��λ����
string Employee::getDid()
{
	return string("普通职工");
}

//��ʾԱ����Ϣ
void Employee::showInfo()
{
	std::cout << "ְ职工编号:" << this->m_Id
		<< "\t职工姓名:" << this->m_Name
		<< "\t职工岗位:" << this->getDid()
		<< "\t我是打工狗" << endl;
}