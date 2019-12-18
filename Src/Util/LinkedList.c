#include "LinkedList.h"

Node* Push(LinkedList *linked_list, void *object)
{
	Node *temp = linked_list->tail;
	linked_list->tail->next = malloc(sizeof(Node));
	linked_list->tail = linked_list->tail->next;
	linked_list->tail->object = object;
	linked_list->tail->prev = temp;
	linked_list->tail->next = NULL;
	
	return linked_list->tail;
}

void RemoveNode(LinkedList *linked_list, Node *node)
{
	if (!node->next)
	{
		linked_list->tail = node->prev;
		node->prev->next = NULL;
	}
	else
	{
		node->next->prev = node->prev;
		node->prev->next = node->next;
	}
	free(node);
}