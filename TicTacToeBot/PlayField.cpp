#include <iostream>
#include <cassert>
#include "PlayField.h"

using namespace std;

bool PlayField::CellPosition::inCorrectRange(int value) const
{
	return  value >= 0 && value < playFieldLineSize;
}

PlayField::CellPosition::CellPosition(int row, int column)
{
	setRow(row);
	setColumn(column);
}

PlayField::CellPosition::operator int() const
{
	return getRow() * playFieldLineSize + getColumn();
}

void PlayField::CellPosition::setRow(int iRow)
{
	assert(("incorrect row value", inCorrectRange(iRow)));
	m_row = iRow;
}

void PlayField::CellPosition::setColumn(int iColumn)
{
	assert(("incorrect column value", inCorrectRange(iColumn)));
	m_column = iColumn;
}

PlayField PlayField::makeMove(CellPosition position) const
{
	return *this + position;
}


PlayField::PlayField()
{
	for (int index = 0; index < playFieldSize; index++)
		playField[index] = csEmpty;
};


PlayField::cellValue PlayField::operator[] (CellPosition position) const
{
	int index = position;
	assert(("this cell is not on the playing field", (index >= 0 || index < playFieldSize)));
	return playField[index];
}

PlayField::fieldStatus PlayField::checkLineStatus(vector<cellValue>& line)
{
	for (auto i : line)
	{
		if (i != line[0] || i == csEmpty)
			return fsNormal;
	}
	if (line[0] == csCross)
		return fsCrossesWin;
	return fsNoughtsWin;

}

PlayField::fieldStatus PlayField::checkFieldStatus() const
{
	bool isCrossWin = false, isNoughtWin = false;
	vector<cellValue> firstDiagonal, secondDiagonal;
	for (int i = 0; i < playFieldLineSize; i++) {
		vector<cellValue> row, column;
		firstDiagonal.push_back((*this)[CellPosition(i, i)]);
		secondDiagonal.push_back((*this)[CellPosition(i, playFieldLineSize - 1 - i)]);
		for (int j = 0; j < playFieldLineSize; j++)
		{
			row.push_back((*this)[CellPosition(i, j)]);
			column.push_back((*this)[CellPosition(j, i)]);
		}	
		fieldStatus rowStatus = checkLineStatus(row);
		fieldStatus columnStatus = checkLineStatus(column);
		if (rowStatus == fsCrossesWin || columnStatus == fsCrossesWin)
			isCrossWin = true;
		else if (rowStatus == fsNoughtsWin || columnStatus == fsNoughtsWin)
			isNoughtWin = true;
	}
	fieldStatus firstDiagonalStatus = checkLineStatus(firstDiagonal);
	fieldStatus secondDiagonalStatus = checkLineStatus(secondDiagonal);
	if (firstDiagonalStatus == fsCrossesWin || secondDiagonalStatus == fsCrossesWin)
		isCrossWin = true;
	if (firstDiagonalStatus == fsNoughtsWin || secondDiagonalStatus == fsNoughtsWin)
		isNoughtWin = true;
	if (isCrossWin && isNoughtWin)
		return fsInvalid;
	if (isCrossWin)
		return fsCrossesWin;
	if (isNoughtWin)
		return fsNoughtsWin;
	for (auto cell : playField)
		if (cell == csEmpty)
			return fsNormal;
	return fsDraw;
}

vector<PlayField::CellPosition> PlayField::getEmptyCells() const
{
	vector<CellPosition> emptyCells;
	for (int row = 0; row < playFieldLineSize; row++)
	{
		for (int column = 0; column < playFieldLineSize; column++)
		{
			CellPosition position(CellPosition(row, column));
			if (playField[position] == csEmpty)
				emptyCells.push_back(position);
		}
	}
	return emptyCells;
}

void PlayField::printField()
{
	for (int index = 0; index < playFieldSize; index++)
	{
		switch (playField[index])
		{
		case (csCross):
			cout << "x";
			break;
		case (csNought):
			cout << "o";
			break;
		default:
			cout << " ";
			break;
		}
		if (index % playFieldLineSize == 2)
			cout << endl;
		else
			cout << "|";
	}
	cout << endl;
}

PlayField PlayField::operator+(CellPosition position) const
{
	assert(("the field is in an unplayable state", this->checkFieldStatus() == fsNormal));
	assert(("attempt to move to a filled cell", (*this)[position] == csEmpty));
	PlayField fieldCopy = *this;
	int crossCount = 0, noughtCount = 0;
	for (auto cell : playField)
	{
		switch (cell)
		{
		case csCross:
			crossCount++;
			break;
		case csNought:
			noughtCount++;
		}
	}
	switch (crossCount - noughtCount)
	{
	case -1:
		fieldCopy.playField[position] = csCross;
		break;
	case 0:
		fieldCopy.playField[position] = csCross;
		break;
	case 1:
		fieldCopy.playField[position] = csNought;
		break;
	default:
		assert("the field is in an unplayable state");
	}
	return fieldCopy;
}
