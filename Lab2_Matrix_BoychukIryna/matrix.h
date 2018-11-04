#pragma once

#include<iostream>

using namespace std;

class Matrix
{
private:
	double **M;
	int size_row, size_column;
public:
	Matrix();
	Matrix(int, int, double);// Конструктор, що відповідає за нульову матрицю
	Matrix& operator =(const Matrix& matrix);// матриці присвоюється повністю tелементи іншої матриці
	Matrix& operator =(const double& matrix); // елементи в матриці присвоюються по черзі
	Matrix operator ==(Matrix & matrix); // todo
	Matrix operator + (Matrix & matrix);
	Matrix operator - (Matrix & matrix);
	Matrix operator * (Matrix & matrix);// matrix*matrix
	Matrix operator * (double & matrix); // chislo
	//todo оператор обертання матриці
	// оператор вводу і виводу
	//	доступ до елемента
};
