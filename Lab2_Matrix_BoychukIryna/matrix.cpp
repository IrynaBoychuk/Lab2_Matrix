#include "Matrix.h"
#include <iostream>

using namespace std;

Matrix::Matrix()
{
	size_row = 0;
	size_column = 0;
}



Matrix& Matrix::operator=(const Matrix& matrix)
{
	/*if(size_row != matrix.size_row 
		|| size_column != matrix.size_column)
		throw new exception("")*/
	//TODO подумати що робити з матрицями різного розміру
	for (int i = 0; i < matrix.size_row; i++)
	{
		for (int j = 0; j < matrix.size_column; j++)
			this->M[i][j] = matrix.M[i][j];

	}
	return *this;
}

Matrix& Matrix::operator=(const double& matrix)
{
	//TODO exception
	for (int i = 0; i < this->size_row; i++)
	{
		for (int j = 0; j < this->size_column; j++)
			this->M[i][j] = matrix;

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

Matrix Matrix::operator*(double & matrix)
{
	Matrix matrixTemp(this->size_row, this->size_column, 0);
	double k, m;
	for (int i = 0; i < this->size_row; i++)
	{
		for (int j = 0; j < this->size_column; j++)

		{
			m = this->M[i][j];
			k = m* matrix;
			matrixTemp.M[i][j] = k;
		}

	}
	return matrixTemp;
}

Matrix::Matrix(int m, int n, double c)
{
	size_row = m;
	size_column = n;
	M = new double*[size_row];
	if (c == 0)
	{
		for (int i = 0; i < size_row; i++)
			M[i] = new double[size_column] {};
	}
	else
		for (int i = 0; i < size_row; i++)
			M[i] = new double[size_column];

	for (int i = 0; i < size_row; i++)
	{
		for (int j = 0; j < size_column; j++)
			M[i][j] = c;
	}

}