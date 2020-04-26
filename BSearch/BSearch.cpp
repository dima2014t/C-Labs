#include <iostream>
#include "BSearch.h"

using namespace std;

int recursiveBSearch(int soughtValue, int* array, int left, int right)
{
	if (right < left)
		return -1;
	int pivot = (left + right) / 2;
	if (array[pivot] == soughtValue)
		return pivot;
	else if (array[pivot] > soughtValue)
		return recursiveBSearch(soughtValue, array, left, pivot - 1);
	return recursiveBSearch(soughtValue, array, pivot + 1, right);
}

int bSearch(int soughtValue, int* array, int left, int right)
{
	int index = (left + right) / 2;
	while (index >= left && index <= right)
	{
		if (array[index] == soughtValue)
			return index;
		if (array[index] > soughtValue)
			right = index - 1;		
		else
			left = index + 1;
		index = (left + right) / 2;
	}
	return -1;
}