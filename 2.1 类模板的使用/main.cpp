/*
#include <iostream>
using namespace std;
class Array {
private:
	T* ptr; //成员指针
	int size;
public:
	Array(T arr[], int s); //传入的 arr 数组为 ptr 指向的数组赋值，s 为输入长度
	void print(); //依次输出数组元素
};

请将类模板补全，并编写主程序代码，对模板进行测试。
*/


#include <iostream>


using namespace std;


template <class T>
class Array 
{
private:
	T* ptr; //成员指针
	int size; //数组长度
public:
	Array(T arr[], int s); //传入的 arr 数组为 ptr 指向的数组赋值，s 为输入长度
	void print(void); //依次输出数组元素
};


template <class T>
Array<T>::Array(T arr[], int s) //传入的 arr 数组为 ptr 指向的数组赋值，s 为输入长度
{
	size = s;
	ptr = new T[size];

	for (int i = 0; i < size; i++)
		ptr[i] = arr[i];
}


template <class T>
void Array<T>::print(void) //依次输出数组元素
{
	for (int i = 0; i < size; i++)
		cout << ptr[i] << " ";
}


int main()
{
	cout << "本程序用于练习类模版的使用" << endl;
	cout << "作者：Peisheng Li  日期：2020/12/06" << endl;

	int menu_choice; //存放菜单选项

	cout << "=========菜单=========" << endl;
	cout << "[1] 输入整数" << endl;
	cout << "[2] 输入字符" << endl;
	cin >> menu_choice;

	int input_length; //数组长度
	cout << "请输入数组长度：" << endl;
	cin >> input_length;

	cout << "请输入 " << input_length << " 个元素：" << endl;
	if (menu_choice == 1) //输入整数
	{
		int* input_array = new int[input_length];
		
		for (int i = 0; i < input_length; i++)
			cin >> input_array[i];

		Array<int> array(input_array, input_length);
		
		cout << "输入的 " << input_length << " 个元素为：" << endl;
		array.print();


		delete[] input_array;
	}
	else //输入字符
	{
		char* input_array = new char[input_length];

		for (int i = 0; i < input_length; i++)
			cin >> input_array[i];

		Array<char> array(input_array, input_length);

		cout << "输入的 " << input_length << " 个元素为：" << endl;
		array.print();

		delete[] input_array;
	}

	return 1;
}