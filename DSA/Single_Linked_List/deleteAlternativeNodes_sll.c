#include <stdio.h>
#include <stdlib.h>

typedef struct node_sll{
	struct node_sll *link;
	int data;
}node_sll_t;

void print_sll( node_sll_t** head ){
	node_sll_t* curr = *head;

	printf("SLL:");
	while(curr){
		printf("\t%d", curr->data);
		curr = curr->link;
	}
	printf("\n");

	return;
}

int count_sll( node_sll_t** head ){
	node_sll_t* curr = *head;
	int countNodes = 0;

	while(curr){
		countNodes++;
		curr = curr->link;
	}

	return countNodes;
}

int insertAtNthLoc_sll(node_sll_t** head, int data, int NthLoc){

	int countNodes = count_sll(&(*head));

	if(NthLoc < 1 || NthLoc > (countNodes + 1)){
		printf("Invalid location = %d to insert node, try valid location\n", NthLoc);
		return -1;
	}

	while(NthLoc--){

		if(NthLoc == 0){
			node_sll_t* newNode = (node_sll_t *)malloc(sizeof(node_sll_t));

			if(newNode == NULL){
				printf("Memory allocation failed in %s function\n", __func__);
				return -1;
			}

			newNode->link = NULL;
			newNode->data = data;

			newNode->link = *head;
			*head = newNode;
		} else {
			head = &(*head)->link;
		}
	}

	return 0;
}

int deleteAlternateNodes_sll(node_sll_t** head){
	if(*head == NULL || (*head)->link == NULL){
		printf("There should be atleast 2 nodes to delete alternative nodes\n");
		return -1;
	}

	node_sll_t* fast = *head, *slow = *head, *temp;

	/* for odd number of nodes*/
	while(fast->link){
		fast = fast->link;
		if(fast->link){
			//printf("fast->data = %d\tslow->data = %d\n", fast->data, slow->data);
			temp = slow;
			fast = fast->link;
			slow = slow->link;
			temp->link = fast;
			free(slow);
			slow = fast;
		}
	}

	/* deleting last node condition for even number of nodes*/
	if(slow->link){
		printf("fast->data = %d\tslow->data = %d\n", fast->data, slow->data);
		free(fast);
		slow->link = NULL;
	}

	return 0;
}

int main(){
	node_sll_t *head = NULL;

	int data = 0;
	int count = 0;

	for(count = 0; count < 11; count++){
		data = data + 10;
		insertAtNthLoc_sll(&head, data, count); 
		print_sll(&head);
	}
	printf("After deleting Alternative nodes\n");
	deleteAlternateNodes_sll(&head);
	print_sll(&head);

	return 0;
}
