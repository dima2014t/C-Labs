#pragma once

class MatrixBase
{
public:
	MatrixBase() = delete;
	unsigned int size() const;
	virtual int element(unsigned int, unsigned int) const = 0;
	virtual int& element(unsigned int, unsigned int) = 0;
	void operator*=(int);
	void operator+=(MatrixBase&);
	friend std::ostream& operator<<(std::ostream&, const MatrixBase&);

protected:
	MatrixBase(unsigned int);
	int** m_matrix;

private:
	const unsigned int m_size;
};

std::ostream& operator<<(std::ostream& stream, const MatrixBase& iMatrix);
