// ©Тарасов Дмитрий РИ-280001

#include <iostream>
#include <vector>
#include <cassert>
#include "PlayField.h"

using namespace std;

bool PlayField::CellPosition::inCorrectRange(int value) const
{
	return  value >= 0 && value <= 2;
}

PlayField::CellPosition::CellPosition(int row, int column)
{
	setRow(row);
	setColumn(column);
}

PlayField::CellPosition::operator int() const
{
	return getRow() * 3 + getColumn();
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
	for (int index = 0; index < 9; index++)
		playField[index] = csEmpty;
};


PlayField::cellValue PlayField::operator[] (CellPosition position) const
{
	int index = int(position);
	assert(("this cell is not on the playing field", (index >= 0 || index <= 8)));
	return playField[index];
}

PlayField::fieldStatus PlayField::checkLineStatus(cellValue firstCell, cellValue secondCell, cellValue thirdCell) const
{
	if (firstCell == secondCell && secondCell == thirdCell && secondCell != csEmpty)
	{
		if (secondCell == csCross)
			return fsCrossesWin;
		return fsNoughtsWin;
	}
	return fsNormal;
}

PlayField::fieldStatus PlayField::checkFieldStatus() const
{
	bool isCrossWin = false, isNoughtWin = false;
	for (int index = 0; index < 3; index++) {
		fieldStatus rowStatus = checkLineStatus((*this)[CellPosition(index, 0)], (*this)[CellPosition(index, 1)], (*this)[CellPosition(index, 2)]);
		fieldStatus columnStatus = checkLineStatus((*this)[CellPosition(0, index)], (*this)[CellPosition(1, index)], (*this)[CellPosition(2, index)]);
		if (rowStatus == fsCrossesWin || columnStatus == fsCrossesWin)
			isCrossWin = true;
		else if (rowStatus == fsNoughtsWin || columnStatus == fsNoughtsWin)
			isNoughtWin = true;
	}
	fieldStatus firstDiagonalStatus = checkLineStatus((*this)[CellPosition(0, 0)], (*this)[CellPosition(1, 1)], (*this)[CellPosition(2, 2)]);
	fieldStatus secondDiagonalStatus = checkLineStatus((*this)[CellPosition(0, 2)], (*this)[CellPosition(1, 1)], (*this)[CellPosition(2, 0)]);
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
	for (int i = 0; i < 9; i++)
	{
		if (playField[i] == csEmpty)
			emptyCells.push_back(PlayField::CellPosition(i / 3, i % 3));
	}
	return emptyCells;
}

void PlayField::printField()
{
	for (int index = 0; index < 9; index++)
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
		if (index % 3 == 2)
			cout << endl;
		else
			cout << "|";
	}
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
	fieldCopy.playField[int(position)] = crossCount > noughtCount ? csNought : csCross;
	return fieldCopy;
}
