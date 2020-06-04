#include <iostream>
#include "MatrixBase.h"

MatrixBase::MatrixBase(unsigned int iSize)
	:m_size(iSize)
{}

unsigned int MatrixBase::size() const
{
	return m_size;
}

void MatrixBase::operator*=(int iMult)
{
	for (int i = 0; i < m_size; i++)
		for (int j = 0; j < m_size; j++)
			this->element(i, j) *= iMult;
}

void MatrixBase::operator+=(MatrixBase& iAdd)
{
	for (int i = 0; i < m_size; i++)
		for (int j = 0; j < m_size; j++)
			this->element(i, j) += iAdd.element(i, j);
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
