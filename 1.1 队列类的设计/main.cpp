/*
设计一个队列类，具有入队、出队、返回队首元素、返回队尾元素、判断队列是否为空、返回队列长度一共 6 个操作，满足先进先出（FIFO）规则。要求限定最大队列长度，不能对已满的队列进行入队操作，不能对已空的队列进行出队操作。
程序注释清楚，完成队列类所有操作的测试。
*/


#include <iostream>

#include "quene.h"


using namespace std;


int main()
{
	cout << "本程序用于队列类的演示" << endl;
	cout << "将演示入队、出队、返回队首元素、返回队尾元素、判断队列是否为空、返回当前队列长度 6 个操作" << endl;
	cout << "队列的最大长度为 10" << endl;
	cout << "作者：Peisheng Li  日期：2020/11/25" << endl;

	Quene quene;
	int menu_choice; //存放菜单选项

	do
	{
		cout << "=========菜单=========" << endl;
		cout << "[1] 入队" << endl;
		cout << "[2] 出队" << endl;
		cout << "[3] 返回队首元素" << endl;
		cout << "[4] 返回队尾元素" << endl;
		cout << "[5] 判断队列是否为空" << endl;
		cout << "[6] 返回当前队列长度" << endl;
		cout << "[0] 结束演示程序" << endl;

		cin >> menu_choice;

		switch (menu_choice)
		{
		case 1: //入队
		{
			cout << "输入需要入队的整数：";

			int num;
			cin >> num;

			if (!quene.In(num))
				cout << "入队失败！队列已满" << endl;
			else cout << "入队成功！" << endl;
		} 
		break;

		case 2: //出队
		{
			if (!quene.Out())
				cout << "出队失败！队列已空" << endl;
			else cout << "出队成功！" << endl;
		}
		break;

		case 3: //返回队首元素
		{
			if (quene.IsEmpty())
				cout << "返回队首元素失败！队列已空" << endl;
			else cout << "队首元素为：" << quene.FrontMember() << endl;
		}
		break;

		case 4: //返回队尾元素
		{
			if (quene.IsEmpty())
				cout << "返回队尾元素失败！队列已空" << endl;
			else cout << "队尾元素为：" << quene.EndMember() << endl;
		}
		break;

		case 5: //判断队列是否为空
		{
			if (quene.IsEmpty())
				cout << "队列为空" << endl;
			else cout << "队列非空" << endl;
		}
		break;

		case 6: //返回当前队列长度
		{
			cout << "当前队列长度为：" << quene.CurrentLength() << endl;
		}
		}
	} while (menu_choice);

	return 1;
}