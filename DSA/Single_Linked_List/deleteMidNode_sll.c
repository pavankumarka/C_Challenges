#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node_sll{
	struct node_sll* link;
	int data;
}node_sll_t;


int countNodes_sll( node_sll_t** head){
	node_sll_t *curr = *head;
	int count = 0;
	while(curr){
		count++;
		curr = curr->link;
	}
	return count;
}

int insertNodeAtNthLoc(node_sll_t** head, int data, int locNth){

	int count = countNodes_sll(&(*head));

	if(locNth < 1 || locNth > (count + 1)){
		printf("Invalid location to insert at %d location\n", locNth);
		return FAILURE;
	}

	while(locNth--){
		if(locNth == 0){

			node_sll_t* newNode = (node_sll_t* )malloc(sizeof(node_sll_t));

			if(newNode == NULL){
				printf(" Malloc failed in %s()\n", __func__);
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

int deleteMidNode_sll(node_sll_t** head){

	if(*head == NULL || (*head)->link == NULL || (*head)->link->link == NULL){
		printf("Nothing to delete\n");
		return SUCCESS;
	}

	node_sll_t* fast = *head, *slow = fast, *prev = slow; 

	while(fast->link){
		fast = fast->link;
		if(fast->link){
			fast = fast->link;
			prev = slow;
			slow = slow->link;
		}
	}
	printf("The mid node data = %d and its address = %p\n", slow->data, slow);

	prev->link = slow->link;
	//printf("The slow data = %d and its address = %p slow->link = %p\n", slow->data, slow, slow->link);
	free(slow);
	slow->data = 0;
	slow->link = NULL;
	//printf("The slow data = %d and its address = %p slow->link = %p\n", slow->data, slow, slow->link);

	return SUCCESS;
}

void printNodes_sll( node_sll_t** head){
	node_sll_t *curr = *head;
	while(curr){
		printf("\t%d", curr->data);
		curr = curr->link;
	}
	printf("\n");
}

int main(){
	node_sll_t* head = NULL;
	int data = 0;
	int locNth = -1, index;

	for(index = 0; index < 10; index++){
		data = data + 10;
		locNth++;
		if(locNth > 5){
			locNth--;
			locNth--;
		}
		printf("\nlocNth = %d\n", locNth);
		insertNodeAtNthLoc(&head, data, locNth);
		printf("DLL: ");
		printNodes_sll(&head);
	}

	for(index = 0; index < 10; index++){
		deleteMidNode_sll(&head);
		printf("DLL: ");
		printNodes_sll(&head);
	}

	for(index = 0; index < 10; index++){
		data = data + 10;
		locNth--;
		if(locNth > 5){
			locNth--;
			locNth--;
		}
		printf("\nlocNth = %d\n", locNth);
		insertNodeAtNthLoc(&head, data, locNth);
		printf("DLL: ");
		printNodes_sll(&head);
	}
}
