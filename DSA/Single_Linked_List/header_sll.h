#ifndef HEADER_SLL_H
#define HEADER_SLL_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node_sll
{
	struct node_sll *link;
	int data;
}NODE_SLL_t;

int insertAtLast_sll(NODE_SLL_t **head, int data);
int insertAtFirst_sll(NODE_SLL_t **head, int data);
int deleteAtLast_sll(NODE_SLL_t **head);
int deleteAtFirst_sll(NODE_SLL_t **head);
void print_sll(NODE_SLL_t **head);

#endif
