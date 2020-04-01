#include <iostream>
#include <vector>

using namespace std;


class PlayField
{
public:
	class CellPosition
	{
	private:
		int row;
		int column;

		bool inCorrectRange(int);

	public:
		CellPosition(int, int);
		CellPosition(int);
		void setRow(int);
		int getRow();
		void setColumn(int);
		int getColumn();
	};

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

	cellValue playField[9];
	cellValue nextMoveSymbol = csCross;

	PlayField();
	PlayField(int[9]);

	cellValue& operator[] (CellPosition);
	fieldStatus checkFieldStatus();
	PlayField makeMove(CellPosition);
	vector<CellPosition> getEmptyCells();
	void printField();

private:
	PlayField operator+(CellPosition position);
	fieldStatus checkLineStatus(cellValue*, cellValue*, cellValue*);
};
