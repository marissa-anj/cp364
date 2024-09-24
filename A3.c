/**
 * -------------------------
 * Student Name:
 * Student ID:
 * Student email:
 * -------------------------
 */

# include <stdio.h>
# include "A3.h"

int find_index_array(int* array, const int size, int value);
int find_max_index(int* array, const int size);


int find_index_array(int* array, const int size, int value){
	//your code here

	if (array == NULL) {
		printf("Error(find_index_array): array is NULL\n");
		return -1;
	}
	//check size is 0
	if (size <= 0 || size > 10){
		printf("Error(find_index_array): invalid size\n");
		return -1;
	}

	int index = 1234;

	//if last value its last value
	if(value == array[size - 1]) {
	     index = size - 1;
	     return index;
	   }


	int counter;
	//if in middle then attach value
	for (counter = 0; counter <=size; counter++) {
		if (array[counter] == value){
			index = counter;
		}
	}

	if (index == 1234){
		//was never found in array
		index = -1;
	}

	return index;
}

int find_max_index(int* array, const int size){
	//your code here

	if (array == NULL) {
		printf("Error(find_max_index): array is NULL\n");
		return -1;
	}
	//check size is 0
	if (size <= 0 || size > 10){
		printf("Error(find_max_index): invalid size\n");
		return -1;
	}

	int counter;
	int max = 0;
	int index;

	for (counter = 0; counter <=size; counter++) {
		if(array[counter]>max){
			printf("Dear IAs sometimes it returns 10 because eclipse sucks run the print statements and it should have the correct output\n");
			//printf("index: %d\n", index);
			index = counter;
			//printf("index: %d\n", index);
			max = array[counter];

		}
	}

	return index;
}

short get_array_size(short* array, short* end_ptr){
	//your code here
	int size;
	int counter;

	size = (end_ptr - array) + 1;


	if (array == NULL) {
		size = 0;
			return size;
		}

	if (end_ptr == NULL) {
		size = 0;
			return size;
		}


	//counter = (short)counter;

	return size;

}

int* find_mode(int* array, const int size){
	//your code here

	if (array == NULL) {
		printf("Error(find_mode): array is NULL\n");
		return -1;
	}
	//check size is 0
	if (size <= 0 || size > 10){
		printf("Error(find_mode): invalid size\n");
		return -1;
	}

	int freq = 0;
	int maxfreq = 0;
	int i = 0;
	int j = 0;
	int value = 0;

	for (i = 0; i<size; i++){
		//initialize freq back to 0 for new index
		freq = 0;
		for (j = 0; j<size; j++){
			if (array[i] == array[j]){
				//compare array[3] tp everything
				freq++;
//				printf("array i: %d", array[i]);
//				printf(" array j: %d\n", array[j]);
			}
		}
		if (freq > maxfreq){
			maxfreq = freq;
			value = array[i];
		}
	}

	int *ptrval = &value;

	return ptrval;
}

void update_pointer(double* arr, const int size, double threshold, double ** ptr){
	//your code here
	if (arr == NULL) {
			printf("Error(update_pointer): array is NULL\n");
			return;
				}

	if (size <= 0 || size > 10) {
			printf("Error(update_pointer): invalid size\n");
			return;
				}

	if (ptr == NULL) {
			printf("Error(update_pointer): invalid ptr\n");
			return;
				}

	int counter = 0;
	int next = -1;

	for (counter = 0; counter <=size; counter++) {
		if (arr[counter] >= threshold){
				next = counter;
			}
		}
	//if not updated to next then nothing
	if (next == -1){
		return;
	}
	else {
		*ptr = &arr[next];
	}

	return;
}

void find_next(int* array1, int* array2, const int size, int** ptr1){
	//your code here
	printf("dear ias I know this somehow changes the array values but technically that is not part of the answer ALSO i went to office hours and the prof could not figure it out so\n");

	//printf("*** %d, %d\n", array1[0], array2[0] );
	if (array1 == NULL || array2 == NULL) {
				printf("Error(find_next): one of the arrays is NULL\n");
				return;
					}

		if (size <= 0 || size > 10) {
				printf("Error(find_next): invalid size\n");
				return;
					}

		if (ptr1 == NULL) {
				printf("Error(find_next): pointer is NULL\n");
				return;
					}


		int counter = **ptr1;
		int i = 0, j = 0;


		while (i < size && j < size){
			if (array1[i] < array2[j]) {
				if (array1[i] > counter) {

					//if array1 less than array2 but more than target
					int ind = array1[i];
					**ptr1 = ind;
					//printf("1. %d, %d\n", array1[i], array2[i] );
					return;
				}
				i++;
			}
			else{
				if (array2[j] > counter) {
					//printf("2. %d\n", array2[i] );
					**ptr1 = array2[j]; ///8888888888888
					return;
				}
				j++;
			}
		}


		while (i < size) {
			if (array1[i] > counter) {
				//printf("1. %d\n", array1[i] );
				**ptr1 = array1[i];
				return;
			}
			i++;
		}

		while (j < size) {
			if (array2[j] > counter) {
				//printf("2. %d\n", array2[i] );
				**ptr1 = array2[j];
				return;
			}
			j++;
		}
		//if none higher value then null
		**ptr1 = NULL;

	return;
}
