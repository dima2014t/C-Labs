#include <iostream>
#include "BSearch.h"

using namespace std;

int recursiveBSearch(int soughtValue, int* array, int left, int right)
{
	if (right < left)
		return -1;
	int pivotIndex = (left + right) / 2;
	if (array[pivotIndex] == soughtValue)
		return pivotIndex;
	else if (array[pivotIndex] > soughtValue)
		return recursiveBSearch(soughtValue, array, left, pivotIndex - 1);
	return recursiveBSearch(soughtValue, array, pivotIndex + 1, right);
}

int bSearch(int soughtValue, int* array, int left, int right)
{
	int pivotIndex = (left + right) / 2;
	while (pivotIndex >= left && pivotIndex <= right)
	{
		if (array[pivotIndex] == soughtValue)
			return pivotIndex;
		if (array[pivotIndex] > soughtValue)
			right = pivotIndex - 1;		
		else
			left = pivotIndex + 1;
		pivotIndex = (left + right) / 2;
	}
	return -1;
}
