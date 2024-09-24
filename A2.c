/**
 * -------------------------
 * Student Name:
 * Student ID:
 * Student email:
 * -------------------------
 */

# include <stdio.h>
# include "matrix.h"
void flip_matrix(char mode);

//----------- Task 1: Symmetric Matrix ------------

/**
 * ----------------------------------------------------------------
 * Parameters:		None
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid symmetric matrix
 * 		A symmetric matrix is a matrix which equals to its transpose
 * 		For more info check: https://mathinsight.org/matrix_transpose
 * 		Notes:
 * 		- an empty matrix is a VALID symmetric matrix
 * 		- a symmetric matrix need to be a square matrix
 * ----------------------------------------------------------------
 */
int is_symmetric_matrix(){

	int row = get_row_length(0);
	int column = get_column_length(0);
	int i = 0, j = 0;
	int bool = 1;
	int check[row][column];

	//check square
	if (row != column){
		bool = 0;
	}
	//make transpose
	else if (row == column){
		for (i = 0; i < row; i++){
				for (j = 0; j < column; j++) {
					check[i][j] = matrix[j][i];
				}
			}
	}

	//check if right
	for (i = 0; i < row; i++){
		for (j = 0; j < column; j++) {
				if (check[i][j] != matrix[i][j]){
					bool = 0;
					break;
				}
			}
		}

	return bool;
}

//----------- Task 2: Incremental Matrix ------------
/**
 * ----------------------------------------------------------------
 * Parameters:		None
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid incremental matrix
 * 		An incremental matrix is:
 * 		a matrix which every element is greater than or equal to the one before it
 * 		Order: left to right, then top to bottom.
 * ----------------------------------------------------------------
 */
int is_incremental_matrix() {
	int bool = 1; //1 is true

	int i = 0, j = 0;

	int row = 0;
	int column = 0;
	int count = 0;

	//count the row
	while (matrix[count][0] != -1){
		row++;
		count++;
	}
	count = 0;
	//count the column
	while (matrix[0][count] != -1){
			column++;
			count++;
		}

	//check empty matrix
	if (row < 1 || column < 1){
		bool = 0;
		return bool;
	}
//check left right

	//printf("%d %d\n", row, column);
	for (i = 0; i < row; i++){
			for (j = 0; j < column; j++) {


				if (matrix[i][j] <= matrix[i+1][j] && i+1 < row) {
					bool = 1;

				}
				else {
					if( i+1 < row)
					{

						bool = 0;

						return bool;
					}
				}
			}
	}
//check top bottom
			for (i = 0; i < column; i++){
					for (j = 0; j < row; j++) {
						if (matrix[i][j] <= matrix[i][j+1] && j+1 < column){
							bool = 1;
						}
						else {
							if(j+1 < column)
							{

								bool = 0;
								return bool;
							}
						}
					}
			}
	return bool;

}


//----------- Task 3: Triangular Matrix  ------------

/**
 * ----------------------------------------------------------------
 * Parameters:	length(int): square side length
 * 				corner(char): 'T'= top corner, 'B' = bottom corner
 * 				side(char): 'L' = left side, 'R' = right side
 * 				fill(int): number to fill the matrix with
 * return:		no returns
 * Description:
 * 		Initialize a matrix then fill it in a triangular manner
 * 		The corner and side determine the position of the triangle right angle
 * 		All cells in the triangle are set to "fill", and the other cells to 0
 * Errors: 		invalid length, invalid corner, invalid side
 * ----------------------------------------------------------------
 */
void create_triangular_matrix(int length, char corner, char side, int fill){

	//int row = get_row_length(0);
	//int column = get_column_length(0);
	int row = 10;
	int column = 10;

	int i = 0, j = 0;

	if (length < 2 || length > 10){
		printf("Error(create_triangular_matrix): invalid length\n");
	}
	if (corner != 'T' && corner != 'B') {
		printf("Error(create_triangular_matrix): invalid corner\n");
	}
	if (side != 'L' && side != 'R') {
		printf("Error(create_triangular_matrix): invalid side\n");
	}

	if (corner == 'T' && side == 'L'){
		//top left
		for (i = 0; i < row; i++){
				for (j = 0; j < column; j++) {
					matrix[i][j] = fill;
					if (i>j){
						matrix[i][j] = 0;
					}
				}
		}
		flip_matrix('v');



//		int temparray[length][10];


		//store in temp array first rows
//		for (a = 0; a < length; a++){
//			for (b = 0; b < 10; b++){
//				temparray[a][b] = matrix[a][b];
//			}
//		}
		int a = 0, b = 0;
		int new = 10 - length;
		//this for loop moves everything up some

		for (a = 0; a < new; a++){
			for (b = 0; b < 10; b++){
				matrix[a][b] = matrix[new + a][b];
			}
		}

	}
	if (corner == 'T' && side == 'R'){
			//top right
		for (i = 0; i < row; i++){
				for (j = 0; j < column; j++) {
					matrix[i][j] = fill;
					if (i>j){
						matrix[i][j] = 0;
					}
				}
		}
		//

		// length - row
		}
	if (corner == 'B' && side == 'L'){
			//bottom left
		for (i = 0; i < row; i++){
				for (j = 0; j < column; j++) {
					matrix[i][j] = fill;
					if (i<j){
						matrix[i][j] = 0;
					}
				}
		}
		}
	if (corner == 'B' && side == 'R'){
				//bottom right
		for (i = 0; i < row; i++){
				for (j = 0; j < column; j++) {
					matrix[i][j] = fill;
					if (i<j){
						matrix[i][j] = 0;
					}
				}
		}
		int a = 0, b = 0;
				int new = 10 - length;
				//this for loop moves everything up some

				for (a = 0; a < length; a++){
					for (b = 0; b < 10; b++){
						matrix[a][b] = matrix[new + a][b];
					}
				}
		flip_matrix('v');


		}
	return;
}

//----------- Task 4: Flip Matrix  ------------
/**
 * ----------------------------------------------------------------
 * Parameters:	mode(char): 'h': horizontal, 'v': vertical
 * return:		no returns
 * Description:
 * 		flips the contents of the global matrix
 * 		For horizontal flip, the first row is swapped with the last row
 * 			the second row is swapped with the second to last row, and so forth
 * 		For vertical flip, the first column is swapped with the last column
 * 			the second column is swapped with the second to last column, and so forth
 * Errors: 	invalid mode, invalid matrix
 * ----------------------------------------------------------------
 */
void flip_matrix(char mode){
	//your code here
	//int row = get_row_length(0);
	//int column = get_column_length(0);




	int row = 0;
	int column = 0;
	int count = 0;


	//count the row
	while (matrix[count][0] != -1 && count < SIZE){
		row++;
		count++;
	}

	count = 0;
	//count the column
	while (matrix[0][count] != -1 && count < SIZE){
			column++;
			count++;
		}



	if (row < 0 || column < 0 || matrix[0][0] == -1){
		printf("Error(flip_matrix): invalid matrix\n");
	}


//	int a = 0, b = 0;
//	for (a = 0; a < 5; a++){
//			for (b = 0; b < 5; b++){
//				if (matrix[0][0] == -1){
//			printf("Error(flip_matrix): invalid matrix\n");
//				}
//		}
//	}

	if (mode != 'h' && mode != 'v'){
		printf("Error(flip_matrix): invalid matrix\n");
	}

	int temp = 0, i = 0, j = 0;

if (mode == 'h'){

	for (i = 0; i < column; i ++){
		for (j = 0; j < row/2; j++){
			temp = matrix[j][i];
			matrix[j][i] = matrix[row-j-1][i];
			matrix[row-j-1][i] = temp;

		}
	}
}


if (mode == 'v'){

	for (i = 0; i < row; i ++){
		for (j = 0; j < column/2; j++){
			temp = matrix[i][j];
		//	printf("b. %d %d\n", matrix[i][j], matrix[i][column-j -1]);
			//matrix[i][j] = matrix[row-i-1][j];
			matrix[i][j] = matrix[i][column-j -1];
			matrix[i][column-j -1] = temp;
		//	printf("a. %d %d\n", matrix[i][j], matrix[i][column-j -1]);
		}
	}
}
	return;
}
