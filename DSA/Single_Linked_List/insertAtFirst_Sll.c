#include "header_sll.h"

#if 0
int insertAtFirst_sll(NODE_SLL_t **head, int data)
{
	/* 1. allocate memory for new node*/
	NODE_SLL_t *newNode = (NODE_SLL_t *)malloc(sizeof(NODE_SLL_t));

	/* 2. check if memory allocation is success in heap*/
	if(!newNode)
	{
		perror("Malloc failed in insertAtFirst_sll() \n");
		return FAILURE;
	}

	/* update link and data values*/
	newNode->link = NULL;
	newNode->data = data;

	/* 4. update new node as head if SLL list is empty */
	if(!(*head))
	{
		*head = newNode;
		return SUCCESS;
	}

	/* make new node as head node if list is non-empty*/
	newNode->link = *head;
	*head = newNode;
	return SUCCESS;

	return FAILURE;
}
#endif
































int insertAtFirst_sll(NODE_SLL_t **head, int data)
{
	/* allocate memory */
	NODE_SLL_t *newNode = (NODE_SLL_t *)malloc(sizeof(NODE_SLL_t));
	if(!newNode)
	{
		return FAILURE;
	}

	/*2. update link and data*/
	newNode->link = NULL;
	newNode->data = data;

	/*3. Update new node as head if head is empty*/
	if(!(*head))
	{
		*head = newNode;
		return SUCCESS;
	}

	/*4. update hea with newnode*/
	newNode->link = *head;
	*head = newNode;

	return SUCCESS;
}
