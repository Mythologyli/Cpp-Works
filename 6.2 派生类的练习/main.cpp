/*
定义 Shape 基类，并实现派生类 Triangle 和 Rectangle。 
要求：数据成员全部定义在基类里；派生类只增加各自的求面积函数。
*/


#include <iostream>


using namespace std;


class Shape
{
public:
	Shape(double base, double height)
	{
		this->base = base;
		this->height = height;
	}

protected:
	double base;
	double height;
};


class Triangle : public Shape
{
public:
	Triangle(double base, double height) : Shape(base, height) {}

	double Area(void)
	{
		return 0.5 * base * height;
	}
};


class Rectangle : public Shape
{
public:
	Rectangle(double base, double height) : Shape(base, height) {}

	double Area(void)
	{
		return base * height;
	}
};


int main()
{
	cout << "本程序用于派生类的练习" << endl;
	cout << "作者：Peisheng Li  日期：2021/01/10" << endl;
	
	Triangle a(5.1, 10.2);
	Rectangle b(5.1, 10.2);

	cout << a.Area() << endl;
	cout << b.Area() << endl;

	return 0;
}