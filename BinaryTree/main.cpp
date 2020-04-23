#include <iostream>
#include "BinaryTree.h"

using namespace std;

void CreateBts(BinaryTree& tree, int* start, int startIndex, int endIndex)
{
	int averageIndex = (startIndex + endIndex) / 2;
	tree.Insert(*(start + averageIndex));
	if (startIndex <= averageIndex - 1)
		CreateBts(tree, start, startIndex, averageIndex - 1);
	if (averageIndex + 1 <= endIndex)
		CreateBts(tree, start, averageIndex + 1, endIndex);
}

BinaryTree* CreateMinimalBST(int* start, int startIndex, int endIndex)
{
	int averageIndex = (startIndex + endIndex) / 2;
	BinaryTree* tree = new BinaryTree(*(start + averageIndex));
	if (startIndex <= endIndex - 1)
		CreateBts(*tree, start, startIndex, averageIndex - 1);
	if (averageIndex + 1 <= endIndex)
		CreateBts(*tree, start, averageIndex + 1, endIndex);
	return tree;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	BinaryTree* tree = CreateMinimalBST(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	TreeNode* node = tree->Search(7);
	cout << node << endl << node->getValue();
	return 0;
}
