#include <iostream>
#include "Matrix2D.h"

int Matrix2D::element(unsigned int i, unsigned int j) const
{
	return m_matrix[i][j];
}

int& Matrix2D::element(unsigned int i, unsigned int j)
{
	return m_matrix[i][j];
}
