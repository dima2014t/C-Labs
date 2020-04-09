// ©Тарасов Дмитрий РИ-280001

#include <iostream>
#include <vector>
#include "PlayField.h"
#include "TreeNode.h"

using namespace std;

void fullDetour(TreeNode &tree, int &crossWinCount, int &noughtWinCount, int &drawWinCount)
{
	switch (tree.value().checkFieldStatus())
	{
		case(PlayField::fsCrossesWin):
			(crossWinCount)++;
			break;
		case(PlayField::fsNoughtsWin):
			(noughtWinCount)++;
			break;
		case(PlayField::fsDraw):
			(drawWinCount)++;
			break;
		case(PlayField::fsNormal):
		{
			for (auto i : tree.value().getEmptyCells())
			{
				TreeNode child{ tree.value().makeMove(i) };
				tree.addChild(&child);
				fullDetour(child, crossWinCount, noughtWinCount, drawWinCount);
			}
		}
	}
}

int main()
{
	int overallCrossWinsCount = 0,
		overallNoughtWinsCount = 0,
		overallDrawWinsCount = 0;
	TreeNode tree{ PlayField() };

	for (auto i : tree.value().getEmptyCells())
	{
		int crossWinCount = 0, 
			noughtWinCount = 0, 
			drawWinCount = 0;

		PlayField currentField = tree.value().makeMove(i);
		TreeNode child{ currentField };
		tree.addChild(&child);
		currentField.printField();
		fullDetour(*tree.m_hair.back(), crossWinCount, noughtWinCount, drawWinCount);
		cout << "\t" << "x = " << crossWinCount << " o = " << noughtWinCount << " d = " << drawWinCount << endl;
		overallCrossWinsCount += crossWinCount;
		overallNoughtWinsCount += noughtWinCount;
		overallDrawWinsCount += drawWinCount;
	}
	cout <<  "TOTAL x = " << overallCrossWinsCount << " o = " << overallNoughtWinsCount << " d = " << overallDrawWinsCount << endl;
	cout << "OVERALL = " << overallCrossWinsCount + overallNoughtWinsCount + overallDrawWinsCount;	
}
