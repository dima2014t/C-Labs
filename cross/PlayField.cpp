#include <iostream>
#include <vector>
#include <cassert>
#include "PlayField.h"

using namespace std;


bool PlayField::CellPosition::inCorrectRange(int value)
{
	return  value >= 0 && value <= 2;
}

PlayField::CellPosition::CellPosition(int row, int column)
{
	setRow(row);
	setColumn(column);
}

PlayField::CellPosition::CellPosition(int index)
{
	setRow(index / 3);
	setColumn(index % 3);
}

void PlayField::CellPosition::setRow(int row)
{
	assert(("uncorrect row value", inCorrectRange(row)));
	this->row = row;
}

int PlayField::CellPosition::getRow() { return row; };

void PlayField::CellPosition::setColumn(int column)
{
	assert(("uncorrect column value", inCorrectRange(column)));
	this->column = column;
}

int PlayField::CellPosition::getColumn() { return column; };


PlayField PlayField::makeMove(CellPosition position)
{
	return *this + position;
}


PlayField::PlayField()
{
	for (int index = 0; index < 9; index++)
		playField[index] = csEmpty;
};

PlayField::PlayField(int field[9])
{
	for (int index = 0; index < 9; index++)
		playField[index] = cellValue(field[index]);
};

PlayField::cellValue& PlayField::operator[] (CellPosition position)
{
	int index = position.getRow() * 3 + position.getColumn();
	assert(("this cell is not on the playing field", (index >= 0 || index <= 8)));
	return playField[index];
}

PlayField::fieldStatus PlayField::checkLineStatus(cellValue* firstCell, cellValue* secondCell, cellValue* thirdÑell)
{
	if (*firstCell == *secondCell && *secondCell == *thirdÑell && *secondCell != csEmpty)
	{
		if (*secondCell == csCross)
			return fsCrossesWin;
		return fsNoughtsWin;
	}
	return fsNormal;
}

PlayField::fieldStatus PlayField::checkFieldStatus()
{
	int cross = 0;
	int nought = 0;
	for (auto cell : playField)
	{
		switch (cell)
		{
		case(csCross):
			cross++;
			break;
		case(csNought):
			nought++;
			break;
		}
	}
	if (abs(cross - nought) >= 2)
		return fsInvalid;
	for (int index = 0; index < 7; index += 3)
	{
		fieldStatus lineStatus = checkLineStatus(&playField[index], &playField[index + 1], &playField[index + 2]);
		if (lineStatus != fsNormal)
			return lineStatus;
	}
	for (int index = 0; index < 3; index++)
	{
		fieldStatus lineStatus = checkLineStatus(&playField[index], &playField[index + 3], &playField[index + 6]);
		if (lineStatus != fsNormal)
			return lineStatus;
	}
	for (int index = 0; index < 3; index += 2)
	{
		fieldStatus lineStatus = checkLineStatus(&playField[index], &playField[4], &playField[8 - index]);
		if (lineStatus != fsNormal)
			return lineStatus;
	}
	for (int index = 0; index < 9; index++)
	{
		if (playField[index] == csEmpty)
			return fsNormal;
	}
	return fsDraw;
}

vector<PlayField::CellPosition> PlayField::getEmptyCells()
{
	vector<CellPosition> emptyCells;
	for (int i = 0; i < 9; i++)
	{
		if (playField[i] == csEmpty)
			emptyCells.push_back(PlayField::CellPosition(i));
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
	
PlayField PlayField::operator+(CellPosition position)
{
	PlayField fieldCopy = *this;
	assert(("attempt to move to a filled cell", fieldCopy[position] == csEmpty));
	fieldCopy[position] = nextMoveSymbol;
	if (fieldCopy.nextMoveSymbol == csCross)
		fieldCopy.nextMoveSymbol = csNought;
	else
		fieldCopy.nextMoveSymbol = csCross;
	return fieldCopy;
}
