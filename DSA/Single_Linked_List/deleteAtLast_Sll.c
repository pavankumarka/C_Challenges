#include "header_sll.h"

int deleteAtLast_sll(NODE_SLL_t **head)
{
	/*If SLL is empty*/
	if(!*head)
	{
		return SUCCESS;
	}


	/*if the sll has more than 1 node*/
	NODE_SLL_t *temp = *head, *copy;

	/*if there is only 1 node in sll*/
	if(!(temp->link))
	{
		free(temp);
		*head = NULL;
		return SUCCESS;
	}

	for(;temp->link; temp = temp->link)
	{
		copy = temp;
	}

	free(temp);
	copy->link = NULL;

	return SUCCESS;
}
