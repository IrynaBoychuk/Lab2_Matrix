#include "Matrix.h"
#include <time.h>
#include <iostream>
#include <algorithm> 

using namespace std;



Matrix::Matrix()
{
	size_row = 0;
	size_column = 0;
}

Matrix::Matrix(int m, int n, FillMethod fillRandom)
{
	size_row = m;
	size_column = n;
	//створення внутрішнього масиву
	M = new double*[size_row];
	for (int i = 0; i < size_row; i++)
		M[i] = new double[size_column] {};
	double k = 0, a;
	//Заповнення
	switch (fillRandom)
	{
	case Random:
		srand(time(0));
		for (int i = 0; i < size_row; i++)
			for (int j = 0; j < size_column; j++)
				M[i][j] = abs(rand() % 10 + 1);
		break;
	case Gilbert:
		cout << "Input last column:  " << endl;
		for (int i = 0; i < size_row; i++)
		{
			cin >> a;
			M[i][size_column - 1] = a;
		}
		for (int i = 0; i < size_row; i++)
		{
			k = i + 1;
			for (int j = 0; j < size_column - 1; j++)
			{
				M[i][j] = 1 / k;
				k++;
			}

		}
		break;
	case Console:
		cout << "Input Matrix:  " << endl;
		for (int i = 0; i < size_row; i++) {
			for (int j = 0; j < size_column; j++) {
				cin >> M[i][j];
			}
		}
		break;
	default:
		for (int i = 0; i < size_row; i++)
			for (int j = 0; j < size_column; j++)
				M[i][j] = 0;
		break;
	}

}



Matrix& Matrix::operator=(const Matrix& matrix)
{
	if (this != &matrix)
	{

		for (int i = 0; i < matrix.size_row; i++)
		{
			for (int j = 0; j < matrix.size_column; j++)
				this->M[i][j] = matrix.M[i][j];

		}
	}
	return *this;
}

Matrix& Matrix::operator=(const double& num)
{
	for (int i = 0; i < this->size_row; i++)
	{
		for (int j = 0; j < this->size_column; j++)
			this->M[i][j] = num;

	}
	return *this;
}


Matrix Matrix::operator +(Matrix & matrix)
{
	if ((size_row == matrix.size_row) && (size_column == matrix.size_column))
	{
		Matrix matrixTemp(matrix.size_row, matrix.size_column, Zero);
		for (int i = 0; i < matrix.size_row; i++)
		{
			for (int j = 0; j < matrix.size_column; j++)

				matrixTemp.M[i][j] = this->M[i][j] + matrix.M[i][j];

		}
		return matrixTemp;
	}
	else
	{
		throw "It is impossible to do addition";
	}
}

Matrix Matrix::operator -(Matrix & matrix)
{
	Matrix matrixTemp(matrix.size_row, matrix.size_column, Zero);
	if ((size_row == this->size_row) && (size_column == this->size_column))
	{
		for (int i = 0; i < matrix.size_row; i++)
		{
			for (int j = 0; j < matrix.size_column; j++)

				matrixTemp.M[i][j] = this->M[i][j] - matrix.M[i][j];

		}
		return matrixTemp;
	}
	//TODO else
}


Matrix Matrix::operator*(Matrix & matrix)
{
	if (matrix.size_row == size_column)
	{
		Matrix matrixTemp(size_row, matrix.size_column, Zero);
		for (int i = 0; i < size_row; i++)
		{
			for (int j = 0; j < matrix.size_column; j++)

				for (int k = 0; k < matrix.size_row; k++)
				{
					matrixTemp.M[i][j] += this->M[i][k] * matrix.M[k][j];
				}
		}
		return matrixTemp;
	}
	else throw "It is impossible to multiply matrixes";
}

Matrix Matrix::operator*(double num) const
{
	Matrix matrixTemp(this->size_row, this->size_column, Zero);
	double k;
	for (int i = 0; i < this->size_row; i++)
	{
		for (int j = 0; j < this->size_column; j++)

		{
			k = this->M[i][j] * num;
			matrixTemp.M[i][j] = k;
		}

	}
	return matrixTemp;
}





Matrix operator~(Matrix &matrix)
{
	Matrix matrixTemp(matrix.size_column, matrix.size_row, Zero);
	for (int i = 0; i < matrix.size_row; i++)
	{
		for (int j = 0; j < matrix.size_column; j++)
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
	if (matrix.size_row != this->size_row && size_column != this->size_column)
		return false;
	for (int i = 0; i < matrix.size_row; i++)
	{
		for (int j = 0; j < matrix.size_column; j++)

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
		cout << endl << "row " << row << endl;
		for (int column = 0; column < task.size_columns() - 1; column++)
		{
			cout << task[row][column] << "*" << answer[column][answer.size_columns() - 1] << endl;
			sum += task[row][column] * answer[column][answer.size_columns() - 1];
		}
		cout << "sum " << sum << endl;
		cout << "task " << task[row][task.size_columns() - 1] << endl;
		cout << sum - task[row][task.size_columns() - 1] << endl;
		if (sum != task[row][task.size_columns() - 1]) {
			cout << row << " error" << endl;
		}
	}
}


bool Matrix::isSimmetrial()
{
	for (int i = 0; i < size_row; i++)
	{
		for (int j = 0; j < size_column; j++)
		{
			if (M[i][j] != M[j][i])
				return false;
		}
	}
	return true;
}

void Matrix::Gauss()
{
	if (size_column - size_row != 1)
		throw "Unsupported matrix size";
	int otherRow = 0;
	int currentRow = 1;
	int col = 0;

	double y = 0;
	Matrix matrixTemp = *this;

	double a = 0;
	double b = 0;

	for (currentRow = 0; currentRow < size_row; currentRow++)
	{
		swapRows(currentRow, argMax(currentRow));
		for (otherRow = currentRow + 1; otherRow < size_row; otherRow++)
		{
			y = matrixTemp[otherRow][currentRow] / matrixTemp[currentRow][currentRow];
			for (col = 0; col < size_column; col++)
			{
				a = matrixTemp[otherRow][col];
				b = matrixTemp[currentRow][col];
				matrixTemp[otherRow][col] = a - b * y;
			}
		}
	}
	cout << matrixTemp;
	Matrix result = getGaussResult(matrixTemp);

	for (int row = 0; row < size_column - 1; row++)
		cout << "x" << row + 1 << "=" << result[row][size_column - 1] << endl;
}

Matrix Matrix::getGaussResult(Matrix &matrixTemp) {
	for (int k = size_row - 2; k >= 0; k--)
	{
		for (int i = k; i >= 0; i--)
		{
			double y = matrixTemp[i][k + 1] / matrixTemp[k + 1][k + 1];
			for (int j = size_column - 1; j >= 0; j--)
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

void Matrix::swapRows(int row1, int row2)
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
	int max = M[column][column];
	int rowMax = column;
	for (int selectRow = column + 1; selectRow < size_row; selectRow++)
	{
		if (max < M[selectRow][column])
		{
			max = M[selectRow][column];
			rowMax = selectRow;
		}
	}
	return rowMax;
}

void Matrix::deleteColumn(int num_column)
{
	for (int i = 0; i < size_row; i++)
	{
		for (int j = num_column - 1; j < size_column - 1; j++)
		{
			M[i][j] = M[i][j + 1];
		}
	}
	--size_column;
}

//TODO хз поки для чого
double Matrix::Norma()
{
	double temp = 0;
	for (int j = 0; j < size_column; j++)
	{
		temp += M[0][j] * M[0][j];
	}
	return sqrt(temp);
}

double Matrix::scalMultiplication(Matrix &other)
{
	double temp = 0;
	for (int j = 0; j < size_column; j++)
		temp += M[0][j] * other.M[0][j];
	return temp;
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