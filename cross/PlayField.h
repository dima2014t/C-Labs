// ©Тарасов Дмитрий РИ-280001

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
	fieldStatus checkLineStatus(cellValue, cellValue, cellValue) const;

	cellValue playField[9];
};
