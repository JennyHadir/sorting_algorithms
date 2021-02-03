#include "sort.h"

/**
 *insertion_sort_list - sort a list with insertion sort methode
 * @list: list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		while (node->prev && (node->n < node->prev->n))
		{
			if (node->next)
				node->next->prev = node->prev;
			node->prev->next = node->next;
			node->next = node->prev;
			node->prev = node->prev->prev;
			node->next->prev = node;
			if (node->prev == NULL)
				*list = node;
			else
				node->prev->next = node;
			print_list(*list);
		}
		node = node->next;
	}
}
