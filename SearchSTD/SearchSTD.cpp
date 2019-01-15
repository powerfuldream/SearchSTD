// SearchSTD.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int BinarySearch(int *array, int key, int low, int high);

int main()
{
    return 0;
}

int BinarySearch(int * arr, int key, int low, int high)
{
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key == arr[mid])
			return mid;
		else if (key < arr[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return 0;
}
