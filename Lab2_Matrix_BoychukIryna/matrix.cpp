#include "Matrix.h"
#include <time.h>
#include <iostream>

using namespace std;

Matrix::Matrix()
{
	size_row = 0;
	size_column = 0;
}




Matrix& Matrix::operator=(const Matrix& matrix)
{
	
	for (int i = 0; i < matrix.size_row; i++)
	{
		for (int j = 0; j < matrix.size_column; j++)
			this->M[i][j] = matrix.M[i][j];

	}
	return *this;
}

Matrix& Matrix::operator=(const double& num)
{
	//TODO exception
	for (int i = 0; i < this->size_row; i++)
	{
		for (int j = 0; j < this->size_column; j++)
			this->M[i][j] = num;

	}
	return *this;
}


Matrix Matrix::operator +(Matrix & matrix)
{
	Matrix matrixTemp(matrix.size_row, matrix.size_column, 0);

	for (int i = 0; i < matrix.size_row; i++)
	{
		for (int j = 0; j < matrix.size_column; j++)

			matrixTemp.M[i][j] = this->M[i][j] + matrix.M[i][j];


	}
	return matrixTemp;
}

Matrix Matrix::operator -(Matrix & matrix)
{
	Matrix matrixTemp(matrix.size_row, matrix.size_column, 0);

	for (int i = 0; i < matrix.size_row; i++)
	{
		for (int j = 0; j < matrix.size_column; j++)

			matrixTemp.M[i][j] = this->M[i][j] - matrix.M[i][j];

	}
	return matrixTemp;
}

Matrix Matrix::operator*(Matrix & matrix)
{

	Matrix matrixTemp(matrix.size_row, matrix.size_column, 0);

	if (matrix.size_row == this->size_row && size_column == this->size_column)
	{
		for (int i = 0; i < size_row; i++)
		{
			for (int j = 0; j < matrix.size_column; j++)

				for (int k = 0; k < matrix.size_row; k++)
				{
					matrixTemp.M[i][j] += this->M[i][k] * matrix.M[k][j];
				}
		}
	}
	return matrixTemp;
}

Matrix Matrix::operator*(double num)
{
	Matrix matrixTemp(this->size_row, this->size_column, 0);
	double k, m;
	for (int i = 0; i < this->size_row; i++)
	{
		for (int j = 0; j < this->size_column; j++)

		{
			m = this->M[i][j];
			k = m * num;
			matrixTemp.M[i][j] = k;
		}

	}
	return matrixTemp;
}

Matrix::Matrix(int m, int n, bool fillRandom)
{
	size_row = m;
	size_column = n;
	//створення внутрішнього масиву
	M = new double*[size_row];
	for (int i = 0; i < size_row; i++)
		M[i] = new double[size_column] {};

	//Заповнення
	if (fillRandom)
	{
		srand(time(0));
		for (int i = 0; i < size_row; i++)
			for (int j = 0; j < size_column; j++)
				M[i][j] = abs(rand() % 10 + 1);
	}
	else 
	{
		cout << "Input Matrix:  ";
		for (int i = 0; i < size_row; i++)
			for (int j = 0; j < size_column; j++)
				cin >> M[i][j];
	}
}



Matrix operator~(Matrix matrix)
{
	int k = 0, n = 0;
	Matrix matrixTemp(matrix.size_row, matrix.size_column, 0);

	for (int i = 0; i < matrix.size_row; i++,n++)
	{
		k = 0;
		for (int j = 0; j<matrixTemp.size_column; j++,k++)
		{
			matrixTemp[j][i] = matrix[i][j];			
		}
	}
	return matrixTemp;
}

double* Matrix::operator[](int i)
{
	return M[i];
}

ostream & operator<<(ostream & os, const Matrix & that)
{
	for (int i = 0; i < that.size_row; i++)
	{
		os << '|';
		for (int j = 0; j < that.size_column; j++)
			os << that.M[i][j] << '\t';
		os << '|' << endl;

	}

	return os;
}

istream & operator>>(istream & os, const Matrix & matrix)
{
	for (int i = 0; i < matrix.size_row; i++)
	{

		for (int j = 0; j < matrix.size_column; j++)
			os >> matrix.M[i][j];


	}

	return os;
}

bool Matrix:: operator==(Matrix & matrix)
{
	for (int i = 0; i < matrix.size_row; i++)
	{
		for (int j = 0; j <matrix .size_column; j++)

			if (*this[i][j] != matrix[i][j])
			{
				return false;
			}

	}
	return true;
}

void Matrix::checkResult(Matrix task, Matrix answer) {
	for (int row = 0; row < task.size_rows(); row++)
	{
		double sum = 0;
		cout <<endl << "row " << row << endl;
		for (int column = 0; column < task.size_columns()-1; column++)
		{
			cout<< task[row][column] <<"*"<<answer[column][answer.size_columns() - 1] <<endl;
			sum += task[row][column] * answer[column][answer.size_columns() - 1];
		}
			cout << "sum " << sum << endl;
			cout << "task "<< task[row][task.size_columns() - 1]<<endl;
			cout << sum - task[row][task.size_columns() - 1] <<endl;
		if (sum != task[row][task.size_columns() - 1]) {
			cout << row << " error" << endl;
		}
	}
}

void Matrix::Gauss()
{
	int i = 0;
	int k = 1; 
	int j = 0;

	double y = 0;
	Matrix matrixTemp = *this;
	
	double a = 0;
	double b = 0;

	for (k = 1; k < size_row; k++)
	{
		for (i = k; i < size_row; i++)
		{
			y = matrixTemp[i][k - 1] / matrixTemp[k - 1][k - 1];
			for (j = 0; j < size_column; j++)
			{
				a = matrixTemp[i][j];
				b = matrixTemp[k - 1][j];
				matrixTemp[i][j] = a - b * y;
			}
		}
	}
	Matrix result = getGaussResult(matrixTemp);
	//cout << getGaussResult(matrixTemp)<< endl;
	//checkResult(*this, getGaussResult(matrixTemp));

	
		for (int row = 0; row < size_row; row++)
			cout << "x" << row+1 << "=" << result[row][size_column - 1] << endl;
}

Matrix Matrix::getGaussResult(Matrix matrixTemp) {
	for (int k = size_row-2; k >= 0; k--)
	{
		for (int i = k; i >=0; i--)
		{
			double y = matrixTemp[i][k + 1] / matrixTemp[k + 1][k + 1];
			for (int j = size_column-1 ; j>=0; j--)
			{
				double a = matrixTemp[i][j];
				double b = matrixTemp[k + 1][j];
				matrixTemp[i][j] = a - b * y;
			}
		}
	}

	double val = 0;
	for (int i = 0; i < size_row; i++)
	{
		val = matrixTemp[i][i];
		for (int j = 0; j < size_column; j++)
			if (matrixTemp[i][j] != 0)
				matrixTemp[i][j] = matrixTemp[i][j] / val;
	}

	return matrixTemp;
}

void Matrix :: swapRows(int row1, int row2)
{	
	int p;
	if (row1 != row2)
	{
		for (int j = 0; j < size_column; j++)
		{
			p = M[row1][j];
			M[row1][j] = M[row2][j];
			M[row2][j] = p;
		}
	}
}

//
int Matrix::argMax(int column)
{	
	int max = M[0][column];
	int rowMax=0;
	for (int selectRow= 1; selectRow < size_row; selectRow++)
	{
		if (max < M[selectRow][column])
		{
			max = M[selectRow][column];
			rowMax = selectRow;
		}
	}
	return rowMax;
}
























//Matrix Matrix::method_gaussa(Matrix b)
//{
//	double f;
//	for (int k = 0; k < N_size - 1; k++)
//	{
//		for (int i = k + 1; i < M_size; i++)
//		{
//			f = this->M[k][k] / this->M[i][k];
//			for (int j = 0; j <= N_size; j++)
//			{
//				this->M[i][j] = this->M[i][j] * f - this->M[k][j];
//
//			}
//			b[0][i] = b[0][i] * f - b[0][k];
//
//		}
//
//	}
//	Matrix temp(1, N_size, 0);
//	for (int i = M_size - 1; i > 0; i--)
//	{
//		temp[0][i] = b[0][i] / this->M[i][i];
//		for (int j = N_size - 1; j >= i; j--)
//		{
//			b.M[0][i - 1] = b[0][i - 1] - this->M[i - 1][j] * temp[0][j];
//
//		}
//	}
//	temp[0][0] = b[0][0] / this->M[0][0];
//
//	return temp;
//}

//int Matrix::MatrixRand()
//{
//
//	double* matrixTemp = new double*[this->size_row];
//	for (int i = 0; i < this->size_row; i++)
//		matrixTemp[i] = new double[this->size_column];
//
//	for (int i = 0; i < this->size_row; i++)
//	{
//		for (int j = 0; j < this->size_column; j++)
//			M[i][j] = (1 + rand() % 1000)*pow(-1, rand());
//	}
//
//}