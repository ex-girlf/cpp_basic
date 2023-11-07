#ifndef __WORKERMANAGER_H__
#define __WORKERMANAGER_H__

#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

#include<fstream>

#define FILENAME "empFile.txt"

class WorkerManager
{
public:
	//
	WorkerManager();

	//�˵�չʾ����
	void showMenu();

	//0.�˳�ϵͳ
	void exitSystem();

	//1.����ְ��
	void addEmp();

	//2.��ʾְ��
	void showEmp();

	//3.ɾ��ְ��
	void deleteEmp();


	int empIsExist(int index);

	//4.�޸�ְ��
	//void modifyEmp();

	//5.����ְ��
	//void findEmp();

	//6.���ձ����������&����
	//void sortEmp();

	//7.���ְ��
	//void clearEmp();
	//��������
	void save();

	//��ȡ�ļ��е����ݸ���
	int getFileEmpNum();

	//���ļ���Ϊ��ʱ�ĳ�ʼ������
	void initEmp();

	//��������
	~WorkerManager();

public:
	int m_Empnum; //ְ����
	Worker ** m_EmpArray; //ְ������

public:
	bool m_FileIsEmpty; //�ж��ļ��Ƿ�Ϊ��
};

#endif