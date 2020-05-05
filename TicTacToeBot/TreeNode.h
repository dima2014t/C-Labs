#pragma once

#include <vector>
#include "PlayField.h"
#include "WinCount.h"

class TreeNode
{
public:
	TreeNode(PlayField);
	~TreeNode();
	bool isTerminal() const;
	int childCount() const;
	const PlayField& value() const;
	TreeNode& operator[](int) const;
	void addChild(TreeNode*);
	WinCount winCount = WinCount();

private:
	int childQty() const;
	const PlayField element;
	std::vector<TreeNode*> m_hair;
	TreeNode* m_parent = 0;
};
