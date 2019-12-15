#include "LinkedList.h"

Node* Push(LinkedList *linked_list, void *object)
{
	if (!linked_list->length)
	{
		linked_list->head = malloc(sizeof(Node));
		linked_list->head->object = object;
		linked_list->head->prev = NULL;
		linked_list->tail = linked_list->head;
		linked_list->tail->next = NULL;
		linked_list->length++;
	}
	else
	{
		Node *temp = linked_list->tail;
		linked_list->tail->next = malloc(sizeof(Node));
		linked_list->tail = linked_list->tail->next;
		linked_list->tail->object = object;
		linked_list->tail->prev = temp;
		linked_list->tail->next = NULL;
		linked_list->length++;
	}
	return linked_list->tail;
}

void RemoveNode(Node *node)
{
	node->next->prev = node->prev;
	node->prev->next = node->next;
	free(node);
}