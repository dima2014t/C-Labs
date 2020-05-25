#pragma once

#include "MatrixBase.h"

class Matrix2D : public MatrixBase
{
public:
	Matrix2D();
	virtual int element(unsigned int, unsigned int) const;
	virtual int& element(unsigned int, unsigned int);
};