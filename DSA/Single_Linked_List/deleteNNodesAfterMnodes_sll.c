#include <stdio.h> //10.34am - 12.17pm
#include <stdlib.h>

typedef struct node_sll{
	struct node_sll* link;
	int data;
}node_sll_t;

void print_sll(node_sll_t **head){
	node_sll_t* curr = *head;
	printf("\nSLL:");
	while(curr){
		printf("\t%d", curr->data);
		curr = curr->link;
	}
	printf("\n");
}

int insertAtLast_sll(node_sll_t **head, int data){
	node_sll_t* newNode = ( node_sll_t* )malloc( sizeof( node_sll_t ));
	if(newNode == NULL){
		printf("memory allocation failed in %s() function at line %d\n", __func__, __LINE__);
		return -1;
	}

	newNode->link = NULL;
	newNode->data = data;

	if(*head == NULL){
		*head = newNode;
		return 0;
	}

	node_sll_t* curr = *head;
	while(curr->link){
		curr = curr->link;
	}

	curr->link = newNode;

	return 0;
}

int numOfNodes_sll(node_sll_t **head){

	node_sll_t* curr = *head;
	int countNodes = 0;
	while(curr){
		countNodes++;
		curr = curr->link;
	}

	return countNodes;
}

int deleteNNodesAfterMNodes(node_sll_t** head, int MnumNodesToSkip, int NnumNodesToDel){
	int numOfNodes = numOfNodes_sll(&(*head));

	if(*head == NULL || NnumNodesToDel < 1 || (MnumNodesToSkip + NnumNodesToDel) > numOfNodes){
		printf("enter valid number of number of nodes to skip or/and delete or/and not exceeding number of nodes\n");
		return -1;
	}

	node_sll_t* curr = *head;
	node_sll_t* prev = NULL, *next = NULL;

	/*If no need to skip nodes but to delete N number of nodes*/
	if(MnumNodesToSkip == 0){
		for(NnumNodesToDel; NnumNodesToDel; NnumNodesToDel--){
			curr = *head;
			*head = curr->link;
			free(curr);
		}
		return 0;
	}

	/*If there are more than M num of nodes to skip and to delete N number of nodes*/
	for(MnumNodesToSkip; MnumNodesToSkip; MnumNodesToSkip--){
		prev = curr;
		curr = curr->link;
	}

	for(NnumNodesToDel; NnumNodesToDel; NnumNodesToDel--){ //while(NnumNodesToDel--){
		next = curr->link;
		prev->link = next;
		free(curr);
		curr = next;
	}

	return 0;
}

int main(){
	node_sll_t* head = NULL;

	int data = 0, count = 0;
	int numOfNodes = 0;

	for(count = 0; count < 10; count++)
	{
		insertAtLast_sll(&head, data++);
	}
	print_sll(&head);
	numOfNodes = numOfNodes_sll(&(head));
	printf("numOfNodes_sll = %d\n", numOfNodes);

	int MnumNodesToSkip = 5;
	int NnumNodesToDel = 5;

	printf("\n\nMnumNodesToSkip = %d\tNnumNodesToDel = %d\n", MnumNodesToSkip, NnumNodesToDel);
	deleteNNodesAfterMNodes(&head, MnumNodesToSkip, NnumNodesToDel);
	print_sll(&head);
	numOfNodes = numOfNodes_sll(&(head));
	printf("numOfNodes_sll = %d\n", numOfNodes);
}

