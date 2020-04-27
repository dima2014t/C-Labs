#include <iostream>
#include "QuickSort.h"
#include "BSearch.h"
#include <chrono>

using namespace std;

int search(int soughtValue, int* array, int left, int right)
{
	for (int i = 0; i <= right; i++)
		if (array[i] == soughtValue)
			return i;
}

void printArray(int* array, int size)
{
	cout << "[";
	for(int index = 0; index < size - 1; index++)
	{
		cout << array[index] << ", ";
	}
	cout << array[size - 1] << "]" << endl;
}

void searchTimeMeasurements(int* array, int arraySize, int searchedValue, int (*searchFunction)(int, int*, int, int))
{
	auto start = chrono::high_resolution_clock::now();
	int index = searchFunction(searchedValue, array, 0, arraySize - 1);
	auto end = chrono::high_resolution_clock::now();
	cout << "\t" << "Searched value = " << searchedValue << endl <<
		"\t" << "Found index = " << index << endl;
	if (index >= 0 && index < arraySize)
		cout << "\t" << "Value by found index = " << array[index] << endl;
	cout << " \t" << "Time spent = " << chrono::nanoseconds(end - start).count() << " ns" << endl;
}

int main()
{
	const int n1 = 100;
	int array1[n1];
	int array2[n1];
	for (int i = 0; i < n1; i++)
	{
		int value = rand() % 21 - 10;
		array1[i] = value;
		array2[i] = value;
	}

	const int n3 = 10000;
	int array3[n3];
	for (int i = 0; i < n3; i++)
		array3[i] = rand() % 2001 - 1000;

	cout << "first array of length 100 (first 50 values): ";
	printArray(array1, n1 / 2);
	cout << "second array of length 100 (first 50 values): ";
	printArray(array2, n1 / 2);

	recursiveQuickSort(array1, 0, n1 - 1);
	cout << "first array after recursive quicksort (first 50 values): ";
	printArray(array1, n1 / 2);

	quickSort(array2, 0, n1 - 1);
	cout << "second array after non-recursive quick sort (first 50 values): ";
	printArray(array2, n1 / 2);

	int searchedValue = -4;
	cout << "Search for an element in the first array using a recursive "
			"binary search. The index of the element "<< searchedValue <<" is equal to: " << 
			recursiveBSearch(searchedValue, array1, 0, n1) << endl;
	cout << "Search for an element in the first array using a non-recursive "
			"binary search. The index of the element "<< searchedValue <<" is equal to: " << 
			bSearch(searchedValue, array2, 0, n1) << endl;

	cout << "The third array is 10000 long (first 50 values): ";
	printArray(array3, 50);

	cout << "Normal search in an unsorted array:" << endl;
	searchTimeMeasurements(array3, n3 - 1, searchedValue, search);

	cout << "Binary search in an unsorted array:" << endl;
	searchTimeMeasurements(array3, n3, searchedValue, recursiveBSearch);

	recursiveQuickSort(array3, 0, n3 - 1);

	cout << "Normal search in an sorted array:" << endl;
	searchTimeMeasurements(array3, n3, searchedValue, search);

	cout << "Binary search in an sorted array:" << endl;
	searchTimeMeasurements(array3, n3, searchedValue, recursiveBSearch);

	return 0;
}
