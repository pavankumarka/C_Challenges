#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node_sll{
	struct node_sll *linkNode_sll;
	int dataNode_sll;
} node_sll_t;

int insertAtFirst_sll(
		node_sll_t **head, 
		int data)
{
	/*allocate memory*/
	node_sll_t *newNode = ( node_sll_t * )malloc( sizeof( node_sll_t ) );

	if(newNode == NULL)
	{
		printf("Allocation failed in function %s\n", __func__);
		return FAILURE;
	}

	newNode->linkNode_sll = NULL;
	newNode->dataNode_sll = data;

	if(*head == NULL)
	{
		*head = newNode;
		return SUCCESS;
	}

	newNode->linkNode_sll = *head;
	*head = newNode;

	return SUCCESS;
}

int insertAtLast_sll(
		node_sll_t **head, 
		int data)
{
	/*allocate memory*/
	node_sll_t *newNode = ( node_sll_t * )malloc( sizeof( node_sll_t ) );

	if(newNode == NULL)
	{
		printf("Allocation failed in function %s\n", __func__);
		return FAILURE;
	}

	newNode->linkNode_sll = NULL;
	newNode->dataNode_sll = data;

	if(*head == NULL)
	{
		*head = newNode;
		return SUCCESS;
	}

	node_sll_t *current = *head;
	while(current->linkNode_sll)
	{
		current = current->linkNode_sll;
	}
	current->linkNode_sll = newNode;

	return SUCCESS;
}


int countNodes_sll( node_sll_t **head)
{
	int count = 0;
	node_sll_t *current;
	for(current = *head; current; current = current->linkNode_sll){
		count++;
	}

	return count;
}

void print_sll(
		node_sll_t **head){
	node_sll_t *current = *head;

	while(current){
		printf("\t%d", current->dataNode_sll);
		current = current->linkNode_sll;
	}
}

void reverseNodes_sll( node_sll_t** head)
{
	if(*head == NULL){
		return;
	}

	node_sll_t *prev = NULL, *curr = *head, *next = NULL;

	while(curr){
		next = curr->linkNode_sll;
		curr->linkNode_sll = prev;

		prev = curr;
		curr = next;
	}

	*head = prev;
	return;
}

int main(){
	node_sll_t *head = NULL;

	insertAtFirst_sll( &head, 10 );
	insertAtFirst_sll( &head, 20 );
	insertAtFirst_sll( &head, 40 );
	insertAtLast_sll( &head, 50 );
	insertAtLast_sll( &head, 60 );
	insertAtLast_sll( &head, 70 );

	int numNodes_sll;
	printf("SLL: ");
	print_sll( &head );
	numNodes_sll = countNodes_sll( &head );
	printf("\ncount = %d\n", numNodes_sll);

	reverseNodes_sll( &head );
	printf("SLL After reverse: ");
	print_sll( &head );
	numNodes_sll = countNodes_sll( &head );
	printf("\ncount = %d\n", numNodes_sll);

	return 0;
}
