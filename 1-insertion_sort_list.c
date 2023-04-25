#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer that points to the pointer head of the node of the list
 *
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *current, *prev, *temp;

	current = (*list)->next;

	while (current != NULL)
	{
		prev = current->prev;
		temp = current->next;

		while (prev != NULL && prev->n > current->n)
		{
			if (prev->prev != NULL)
				prev->prev->next = current;

			current->prev = prev->prev;
			prev->next = temp;

			if (temp != NULL)
				temp->prev = prev;

			prev->prev = current;
			current->next = prev;

			prev = current->prev;

			if (prev == NULL)
				*list = current;

			print_list(*list);
		}

		current = temp;
	}
}
