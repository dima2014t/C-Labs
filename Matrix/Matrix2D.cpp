#include <iostream>
#include "Matrix2D.h"

Matrix2D::Matrix2D()
	:MatrixBase(2)
{
	m_matrix = new int*[2];
	for (int i = 0; i < 2; i++)
		m_matrix[i] = new int[2];
}

int Matrix2D::element(unsigned int i, unsigned int j) const
{
	return m_matrix[i][j];
}

int& Matrix2D::element(unsigned int i, unsigned int j)
{
	return m_matrix[i][j];
}