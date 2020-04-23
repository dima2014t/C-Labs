#pragma once

#include <iostream>

class TreeNode
{
public:
	TreeNode();
	explicit TreeNode(int);
	~TreeNode();
	int getValue() const;
	void setValue(int);
	TreeNode* getLowerValueNode() const;
	void setLowerValueNode(TreeNode*);
	TreeNode* getHighValueNode() const;
	void setHighValueNode(TreeNode*);

private:
	int m_value = 0;
	TreeNode* m_lowerValueNode = nullptr;
	TreeNode* m_highValueNode = nullptr;
};