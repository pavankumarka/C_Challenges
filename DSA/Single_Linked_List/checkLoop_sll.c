#include <stdio.h>
#include <stdlib.h>

typedef struct node_sll{
	struct node_sll* link;
	int data;
}node_sll_t;

int insertSorted_sll(node_sll_t** head, int data){

	node_sll_t* newNode = (node_sll_t *)malloc(sizeof(node_sll_t));
	if(newNode == NULL){
		printf("memory allocation failed in %s() function\n", __func__);
		return -1;
	}

	newNode->link = NULL;
	newNode->data = data;

	if(*head == NULL || newNode->data <= (*head)->data){
		newNode->link = *head;
		*head = newNode;

		return 0;
	}

	node_sll_t* curr = *head;
	while(curr->link != NULL && newNode->data >= (curr->link)->data){
		curr = curr->link;
	}

	newNode->link = curr->link;
	curr->link = newNode;

	return 0;
}

void print_sll(node_sll_t** head){
	if(*head == NULL){
		printf("SLL is empty\n");
		return;
	}

	node_sll_t* curr = *head;

	printf("SLL:");
	while(curr){
		printf("\t%d", curr->data);
		curr = curr->link;
	}
	printf("\n");

	return;
}

int removeDuplicates_sll(node_sll_t** head){
	if(*head == NULL){
		printf("SLL is empty to resolve duplicates\n");
		return -1;
	}

	node_sll_t* curr = *head, *next = curr, *dup = NULL;

	while(curr){
		for(next = curr; next->link;){
			if(curr->data == (next->link)->data){
				dup = next->link;
				next->link = (next->link)->link;
				free(dup);
			} else {
				next = next->link;
			}
		}
		curr = curr->link;
	}
	return 0;
}

int createLoop_sll(node_sll_t** head){
	if(*head == NULL){
		printf("SLL is empty to create loop\n");
		return -1;
	}

	node_sll_t* curr = *head;
	while(curr->link){
		curr = curr->link;
	}

	curr->link = (*head);
	return 0;
}

int checkLoop_sll(node_sll_t** head){
	node_sll_t* fast = *head, *slow = fast;
	while(fast->link){
		fast = fast->link;
		if(fast->link){
			fast = fast->link;
		}

		if(fast->link == (*head)){
			printf("loop found at %d\n", fast->link->data);
			return 0;
		} 
	}
	return -1;
}


int main(){

	node_sll_t* head = NULL;
	int data = 0;
	int count = 0;

	for(count = 0; count < 5; count++){
		data = data + 100;
		insertSorted_sll(&head, data);
		if(count <= 3)
			insertSorted_sll(&head, data);
	}
	insertSorted_sll(&head, data);
	print_sll(&head);
	printf("SLL after removing duplicates\n");
	removeDuplicates_sll(&head);
	print_sll(&head);
	if(checkLoop_sll(&head) == 0){
		printf("loop detected in SLL list\n");
	} else {
		printf("No loop created in this SLL list\n");
	}
	printf("created loop between last node and first node\n");
	createLoop_sll(&head);
	//print_sll(&head);
	if(checkLoop_sll(&head) == 0){
		printf("loop detected in SLL list\n");
	} else {
		printf("No loop created in this SLL list\n");
	}

	return 0;

}
