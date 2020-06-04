#pragma once

#include "MatrixBase.h"

class Matrix2D : public MatrixBase
{
public:
	Matrix2D() : MatrixBase(m_dim) {};
	virtual int element(unsigned int, unsigned int) const override;
	virtual int& element(unsigned int, unsigned int) override;

private:
	static constexpr int m_dim = 2;
	int m_matrix[m_dim][m_dim];
}; 
