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

	Matrix& operator =(const Matrix& matrix);// матриці присвоюється повністю елементи іншої матриці
	Matrix& operator =(const double& num); // матриця заповнюється однаковим числом
	bool operator ==(Matrix & matrix); // todo
	Matrix operator + (Matrix & matrix);
	Matrix operator - (Matrix & matrix);
	Matrix operator * (Matrix & matrix);// matrix*matrix
	Matrix operator * (double num) const; // matrix*num
	friend ostream & operator<<(ostream & os, const Matrix & that);
	friend istream & operator>>(istream & os, const Matrix & that);
	friend Matrix operator ~(Matrix &matrix);
	double* operator [](int); //	доступ до елемента
	//TODO
	double scalMultiplication(Matrix &matrix);

    void Gauss();
	//void Kachmag();
	Matrix getGaussResult(Matrix &upper); //
	bool isSimmetrial();
	double Norma(); // для КАчмажа
	void deleteColumn(int);  // для КАчмажа
	void swapRows(int, int);
	int argMax(int k);
	int size_rows() { return size_row; };
	int size_columns() { return size_column; };
	void checkResult(Matrix task, Matrix answer);
};


