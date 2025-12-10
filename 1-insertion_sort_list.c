#include "sort.h"
/**
* insertion_sort_list - Sorts a doubly linked list using insertion sort.
* @list: Double pointer to the head of the list.
*
* Description: Prints the list after every swap.
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *temp;
	listint_t *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		temp = current;
		current = current->next;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			prev = temp->prev;

			prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = prev;

			temp->next = prev;
			temp->prev = prev->prev;

			if (prev->prev != NULL)
				prev->prev->next = temp;
			else
				*list = temp;

			prev->prev = temp;

			print_list(*list);
		}
	}
}
