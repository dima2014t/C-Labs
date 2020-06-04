#include <cassert>
#include "TreeNode.h"

using namespace std;

bool TreeNode::isTerminal() const
{
	PlayField::fieldStatus elementStatus = element.checkFieldStatus();
	return elementStatus == PlayField::fsCrossesWin ||
		elementStatus == PlayField::fsNoughtsWin ||
		elementStatus == PlayField::fsDraw;
}

int TreeNode::childQty() const
{
	if (m_parent)
		return m_parent->childQty() - 1;
	return element.getEmptyCells().size();
}

void TreeNode::addChild(TreeNode* node)
{
	assert(("at this level already the maximum number of descendants", childQty() > childCount()));
	node->m_parent = this;
	m_hair.push_back(node);
}

TreeNode& TreeNode::operator[](int index) const
{
	assert(("this node has no descendant with this index", childCount() > index));
	return *m_hair[index];
}

int TreeNode::childCount() const
{
	return m_hair.size();
}

const PlayField& TreeNode::value() const
{
	return element;
}

TreeNode::TreeNode(PlayField value)
	: element(value)
{}

TreeNode::~TreeNode()
{
	for (auto i : m_hair)
		delete i;
}
