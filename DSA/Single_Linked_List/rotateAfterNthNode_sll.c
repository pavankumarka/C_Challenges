#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node_sll{
	struct node_sll *link;
	int data;
}node_sll_t;

int countNodes_sll(node_sll_t** head)
{
	node_sll_t* temp = *head;
	int count = 0;
	while(temp){
		count++;
		temp = temp->link;
	}

	return count;
}

int insertAtNthNode_sll( node_sll_t** head, int data, int numOfNodes, int locNth){
	if(locNth < 1 || locNth > (numOfNodes + 1)){
		printf("Invalid Node location to insert\n");
		return FAILURE;
	} else {
		while(locNth--){
			if(locNth == 0){
				node_sll_t *newNode = (node_sll_t *)malloc(sizeof(node_sll_t));
				if(newNode == NULL){
					printf("Memory allocation failed in function %s()\n", __func__);
					return FAILURE;
				}

				newNode->link = NULL;
				newNode->data = data;

				newNode->link = *head;
				*head = newNode;

				return SUCCESS;
			} else {
				head = &(*head)->link;
			}
		}
	}
}

void printNodes_sll(node_sll_t** head)
{
	node_sll_t* temp = *head;
	while(temp){
		printf("\t%d", temp->data);
		temp = temp->link;
	}
	printf("\n");
}

int rotateAfterNthNode(node_sll_t** head, int numNodesToSkip){

	int numNodes = countNodes_sll(&(*head));

	if(*head == NULL || (numNodesToSkip < 1 || numNodesToSkip >= numNodes))
	{
		printf("invalid number of nodes to rotate\n");
		return FAILURE;
	}

	node_sll_t *curr = *head, *prev = NULL, *old_head = *head, *new_head;

	while(--numNodesToSkip){
		prev = curr;
		curr = curr->link;
	}

	new_head = curr->link;
	*head = new_head;
	curr->link = NULL;

	while(new_head->link){
		new_head = new_head->link;
	}

	new_head->link = old_head;

	return SUCCESS;
}

int main()
{
	node_sll_t* head = NULL;

	int data = 0;
	int numOfNodes; 
	int locNth = 0;
	int index = 0;
	
	for(index = 0; index < 6; index++){
		data = data + 10;
		numOfNodes = countNodes_sll(&head);
		locNth = locNth + 1;
		insertAtNthNode_sll(&head, data, numOfNodes, locNth);
		printf("SLL: ");
		printNodes_sll(&head);
	}

	int numNodesToSkip = 0;

	for(index = -2; index < 8; index++)
	{
		numNodesToSkip = index;
		printf("\nnumNodesToSkip to rotate = %d\n", numNodesToSkip);
		rotateAfterNthNode(&head, numNodesToSkip);
		printf("SLL: ");
		printNodes_sll(&head);
	}
	
}

