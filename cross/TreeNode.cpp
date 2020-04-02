#include <iostream>
#include <vector>
#include <cassert>
#include "PlayField.h"
#include "TreeNode.h"

using namespace std;


bool TreeNode::isTerminal()
{
	return hair.size() == 0;
}

int TreeNode::childQty()
{
	return element.getEmptyCells().size();
}

void TreeNode::addChild(PlayField* field)
{
	TreeNode v = TreeNode(*field);
	assert(("at this level already the maximum number of descendants", childQty() > childCount()));
	hair.push_back(v);
}

TreeNode* TreeNode::operator[](int index)
{
	assert(("this node has no descendant with this index", childCount() > index));
	return &hair[index];
}

int TreeNode::childCount()
{
	return hair.size();
}

const PlayField* TreeNode::value()
{
	return &element;
}

TreeNode::TreeNode(PlayField value)
{
	element = value;
}
