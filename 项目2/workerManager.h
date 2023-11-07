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

	//显示菜单
	void showMenu();

	//0.退出菜单
	void exitSystem();

	//1.添加职工
	void addEmp();

	//2.显示职工
	void showEmp();

	//3.删除职工
	void deleteEmp();


	int empIsExist(int index);

	//4.修改职工
	void modifyEmp();

	//5.查找职工
	//void findEmp();

	//6.排序职工
	//void sortEmp();

	//7.清空数据
	//void clearEmp();
	//保存数据
	void save();

	//获取职工数量
	int getFileEmpNum();

	//初始化
	void initEmp();

	//析构函数
	~WorkerManager();

public:
	int m_Empnum; //ְ职工人数
	Worker ** m_EmpArray; //数组

public:
	bool m_FileIsEmpty; //文件是否为空
};

#endif