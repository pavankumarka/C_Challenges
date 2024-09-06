#include <stdio.h>  //5.10pm-6.25pm
#include <stdlib.h>

typedef struct node_sll{
	struct node_sll* link;
	int data;
}node_sll_t;

void print_sll(node_sll_t **head){
	node_sll_t *curr = *head;
	printf("SLL: ");
	while(curr){
		printf("%d--->", curr->data);
		curr = curr->link;
	}
	printf("--__\n");
}

int insertSorted(node_sll_t **head, int data){

	node_sll_t *newNode = ( node_sll_t *)malloc( sizeof(node_sll_t));
	if(newNode == NULL){
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
	while(curr->link != NULL && newNode->data > curr->link->data){
		curr = curr->link;
	}

	newNode->link = curr->link;
	curr->link = newNode;

	return 0;
}

int mergeAlternativeNodes_sll(node_sll_t **head1, node_sll_t **head2){

	if(*head1 == NULL || *head2 == NULL){
		return -1;
	}

	node_sll_t *curr1 = *head1, *curr2 = *head2, *next1, *next2;
	while(curr1 != NULL && curr2 != NULL){
			next1 = curr1->link;
			next2 = curr2->link;
			curr2->link = curr1->link;
			curr1->link = curr2;
			curr1 = next1;
			curr2 = next2;
	}

	*head2 = next2;

	return 0;
}


int main(){
	node_sll_t *head1 = NULL, *head2 = NULL;
	int data = 0;
	int count;

	for(count = 0; count < 0; count++){
		data = data + 100;
		insertSorted(&head1, data);
	}
	printf("\n1st SLL list before merging alternatively:\n");
	print_sll(&head1);

	for(count = 0; count < 3; count++){
		data = data + 100;
		insertSorted(&head2, data);
	}
	printf("2nd SLL list before merging alternatively:\n");
	print_sll(&head2);

	mergeAlternativeNodes_sll(&head1, &head2);
	printf("\n1st SLL list After merging alternatively:\n");
	print_sll(&head1);
	printf("2nd SLL list After merging alternatively:\n");
	print_sll(&head2);


}
