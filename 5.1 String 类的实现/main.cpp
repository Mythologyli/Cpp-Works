/*
ʵ�� String ����ĸ����������ԡ�Ҫ���д����ʵ�ִ���ʱ�����Ե��� strlen strcpy ������

class String
{
public:
	String(const char* str = NULL); //���캯��
	String(const String& other); //�������캯��
	~String(void); //��������
	String& operator=(const String& other); //��ֵ����

private:
	char *m_data; //���ڱ����ַ���
};
*/


#include <iostream>
#include <string.h>


using namespace std;


class String
{
public:
	String(const char* str = NULL); //���캯��
	String(const String& other); //�������캯��
	~String(void); //��������
	String& operator=(const String& other); //��ֵ����
	void Print(void); //��ʾ�ַ���

private:
	char* m_data; //���ڱ����ַ���
};


String::String(const char* str) //���캯��
{
	if (str == NULL) //���� str Ϊ��
	{
		m_data = new char('\0');
	}
	else
	{
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}
}


String::String(const String& other) //�������캯��
{
	m_data = new char[strlen(other.m_data) + 1];
	strcpy(m_data, other.m_data);
}


String::~String(void) //��������
{
	delete[] m_data;
}


String& String::operator=(const String& other) //��ֵ����
{
	if (this == &other) //�Ը�ֵ
		return *this;

	delete[] m_data; //ɾ��ԭ�ַ����ռ�
	m_data = new char[strlen(other.m_data) + 1];
	strcpy(m_data, other.m_data);
	return *this;
}


void String::Print(void) //��ʾ�ַ���
{
	cout << m_data << endl;
}


int main()
{
	cout << "���������� String �����ϰ" << endl;
	cout << "���ߣ�Peisheng Li  ���ڣ�2021/01/01" << endl;

	String str_1; //�޲ι���
	String str_2("test string 1"); //�вι���
	String str_3 = str_2; //��������
	String str_4("test string 2"); //�вι���
	str_1 = str_1; //�Ը�ֵ
	str_4 = str_4; //�Ը�ֵ
	str_1 = str_4; //��ֵ

	//����ĸ��ַ���
	str_1.Print();
	str_2.Print();
	str_3.Print();
	str_4.Print();

	return 0;
}