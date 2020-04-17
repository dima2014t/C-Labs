#include <iostream>
#include "TreeNode.h"
#include "BinaryTree.h"

using namespace std;

BinaryTree::BinaryTree()
{
	m_root = TreeNode();
};

BinaryTree::BinaryTree(TreeNode value)
{
	m_root = value;
};

void BinaryTree::Insert(TreeNode* node, int value)
{
	TreeNode* (TreeNode::*getSubNode)()const;
	void (TreeNode::*setSubNode)(TreeNode*);
	if (node->getValue() < value)
	{
		getSubNode = &TreeNode::getHighValueNode;
		setSubNode = &TreeNode::setHighValueNode;		
	}
	else
	{
		getSubNode = &TreeNode::getLowerValueNode;
		setSubNode = &TreeNode::setLowerValueNode;
	}
	TreeNode* subnode = (node->*getSubNode)();
	if (subnode)
		Insert(subnode, value);
	else
		(node->*setSubNode)(new TreeNode(value));
}

void BinaryTree::Insert(int value)
{
	Insert(&m_root, value);
}

TreeNode* BinaryTree::Search(int value)
{
	return Search(&m_root, value);
}

TreeNode* BinaryTree::Search(TreeNode* node, int value) const
{
	int nodeValue = node->getValue();
	if (value == nodeValue)
		return node;
	else if (value > node->getValue())
		return Search(node->getHighValueNode(), value);
	else
		return Search(node->getLowerValueNode(), value);
}
