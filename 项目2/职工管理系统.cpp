#include<iostream>
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include <unistd.h>
using namespace std;

int main()
{
	//���Դ���
	//Worker *w = NULL;
	//w = new Employee(1, "����", 1);
	//w->showInfo();
	//delete w;

	//w = new Manager(2, "����", 2);
	//w->showInfo();
	//delete w;

	//w = new Boss(3, "����", 3);
	//w->showInfo();
	//delete w;

	WorkerManager wm;

	while (true)
	{
		wm.showMenu();
		cout << "请输入序号：" << endl;
		int choice = 0;
		cin >> choice;

		switch (choice)
		{
		case 0: //�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1: //����ְ��
			wm.addEmp();
			break;
		case 2: //��ʾְ��
			wm.showEmp();
			break;
		case 3: //ɾ��ְ��
			wm.deleteEmp();
			break;
		case 4: //�޸�ְ��
			//wm.modifyEmp();
			break;
		case 5: //����ְ��
			//wm.findEmp();
			break;
		case 6: //���ձ����������&����
			//wm.sortEmp();
			break;
		case 7: //���ְ��
			//wm.clearEmp();
			break;
		default:
			cout << "������������������!" << endl;
			break;
		}
		pause();
		//system("cls");
	}

	pause();

	return 0;
}