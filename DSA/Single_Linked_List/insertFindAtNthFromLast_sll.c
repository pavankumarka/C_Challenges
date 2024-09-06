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

int insertAtNthNode_sll(node_sll_t **head, int numNodes_sll, int data, int locNum)
{

	if(locNum < 1 || locNum > (numNodes_sll + 1))
	{
		printf("SLL count exceeded, try valid location\n");
		return FAILURE;
	}

	while(locNum--)
		if(locNum == 0)
		{
			/*allocate memory*/
			node_sll_t *newNode = ( node_sll_t * )malloc( sizeof( node_sll_t ) );

			if(newNode == NULL)
			{
				printf("Allocation failed in function %s\n", __func__);
				return FAILURE;
			}

			newNode->dataNode_sll = data;

			newNode->linkNode_sll = *head;
			*head = newNode;

			return SUCCESS;
		} else {
			head = &(*head)->linkNode_sll;
		}
}

void print_sll(
		node_sll_t **head){
	node_sll_t *current = *head;

	while(current){
		printf("\t%d", current->dataNode_sll);
		current = current->linkNode_sll;
	}
}

int findNthLastNode_sll(node_sll_t** head, int dataAtNthLast)
{

	int count = countNodes_sll(&(*head));

	if (dataAtNthLast > count)
	{
		printf("%dth last is invalid Node location in SLL with %d nodes\n", dataAtNthLast, count); 
		return FAILURE;
	}

	count = count - dataAtNthLast + 1;
	node_sll_t* current = *head;
	while(count--)
	{
		if(count == 0)
		{
			printf("%dth last data = %d\n", dataAtNthLast, current->dataNode_sll);
			return SUCCESS;
		}
		current = current->linkNode_sll;
	}
}

int insertAtNthLastNode_sll(
		node_sll_t** head,
		int locNthLast,
		int data){
	int count = countNodes_sll(&(*head));

	if (locNthLast > count)
	{
		printf("%dth last is invalid Node location in SLL with %d nodes\n", locNthLast, count); 
		return FAILURE;
	}

	insertAtNthNode_sll(&(*head), count, data, count - locNthLast+2); 
}

int main()
{
	node_sll_t *head = NULL;

	insertAtFirst_sll( &head, 10 );
	insertAtFirst_sll( &head, 20 );
	insertAtFirst_sll( &head, 40 );
	insertAtLast_sll( &head, 50 );

	int numNodes_sll;
	printf("SLL: ");
	print_sll( &head );
	numNodes_sll = countNodes_sll( &head );
	printf("\ncount = %d\n", numNodes_sll);

	int locNum = 3;
	printf("\nLoc to insert = %d\n", locNum);
	insertAtNthNode_sll( &head, numNodes_sll, 30 , locNum);

	printf("SLL: ");
	print_sll( &head );
	numNodes_sll = countNodes_sll( &head );
	printf("\ncount = %d\n", numNodes_sll);

	int findNthLast = 5;
	findNthLastNode_sll(&head, findNthLast);

	int locNthLast = 5, data = 777;
	printf("insert %d at %dth from last\n", data, locNthLast);
	insertAtNthLastNode_sll(&head, locNthLast, data);

	printf("SLL: ");
	print_sll( &head );
	numNodes_sll = countNodes_sll( &head );
	printf("\ncount = %d\n", numNodes_sll);
}

