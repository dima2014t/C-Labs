// ©Тарасов Дмитрий РИ-280001

#include <vector>
#include <cassert>
#include "PlayField.h";
#include "TreeNode.h";

using namespace std;


bool TreeNode::isTerminal() const
{
	PlayField::fieldStatus elementStatus = element.checkFieldStatus();
	return elementStatus != PlayField::fsInvalid && elementStatus != PlayField::fsNormal;
}

int TreeNode::childQty() const
{
	return element.getEmptyCells().size();
}

void TreeNode::addChild(TreeNode node)
{
	assert(("at this level already the maximum number of descendants", childQty() > childCount()));
	m_hair.push_back(&node);
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

TreeNode::TreeNode(PlayField value, TreeNode* iParent)
	: element(value)
{
	m_parent = iParent;
}
