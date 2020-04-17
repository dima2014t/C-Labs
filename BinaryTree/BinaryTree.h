#pragma once
#include <iostream>
#include "TreeNode.h"

using namespace std;

class BinaryTree
{
public:
	BinaryTree();
	BinaryTree(TreeNode);
	void Insert(int);
	TreeNode* Search(int);
private:
	void Insert(TreeNode*, int);
	TreeNode* Search(TreeNode*, int) const;
	TreeNode m_root;
};
