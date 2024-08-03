/* draw a square inside square

Input: length = 7

Output:

*	*	*	*	*	*	*

*						*

*		*	*	*		*

*		*		*		*

*		*	*	*		*

*						*

*	*	*	*	*	*	*

*/


#include <stdio.h>

int main(){
	int indx_row, indx_col, sq_size;

	printf("enter square length = ");
	scanf("%d", &sq_size);

	for( indx_row = 1; indx_row <=sq_size; indx_row++){
		for( indx_col = 1; indx_col <=sq_size; indx_col++){
			if((indx_row == 1 || indx_row == sq_size || indx_col == 1 || indx_col == sq_size) ||
					(indx_row >= 3 && indx_row <= sq_size - 2 && indx_col >= 3 && indx_col <= sq_size - 2) &&
					(indx_row == 3 || indx_row == sq_size - 2 || indx_col == 3 || indx_col == sq_size - 2))
			{
				printf("*\t");
			} else {
				printf(" \t");
			}
		}
		printf("\n\n");
	}

	return 0;
}
