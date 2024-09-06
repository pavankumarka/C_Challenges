#include "header_sll.h"

void print_sll(NODE_SLL_t **head)
{
	printf("SLL:\t");
	NODE_SLL_t *temp = *head;
	for(;temp; temp = temp->link)
	{
		printf("%d\t", temp->data);
	}
}
