/* draw a square

Input: length = 5

Output:

*	*	*	*	*

*				*

*				*

*				*

*	*	*	*	*

*/


#include <stdio.h>

int main(){
	int indx_row, indx_col, sq_size;

	printf("enter square length = ");
	scanf("%d", &sq_size);

	for( indx_row = 1; indx_row <=sq_size; indx_row++){
		for( indx_col = 1; indx_col <=sq_size; indx_col++){
			if(indx_row == 1 || indx_row == sq_size || indx_col == 1 || indx_col == sq_size){
				printf("*\t");
			} else {
				printf(" \t");
			}
		}
		printf("\n\n");
	}

	return 0;
}
