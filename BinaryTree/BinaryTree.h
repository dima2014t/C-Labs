#pragma once

#include <iostream>
#include "TreeNode.h"

class BinaryTree
{
public:
	BinaryTree();
	BinaryTree(int);
	~BinaryTree();
	void Insert(int);
	TreeNode* Search(int);
private:
	void Insert(TreeNode*, int);
	TreeNode* Search(TreeNode*, int) const;
	TreeNode* m_root = nullptr;
};
