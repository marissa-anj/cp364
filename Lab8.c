#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Lab8.h"

/*
 * ----------------------------------------------------
 * Linear Search (Iterative Version)
 * 					Comparisons
 * Worst Case:		O(n)
 * Best Case:		O(1)
 * Average Case:	O(n) N/2
 * ----------------------------------------------------
 */
int linear_search(Data *array, const int size, Data item) {
	assert(array);
	assert(size >= 1);
	int result = -1;
	for (int i = 0; i < size; i++)
		if (compare_data(&array[i], &item) == 0) {
			result = i;
			break;
		}
	return result;
}

/*
 * ----------------------------------------------------
 * Linear Search (Recursive Version)
 * ----------------------------------------------------
 */
int linear_search_r_aux(Data *array, int start, int end, Data item) {
	if (start > end)
		return -1;
	if (compare_data(&array[start], &item) == 0)
		return start;
	return linear_search_r_aux(array, start + 1, end, item);
}
int linear_search_r(Data *array, const int size, Data item) {
	return linear_search_r_aux(array, 0, size - 1, item);
}

/*
 * ----------------------------------------------------
 * Binary Search (Iterative Version)
 * 					Comparisons
 * Worst Case:		O(log n)
 * Best Case:		1
 * Average Case:	O(log n)
 * ----------------------------------------------------
 */
int binary_search(Data *array, const int size, Data item) {
	int result, middle;
	int start = 0;
	int end = size - 1;
	while (start <= end) {
		middle = (start + end) / 2;
		result = compare_data(&array[middle], &item);
		if (result == 0)
			return middle;
		if (result == 1)
			end = middle - 1;
		else
			start = middle + 1;
	}
	return -1;
}

/*
 * ----------------------------------------------------
 * Binary Search (Recursive Version)
 * ----------------------------------------------------
 */
int binary_search_r_aux(Data *array, int start, int end, Data item) {
	if (start > end)
		return -1;
	int mid = start + (end - start) / 2;

	// If the element is present at the middle  itself
	if (compare_data(&array[mid], &item) == 0)
		return mid;

	// If element is smaller than mid, then it can only be present in left subarray
	if (compare_data(&array[mid], &item) == 1)
		return binary_search_r_aux(array, start, mid - 1, item);
	// Else the element can only be present in right subarray
	return binary_search_r_aux(array, mid + 1, end, item);
}

int binary_search_r(Data *array, const int size, Data item) {
	return binary_search_r_aux(array, 0, size - 1, item);
}

/*
 * ----------------------------------------------------
 * Algorithm name:		Bubble Sort
 *
 * Time Complexity:
 * 					Comparisons		Swaps
 * Worst Case:		O(n^2)			O(n^2)
 * Best Case:		O(n^2)			O(1)
 * Average Case:	O(n^2)			O(n^2)
 *
 * Memory: O(1)
 *
 * Worst sorting algorithm, but stable, can be improved a bit
 * ----------------------------------------------------
 */
void bubble_sort(Data *array, const int size) {
	int i, j;
	for (i = 0; i < size - 1; i++)
		for (j = 0; j < size - i; j++)
			if (compare_data(&array[j], &array[j + 1]) == 1)
				swap_data(&array[j], &array[j + 1]);
	return;
}

/*
 * ----------------------------------------------------
 * Algorithm name: 		Selection Sort
 *
 * Time Complexity:
 * 					Comparisons		Swaps
 * Worst Case:		O(n^2)			O(n)
 * Best Case:		O(n^2)			O(1)
 * Average Case:	O(n^2)			O(n)
 *
 * Memory: O(1)
 * ----------------------------------------------------
 */
void selection_sort(Data *array, const int size) {
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < size - 1; i++) {
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (compare_data(&array[j], &array[min_idx]) == 2)
				min_idx = j;

		// Swap the found minimum element with the first element
		swap_data(&array[min_idx], &array[i]);
	}
}

/*
 * ----------------------------------------------------
 *  Algorithm name:	Insertion Sort
 *
 * Time Complexity:
 * 					Comparisons		Swaps
 * Worst Case:		O(n^2)			O(n^2)
 * Best Case:		O(n)			O(1)
 * Average Case:	O(n^2)			O(n^2)
 *
 * Memory: O(1)
 * Insertion sort performs better than selection sort
 * 		best when list is partially sorted
 * ----------------------------------------------------
 */
void insertion_sort(Data *array, const int size) {
	int i, j;
	Data key;
	for (i = 1; i < size; i++) {
		key = array[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		 greater than key, to one position ahead
		 of their current position */
		while (j >= 0 && compare_data(&array[j], &key) == 1) {
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
	return;
}

/*
 * ----------------------------------------------------
 * Algorithm name:	Quick Sort
 *
 * Time Complexity:
 * 					Comparisons		Swaps
 * Worst Case:		O(n^2)
 * Best Case:		O(n log n)
 * Average Case:	O(n log n)
 *
 * Memory: O(n)
 * Quicksort is better than merge sort for small arrays
 * Quicksort is not stable
 * ----------------------------------------------------
 */

//Lumuto Partition scheme, select last element as pivot
int partition(Data *array, int start, int end) {
	Data pivot = array[end];
	int pivot_indx = start;
	for (int j = start; j < end; j++)
		if (compare_data(&array[j], &pivot) == 2) {
			swap_data(&array[pivot_indx], &array[j]);
			pivot_indx++;
		}
	swap_data(&array[pivot_indx], &array[end]);
	return pivot_indx;
}

void quick_sort_r(Data *array, int start, int end) {
	if (start >= end)
		return;
	int pivot_indx = partition(array, start, end);
	quick_sort_r(array, start, pivot_indx - 1);
	quick_sort_r(array, pivot_indx + 1, end);
	return;
}

void quick_sort(Data *array, const int size) {
	quick_sort_r(array, 0, size - 1);
	return;
}

/*
 * ----------------------------------------------------
 * Algorithm name:		Merge Sort
 *
 * Time Complexity:
 * 					Comparisons		Swaps
 * Worst Case:		O(n log n)
 * Best Case:		O(n log n)
 * Average Case:	O(n log n)
 *
 * Memory: O(n)
 * Notes: Merge sort is better than quicksort for big arrays
 * 		  Merge sort is stable
 * ----------------------------------------------------
 */
void merge(Data *array, int left, int middle, int right) {
	int i, j, k;
	int n1 = middle - left + 1;
	int n2 = right - middle;
	Data *L = (Data*) malloc(sizeof(Data) * n1); //temp arrays
	Data *R = (Data*) malloc(sizeof(Data) * n2);

	for (i = 0; i < n1; i++) //copy left array
		L[i] = array[left + i];
	for (j = 0; j < n2; j++) //copy right array
		R[j] = array[middle + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = left; // Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (compare_data(&L[i], &R[j]) == 2 || compare_data(&L[i], &R[j]) == 0)
			array[k] = L[i++];
		else
			array[k] = R[j++];
		k++;
	}

	/* Copy the remaining elements of L[], if there are any */
	while (i < n1)
		array[k++] = L[i++];

	/* Copy the remaining elements of R[], if there are any */
	while (j < n2)
		array[k++] = R[j++];

	free(L);
	L = NULL;
	free(R);
	R = NULL;
	return;
}

/* l is for left index and r is right index of the
 sub-array of arr to be sorted */
void merge_sort_r(Data *array, int left, int right) {
	if (left >= right)
		return;

	// Same as (l+r)/2, but avoids overflow for large l and h
	int middle = left + (right - left) / 2;

	// Sort first and second halves
	merge_sort_r(array, left, middle);
	merge_sort_r(array, middle + 1, right);

	merge(array, left, middle, right);
}

void merge_sort(Data *array, const int size) {
	merge_sort_r(array, 0, size - 1);
}

