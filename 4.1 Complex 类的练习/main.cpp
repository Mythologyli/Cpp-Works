/*
完善 Complex 类并测试。
要求：
1.完善单目（只有一个参数）函数 complex_add(...)，实现自身 Complex 对象和另一个用户传入的 Complex 对象相加（按复数加法规则）。
2.重载 complex_add 函数，实现整数 + 自身 Complex 对象。
3.完善 display() 函数，实现 Complex 对象以复数的数学形式输出（比如 1+2i）。
4.增加一个双目友元函数，实现两个 Complex 对象的相加。

#include <iostream>

using namespace std;

class Complex
{
public:
	Complex(){real=0;imag=0;}
	Complex complex_add(...);
	void display();
private:
	double real;
	double imag;
};
*/


#include <iostream>


using namespace std;


class Complex
{
public:
	Complex(double real_part = 0, double imag_part = 0)
	{ 
		real = real_part;
		imag = imag_part;
	}
	Complex complex_add(Complex complex_num); //自身 Complex 对象和另一个用户传入的 Complex 对象相加
	Complex complex_add(int real_int_num); //整数 + 自身 Complex 对象
	void display(void); //以复数的数学形式输出

	friend Complex two_complex_add(Complex complex_a, Complex complex_b); //两个 Complex 对象的相加

private:
	double real;
	double imag;
};


Complex Complex::complex_add(Complex complex_num) //自身 Complex 对象和另一个用户传入的 Complex 对象相加
{
	Complex sum(real + complex_num.real, imag + complex_num.imag);

	return sum;
}


Complex Complex::complex_add(int real_int_num) //整数 + 自身 Complex 对象
{
	Complex sum(real + real_int_num, imag);

	return sum;
}


void Complex::display(void) //以复数的数学形式输出
{
	cout << real << "+" << imag << "i" << endl;
}


Complex two_complex_add(Complex complex_a, Complex complex_b) //两个 Complex 对象的相加
{
	Complex sum(complex_a.real + complex_b.real, complex_a.imag + complex_b.imag);

	return sum;
}


int main()
{
	cout << "本程序用于 Complex 类的练习" << endl;
	cout << "作者：Peisheng Li  日期：2020/12/20" << endl;

	double real_part_1;
	cout << "请输入第一个复数的实部：";
	cin >> real_part_1;
	double imag_part_1;
	cout << "请输入第一个复数的虚部：";
	cin >> imag_part_1;
	Complex complex_1(real_part_1, imag_part_1);

	double real_part_2;
	cout << "请输入第二个复数的实部：";
	cin >> real_part_2;
	double imag_part_2;
	cout << "请输入第二个复数的虚部：";
	cin >> imag_part_2;
	Complex complex_2(real_part_2, imag_part_2);

	double real_part_3;
	cout << "请输入第三个复数的实部：";
	cin >> real_part_3;
	double imag_part_3;
	cout << "请输入第三个复数的虚部：";
	cin >> imag_part_3;
	Complex complex_3(real_part_3, imag_part_3);

	int int_num;
	cout << "请输入一个整数：";
	cin >> int_num;

	cout << "第一个复数与第二个复数的和为：" << endl;
	Complex sum_1_and_2;
	sum_1_and_2 = complex_1.complex_add(complex_2);
	sum_1_and_2.display();

	cout << "第一个复数与整数的和为：" << endl;
	Complex sum_1_and_int;
	sum_1_and_int = complex_1.complex_add(int_num);
	sum_1_and_int.display();


	cout << "第二个复数与第三个复数的和为：" << endl;
	Complex sum_2_and_3;
	sum_2_and_3 = two_complex_add(complex_2, complex_3);
	sum_2_and_3.display();

	return 1;
}