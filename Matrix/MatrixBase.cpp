#include <iostream>
#include "MatrixBase.h"

MatrixBase::MatrixBase(unsigned int iSize)
	:m_size(iSize)
{}

unsigned int MatrixBase::size() const
{
	return m_size;
}

MatrixBase& MatrixBase::operator*=(int iMult)
{
	for (int i = 0; i < m_size; i++)
		for (int j = 0; j < m_size; j++)
			element(i, j) *= iMult;
	return *this;
}

MatrixBase& MatrixBase::operator+=(const MatrixBase& iMatrix)
{
	for (int i = 0; i < m_size; i++)
		for (int j = 0; j < m_size; j++)
			element(i, j) += iMatrix.element(i, j);
	return *this;
}

std::ostream& operator<<(std::ostream& stream, const MatrixBase& iMatrix)
{
	for (int i = 0; i < iMatrix.m_size; i++)
	{
		for (int j = 0; j < iMatrix.m_size; j++)
		{
			stream << iMatrix.element(i, j);
			if (j < iMatrix.m_size - 1)
				stream << "|";
		}
		stream << std::endl;
	}
	return stream;
}
