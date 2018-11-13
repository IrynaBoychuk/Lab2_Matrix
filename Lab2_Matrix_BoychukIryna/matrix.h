#pragma once

#include<iostream>

using namespace std;
enum FillMethod {
	Zero=0,
	Random=1,
	Console=2,
	Gilbert=3,
	Number = 4
};


class Matrix
{
private:
	double **M;
	int size_row, size_column;
public:
	Matrix();
	Matrix(int m, int n): Matrix( m,  n, Zero){}
	Matrix(int m, int n, FillMethod fillMethod = FillMethod::Zero, double fillNumber = 0);

	Matrix& operator =(const Matrix& matrix);
	Matrix& operator =(const double& num); 
	bool operator ==(Matrix & matrix); 
	Matrix operator + (Matrix & matrix);
	Matrix operator - (Matrix & matrix);
	Matrix operator * (Matrix & matrix);
	Matrix operator * (double num) const; 
	friend ostream & operator<<(ostream & os, const Matrix & that);
	friend istream & operator>>(istream & os, const Matrix & that);
	friend Matrix operator ~(Matrix &matrix);
	double* operator [](int); //	доступ до елемента
	
	double scalMultiplication(Matrix &matrix);
    void Gauss();
	Matrix Kachmag();
	Matrix getGaussResult(Matrix &upper); //
	bool isSimmetrial();
	double Norma(); // для Качмажа
	void deleteColumn(int);  // для КАчмажа
	double* getRow(int);
	double* getColumn(int);
	void swapRows(int, int);
	int argMax(int k);
	int size_rows() { return size_row; };
	int size_columns() { return size_column; };
	//void checkResult(Matrix task, Matrix answer);
};


