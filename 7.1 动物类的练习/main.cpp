/*
定义抽象类 Animal，并由其派生出至少 2 个动物类
要求：通过运行时多态显示输出每种动物自身的叫声
*/


#include <iostream>


using namespace std;


class Animal
{
public:
	virtual void ShowSound(void) = 0;
};


class Bird : public Animal
{
public:
	void ShowSound(void)
	{
		cout << "Bird Sound" << endl;
	}
};


class Dog : public Animal
{
public:
	void ShowSound(void)
	{
		cout << "Dog Sound" << endl;
	}
};


int main()
{
	cout << "本程序用于动物类的练习" << endl;
	cout << "作者：Peisheng Li  日期：2021/01/24" << endl;

	Animal* bird_ptr = new Bird;
	Animal* dog_ptr = new Dog;

	bird_ptr->ShowSound();
	dog_ptr->ShowSound();

	return 0;
}