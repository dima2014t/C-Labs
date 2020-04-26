#include <iostream>
#include "QuickSort.h"
#include <vector>

using namespace std;

void recursiveQuickSort(int* array, int start, int end)
{
	int pivot = array[(start + end) / 2];
	int low = start;
	int high = end;
	int temp;
	while (low <= high)
	{
		while (array[low] < pivot)
			low++;
		while (array[high] > pivot)
			high--;
		if (low <= high)
		{
			temp = array[low];
			array[low] = array[high];
			array[high] = temp;
			low++;
			high--;
		}
	}
	if (high > start)
		recursiveQuickSort(array, start, high);
	if (low < end)
		recursiveQuickSort(array, low, end);
}

class Borders
{
public:
	Borders(int left, int right)
	{
		m_left = left;
		m_right = right;
	}
	int m_left;
	int m_right;
private:
};

void quickSort(int* array, int start, int end)
{
	vector<Borders> queue;
	queue.push_back(Borders(start, end));
	while (queue.size() > 0)
	{
		Borders board = queue.back();
		queue.pop_back();
		int low = board.m_left;
		int high = board.m_right;
		int pivot = array[(low + high) / 2];
		int temp;
		while (low <= high)
		{
			while (array[low] < pivot)
				low++;
			while (array[high] > pivot)
				high--;
			if (low <= high)
			{
				temp = array[low];
				array[low] = array[high];
				array[high] = temp;
				low++;
				high--;
			}
		}
		if (high > board.m_left)
			queue.push_back(Borders(board.m_left, high));
		if (low < board.m_right)
			queue.push_back(Borders(low, board.m_right));
	}
}