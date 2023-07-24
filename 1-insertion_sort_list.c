#include "sort.h"

/**
 * swap_nodes - a function that swaps two nodes in a listint_t.
 * @h: pointer to the head of the doubly-linked list.
 * @n1: first pointer to the first node to swap.
 * @n2: second node to swap.
 */

void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - a function that sorts a doubly linked
 * list of integers in ascending order using the Insertion sort algorithm.
 * @list: pointer to the head of a doubly-linked list of integers.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *a;
	listint_t *i;
	listint_t *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (a = (*list)->next; a != NULL; a = temp)
	{
		temp = a->next;
		i = a->prev;
		while (i != NULL && a->n < i->n)
		{	swap_nodes(list, &i, a);
			print_list((const listint_t *)*list);
		}
	}
}
