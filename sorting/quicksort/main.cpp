//
//  main.cpp
//  sorting
//
//  Created by Johann on 9/11/17.
//  Copyright © 2017 Johann. All rights reserved.
//

#include <iostream>

using namespace std;

void swap(int &left, int &right)
{
	int temp = left;
	left = right;
	right = temp;
}
int partition(int arr[], int left, int right)
{
	int result = -1;
	int pivot = (arr[left] + arr[right]) / 2;
	
	while (left < right)
	{
		//Find the element supposed not to be left half
		while (arr[left] < pivot)
		{
			left ++;
		}
		
		//Find the element supposed not to be right half
		while (arr[right] > pivot)
		{
			right --;
		}
		
		if (left < right)
		{
			swap(arr[left], arr[right]);
			left ++;
			right --;
		}
		
		//Handle case left = right: arr[left] = arr[right] = arr[pivot]
		//--> no need to swap.
		//--> result = left = right = pivot.
	}
	
	result = left;
	
	return result;
}
void quicksort(int arr[], int left, int right)
{
	if (right - left < 2)
	{
		if (arr[left] > arr[right])
		{
			swap(arr[left], arr[right]);
		}
		return;
	}
	
	int index = partition(arr, left, right);
	if (index > left)
	{
		quicksort(arr, left, index - 1);
	}
	
	if (index < right)
	{
		quicksort(arr, index, right);
	}
}

int main(int argc, const char * argv[]) {
	// insert code here...
	int arr[10] = {23, 9876, 459, 650, 32, 9, 4705, 1, 17, 4705};
	quicksort(arr, 0, 9);
	
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}
	
	return 0;
}
