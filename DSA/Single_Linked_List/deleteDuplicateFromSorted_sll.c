#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node_sll{
	struct node_sll* nextNodeLink_sll;
	int dataNode_sll;
} node_sll_t;

unsigned int randomData( void ){

	static unsigned int randNum = 0;

	return (randNum = (randNum + time(0)) % 10000);
}

#if 0
int insertSorted_sll(node_sll_t** head, int data){

	node_sll_t* newNode = (node_sll_t *)malloc(sizeof(node_sll_t));

	if(newNode == NULL){
		printf("memory allocation failed in function %s()\n", __func__);
		return FAILURE;
	}

	newNode->nextNodeLink_sll = NULL;
	newNode->dataNode_sll = data;

	if(*head == NULL || newNode->dataNode_sll <= (*head)->dataNode_sll){
		newNode->nextNodeLink_sll = *head;
		*head = newNode;

		return SUCCESS;
	}

	node_sll_t* currNode_sll = *head;
	while(currNode_sll->nextNodeLink_sll != NULL && newNode->dataNode_sll > (currNode_sll->nextNodeLink_sll)->dataNode_sll){
		currNode_sll = currNode_sll->nextNodeLink_sll;
	}

	newNode->nextNodeLink_sll = currNode_sll->nextNodeLink_sll;
	currNode_sll->nextNodeLink_sll = newNode;

	return SUCCESS;
}


int removeDuplicateNodes_sll(node_sll_t** headNode_sll){

	if( *headNode_sll == NULL ){
		printf("SLL list is empty\n");
		return FAILURE;
	}

	node_sll_t *currNode_sll = *headNode_sll, *duplicateNode_sll = NULL, *nextNode_sll = NULL;

	while( currNode_sll ){
		for( nextNode_sll = currNode_sll ; nextNode_sll->nextNodeLink_sll != NULL ; ){
			if( currNode_sll->dataNode_sll == (nextNode_sll->nextNodeLink_sll)->dataNode_sll){
				duplicateNode_sll = nextNode_sll->nextNodeLink_sll;
				nextNode_sll->nextNodeLink_sll =  (nextNode_sll->nextNodeLink_sll)->nextNodeLink_sll;
				free(duplicateNode_sll);
			} else {
				nextNode_sll = nextNode_sll->nextNodeLink_sll;
			}
		}
		currNode_sll = currNode_sll->nextNodeLink_sll;
	}

	return SUCCESS;
}

#endif

int insertSorted_sll(node_sll_t** head, int data){

	node_sll_t* newNode = (node_sll_t *)malloc(sizeof(node_sll_t));

	if(newNode == NULL){
		printf("malloc failed in %s() function\n", __func__);
		return FAILURE;
	}

	newNode->nextNodeLink_sll = NULL;
	newNode->dataNode_sll = data;

	if(*head == NULL || newNode->dataNode_sll <= (*head)->dataNode_sll){
		newNode->nextNodeLink_sll = *head;
		*head = newNode;

		return SUCCESS;
	}

	node_sll_t* currNode_sll = *head;

	while(currNode_sll->nextNodeLink_sll != NULL && newNode->dataNode_sll >= (currNode_sll->nextNodeLink_sll)->dataNode_sll){
		currNode_sll = currNode_sll->nextNodeLink_sll;
	}

	newNode->nextNodeLink_sll = currNode_sll->nextNodeLink_sll;
	currNode_sll->nextNodeLink_sll = newNode;

	return SUCCESS;
}

int removeDuplicateNodes_sll(node_sll_t** head){

	if(*head == NULL){
		printf("List is empty to remove duplicates\n");
		return FAILURE;
	}

	node_sll_t *curr = *head, *next = NULL, *dup = NULL;

	while(curr){
		for(next = curr; next->nextNodeLink_sll != NULL;){
			if(curr->dataNode_sll == next->nextNodeLink_sll->dataNode_sll){
				dup = next->nextNodeLink_sll;
				next->nextNodeLink_sll = next->nextNodeLink_sll->nextNodeLink_sll;
				free(dup);
			} else {
				next = next->nextNodeLink_sll;
			}
		}
		curr = curr->nextNodeLink_sll;
	}

	return SUCCESS;
}


void print_sll(node_sll_t** headNode_sll){

	node_sll_t* currNode_sll = *headNode_sll;

	printf("SLL:");
	while(currNode_sll){
		printf("\t%d", currNode_sll->dataNode_sll);
		currNode_sll = currNode_sll->nextNodeLink_sll;
	}
	printf("\n");

	return;
}

int main(){

	node_sll_t* headNode_sll = NULL;
	int data;
	int count;

	for( count = 0; count < 5; count++){
		data = randomData();
		insertSorted_sll( &headNode_sll, data );
		if( count < 2 )
			insertSorted_sll( &headNode_sll, data );
		print_sll( &headNode_sll );
	}

	if(count == count){
		insertSorted_sll( &headNode_sll, data );
		print_sll( &headNode_sll );
	}

	removeDuplicateNodes_sll( &headNode_sll );
	printf( "After removing duplicates " );
	print_sll( &headNode_sll );

	return 0;
}
