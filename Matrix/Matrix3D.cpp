#include <iostream>
#include "Matrix3D.h"

Matrix3D::Matrix3D()
	:MatrixBase(3)
{
	m_matrix = new int* [3];
	for (int i = 0; i < 3; i++)
		m_matrix[i] = new int[3];
}

int& Matrix3D::element(unsigned int i, unsigned int j)
{
	return m_matrix[i][j];
}

int Matrix3D::element(unsigned int i, unsigned int j) const
{
	return m_matrix[i][j];
}