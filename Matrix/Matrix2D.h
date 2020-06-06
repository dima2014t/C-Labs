#pragma once

#include "MatrixBase.h"

class Matrix2D : public MatrixBase
{
public:
	Matrix2D() : MatrixBase(m_dim) {};
	virtual int element(unsigned int, unsigned int) const override final;
	virtual int& element(unsigned int, unsigned int) override final;

private:
	static constexpr int m_dim = 2;
	int m_matrix[m_dim][m_dim];
}; 
