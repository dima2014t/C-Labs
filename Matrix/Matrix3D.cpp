#include <iostream>
#include "Matrix3D.h"

int& Matrix3D::element(unsigned int i, unsigned int j)
{
	return m_matrix[i][j];
}

int Matrix3D::element(unsigned int i, unsigned int j) const
{
	return m_matrix[i][j];
}
