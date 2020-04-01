#include <iostream>
#include <vector>
#include "PlayField.h"
#include "TreeNode.h"

using namespace std;


void fullDetour(TreeNode* tree, int* crossWinCount, int* noughtWinCount, int* drawWinCount)
{
	switch (tree->element.checkFieldStatus())
	{
		case(PlayField::fsCrossesWin):
			(*crossWinCount)++;
			break;
		case(PlayField::fsNoughtsWin):
			(*noughtWinCount)++;
			break;
		case(PlayField::fsDraw):
			(*drawWinCount)++;
			break;
		case(PlayField::fsInvalid):
			break;
		case(PlayField::fsNormal):
		{
			for (auto i : tree->element.getEmptyCells())
			{
				tree->addChild(&(tree->element.makeMove(i)));
				fullDetour(&tree->hair.back(), crossWinCount, noughtWinCount, drawWinCount);
			}
		}
	}
}

int main()
{
	int overallCrossWinsCount = 0,
		overallNoughtWinsCount = 0,
		overallDrawWinsCount = 0;
	PlayField field = PlayField();
	TreeNode tree = TreeNode(field);

	for (auto i : tree.element.getEmptyCells())
	{
		int crossWinCount = 0, 
			noughtWinCount = 0, 
			drawWinCount = 0;

		PlayField currentField = field.makeMove(i);
		tree.addChild(&currentField);
		currentField.printField();
		fullDetour(&tree.hair.back(), &crossWinCount, &noughtWinCount, &drawWinCount);
		cout << "\t" << "x = " << crossWinCount << " o = " << noughtWinCount << " d = " << drawWinCount << endl;
		overallCrossWinsCount += crossWinCount;
		overallNoughtWinsCount += noughtWinCount;
		overallDrawWinsCount += drawWinCount;
	}
	cout <<  "TOTAL x = " << overallCrossWinsCount << " o = " << overallNoughtWinsCount << " d = " << overallDrawWinsCount << endl;
	cout << "OVERALL = " << overallCrossWinsCount + overallNoughtWinsCount + overallDrawWinsCount;	
}