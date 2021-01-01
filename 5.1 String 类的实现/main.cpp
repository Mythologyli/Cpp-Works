/*
实现 String 类的四个函数并测试。要求编写函数实现代码时，可以调用 strlen strcpy 函数。

class String
{
public:
	String(const char* str = NULL); //构造函数
	String(const String& other); //拷贝构造函数
	~String(void); //析构函数
	String& operator=(const String& other); //赋值函数

private:
	char *m_data; //用于保存字符串
};
*/


#include <iostream>
#include <string.h>


using namespace std;


class String
{
public:
	String(const char* str = NULL); //构造函数
	String(const String& other); //拷贝构造函数
	~String(void); //析构函数
	String& operator=(const String& other); //赋值函数
	void Print(void); //显示字符串

private:
	char* m_data; //用于保存字符串
};


String::String(const char* str) //构造函数
{
	if (str == NULL) //传入 str 为空
	{
		m_data = new char('\0');
	}
	else
	{
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}
}


String::String(const String& other) //拷贝构造函数
{
	m_data = new char[strlen(other.m_data) + 1];
	strcpy(m_data, other.m_data);
}


String::~String(void) //析构函数
{
	delete[] m_data;
}


String& String::operator=(const String& other) //赋值函数
{
	if (this == &other) //自赋值
		return *this;

	delete[] m_data; //删除原字符串空间
	m_data = new char[strlen(other.m_data) + 1];
	strcpy(m_data, other.m_data);
	return *this;
}


void String::Print(void) //显示字符串
{
	cout << m_data << endl;
}


int main()
{
	cout << "本程序用于 String 类的练习" << endl;
	cout << "作者：Peisheng Li  日期：2021/01/01" << endl;

	String str_1; //无参构造
	String str_2("test string 1"); //有参构造
	String str_3 = str_2; //拷贝构造
	String str_4("test string 2"); //有参构造
	str_1 = str_1; //自赋值
	str_4 = str_4; //自赋值
	str_1 = str_4; //赋值

	//输出四个字符串
	str_1.Print();
	str_2.Print();
	str_3.Print();
	str_4.Print();

	return 0;
}