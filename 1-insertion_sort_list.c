#include "sort.h"
/**
* insertion_sort_list - Sorts a doubly linked list using insertion sort.
* @list: Double pointer to the head of the list.
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *prev_n;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		temp = current;
		current = current->next;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			prev_n = temp->prev;

			prev_n->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = prev_n;

			temp->next = prev_n;
			temp->prev = prev_n->prev;

			if (prev_n->prev != NULL)
				prev_n->prev->next = temp;
			else
				*list = temp;

			prev_n->prev = temp;

			print_list(*list);
		}
	}
}
