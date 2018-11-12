#include<iostream>
#include"matrix.h"

void TestOperators() {
	Matrix FirstMatrix(5, 5, Random);
	Matrix SecondMatrix(5, 5, Random);

	cout << FirstMatrix << endl;

	cout << SecondMatrix << endl;;

	Matrix y = FirstMatrix * -1.0;
	cout << y << endl;

	Matrix x = ~FirstMatrix;
	cout << x << endl;

}

using namespace std;
int main()
{
	try
	{
		Matrix FirstMatrix(3, 4, Random);
		Matrix SecondMatrix(4, 4, Random);
		cout << FirstMatrix << endl;
		cout << ~FirstMatrix << endl;
		cout << SecondMatrix << endl;
		cout << FirstMatrix * SecondMatrix << endl;


		FirstMatrix.Gauss();
		//TestOperators();
	}
	catch (char* ex)
	{
		cout << "Mistake:" << ex;
	}
	
	system("pause");
	return 0;
}