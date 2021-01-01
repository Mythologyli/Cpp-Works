/*
思考、补充和完善下列代码。要求 S 类只能生成最多一个对象（注意构造函数 S()的访问权限）。

class S
{
public:
	static S* getInstance();
	//可以补充
private:
	S();
	static S* instance_;
	//可以补充
};
*/


#include <iostream>


using namespace std;


class S
{
public:
	static S* getInstance(); //获取实例地址
	void setInstance(int num); //设置实例内容
	void Print(void); //显示实例内容

private:
	S(int num = 0); //构造函数
	static S* instance_;
	int number;
};


S::S(int num) //构造函数
{
	number = num;
}


S* S::getInstance() //获取实例地址
{
	if (!instance_) //若实例未生成，生成实例
		instance_ = new S;
	
	return instance_;
}


void S::setInstance(int num) //设置实例内容
{
	number = num;
}


void S::Print(void) //显示实例内容
{
	cout << number << endl;
}


S* S::instance_ = NULL; //初始化实例地址变量


int main()
{
	cout << "本程序用于单例模式练习" << endl;
	cout << "作者：Peisheng Li  日期：2021/01/01" << endl;

	S* s_ptr = S::getInstance(); //获取实例地址
	s_ptr->Print(); //输出实例内容
	s_ptr->setInstance(999); //设置实例内容
	s_ptr->Print(); //输出实例内容
	S* s_ptr_2 = S::getInstance(); //获取实例地址
	s_ptr_2->Print(); //输出实例内容

	return 0;
}