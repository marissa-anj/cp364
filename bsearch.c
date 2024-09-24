/*
 * bsearch.c
 *
 *  Created on: Nov. 11, 2022
 *      Author: aroma
 */

#include<stdio.h>


int binarySearch(int *, int st, int ed, int key);
int binarySearchIterative(int *,int ed, int key);

int main()
{
	int Arr[] = {1, 3, 5, 6, 7, 8, 10, 12, 15, 20, 30, 35};
	int length = sizeof(Arr)/sizeof(int);
	int found = binarySearch(Arr, 0, length-1, 5);
	printf("%d", found);

	setbuf(stdout, NULL);
	return 1;
}

int binarySearch(int * A, int st, int ed, int key)
{
	if(key == A[st])
		return st;
	else if (key == A[ed])
		return ed;


	if((key > A[st] || key < A[ed]) && st < ed)
	{
		int mid = (st+ed)/2;
		if(key <= A[mid])
		{
			return binarySearch(A, st, mid, key);
		}
		else
		{
			return binarySearch(A, mid+1, ed, key);
		}

	}
	return -1;
}

int binarySearchIterative(int * A,int length, int key)
{
	if(key >= A[0] && key <= A[length-1])
	{
		if(key == A[0])
			return 0;
		if(key == A[length-1])
			return length - 1;

		int st = 0;
		int end = length - 1;
		while(st < end)
		{
			int mid = (st+end)/2;
			if(key < A[mid])
				end = mid-1;
			else if(key > A[mid])
				st = mid+1;
			else
				return mid;
		}


	}
	return -1;
}
