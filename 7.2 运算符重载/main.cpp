/*
在 Matrix 类基础上，实现：
1. 重载运算符 >>，用于输入矩阵的元素值
2. 重载运算符 <<，用于按行输出矩阵元素，元素与元素之间用空格
分隔
3. 一个重载 + 的成员函数，用于实现两个矩阵的相加
4. 一个重载 - 的友元函数，用于实现两个矩阵的相减
*/


#include <iostream>


using namespace std;


class Matrix
{
private:
	int matrix[4][4];

public:
	Matrix(void); //构造函数，将所有矩阵元素初始化为 1
	friend istream& operator>> (istream& input, Matrix& matrix);
	friend ostream& operator<< (ostream& output, Matrix matrix);
	Matrix operator+ (Matrix& matrix);
	friend Matrix operator- (Matrix& matrix_a, Matrix& matrix_b);
};


Matrix::Matrix(void) //构造函数，将所有矩阵元素初始化为 1
{
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
			matrix[x][y] = 1;
}


istream& operator>> (istream& input, Matrix& matrix)
{
	for (int x = 0; x < 4; x++) //遍历输入
	{
		for (int y = 0; y < 4; y++)
		{
			cout << "请输入 (" << x + 1 << ", " << y + 1 << ") 处的整数：";
			input >> matrix.matrix[x][y];
		}
	}

	return input;
}


ostream& operator<< (ostream& output, Matrix matrix)
{
	output << "矩阵为：" << endl;

	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			output << matrix.matrix[x][y] << " ";
		}

		output << endl;
	}

	return output;
}


Matrix Matrix::operator+ (Matrix& matrix)
{
	Matrix sum;

	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			sum.matrix[x][y] = this->matrix[x][y] + matrix.matrix[x][y];
		}
	}

	return sum;
}


Matrix operator- (Matrix& matrix_a, Matrix& matrix_b)
{
	Matrix difference;

	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			difference.matrix[x][y] = matrix_a.matrix[x][y] - matrix_b.matrix[x][y];
		}
	}

	return difference;
}


int main()
{
	cout << "本程序用于练习运算符重载" << endl;
	cout << "作者：Peisheng Li  日期：2021/01/24" << endl;

	Matrix matrix_1; //第一个对象
	Matrix matrix_2; //第二个对象
	Matrix matrix_3; //第二个对象

	cout << "输入第一个矩阵：" << endl;
	cin >> matrix_1;

	cout << "输入第二个矩阵：" << endl;
	cin >> matrix_2;

	cout << matrix_1 + matrix_2;
	cout << matrix_1 - matrix_2;

	return 0;
}