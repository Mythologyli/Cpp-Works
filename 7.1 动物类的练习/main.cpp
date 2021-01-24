/*
��������� Animal������������������ 2 ��������
Ҫ��ͨ������ʱ��̬��ʾ���ÿ�ֶ�������Ľ���
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
	cout << "���������ڶ��������ϰ" << endl;
	cout << "���ߣ�Peisheng Li  ���ڣ�2021/01/24" << endl;

	Animal* bird_ptr = new Bird;
	Animal* dog_ptr = new Dog;

	bird_ptr->ShowSound();
	dog_ptr->ShowSound();

	return 0;
}