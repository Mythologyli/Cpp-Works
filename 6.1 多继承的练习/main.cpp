/*
要求：
Person 类的 all_info() 能够显示姓名，
Student 类的 all_info() 能够显示姓名+考试通过的科目，
Mathematician 类的 all_info() 能够显示姓名+证明的定理，
Math_student 类的 all_info() 能够显示所有的信息。
*/


#include <iostream>
#include <string>


using namespace std;


class Person
{
public:
	Person(string name)
	{
		this->name = name;
	}

	void all_info(void)
	{
		cout << "Name: " + name << endl;
	}

protected:
	string name;
};


class Student: virtual public Person
{
public:
	Student(string name, string passed) : Person(name)
	{
		this->passed = passed;
	}

	void all_info(void)
	{
		cout << "Passed: " + passed << endl;
	}

protected:
	string passed;
};


class Mathematician : virtual public Person
{
public:
	Mathematician(string name, string proved) : Person(name)
	{
		this->proved = proved;
	}

	void all_info(void)
	{
		cout << "Proved: " + proved << endl;
	}

protected:
	string proved;
};


class Math_student : public Student, public Mathematician
{
public:
	Math_student(string name, string passed, string proved) : Person(name), Student(name, passed), Mathematician(name, proved) {}

	void all_info(void)
	{
		cout << "Name: " + name + "    Passed: " + passed + "    Proved: " + proved << endl;
	}
};


int main()
{
	cout << "本程序用于多继承的练习" << endl;
	cout << "作者：Peisheng Li  日期：2021/01/10" << endl;
	
	Math_student student_a("Mike", "ODE", "Liouville_theorem");
	student_a.Person::all_info();
	student_a.Student::all_info();
	student_a.Mathematician::all_info();
	student_a.all_info();

	return 0;
}