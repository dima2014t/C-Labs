#include <iostream>
#include <vector>

using namespace std;


class TreeNode
{
public:
	PlayField element;
	vector<TreeNode> hair;
	bool isTerminal();
	void addChild(PlayField*);
	int childCount();
	const PlayField* value();
	TreeNode(PlayField);
	TreeNode* operator[](int);

private:
	int childQty();
};
