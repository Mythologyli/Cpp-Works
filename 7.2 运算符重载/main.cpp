/*
�� Matrix ������ϣ�ʵ�֣�
1. ��������� >>��������������Ԫ��ֵ
2. ��������� <<�����ڰ����������Ԫ�أ�Ԫ����Ԫ��֮���ÿո�
�ָ�
3. һ������ + �ĳ�Ա����������ʵ��������������
4. һ������ - ����Ԫ����������ʵ��������������
*/


#include <iostream>


using namespace std;


class Matrix
{
private:
	int matrix[4][4];

public:
	Matrix(void); //���캯���������о���Ԫ�س�ʼ��Ϊ 1
	friend istream& operator>> (istream& input, Matrix& matrix);
	friend ostream& operator<< (ostream& output, Matrix matrix);
	Matrix operator+ (Matrix& matrix);
	friend Matrix operator- (Matrix& matrix_a, Matrix& matrix_b);
};


Matrix::Matrix(void) //���캯���������о���Ԫ�س�ʼ��Ϊ 1
{
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
			matrix[x][y] = 1;
}


istream& operator>> (istream& input, Matrix& matrix)
{
	for (int x = 0; x < 4; x++) //��������
	{
		for (int y = 0; y < 4; y++)
		{
			cout << "������ (" << x + 1 << ", " << y + 1 << ") ����������";
			input >> matrix.matrix[x][y];
		}
	}

	return input;
}


ostream& operator<< (ostream& output, Matrix matrix)
{
	output << "����Ϊ��" << endl;

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
	cout << "������������ϰ���������" << endl;
	cout << "���ߣ�Peisheng Li  ���ڣ�2021/01/24" << endl;

	Matrix matrix_1; //��һ������
	Matrix matrix_2; //�ڶ�������
	Matrix matrix_3; //�ڶ�������

	cout << "�����һ������" << endl;
	cin >> matrix_1;

	cout << "����ڶ�������" << endl;
	cin >> matrix_2;

	cout << matrix_1 + matrix_2;
	cout << matrix_1 - matrix_2;

	return 0;
}