#include <iostream>
#include "TreeNode.h"

using namespace std;

TreeNode::TreeNode()
{
	m_value = 0;
	m_lowerValueNode = nullptr;
	m_highValueNode = nullptr;
}

TreeNode::TreeNode(int value)
{
	m_value = value;
	m_lowerValueNode = nullptr;
	m_highValueNode = nullptr;
}

TreeNode::~TreeNode()
{
	delete m_lowerValueNode;
	delete m_highValueNode;
}
	
int TreeNode::getValue() const
{
	return m_value;
}

void TreeNode::setValue(int value)
{
	m_value = value;
}

TreeNode* TreeNode::getLowerValueNode() const
{
	return m_lowerValueNode;
}

void TreeNode::setLowerValueNode(TreeNode* value)
{
	m_lowerValueNode = value;
}

TreeNode* TreeNode::getHighValueNode() const
{
	return m_highValueNode;
}

void TreeNode::setHighValueNode(TreeNode* value)
{
	m_highValueNode = value;
}
