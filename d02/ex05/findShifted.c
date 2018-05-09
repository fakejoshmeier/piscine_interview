#include "header.h"

int findPivot(int arr[], int low, int high){
	int mid = (low + high) / 2;
	if (high < low)
		return (-1);
	if (high == low)
		return (low);
	if (mid < high && arr[mid] > arr[mid + 1])
		return (mid);
	if (mid > low && arr[mid] < arr[mid - 1])
		return (mid - 1);
	if (arr[low] >= arr[mid])
		return (findPivot(arr, low, mid));
	return (findPivot(arr, mid, high));
}

int	binarySearch(int arr[], int key, int s, int e){
	if (s > e)
	 	return (-1);
	int mid = (s + e) / 2;
	if (key > arr[mid])
		return (binarySearch(arr, key, mid + 1, e));
	if (key < arr[mid])
		return (binarySearch(arr, key, s, mid - 1));
	return (mid);
}

int shifted(int arr[], int n, int key){
	int pivot = findPivot(arr, 0, n - 1);
	if (pivot == -1)
		return binarySearch(arr, key, 0, n - 1);
	// If we found a pivot, then first compare with pivot
	// and then search in two subarrays around pivot
	if (arr[pivot] == key)
		return (pivot);
	if (arr[0] <= key)
		return (binarySearch(arr, key, 0, pivot - 1));
	return (binarySearch(arr, key, pivot + 1, n - 1));
}

int searchShifted(int arr[], int n, int key){
	int key_ind = shifted(arr, n, key);
	if (key_ind == -1 || key_ind == 0)
		return (key_ind);
	while (arr[--key_ind] == key);
	return (key_ind + 1);
}
