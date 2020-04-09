// ©Тарасов Дмитрий РИ-280001

#include <vector>

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

	vector<TreeNode*> m_hair;
	TreeNode* m_parent = 0;

private:
	TreeNode(const TreeNode&);
	int childQty() const;
	const PlayField element;
};
