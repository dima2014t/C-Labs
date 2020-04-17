#pragma once
#include <iostream>

using namespace std;

class TreeNode
{
public:
	TreeNode();
	TreeNode(int);
	~TreeNode();
	int getValue() const;
	void setValue(int);
	TreeNode* getLowerValueNode() const;
	void setLowerValueNode(TreeNode*);
	TreeNode* getHighValueNode() const;
	void setHighValueNode(TreeNode*);

private:
	int m_value;
	TreeNode* m_lowerValueNode;
	TreeNode* m_highValueNode;
};