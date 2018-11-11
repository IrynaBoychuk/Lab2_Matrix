#pragma once

#include<iostream>

using namespace std;
enum FillMethod {
	Zero=0,
	Random=1,
	Console=2,
	Gilbert=3
};


class Matrix
{
private:
	double **M;
	int size_row, size_column;
public:
	Matrix();
	Matrix(int m, int n): Matrix( m,  n, Zero){}
	Matrix(int, int, FillMethod);

	Matrix& operator =(const Matrix& matrix);// матриц≥ присвоюЇтьс€ повн≥стю елементи ≥ншоњ матриц≥
	Matrix& operator =(const double& num); // матриц€ заповнюЇтьс€ однаковим числом
	bool operator ==(Matrix & matrix); // todo
	Matrix operator + (Matrix & matrix);
	Matrix operator - (Matrix & matrix);
	Matrix operator * (Matrix & matrix);// matrix*matrix
	Matrix operator * (double num); // matrix*num

	friend Matrix operator ~(Matrix matrix);
	double* operator [](int); //	доступ до елемента
    void Gauss();
	Matrix Matrix::getGaussResult(Matrix upper); //лишаЇ т≥льки головну д≥агональ

	friend ostream & operator<<(ostream & os, const Matrix & that);
	friend istream & operator>>(istream & os, const Matrix & that);
	void swapRows(int, int);
	int argMax(int k);
	int size_rows() { return size_row; };
	int size_columns() { return size_column; };
	void checkResult(Matrix task, Matrix answer);
};


