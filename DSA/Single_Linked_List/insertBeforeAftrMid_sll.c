#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node_sll{
	struct node_sll* link;
	int data;
}node_sll_t;

int insertAtFirst_sll(
		node_sll_t** head, 
		int data){

	//allocate memory
	node_sll_t* newNode = ( node_sll_t* )
		malloc( sizeof( node_sll_t ) );

	//handle failure case for memory allocation
	if( newNode == NULL ){
		printf("Memory allocation failed in function %s\n", __func__); 
		return FAILURE;
	}

	// update SLL node variables if mem alloc is success
	newNode->link = NULL;
	newNode->data = data;

	
#if 0
	printf("&newNode = %p\n\n", &newNode);
	printf("newNode = %p\n*newNode = %p\n&newNode = %p\n\n", newNode, *newNode, &newNode);
	printf("&newNode = %p\n\n", &newNode);
	printf("\nnewNode->link= %p\nnewNode->data=%d\n\n", newNode->link , newNode->data);
	printf("(newNode)->link = %p\n", (newNode)->link);
	printf("newNode->link = %p\n\n", newNode->link);
	printf("newNode->data = %d\n\n", newNode->data);
#endif
	//assign newnode as first node if SLL link is empty
	if(*head == NULL){
//		printf("head = %p\n*head = %p\n&head = %p\n&(*head) = %p\n\n", head, *head, &head, &(*head));
		*head = newNode;
//		printf("head = %p\n*head = %p\n&head = %p\n&(*head) = %p\n(*head)->link = %p\n&(*head)->link=%p\n(*head)->data=%d\n", head, *head, &head, &(*head), (*head)->link, &(*head)->link, (*head)->data);
		return SUCCESS;
	}


	//Update newNode as first node if SLL is non-empty
	newNode->link = *head;
	*head = newNode;
	return SUCCESS;
}

int insertAtLast_sll(
		node_sll_t** head, 
		int data){

	//allocate memory
	node_sll_t* newNode = ( node_sll_t* )
		malloc( sizeof( node_sll_t ) );

	//handle failure case for memory allocation
	if( newNode == NULL ){
		printf("Memory allocation failed in function %s\n", __func__); 
		return FAILURE;
	}

	// update SLL node variables if mem alloc is success
	newNode->link = NULL;
	newNode->data = data;

	//assign newnode as first node if SLL link is empty
	if(*head == NULL){
		*head = newNode;
		return SUCCESS;
	}

	//traverse till last node to reach last node
	node_sll_t* current = *head;
	while(current->link){
		current = current->link;
	}

	//Insert newNode as last node if SLL is non-empty
	current->link = newNode;
	return SUCCESS;
}

void print_sll(
		node_sll_t** head){
	node_sll_t* current = *head;
	while(current){
		printf("\t%d", current->data);
		current = current->link;
	}
	printf("\n");
	return;
}

int count_sll(
		node_sll_t** head){
	int count = 0;
	node_sll_t* current = *head;
	while(current){
		count++;
		current = current->link;
	}
	return count;
}

bool findNode_sll(
		node_sll_t** head, int data){
	bool found = false;
	node_sll_t* current = *head;
	while(current){
		if(current->data == data){
			// return success case
			found = true;
			return found;
		}
		current = current->link;
	}

	//return Failure case
	return found;
}

int insertBeforeData_sll(
		node_sll_t** head, 
		int dataPrsntInSll, 
		int newDatatoInsertB4Prsnt){

	// if SLL is empty
	if(*head == NULL){
		printf("SLL is empty\n");
		return FAILURE;
	}

	// if required data is present in first node
	if((*head)->data == dataPrsntInSll){

		//allocate memory
		node_sll_t* newNode = ( node_sll_t* )
			malloc( sizeof( node_sll_t ) );

		//handle failure case for memory allocation
		if( newNode == NULL ){
			printf("Memory allocation failed in function %s\n", __func__); 
			return FAILURE;
		}

		// update SLL node variables if mem alloc is success
		newNode->data = newDatatoInsertB4Prsnt;

		//insert before found node
		newNode->link = *head;
		*head = newNode;

		return SUCCESS;
	}

	//traverse through the SLL to find the node
	node_sll_t* current = *head;

	while(current->link){
		if(current->link->data == dataPrsntInSll)
		{
			//allocate memory
			node_sll_t* newNode = ( node_sll_t* )
				malloc( sizeof( node_sll_t ) );

			//handle failure case for memory allocation
			if( newNode == NULL ){
				printf("Memory allocation failed in function %s\n", __func__); 
				return FAILURE;
			}

			// update SLL node variables if mem alloc is success
			newNode->data = newDatatoInsertB4Prsnt;

			//insert before found node
			newNode->link = current->link;
			current->link = newNode;
			return SUCCESS;
		}
		current = current->link;
	}

	printf("Data not found in SLL to perform %s\n", __func__);
	return FAILURE;
}

int insertAfterData_sll(
		node_sll_t** head, 
		int dataPrsntInSll, 
		int newDatatoInsertB4Prsnt){

	// if SLL is empty
	if(*head == NULL){
		printf("SLL is empty\n");
		return FAILURE;
	}

	//traverse through the SLL to find the node
	node_sll_t* current = *head;

	while(current->link){
		if(current->data == dataPrsntInSll)
		{
			//allocate memory
			node_sll_t* newNode = ( node_sll_t* )
				malloc( sizeof( node_sll_t ) );

			//handle failure case for memory allocation
			if( newNode == NULL ){
				printf("Memory allocation failed in function %s\n", __func__); 
				return FAILURE;
			}

			// update SLL node variables if mem alloc is success
			newNode->data = newDatatoInsertB4Prsnt;

			//insert After found node
			newNode->link = current->link;
			current->link = newNode;
			return SUCCESS;
		}
		current = current->link;
	}

	if(current->link == NULL && current->data == dataPrsntInSll)
	{
		//allocate memory
		node_sll_t* newNode = ( node_sll_t* )
			malloc( sizeof( node_sll_t ) );

		//handle failure case for memory allocation
		if( newNode == NULL ){
			printf("Memory allocation failed in function %s\n", __func__); 
			return FAILURE;
		}

		// update SLL node variables if mem alloc is success
		newNode->link = NULL;
		newNode->data = newDatatoInsertB4Prsnt;

		current->link = newNode;

		return SUCCESS;

	}

	printf("Data not found in SLL to perform %s\n", __func__);
	return FAILURE;
}

int findMidNodeData_sll(node_sll_t** head){
	if(*head == NULL)
	{
		printf("The SLL is empty to find mid Node\n");
		return FAILURE;
	}

	if((*head)->link == NULL || (*head)->link->link == NULL)
	{
		printf("The mid node data = %d\n", (*head)->data);
		return SUCCESS;
	}

	node_sll_t *slow = *head, *fast = *head;

	while(fast->link)
	{
		fast = fast->link;
		if(fast->link)
		{
			fast = fast->link;
			slow = slow->link;
		}
	}

	printf("The mid node data = %d an its address = %p\n", slow->data, slow);

	return SUCCESS;

}


int insertAtMidData_sll(node_sll_t** head, int newMidData){

	int count = count_sll(&(*head));

	if(count < 2){
		printf("No of nodes found before %s = %d\n", __func__, count);
		return FAILURE;
	}

	if(*head == NULL){
		return FAILURE;
	}

	node_sll_t* fast = *head, *slow = fast;
	while(fast->link)
	{
		fast =  fast->link;
		if(fast->link)
		{
			fast = fast->link;
			slow = slow->link;
		}
	}

	//allocate memory
	node_sll_t* newNode = ( node_sll_t* )
		malloc( sizeof( node_sll_t ) );

	//handle failure case for memory allocation
	if( newNode == NULL ){
		printf("Memory allocation failed in function %s\n", __func__); 
		return FAILURE;
	}

	// update SLL node variables if mem alloc is success
	newNode->link = NULL;
	newNode->data = newMidData;

	newNode->link = slow->link;
	slow->link = newNode;

	return SUCCESS;

}


int main(){
	node_sll_t* head = NULL;
	int count;

	for( count = 1; count < 2; count++){
		insertAtFirst_sll(&head, count + 10);
		//insertAtLast_sll(&head, count + 100);
	}
	printf("\nSLL: ");
	print_sll(&head);
	count = count_sll(&head);
	printf("\nNo of nodes = %d\n", count);

#if 0
	if(findNode_sll(&head, 102) == true){
		printf("Data found in SLL node, size of bool = %ld\n", sizeof(bool));
	} else {
		printf("Data not found in SLL node\n");
	}

	//insertBeforeData_sll(&head, 11, 777);
	printf("\nNo of nodes = %d\nSLL: ", count_sll(&head)); 
	print_sll(&head);

	//insertAfterData_sll(&head, 13, 999);
	printf("\nNo of nodes = %d\nSLL: ", count_sll(&head)); 
	print_sll(&head);	

	insertAtMidData_sll(&head, 70007);
	printf("\nNo of nodes = %d\nSLL: ", count_sll(&head)); 
	print_sll(&head);	

	findMidNodeData_sll(&head);
#endif



}


