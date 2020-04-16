// ©Тарасов Дмитрий РИ-280001

#pragma once
#include <vector>

using namespace std;

class PlayField
{
public:
	enum fieldStatus
	{
		fsInvalid,
		fsNormal,
		fsCrossesWin,
		fsNoughtsWin,
		fsDraw,
	};
	enum cellValue
	{
		csEmpty,
		csCross,
		csNought
	};

	class CellPosition
	{
	public:
		CellPosition(int, int);
		operator int() const;
		void setRow(int);
		int getRow() const { return m_row; };
		void setColumn(int);
		int getColumn() const { return m_column; };

	private:
		bool inCorrectRange(int) const;
		int m_row;
		int m_column;
	};

	PlayField();
	cellValue operator[] (CellPosition) const;
	fieldStatus checkFieldStatus() const;
	PlayField makeMove(CellPosition) const;
	vector<CellPosition> getEmptyCells() const;
	void printField();

private:
	PlayField operator+(CellPosition position) const;
	static fieldStatus checkLineStatus(cellValue, cellValue, cellValue);

	static const int playFieldSize = 9;
	static const int playFieldLineSize = 3;
	cellValue playField[playFieldSize];
};
