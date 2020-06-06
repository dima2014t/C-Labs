#pragma once

#include "MatrixBase.h"

class Matrix3D : public MatrixBase
{
public:
	Matrix3D() : MatrixBase(m_dim) {};
	virtual int element(unsigned int, unsigned int) const override final;
	virtual int& element(unsigned int, unsigned int) override final;

private:
	static constexpr int m_dim = 3;
	int m_matrix[m_dim][m_dim];
};
