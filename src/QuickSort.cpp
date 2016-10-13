//============================================================================
// Name        : QuickSort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


static int SIZE = 9;

void swap(int* arr, int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}


int partition(int* arr, int left, int right)
{
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while(low <= high)
	{
		//find low which is greater than pivot value.
		while(pivot >= arr[low] && (low <= right))
			low++;

		//find high which is less than pivot value.
		while(pivot <= arr[high] &&  (high >= (left + 1)))
			high--;

		//if low and high is not crossed, swap low and high value.
		//swap(arr[low], arr[high]);
		if(low <= high)
			swap(arr, low, high);
	}

	//at this point, low and high is crossed, so high and pivot need to be swapped.
	swap(arr, high, left);

	//return high index, high index should be reference of dividing data as two part.
	return high;
}


//quick sort will call partition recursively to sort the data.
void quickSort(int* arr, int start, int end)
{
	if(start <= end)
	{
		int mid = partition(arr, start, end);
		quickSort(arr, start, mid - 1);
		quickSort(arr, mid + 1, end );
	}
}


int main()
{
	int myArray[SIZE] = { 5, 1, 3, 4, 2, 9, 7, 6, 8 };


	quickSort(myArray, 0, 8);


	for(int i = 0; i < SIZE; i++)
	{
		cout << myArray[i] << " ";
	}
	cout << endl;

	return 0;
}
