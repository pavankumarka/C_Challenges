#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node_sll{
	struct node_sll* link;
	int data;
}node_sll_t;

int insertSortedNode_sll(node_sll_t** head, int data){

	node_sll_t *newNode = ( node_sll_t* )malloc(sizeof(node_sll_t));
	if(newNode == NULL){
		printf("Memory allocation failed in %s()\n", __func__);
		return FAILURE;
	}

	newNode->link = NULL;
	newNode->data = data;


	node_sll_t* curr = *head;

	if(*head == NULL || newNode->data <= (*head)->data){
		newNode->link = *head;
		*head = newNode;
		return SUCCESS;
	} 
	else
	{
		while(curr->link != NULL && newNode->data > curr->link->data)
		{
			curr=curr->link;
		}
		newNode->link = curr->link;
		curr->link = newNode;
		return SUCCESS;
	}
}

void printNodes_sll( node_sll_t** head){
	node_sll_t *curr = *head;
	printf("SLL: ");
	while(curr){
		printf("\t%d", curr->data);
		curr = curr->link;
	}
	printf("\n");
}

int main(){

	node_sll_t* head = NULL;
	int data = 0;
	int index;
	
	for(index = 0; index < 4; index++){
		//data = time(0) % 1000;
		data = data + 10 ;
		insertSortedNode_sll(&head, data);
		printNodes_sll(&head);
	}

	insertSortedNode_sll(&head, 25);
	printNodes_sll(&head);
	insertSortedNode_sll(&head, 225);
	printNodes_sll(&head);
	insertSortedNode_sll(&head, 5);
	printNodes_sll(&head);
	insertSortedNode_sll(&head, 8);
	printNodes_sll(&head);
	insertSortedNode_sll(&head, -888);
	printNodes_sll(&head);
	insertSortedNode_sll(&head, 999);
	printNodes_sll(&head);
	insertSortedNode_sll(&head, 25);
	printNodes_sll(&head);
	insertSortedNode_sll(&head, 25);
	printNodes_sll(&head);
}
