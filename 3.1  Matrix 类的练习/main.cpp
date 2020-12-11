/*
编写 Matrix 类，要求私有成员变量为 int matrix[4][4]。主程序中生成两个 Matrix 对象。
要求第一个对象的值由构造函数设置，另一个对象的值由键盘输入。由构造函数设置时,矩阵元素全部为 1。
*/


#include <iostream>


using namespace std;


class Matrix
{
private:
	int matrix[4][4];

public:
	Matrix(void); //构造函数，将所有矩阵元素初始化为 1
	int Input(void); //输入矩阵元素。可选择是否使用默认设置
	void Output(void); //输出矩阵
};


Matrix::Matrix(void) //构造函数，将所有矩阵元素初始化为 1
{
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
			matrix[x][y] = 1;
}


int Matrix::Input(void) //输入矩阵元素。可选择是否使用默认设置
{
	cout << "是否将全部矩阵元素设置为默认值 1 ? (y/n)" << endl;

	char choice;
	cin >> choice;

	if (choice == 'y')
		return 0;
	
	for (int x = 0; x < 4; x++) //遍历输入
	{
		for (int y = 0; y < 4; y++)
		{
			cout << "请输入 (" << x + 1 << ", " << y + 1 << ") 处的整数：";
			cin >> matrix[x][y];
		}
	}

	return 1;
}


void Matrix::Output(void) //输出矩阵
{
	cout << "矩阵为：" << endl;
	
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			cout << matrix[x][y] << " ";
		}

		cout << endl;
	}
}
	

int main()
{
	cout << "本程序用于输入并显示矩阵" << endl;
	cout << "作者：Peisheng Li  日期：2020/12/10" << endl;
	
	Matrix matrix_1; //第一个对象

	cout << "建立第一个矩阵类对象" << endl;

	matrix_1.Input();
	matrix_1.Output();

	Matrix matrix_2; //第二个对象

	cout << "建立第二个矩阵类对象" << endl;

	matrix_2.Input();
	matrix_2.Output();

	return 1;
}