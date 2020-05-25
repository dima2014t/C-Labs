#include <iostream>
#include "Matrix2D.h"
#include "Matrix3D.h"

using namespace std;

void fillingArray(MatrixBase& matrix)
{
	for (int i = 0; i < matrix.size(); i++)
		for (int j = 0; j < matrix.size(); j++)
			matrix.element(i, j) = i * matrix.size() + j + 1;
}

int main()
{
	Matrix2D m2a, m2b;
	Matrix3D m3a, m3b;

	fillingArray(m2a);
	fillingArray(m2b);
	fillingArray(m3a);
	fillingArray(m3b);

	cout << "m2a:" << endl << m2a << endl;
	cout << "m3a:" << endl << m3a << endl;
	cout << "m2b:" << endl << m2b << endl;
	cout << "m3b:" << endl << m3a << endl;

	m2b *= 2;
	cout << "m2b *= 2:" << endl << m2b << endl;
	m3b *= 3;
	cout << "m3b *= 3:" << endl << m3b << endl;
	m2a += m2b;
	cout << "m2a += m2b:" << endl << m2a << endl;
	m3a += m3b;
	cout << "m3a += m3b:" << endl << m3a << endl;

	return 0;
}
