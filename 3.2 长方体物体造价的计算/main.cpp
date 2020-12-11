/*
需要计算四个长方体物体的总造价。
给出长方体的长、宽、高，并按照每立方米造价等于 10，计算四个长方体物体的总造价。编写程序实现这一功能。
要求：每个物体的长宽高由用户给定，默认长=宽=高=5。造价累加使用静态变量实现。
*/


#include <iostream>


using namespace std;


#define DEFAULT_LENGTH 5.0 //默认长度
#define UNIT_COST 10.0 //单位体积造价


class Cuboid
{
private:
	double size[3]; //长、宽、高
	static double cost; //静态成员变量：总造价

public:
	Cuboid(void); //构造函数，初始化长宽高为 DEFAULT_LENGTH
	int Add(void); //输入长宽高。可选择使用默认值。同时向总造价累加
	static double Cost(void); //静态成员函数：返回总造价
};


double Cuboid::cost = 0.0; //初始化总造价为 0


Cuboid::Cuboid(void) //构造函数，初始化长宽高为 DEFAULT_LENGTH
{
	size[0] = size[1] = size[2] = DEFAULT_LENGTH;
}


int Cuboid::Add(void) //输入长宽高。可选择使用默认值。同时向总造价累加
{
	cout << "是否使用长宽高的默认值 5 ? (y/n)";

	char choice;
	cin >> choice;

	if (choice == 'y') //使用默认值
	{
		cost += DEFAULT_LENGTH * DEFAULT_LENGTH * DEFAULT_LENGTH * UNIT_COST;
		return 0;
	}
	
	//键盘输入

	cout << "请输入长：";
	cin >> size[0];

	cout << "请输入宽：";
	cin >> size[1];

	cout << "请输入高：";
	cin >> size[2];

	cost += size[0] * size[1] * size[2] * UNIT_COST;

	return 1;
}


double Cuboid::Cost(void) //静态成员函数：返回总造价
{
	return cost;
}


int main()
{
	cout << "本程序用于计算四个长方体物体的总造价" << endl;
	cout << "作者：Peisheng Li  日期：2020/12/11" << endl;
	
	cout << "第一个物体" << endl;
	Cuboid cuboid_1;
	cuboid_1.Add();

	cout << "第二个物体" << endl;
	Cuboid cuboid_2;
	cuboid_2.Add();

	cout << "第三个物体" << endl;
	Cuboid cuboid_3;
	cuboid_3.Add();

	cout << "第四个物体" << endl;
	Cuboid cuboid_4;
	cuboid_4.Add();

	cout << "总造价为：" << Cuboid::Cost();

	return 1;
}