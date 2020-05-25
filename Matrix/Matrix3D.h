#pragma once

#include "MatrixBase.h"

class Matrix3D : public MatrixBase
{
public:
	Matrix3D();
	virtual int element(unsigned int, unsigned int) const;
	virtual int& element(unsigned int, unsigned int);
};
