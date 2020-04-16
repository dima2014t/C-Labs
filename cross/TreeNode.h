// ©Тарасов Дмитрий РИ-280001

#include <vector>
#include "PlayField.h"

using namespace std;

class TreeNode
{
public:
	TreeNode(PlayField);
	~TreeNode();
	bool isTerminal() const;
	int childCount() const;
	const PlayField& value() const;
	TreeNode& operator[](int) const;
	void addChild(TreeNode*);

private:
	int childQty() const;
	const PlayField element;
	vector<TreeNode*> m_hair;
	TreeNode* m_parent = 0;
};
