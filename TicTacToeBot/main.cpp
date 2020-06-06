#include <iostream>
#include "XOPlayer.h"

using namespace std;

void fullDetour(TreeNode& tree)
{
	switch (tree.value().checkFieldStatus())
	{
	case(PlayField::fsCrossesWin):
		tree.setWinCount(WinCount(1, 0, 0));
		break;
	case(PlayField::fsNoughtsWin):
		tree.setWinCount(WinCount(0, 1, 0));
		break;
	case(PlayField::fsDraw):
		tree.setWinCount(WinCount(0, 0, 1));
		break;
	case(PlayField::fsNormal):
	{
		for (auto i : tree.value().getEmptyCells())
		{
			TreeNode* child = new TreeNode(tree.value().makeMove(i));
			tree.addChild(child);
			fullDetour(*child);
			tree.getWinCount() += child->getWinCount();
		}
	}
	}
}

void playerMove(XOPlayer& player)
{
	while (true)
	{
		cout << "Enter the coordinate of your move:";
		int row, column;
		cin >> row >> column;
		auto cell = PlayField::CellPosition(row, column);
		if (player.currentState()[cell] == PlayField::csEmpty)
		{
			player.makeMove(cell);
			break;
		}
		else
			cout << "This cell is already taken" << endl;
	}
	player.currentState().printField();
}

void botMove(XOPlayer& player)
{
	cout << "The bot makes its move:" << endl;
	player.makeMove();
	player.currentState().printField();
}

int main()
{
	auto tree = TreeNode(PlayField());
	fullDetour(tree);
	cout << "Select player (0 - Xs, 1 - Os)" << std::endl;
	int sel_player;
	cin >> sel_player;
	XOPlayer player = XOPlayer(tree, (sel_player == 1 ? PlayField::csCross : PlayField::csNought));
	void (*move)(XOPlayer&) = sel_player == 1 ? botMove : playerMove;

	do 
	{
		move(player);
		move = (move == botMove) ? playerMove : botMove;
	} while (player.fieldStatus() == PlayField::fsNormal);

	cout << "The game is over with the result: ";
	switch (player.fieldStatus())
	{
	case(PlayField::fsCrossesWin):
		cout << "crosses won!!!";
		break;
	case(PlayField::fsNoughtsWin):
		cout << "nought won!!!";
		break;
	case(PlayField::fsDraw):
		cout << "draw!!!";
		break;
	default:
		cout << "unexpected error";
		break;
	}

	return 0;
}
