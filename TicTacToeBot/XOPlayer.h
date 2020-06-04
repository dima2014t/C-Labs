#pragma once

#include "TreeNode.h"

class XOPlayer
{
public:
	XOPlayer(TreeNode&, PlayField::cellValue);
	PlayField::cellValue selectPlayer() const;
	void makeMove(PlayField::CellPosition iCell);
	void makeMove();
	PlayField currentState() const;
	PlayField::fieldStatus fieldStatus() const;

private:
	TreeNode& m_tree;
	TreeNode* m_currentState;
	PlayField::cellValue m_botSymbol;
};
