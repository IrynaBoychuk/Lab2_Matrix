#pragma once

#include<iostream>

using namespace std;

class Matrix
{
private:
	int size;
public:
	Matrix();
	Matrix& operator =(const Matrix& M);
	Matrix operator ==(Matrix & M);
	Matrix operator + (Matrix & M);
	Matrix operator - (Matrix & M);
	Matrix operator * (Matrix & M);
	//todo оператор обертання матриці
	// оператор вводу і виводу
	//	доступ до елемента
};
