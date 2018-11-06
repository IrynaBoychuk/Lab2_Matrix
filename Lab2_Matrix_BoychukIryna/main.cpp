#include<iostream>
#include"matrix.h"

void TestOperators() {
	Matrix FirstMatrix(5, 5, true);
	Matrix SecondMatrix(5, 5, true);

	cout << FirstMatrix << endl;

	cout << SecondMatrix << endl;;

	Matrix y = FirstMatrix * -1.0;
	cout << y << endl;

	Matrix x = ~FirstMatrix;
	cout << x << endl;

}

int main()
{
	Matrix FirstMatrix(5, 6, true);

	cout << FirstMatrix << endl;
	FirstMatrix.Gauss();
	//TestOperators();
	system("pause");
	return 0;
}