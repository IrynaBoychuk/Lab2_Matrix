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
	Matrix(int, int, double);// �����������, �� ������� �� ������� �������
	Matrix& operator =(const Matrix& matrix);// ������� ������������ ������� t�������� ���� �������
	Matrix& operator =(const double& matrix); // �������� � ������� ������������ �� ����
	Matrix operator ==(Matrix & matrix); // todo
	Matrix operator + (Matrix & matrix);
	Matrix operator - (Matrix & matrix);
	Matrix operator * (Matrix & matrix);// matrix*matrix
	Matrix operator * (double & matrix); // chislo
	//todo �������� ��������� �������
	// �������� ����� � ������
	//	������ �� ��������
};
