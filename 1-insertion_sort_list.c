#include "sort.h"
/**
* find_position - Finds the correct insertion position
*					for a value in sorted list.
* @head: Pointer to the head of the sorted list.
* @value: Value to insert.
*
* Return: Pointer to first node >= value, or NULL.
*/
listint_t *find_position(listint_t *head, int value)
{
	while (head != NULL && head->n < value)
		head = head->next;

	return (head);
}

/**
* move_node - Moves a node before a specified position in a doubly linked list.
* @current: Pointer to the node to move.
* @new_position: Pointer to the node before which @current must be inserted.
* @list: Double pointer to the head of the list.
*/
void move_node(listint_t *current, listint_t *new_position, listint_t **list)
{
	listint_t *prev = current->prev;
	listint_t *next = current->next;

	if (prev)
		prev->next = next;
	else
		*list = next;

	if (next)
		next->prev = prev;

	if (new_position == *list)
	{
		current->prev = NULL;
		current->next = *list;
		(*list)->prev = current;
		*list = current;
		return;
	}

	current->next = new_position;
	current->prev = new_position->prev;

	new_position->prev->next = current;
	new_position->prev = current;
}

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
		temp = current->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			prev_n = current->prev;

			prev_n->next = current->next;
			if (current->next != NULL)
				current->next->prev = prev_n;

			current->prev = prev_n->prev;
			current->next = prev_n;

			if (prev_n->prev != NULL)
				prev_n->prev->next = current;
			else
				*list = current;

			prev_n->prev = current;

			print_list(*list);
		}

		current = temp;
	}
}
