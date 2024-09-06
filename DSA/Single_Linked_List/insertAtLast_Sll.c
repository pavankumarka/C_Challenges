#include "header_sll.h"

int insertAtLast_sll(NODE_SLL_t **head, int data)
{
	/* 1. allocate memory and check error*/
	NODE_SLL_t *newNode = (NODE_SLL_t *)malloc(sizeof(NODE_SLL_t));
	if(newNode == NULL)
	{
		perror("No Free Heap Memory\n");
		return FAILURE;
	}

	newNode->link = NULL;
	newNode->data = data;

	/* 2. Check if the SLL link is empty, then assign new node as head node*/
	if(*head == NULL)
	{
		*head = newNode;
		return SUCCESS;
	}

	NODE_SLL_t *temp = *head;

	/*3. If first link is non empty, traverse till end to insert new node*/
	for(;temp->link; temp = temp->link)
	{}

	/* update link and return*/
	temp->link = newNode;
	return SUCCESS;
}
