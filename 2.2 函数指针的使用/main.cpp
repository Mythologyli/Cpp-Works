/*
有如下函数定义：

void func(int x)
{ 
	cout << x; 
}

编写主程序代码，用函数指针调用该函数。
*/


#include <iostream>


using namespace std;


void func(int x)
{
	cout << x;
}


int main()
{
	cout << "本程序用于函数指针的使用" << endl;
	cout << "作者：Peisheng Li  日期：2020/12/06" << endl;

	int x;
	cout << "请输入一个整数：" << endl;
	cin >> x;
	
	void (*fp)(int a); //函数指针
	fp = func;

	cout << "您输入的整数为：" << endl;
	fp(x); //通过函数指针调用函数

	return 1;
}