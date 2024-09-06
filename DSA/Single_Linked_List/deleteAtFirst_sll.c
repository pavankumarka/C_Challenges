#include "header_sll.h"

int deleteAtFirst_sll(NODE_SLL_t **head)
{
	/*if SLL is empty*/
	if(!*head)
	{
		printf("No nodes to delete\n");
		return SUCCESS;
	}

	NODE_SLL_t *curr_node = *head, *prev_node; 
	/*if SLL has one node*/
	if(!(curr_node->link))
	{
		free(curr_node);
		*head = NULL;
		return SUCCESS;
	}

	/*if SLL has more than one node*/
	prev_node = curr_node->link;
	free(curr_node);
	curr_node = NULL;
	*head = prev_node;

	return SUCCESS;
}
